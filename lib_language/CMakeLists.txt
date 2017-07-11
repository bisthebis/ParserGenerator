find_package(Qt5Core REQUIRED)

add_library(lib_language
    regex.cpp regex.h
    tokentype.cpp tokentype.h
    charset.cpp charset.h
    language.cpp language.h
    )

target_link_libraries(lib_language Qt5::Core)
