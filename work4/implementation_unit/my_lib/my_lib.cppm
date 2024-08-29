module;
export module my_lib;
import std;
export namespace my_lib {
    struct foo {
        std::string say();
    };
    struct bar {
        std::string speak();
    };
    bar& create_bar();
}