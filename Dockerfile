# Use the official Ubuntu base image
FROM ubuntu:latest

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
    unzip

# Set the working directory
WORKDIR /app

# Copy the entire project into the container
COPY . .

# Create a build directory and navigate into it
RUN mkdir build && cd build && \
    cmake .. && \
    make

# Entry point 
ENTRYPOINT ["./build/test_kazuha"]

# Specify the command to run on container start
CMD ["./build/example"]  