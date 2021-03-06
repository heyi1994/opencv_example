# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("opencv_example")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             opencv

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).

             lib_headers.h
             cv_pixel.h
             jni_interface.cpp
             jni_interface.h
             cv_pixel.cpp

             effects/composite/cv_composite.cpp
             effects/composite/cv_composite.h

             effects/contrast/cv_contrast.cpp
             effects/contrast/cv_contrast.h

             effects/blur/cv_blur.h
             effects/blur/cv_blur.cpp

             utils/utils.cpp
             utils/utils.h

             effects/swell/cv_swell.cpp
             effects/swell/cv_swell.h


             effects/open/cv_open.cpp
             effects/open/cv_open.h


             effects/vertical_lines/cv_vertical.cpp
             effects/vertical_lines/cv_vertical.h

        )

#导入头文件
include_directories(include)

#导入库文件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}")


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       opencv

                       #添加opencv_java3
                       opencv_java3

                       # bitmap
                       jnigraphics
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       )