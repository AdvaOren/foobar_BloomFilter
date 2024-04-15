cmake_minimum_required(VERSION 3.18)
project(foobar_DT)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
find_package(Threads REQUIRED)

add_executable(project_main
        AddCommand.cpp
        AddCommand.h
        App.cpp
        App.h
        BloomFilter.cpp
        BloomFilter.h
        CheckCommand.cpp
        CheckCommand.h
        DoubleHash.cpp
        DoubleHash.h
        Factory.cpp
        Factory.h
        ICommand.h
        IHash.h
        IMenu.h
        InputHandler.cpp
        InputHandler.h
        main.cpp
        Menu.cpp
        Menu.h
        SingleHash.cpp
        SingleHash.h
        Server.cpp
        Server.h
        ServerClientHandler.cpp
        ServerClientHandler.h)

target_link_libraries(project_main PRIVATE Threads::Threads)