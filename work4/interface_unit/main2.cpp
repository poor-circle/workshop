// 请尝试：导入模块my_lib.foo，而不导入my_lib.bar
// import xxx;
int main() {
    std::cout<<my_lib::foo()<<std::endl;
    // 下面这行代码应该报错
    // std::cout<<my_lib::bar()<<std::endl; 
}