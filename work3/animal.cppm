module;
// global module fragment
// 请在这里添加需要包含的头文件
// #include <xxx>


// 此处声明了一个模块animal, 并将这个模块导出给用户使用
export module animal;


// import xxx;
// 请在这里引入其他模块，比如标准库模块std
// import std;

// 接下来是各个函数和类的实现：
// 请确定main.cpp中使用到了哪些函数，然后在这些声明的前面加上export关键字：
// 例如：
// export void hello(){}
// export struct hi{};
// export namespace my_lib{}
// export int i=0;
// 请尽可能的只导出被直接用到的接口！
namespace life {
    struct animal {
        virtual std::string say() const {
            assert("failed!");
            return "Error!";
        }
    };
    struct dog : public animal {
        virtual std::string say() const {
            return "Woof!";
        }
    };
    struct cat : public animal {
        virtual std::string say() const {
            return "Meow!";
        }
    };
    namespace detail {
        enum class animal_type {
            dog,
            cat,
            unknown
        };
        std::unique_ptr<animal> animal_factory(animal_type type) {
            if (type==animal_type::dog) {
                return std::make_unique<dog>();
            }
            else if (type==animal_type::cat) {
                return std::make_unique<cat>();
            }
            else {
                return std::make_unique<animal>();
            }
        }
    }
}

std::vector<std::unique_ptr<life::animal>> create_animals() {
    using namespace life::detail;
    std::vector<std::unique_ptr<life::animal>> result;
    for (auto &type :{animal_type::dog,animal_type::cat,animal_type::dog}) {
        result.push_back(animal_factory(type));
    }
    return result;
}

std::string animal_say(const life::animal& animal) {
    return "It say: " + animal.say() + '\n';
}

