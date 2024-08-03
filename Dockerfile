# Use a newer Ubuntu base image
FROM ubuntu:20.04

# Set Env Variable
ENV DEBIAN_FRONTEND=noninteractive

# Set the maintainer label
LABEL maintainer="khairandramnandyka@gmail.com"

# Install required packages and CMake
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    g++ \
    git \
    libeigen3-dev \
    cmake \
    unzip \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the entire project into the container
COPY . .

# Create a build directory and navigate into it
RUN mkdir -p build && cd build && \
    cmake .. && \
    make

# Specify the command to run on container start
CMD ["./build/example"]
