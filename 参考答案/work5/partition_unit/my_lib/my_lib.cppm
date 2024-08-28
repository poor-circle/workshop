module;
export module my_lib;
export import :foo;
export import :bar;
// 我们可以使用语法export import :bar; 来导入同属于my_lib下的另外一个partition, 并导出给用户使用
// export import :xxx;