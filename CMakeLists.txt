cmake_minimum_required(VERSION 3.1.0)
project(Spegetti_Demo)

set(SOURCES
"Spegetti_Demo/Sources/main.cpp"
"Spegetti_Demo/Spegetti API.h"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

target_link_libraries(${PROJECT_NAME} PUBLIC user32)

target_include_directories(${PROJECT_NAME} PUBLIC "Spegetti_Demo")
