module;
export module my_lib.foo; // 请改为声明my_lib:foo模块
// 我们可以使用语法 import :bar; 来导入同属于my_lib下的另外一个partition
import my_lib.bar; 

export namespace my_lib {
    class foo {
        bar b;
    };
}