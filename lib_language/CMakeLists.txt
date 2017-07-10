find_package(Qt5Core REQUIRED)

add_executable(lib_language main.cpp)
target_link_libraries(lib_language Qt5::Core)