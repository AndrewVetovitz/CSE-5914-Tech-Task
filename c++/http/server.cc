#include <string>
#include <sstream>
#include <iterator>

#include "pistache/endpoint.h"

using namespace Pistache;

class MathTestHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(MathTestHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
        std::istringstream iss(request.body());
        std::vector<std::string> results(
            (std::istream_iterator<std::string>(iss)),
            std::istream_iterator<std::string>()
        );

        int a, b;

        std::istringstream ss_a(results.at(0));
        std::istringstream ss_b(results.at(1));

        ss_a >> a;
        ss_b >> b;

        std::string result(std::to_string(a * b));

        response.send(Pistache::Http::Code::Ok, result);
    }
};

int main() {
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(5000));
    auto opts = Pistache::Http::Endpoint::options().threads(1);

    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Http::make_handler<MathTestHandler>());
    server.serve();

    server.shutdown();

    return 0;
}