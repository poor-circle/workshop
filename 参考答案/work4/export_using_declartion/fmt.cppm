module;
#include<fmt/core.h>
#include<fmt/ranges.h>
export module fmt;
namespace fmt {
    // 请确定我们使用了哪些fmt的声明，然后通过export using xxx;的写法，将这些声明导出给用户使用
    export using fmt::print;
    // 请继续将其他声明导出给用户使用
    // export using .....
    export using fmt::join;
    export using fmt::format;
}