# Use an official Ubuntu image as the base
FROM ubuntu:latest

# Install essential tools and dependencies, including X11 libraries
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    clang \
    git \
    libx11-dev \
    libxext-dev \
    libxrender-dev \
    libxrandr-dev \
    libpng-dev \
    imagemagick \
    && rm -rf /var/lib/apt/lists/*

# Set up a directory for the project
WORKDIR /workspace

# Expose ports if needed for debugging (for example, gdbserver on port 1234)
EXPOSE 1234

# Default command, can be overridden
CMD ["/bin/bash"]