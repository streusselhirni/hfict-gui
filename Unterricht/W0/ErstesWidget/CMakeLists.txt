cmake_minimum_required(VERSION 3.13)
project(W0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC on)
set(CMALE_AUTOUIC on)
set(CMAKE_PREFIX_PATH ~/Applications/Qt5.12.0/5.12.0/clang_64/lib/cmake)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(SOURCE_FILES main.cpp Widget.cpp Widget.h)

add_executable(W0 ${SOURCE_FILES})
target_link_libraries(W0 Qt5::Widgets)