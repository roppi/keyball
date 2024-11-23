FROM ghcr.io/qmk/qmk_cli:latest

# Update packages
# RUN apt-get update && apt upgrade -y

# Setup qmk_firmware
ARG QMK_TAG
ARG QMK_PATH
RUN git clone https://github.com/qmk/qmk_firmware.git -b ${QMK_TAG} ${QMK_PATH} \
    && qmk setup --home ${QMK_PATH} --yes

# Install python modules
RUN /usr/bin/python3 -m pip install -r ${QMK_PATH}/requirements.txt

# Remove other keyboards
RUN rm -rf /${QMK_PATH}/keyboards/*

# Set `DEVCONTAINER` environment variable to help with orientation
ENV DEVCONTAINER=true