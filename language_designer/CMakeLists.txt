find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/lib_language)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(language_designer main.cpp)

target_link_libraries (language_designer lib_language)
target_link_libraries (language_designer Qt5::Core)
target_link_libraries (language_designer Qt5::Gui)
target_link_libraries (language_designer Qt5::Widgets)