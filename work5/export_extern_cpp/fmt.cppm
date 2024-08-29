module;
import std;

#include<climits>
#include<cerrno>
#include<cstdio>
export module fmt;
//在这里我们定义了宏FMT_MODULE, fmtlib内部检测到这个宏的时候，不会包含其他头文件。
#define FMT_MODULE
export extern "C++" {
// 请在这里添加我们用到的fmt的头文件。我们用到了那些头文件可以参考main.cpp的注释
// #include<fmt/...>
}