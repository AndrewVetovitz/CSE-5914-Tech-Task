#include <string>

#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>

using namespace Pistache;
using namespace Pistache::Http;

#include <time.h>
#include <sstream>

int main(int argc, char *argv[]) {
    int val = 10;

    if(argc > 1){
        std::istringstream iss(argv[1]);

        if(!(iss >> val)) {
            return -1;
        }
    }

    Http::Client client;

    auto opts = Http::Client::options().threads(1);
    client.init(opts);

    std::vector<Async::Promise<Http::Response>> responses;

    clock_t time;
    time = clock();

    for (int i = 0; i < val; ++i) {
        std::string request(std::to_string(i) + " " + std::to_string(i + 5));
        std::string response_string("Answer received: " + std::to_string(i) + " * " + std::to_string(i + 5) + " = ");
        auto resp = client.get("0.0.0.0:5000").body(request).send();
        resp.then([&](Http::Response response) {
            auto body = response.body();
            if (!body.empty())
                std::cout << response_string << body << std::endl;
        }, Async::IgnoreException);
         responses.push_back(std::move(resp));
    }

    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Http::Response>> barrier(sync);

    barrier.wait_for(std::chrono::seconds(5));

    time = clock() - time;

    std::cout << "Total time: " << time << std::endl;

    client.shutdown();
}


// /* 
//    Mathieu Stefani, 07 février 2016
   
//  * Http client example
// */

// #include <atomic>

// #include <pistache/net.h>
// #include <pistache/http.h>
// #include <pistache/client.h>

// using namespace Pistache;
// using namespace Pistache::Http;

// int main(int argc, char *argv[]) {
//     int count = 1;
//     if (argc == 3) {
//         count = std::stoi(argv[2]);
//     }

//     Http::Client client;

//     auto opts = Http::Client::options()
//         .threads(1)
//         .maxConnectionsPerHost(8);
//     client.init(opts);

//     std::vector<Async::Promise<Http::Response>> responses;

//     std::atomic<size_t> completedRequests(0);
//     std::atomic<size_t> failedRequests(0);

//     auto start = std::chrono::system_clock::now();

//     for (int i = 0; i < count; ++i) {
//         auto resp = client.get("0.0.0.0:5000").cookie(Http::Cookie("FOO", "bar")).send();
//         resp.then([&](Http::Response response) {
//                 ++completedRequests;
//             std::cout << "Response code = " << response.code() << std::endl;
//             auto body = response.body();
//             if (!body.empty())
//                std::cout << "Response body = " << body << std::endl;
//         }, Async::IgnoreException);
//         responses.push_back(std::move(resp));
//     }

//     auto sync = Async::whenAll(responses.begin(), responses.end());
//     Async::Barrier<std::vector<Http::Response>> barrier(sync);

//     barrier.wait_for(std::chrono::seconds(5));

//     auto end = std::chrono::system_clock::now();
//     std::cout << "Summary of execution" << std::endl
//               << "Total number of requests sent     : " << count << std::endl
//               << "Total number of responses received: " << completedRequests.load() << std::endl
//               << "Total number of requests failed   : " << failedRequests.load() << std::endl
//               << "Total time of execution           : "
//               << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

//     client.shutdown();
// }
