// 引入模块my_lib，相当于引入了std模块，my_lib.foo模块和my_lib.bar模块
import my_lib;
int main() {
    std::cout<<my_lib::foo()<<std::endl;
    std::cout<<my_lib::bar()<<std::endl;
}