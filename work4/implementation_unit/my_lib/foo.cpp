// 在这里，我们声明了一个模块my_lib但不添加export关键字，代表这是一个implementation unit，用于实现模块内的声明
module my_lib;
// 导入标准库
import std;
// 和传统的头文件不同，我们不需要在代码中import my_lib; 由于它们都在同一个module my_lib中，因此这里会自动导入foo的声明。
namespace my_lib {
    std::string foo::say() {
        return "Hello!";
    }
}