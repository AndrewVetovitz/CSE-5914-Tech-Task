#include "../../cpp-httplib/httplib.h"

#include <iostream>

int main(void){
    httplib::Client cli("localhost", 5000);

    auto res = cli.Post("/", "testing", "text/plain");
    if (res && res->status == 200) {
        std::cout << res->body << std::endl;
    }
}