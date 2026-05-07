FROM devkitpro/devkitarm:20260221

ENV DEVKITPRO=/opt/devkitpro
ENV DEVKITARM=/opt/devkitpro/devkitARM
ENV PATH="${DEVKITARM}/bin:${DEVKITPRO}/tools/bin:${PATH}"

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        git \
        jq \
        libpng-dev \
        make \
        pkg-config \
        wget \
    && rm -rf /var/lib/apt/lists/*
