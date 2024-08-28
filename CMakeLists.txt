cmake_minimum_required(VERSION 3.26)
project(workshop)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.28)
    cmake_policy(SET CMP0155 NEW)
elseif(CMAKE_VERSION VERSION_GREATER_EQUAL 3.27)
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")
elseif(CMAKE_VERSION VERSION_GREATER_EQUAL 3.26)
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMake_TEST_CXXModules_UUID "a246741c-d067-4019-a8fb-3d16b0c9d1d3")
        set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

        set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "clang")
        set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "@<MODULE_MAP_FILE>")

        # Default to C++ extensions being off. Clang's modules support have trouble
        # with extensions right now.
        set(CMAKE_CXX_EXTENSIONS OFF)
    endif()
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
    endif()
endif()
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "16.0.0")
        string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
        "\"${CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS}\""
        " -format=p1689"
        " --"
        " <CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS>"
        " -x c++ <SOURCE> -c -o <OBJECT>"
        " -MT <DYNDEP_FILE>"
        " -MD -MF <DEP_FILE>"
        # Write to a temporary file. If the scan fails, we do not want to update
        # the actual output file as `ninja` (at least) assumes that failed
        # commands either delete or leave output files alone. See Issue#25419.
        " > <DYNDEP_FILE>.tmp"
        # We cannot use `copy_if_different` as the rule does not have a feature
        # analogous to `ninja`'s `restat = 1`. It would also leave behind the
        # `.tmp` file.
        " && mv <DYNDEP_FILE>.tmp <DYNDEP_FILE>")
        set(CMAKE_CXX_MODULE_MAP_FORMAT "clang")
        set(CMAKE_CXX_MODULE_MAP_FLAG "@<MODULE_MAP_FILE>")
        set(CMAKE_CXX_MODULE_BMI_ONLY_FLAG "--precompile")
    endif()
endif()

add_executable(stdmodule "/home/user/workshop/work2/2.cpp")

target_sources(stdmodule
    PUBLIC
    FILE_SET CXX_MODULES FILES "others/stdmodule/std.mock.cppm"
)