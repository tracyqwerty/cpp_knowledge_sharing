#include <cpr/cpr.h>
#include <iostream>
#include <string>
int main() {
  // TODO: fix the ssl problem.
  /*
    tracyqwerty@tracyqwertydezhuantou cs106L-assignment2-master % ./check_cpr
    Status code: 0
    Response:
    Error message: LibreSSL SSL_connect: SSL_ERROR_SYSCALL in connection to
    en.wikipedia.org:443
  */
  std::string url = "https://en.wikipedia.org/wiki/Main_Page";
  cpr::Proxies proxies{{"http", "http://127.0.0.1:7890"},
                       {"https", "http://127.0.0.1:7890"}};

  // Create a cpr::Session object and set the proxies
  cpr::Session session;
  session.SetProxies(proxies);
  session.SetUrl(cpr::Url{url});
  // cpr::Response r = cpr::Get(cpr::Url{"https://baike.baidu.com/"});
  cpr::Response r = session.Get();

  std::cout << "Status code: " << r.status_code << std::endl;
  if (r.text.size() > 100) {
    std::cout << "First 100 characters of response: " << r.text.substr(0, 100)
              << std::endl;
  } else {
    std::cout << "Response: " << r.text << std::endl;
    std::cout << "Error message: " << r.error.message << std::endl;
  }
  return 0;
}
