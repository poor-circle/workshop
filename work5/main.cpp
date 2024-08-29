import std;
// #include<fmt/core.h>
// #include<fmt/ranges.h>
import fmt;
int main() {
    std::string hello = fmt::format("hello world {}!\n", 2024);
    std::vector<std::string> names{"Oliver","Betty","Alice","Bob2", hello};
    fmt::print("{}\n",fmt::join(names,", "));
}