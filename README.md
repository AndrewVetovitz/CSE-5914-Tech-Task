# CSE-5914-Tech-Task
Tech task for 5914

# What is gRPC
gRPC which is short for Google RPC is an application based communication based on buffers. These buffers can communicate language-anonomous (so ruby -> python or C++ -> Java for exp.).

gRPC is written in a serialization format. The base use in this tutorial with be protobuf which comes default with the gRPC in the download section below. Any serialization language can be used however.

# gRPC vs REST
The advantage of gRPC over REST is several. First and foremost gRPC is much quicker than REST because encoding / decoding happens over the users local CPU. Secondly the amount of code one needs to write is less than that of most REST implementations. 

# C++ Installation
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

# Writing a simple request

Please refer the [/cpp](https://github.com/AndrewVetovitz/CSE-5914-Tech-Task/tree/master/c%2B%2B) folder.

# Benchmarks
        1           10          100         1000        10000       1000000
http:   .007 sec    .021 sec    .044 sec    .270 sec    2.525 sec   25.046 sec
gRPC:   .003 sec    .007 sec    .019 sec    .078 sec    .665 sec    6.404 sec

# Closing
While gRPC can be a little difficult to setup at first while most rest services are quicker to get up and running if speed is a requirment the extra time to prepare gRPC can be worth it. Also since more content is being driven over the web year over year being able to presupport http2 can be worth it for the asynchronous gains used in these requests.
