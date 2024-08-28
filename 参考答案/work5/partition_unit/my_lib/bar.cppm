module;
export module my_lib:bar; // 请改为声明my_lib:bar模块
export namespace my_lib {
    class foo;
    class bar {
    public:
        foo* b;
    };
}