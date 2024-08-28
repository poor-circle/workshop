import std;
import my_lib;
int main() {
    my_lib::foo f;
    std::cout<<f.say()<<"\n";
    std::cout<<my_lib::create_bar().speak()<<"\n";
    return 0;
}