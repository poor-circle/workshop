// 2.cpp
// 任务：请在下一行，通过import std;语句导入标准库,告别头文件！
import std;
int main() {
  // 在此处打印"Hello world Module!";
  std::cout<<"Hello world Module!"<<std::endl;
  // 按随机顺序打印0-9
  std::vector<int> vec;
  for (int i=0;i<10;++i) {
    vec.push_back(i);
  }
  std::default_random_engine engine(std::time(nullptr));
  std::shuffle(vec.begin(),vec.end(), engine);
  for (auto &e:vec) {
    std::cout<<e<<" ";
  }
  std::cout<<"\n";
}
