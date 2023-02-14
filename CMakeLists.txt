cmake_minimum_required(VERSION 3.0.0)
project(eecsge VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(.)

file(GLOB COMPONENTS_SRC EECSGE/components/*.hpp)
file(GLOB CORE_SRC EECSGE/core/include/*.hpp EECSGE/core/src/*.cpp)
file(GLOB SYSTEM_SRC EECSGE/system/include/*.hpp EECSGE/system/src/*.cpp)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)
FetchContent_Declare(GTEST
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.13.x)
FetchContent_MakeAvailable(GTEST)

add_library(eecsge ${COMPONENTS_SRC} ${CORE_SRC} ${SYSTEM_SRC})

target_link_libraries(eecsge sfml-audio sfml-graphics sfml-system sfml-window gtest gtest_main)

target_include_directories(eecsge PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

IF(test AND test STREQUAL "on")
    message("Testing enabled")
    set(SOURCES_TEST
        ${PROJECT_SOURCE_DIR}/src/systems/player_system.cpp
        ${PROJECT_SOURCE_DIR}/tests/test_InputEngine.cpp
        )

    file(GLOB TEST_SRC_FILES ${SOURCES_TEST})

    enable_testing()
    
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)

    add_executable(runUnitTests ${TEST_SRC_FILES})
    
    target_link_libraries(runUnitTests gtest gtest_main sfml-audio sfml-graphics sfml-system sfml-window eecsge)

    add_test(UnitTests runUnitTests)

ENDIF()

#--------

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
