cmake_minimum_required(VERSION 3.0.0)
project(eecsge VERSION 0.1.0)

include(CTest)
enable_testing()

set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SRCS
    src/core/src/ComponentManager.cpp
    src/core/src/Coordinator.cpp
    src/core/src/EntityManager.cpp
    src/core/src/SystemManager.cpp
)

set(SYSTEMS
    src/systems/src/animation.cpp
    src/systems/src/background.cpp
    src/systems/src/collision.cpp
    src/systems/src/death.cpp
    src/systems/src/drawable.cpp
    src/systems/src/movement.cpp
    src/systems/src/player.cpp
    src/systems/src/sound.cpp
)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)
FetchContent_Declare(GTEST
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.13.x)
FetchContent_MakeAvailable(GTEST)

add_library(eecsge SHARED ${SRCS} ${SYSTEMS} )

target_link_libraries(eecsge sfml-audio sfml-graphics sfml-system sfml-window gtest gtest_main)


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
    
    target_link_libraries(runUnitTests gtest gtest_main sfml-audio sfml-graphics sfml-system sfml-window)

    add_test(UnitTests runUnitTests)

ENDIF()

#--------

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
