# CSE548 homework

## Setup

1. Install Docker Community Edition (CE)
    * [Linux](https://docs.docker.com/install/linux/docker-ce/ubuntu/)
    * [Mac](https://store.docker.com/editions/community/docker-ce-desktop-mac)
    * [Windows](https://store.docker.com/editions/community/docker-ce-desktop-windows)

2. Post-installation steps (run Docker as non-root user - Linux only)
    * Follow the steps in [Manage Docker as a non-root user](https://docs.docker.com/install/linux/linux-postinstall/)

3. Build Docker image (need at least 10GB of space and one hour of time)
    * Run `make -C setup build`

4. Test if you can run container in interactive mode
    * Run `make -C setup run`
    * Run (in the cointainer) `exit`
