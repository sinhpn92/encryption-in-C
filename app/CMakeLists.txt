
cmake_minimum_required(VERSION 3.4.1)

set(MD5SOURCES
    src/main/cpp/md5.c)


add_library(native-lib
             SHARED
             src/main/cpp/native-lib.cpp
              ${MD5SOURCES})


find_library(log-lib
              log )

target_link_libraries(native-lib
                       ${log-lib} )
