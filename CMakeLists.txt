cmake_minimum_required(VERSION 3.2)
project(text_quest)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(text_quest main.cpp func.cpp)

target_link_libraries(text_quest sfml-graphics sfml-audio)

add_executable(quest_test test.cpp func.cpp)

target_link_libraries(quest_test sfml-graphics sfml-audio)

enable_testing()
add_test(text_quest text_quest)

