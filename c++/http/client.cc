#include "../../cpp-httplib/httplib.h"

#include <iostream>
#include <string>

#include <time.h>

void Run(int& val){
    httplib::Client cli("localhost", 5001);

    clock_t t;
    t = clock();

    for(int i = 0; i < val; i++){
        std::string body(std::to_string(i) + " " + std::to_string(i + 5));
        auto res = cli.Post("/", body, "text/plain");
        if (res && res->status == 200) {
        std::cout << "Answer received: " << i << " * " << i + 5 << " = " << res->body << std::endl;
        }
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
