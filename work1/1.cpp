// work1.cpp
// 请阅读代码，添加缺少的头文件
int main() {
  // 在此处打印"GoodBye Head File!";
  std::cout<<"GoodBye Head File!"<<std::endl;
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
  return 0;
}