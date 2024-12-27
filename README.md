## 说明
这是一个简单的C++ Module入门教程，包含：环境搭建和语法介绍等内容。
## 运行环境：
### docker
1. 启动并执行容器
```shell
docker run -it myoj2/clang-cxx-module-workshop /bin/bash
su workshop
cd ~
```
如随后需要使用ssh登录：（ssh账户和密码均为`workshop`）
```shell
docker run -p 50000:22 --restart=always -it myoj2/clang-cxx-module-workshop sh -c "/usr/sbin/sshd ; bash"
ssh workshop@localhost -p 50000 
```

代码位于`~/workshop`路径（`/home/workshop/workshop`)

### 手动安装
以ubuntu 24.04环境为例：
1. 安装wget，xz，cmake
2. 在某个文件夹保存下面脚本，执行以编译clang
```shell
#!/bin/bash

VERSION=18.1.0-rc1

components=(
    "bolt"
    "clang"
    "clang-tools-extra"
    "cmake"
    "compiler-rt"
    "flang"
    "libclc"
    "libcxx"
    "libcxxabi"
    "libunwind"
    "lld"
    "lldb"
    "llvm"
    "mlir"
    "openmp"
    "polly"
    "runtimes"
    "test-suite"
    "third-party"
)

declare -A URLS
declare -A SRC_ROOTS
declare -A DIRS

for component in "${components[@]}"; do
    URLS[$component]="https://github.com/llvm/llvm-project/releases/download/llvmorg-${VERSION}/${component}-${VERSION/-/}.src.tar.xz"
    SRC_ROOTS[$component]="${component}-${VERSION/-/}.src"
    DIRS[$component]="${component}"
done

for component in "${components[@]}"; do
    if [ -d ${SRC_ROOTS[$component]} ]; then
        rm -rf ${SRC_ROOTS[$component]}
    fi
    if [ -d ${DIRS[$component]} ]; then
        rm -rf ${DIRS[$component]}
    fi
done

if [ -d "build" ]; then
    rm -rf build
fi

for component in "${components[@]}"; do
    if [ ! -f ${SRC_ROOTS[$component]}.tar.xz ]; then
        echo "Downloading ${SRC_ROOTS[$component]}.tar.xz"
        wget -O ${SRC_ROOTS[$component]}.tar.xz ${URLS[$component]}
    else
        echo "Found ${SRC_ROOTS[$component]}.tar.xz"
    fi
done

for component in "${components[@]}"; do
    echo "Extracting ${SRC_ROOTS[$component]}.tar.xz"
    tar xf ${SRC_ROOTS[$component]}.tar.xz
    mv ${SRC_ROOTS[$component]} ${DIRS[$component]}
done

mv clang llvm/tools/clang
mv clang-tools-extra llvm/tools/clang/tools/extra
mv lld llvm/tools/lld
mv lldb llvm/tools/lldb
cp cmake/Modules/* llvm/cmake/modules/

mkdir build

cmake -S llvm \
    -B build \
    -G "Unix Makefiles" \
    -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_ENABLE_RUNTIMES="all" \
    -DLLVM_INCLUDE_TESTS=OFF \
    -DLLVM_INCLUDE_BENCHMARKS=OFF \
    -DLIBCXX_INCLUDE_BENCHMARKS=OFF \
    -DLIBCXX_INSTALL_MODULES=ON
cmake --build build -- -j
```
3. 安装clang
```
cd build
make install -j
```
4. 安装gcc
5. 安装xmake
6. 克隆教程代码
