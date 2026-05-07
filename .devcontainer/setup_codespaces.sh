#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
export DEVKITPRO=/opt/devkitpro
export DEVKITARM="${DEVKITPRO}/devkitARM"
export PATH="${DEVKITARM}/bin:${DEVKITPRO}/tools/bin:${PATH}"

echo "==> Installing Linux packages"
if command -v apt-get >/dev/null 2>&1; then
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
fi

echo "==> Checking devkitARM"
if ! command -v arm-none-eabi-cpp >/dev/null 2>&1; then
  echo "arm-none-eabi-cpp was not found. Rebuild the Codespace so it uses .devcontainer/Dockerfile."
  exit 1
fi

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
