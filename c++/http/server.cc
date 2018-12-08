#include "../../cpp-httplib/httplib.h"

#include <string>
#include <iostream>

int main(void){
    using namespace httplib;

    Server svr;

    svr.Post("/", [](const Request& req, Response& res) {
        std::istringstream iss(req.body);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

        int a = std::stoi(results.at(0));
        int b = std::stoi(results.at(1));

        std::string result(std::to_string(a * b));
        res.set_content(result, "text/plain");
    });

    svr.listen("localhost", 5001);
}
