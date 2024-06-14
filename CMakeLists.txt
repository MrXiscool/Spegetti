cmake_minimum_required(VERSION 3.1.0)
project(Spegetti_Demo)

set(SOURCES
"Spegetti_Demo/Sources/main.cpp"
"Spegetti_Demo/Spegetti.h"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "Spegetti_Demo")