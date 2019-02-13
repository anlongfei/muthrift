1.cmake version
cmake_minimum_required(VERSION 2.8)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT(muthrift_test)

set(CMAKE_C_CFLAGS "-Wall")
# set(CMAKE_CXX_FLAGS "-save-temps -Ofast -g -w -pthread -fpermissive -Wl,--export-dynamic -Wno-deprecated -lmuduo_base")
set(CMAKE_CXX_FLAGS "-Ofast -g -w -pthread -fpermissive -Wl,--export-dynamic -Wno-deprecated -lmuduo_base")
#g++ -g -w -Ofast -pthread test_thread.cpp    -lmuduo_net -lmuduo_base


add_definitions(
    -DMUDUO_STD_STRING
    -DHAVE_NETINET_IN_H
    -DMUDUO_LOG
    )

#3.head file path，头文件目录
INCLUDE_DIRECTORIES(
    "${PROJECT_SOURCE_DIR}/deps/muduo/include"
    )

#4.source directory，源文件目录
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/ut DIR_UT)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
SET(TEST_MATH
    ${DIR_SRCS}
    ${DIR_UT}
    )

#6.add executable file，添加要编译的可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${TEST_MATH})

#7.add link library，添加可执行文件所需要的库，比如我们用到了libm.so（命名规则：lib+name+.so），就添加该库的名称
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    thrift
    boost_date_time
    boost_filesystem
    boost_thread
    -lmuduo_base
    -lmuduo_http
    -lmuduo_net
    -pthread
    m
    z
    )
