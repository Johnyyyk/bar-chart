cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(BarChart LANGUAGES CXX VERSION 0.2.6)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_DEBUG_POSTFIX "d")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt5 REQUIRED COMPONENTS
    OpenGL
    Quick
    )

file(GLOB SRC "src/*.cpp")
file(GLOB HEADERS "includes/*.h")
file(GLOB RESOURCES "qml/*.qrc")

add_executable(${PROJECT_NAME} WIN32 ${SRC} ${HEADERS} ${RESOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/includes
    )

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Quick
    Qt5::OpenGL
    Qt5::Widgets
    )
