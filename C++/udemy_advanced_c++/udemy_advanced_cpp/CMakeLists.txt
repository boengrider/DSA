cmake_minimum_required(VERSION 3.16)

project(udemy_advanced_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(udemy_advanced_cpp main.cpp
    myexception.h myexception.cpp
)

include(GNUInstallDirs)
install(TARGETS udemy_advanced_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
