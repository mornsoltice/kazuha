# Use the official Ubuntu base image
FROM ubuntu:22.04

# Set Env Variable
ENV DEBIAN_FRONTEND=noninteractive

# Set the maintainer label
LABEL maintainer="khairandramnandyka@gmail.com"

# Install required packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    g++ \
    git \
    libeigen3-dev \
    unzip && \
    rm -rf /var/lib/apt/lists/*

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
