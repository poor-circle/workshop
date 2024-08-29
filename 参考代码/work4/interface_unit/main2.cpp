// 请尝试：只导入模块my_lib.foo，不要导入my_lib.bar
// import xxx;
import std;
import my_lib.foo;
int main() {
    std::cout<<my_lib::foo()<<std::endl;
}