# Use the official Ubuntu base image
FROM ubuntu:latest

# Set the working directory
WORKDIR /app

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    git \
    libeigen3-dev \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy the entire project to the container
COPY . .

# Build Google Test (gtest)
RUN cd /usr/src/googletest && \
    cmake . && \
    make && \
    cp lib/*.a /usr/lib

# Build the project
RUN mkdir build && cd build && \
    cmake .. && \
    make

# Run tests
RUN cd build && ctest --output-on-failure

# Set the entry point for the container
CMD ["bash"]
