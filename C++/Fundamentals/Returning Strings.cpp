#include <string>
#include <string_view>

using namespace std::string_literals;

inline std::string greet(std::string_view n) { return "Hello, "s + std::string(n) + " how are you doing today?"s; }
