cmake_minimum_required(VERSION 3.4.1)

# 编译library
add_library( # 设置library名称
             nativelib

             # 设置library模式
             # SHARED模式会编译so文件，STATIC模式不会编译
             SHARED

             # 设置原生代码路径
             src/main/jni/native-lib.cpp )
#设置生成的so动态库最后输出的路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})
# 定位library
find_library( # library名称
              log-lib

              # 将library路径存储为一个变量，可以在其他地方用这个变量引用NDK库
              # 在这里设置变量名称
              log )

# 关联library
target_link_libraries( # 关联的library
                       nativelib

                       # 关联native-lib和log-lib
                       ${log-lib} )