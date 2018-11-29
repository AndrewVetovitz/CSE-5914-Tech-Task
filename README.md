# CSE-5914-Tech-Task
Tech task for 5914

# What is GRPC
gRPC is a application based communication based on buffers. These buffers can communicate language-anonomous (so ruby -> python or C++ -> Java for exp.). The idea over rest is to reduce the amount of required code as well as reduce overall complexity while improving speed.

# C++
How To Install
Linux:
[sudo] apt-get install build-essential autoconf libtool pkg-config

git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
cd grpc
git submodule update --init

cd grpc/third_party/protobuf
sudo make install

Windows:
Install Visual Studio 2015 or 2017 (Visual C++ compiler will be used).
Install Git.
Install CMake.
Install Active State Perl (choco install activeperl)
Install Go (choco install golang)
Install yasm and add it to PATH (choco install yasm)

powershell git clone --recursive -b ((New-Object System.Net.WebClient).DownloadString(\"https://grpc.io/release\").Trim()) https://github.com/grpc/grpc
cd grpc
git submodule update --init

MacOS:
[sudo] xcode-select --install
(optional) brew install autoconf automake libtool shtool

git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
cd grpc
git submodule update --init

cd grpc/third_party/protobuf
sudo make install
