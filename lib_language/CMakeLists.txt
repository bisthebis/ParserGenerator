find_package(Qt5Core REQUIRED)

add_executable(lib_language
    main.cpp
    regex.cpp regex.h
    tokentype.cpp tokentype.h
    charset.cpp charset.h
    )

target_link_libraries(lib_language Qt5::Core)
