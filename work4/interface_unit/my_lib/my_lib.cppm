module;
export module my_lib;


// 我们可以通过export import xxx;的写法，将一个模块作为本模块的一部分导出
// 例如，下面这行代码将std模块包含在本模块中，作为my_lib的一部分并暴露给用户使用
export import std;
// 请参考上面的代码，将模块my_lib.foo和my_lib.bar包含在my_lib中并导出给用户