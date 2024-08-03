## still on development but you can try few features

![kazuha](kazuha.jpg)

# kazuha 

kazuha is a simple quantum computing library for c++, for now only support basic features like quantum logic gates, qft, superposition, entanglement, etc. 

# Installations

i use eigen and openmp for this project so make sure to install eigen and openmp

for arch based
```sh
yay -S eigen openmp
```

for debian based
```sh
sudo apt-get install libeigen3-dev libomp-dev
cp -r /usr/local/include/eigen3/Eigen /usr/local/include 
```

## Building from sources

if you want to build from source then.. 

1. clone the repo

```sh
git clone https://github.com/mornsoltice/kazuha.git 
cd kazuha 
```

2. create a build folder and build it 

```sh 
mkdir build && cd build && cmake .. && make
```

## Docker 

well if you want to build it with docker then...

1. build the docker image 

```sh
docker build -t kazuha 
```

2. run the docker container

```sh
docker run --rm -it kazuha 
```

# Usage 

well for usage, just see the code lol or see the example on 'examples'

# Contributing

contributions are welcome, but idk why you want to contribute lol.

# License

this project is under MIT License


