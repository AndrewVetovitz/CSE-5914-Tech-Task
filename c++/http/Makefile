CXX = g++
CXXFLAGS += -std=c++11

FLAGS = -lpistache -lpthread

all: server client

server: server.o
	$(CXX) $^ -o $@  $(FLAGS)

client: client.o
	$(CXX) $^ -o $@ $(FLAGS)

clean:
	rm -f *.o client server
