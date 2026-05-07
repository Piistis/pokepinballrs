#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
export DEVKITPRO=/opt/devkitpro
export DEVKITARM="${DEVKITPRO}/devkitARM"
export PATH="${DEVKITARM}/bin:${DEVKITPRO}/tools/bin:${PATH}"

echo "==> Installing Linux packages"
sudo apt-get update
sudo DEBIAN_FRONTEND=noninteractive apt-get install -y \
  build-essential \
  ca-certificates \
  git \
  jq \
  libpng-dev \
  make \
  pkg-config \
  wget

echo "==> Installing devkitPro pacman/devkitARM"
if ! command -v dkp-pacman >/dev/null 2>&1; then
  tmpdir="$(mktemp -d)"
  trap 'rm -rf "$tmpdir"' EXIT
  wget -q -O "${tmpdir}/install-devkitpro-pacman" https://apt.devkitpro.org/install-devkitpro-pacman
  chmod +x "${tmpdir}/install-devkitpro-pacman"
  sudo "${tmpdir}/install-devkitpro-pacman"
fi

sudo dkp-pacman -Sy --noconfirm
sudo dkp-pacman -S --needed --noconfirm gba-dev

echo "==> Building and installing pret/agbcc"
if [ ! -x "${repo_root}/tools/agbcc/bin/agbcc" ]; then
  agbcc_dir="$(dirname "${repo_root}")/agbcc"
  if [ ! -d "${agbcc_dir}/.git" ]; then
    git clone https://github.com/pret/agbcc "${agbcc_dir}"
  else
    git -C "${agbcc_dir}" pull --ff-only
  fi
  (cd "${agbcc_dir}" && ./build.sh && ./install.sh "${repo_root}")
fi

echo "==> Building pokepinballrs helper tools"
(cd "${repo_root}" && make tools)

cat <<'MSG'

Codespaces setup finished.

Next steps:
1. Upload your original ROM into the repository root as baserom.gba.
2. Run: make -j"$(nproc)"
3. The built ROM should appear as pokepinballrs.gba.

MSG
