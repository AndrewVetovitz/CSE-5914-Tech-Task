#include <string>

#include <grpcpp/grpcpp.h>

#include "mathtest.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using mathtest::MathTest;
using mathtest::MathRequest;
using mathtest::MathReply;

#include <time.h>
#include <sstream>

class MathTestClient {
    public:
        MathTestClient(std::shared_ptr<Channel> channel) : stub_(MathTest::NewStub(channel)) {}

    int sendRequest(int a, int b) {
        MathRequest request;

        request.set_a(a);
        request.set_b(b);

        MathReply reply;

        ClientContext context;

        Status status = stub_->sendRequest(&context, request, &reply);

        if(status.ok()){
            return reply.result();
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    private:
        std::unique_ptr<MathTest::Stub> stub_;
};

void Run(int& runs) {
    std::string address("0.0.0.0:5000");
    MathTestClient client(
        grpc::CreateChannel(
            address, 
            grpc::InsecureChannelCredentials()
        )
    );

    int response;

    clock_t t;
    t = clock();

    for(int i = 0; i < runs; i++) {
        response = client.sendRequest(i, i + 5);
        std::cout << "Answer received: " << i << " * " << i + 5 << " = " << response << std::endl;
    }

    t = clock() - t;
    std::cout << "Total time: " << (float)t / CLOCKS_PER_SEC << " seconds" << std::endl;
}

int main(int argc, char* argv[]){
    int val = 10;

    if(argc > 1){
        std::istringstream iss(argv[1]);

        if(!(iss >> val)) {
            return -1;
        }
    }

    Run(val);

    return 0;
}
