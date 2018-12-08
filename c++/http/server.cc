#include "../../cpp-httplib/httplib.h"

#include <string>
#include <iostream>

int main(void){
    using namespace httplib;

    Server svr;

    svr.Post("/", [](const Request& req, Response& res) {
        std::cout << req.body << std::endl;
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("localhost", 5000);
}
