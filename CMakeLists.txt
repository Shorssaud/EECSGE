cmake_minimum_required(VERSION 3.0.0)
project(eecsge VERSION 0.1.0)

include(CTest)
enable_testing()

# macro to facilitate setting options
macro(eecsge_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# set default build type to release
eecsge_set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build SFML as shared libraries, FALSE to build it as static libraries")

# set default modules to build
eecsge_set_option(EECSGE_BUILD_PHYSICS TRUE BOOL "TRUE to build EECSGE's Physics module. This setting is ignored, if the graphics module is built.")
eecsge_set_option(EECSGE_BUILD_GRAPHICS TRUE BOOL "TRUE to build EECSGE's Graphics module.")
eecsge_set_option(EECSGE_BUILD_AUDIO TRUE BOOL "TRUE to build EECSGE's Audio module.")
eecsge_set_option(EECSGE_BUILD_NETWORK FALSE BOOL "TRUE to build EECSGE's Network module.")

if(EECSGE_BUILD_GRAPHICS AND NOT EECSGE_BUILD_WINDOW)
    message(WARNING "You're trying to build EECSGE's PHYSICS module without the Graphics module. Forcing building of the Graphics module as a dependency.")
    set(EECSGE_BUILD_PHYSICS TRUE)
endif()

set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)
FetchContent_Declare(GTEST
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.13.x)
FetchContent_MakeAvailable(GTEST)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SRC_BASE
    src/core/src/ComponentManager.cpp
    src/core/src/Coordinator.cpp
    src/core/src/EntityManager.cpp
    src/core/src/SystemManager.cpp
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

set(SRCS
    EECSGE/core/include/ComponentManager.hpp
    EECSGE/core/include/Coordinator.hpp
    EECSGE/core/include/EntityManager.hpp
    EECSGE/core/include/Event.hpp
    EECSGE/core/include/EventManager.hpp
    EECSGE/core/include/IComponentArray.hpp
    EECSGE/core/include/System.hpp
    EECSGE/core/include/SystemManager.hpp
    EECSGE/core/include/Types.hpp
)

set(SYSTEMS
    EECSGE/systems/src/animation.cpp
    EECSGE/systems/src/draw.cpp
    EECSGE/systems/src/sound.cpp
)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)

add_library(eecsge STATIC ${SRCS} ${SYSTEMS} ${EVENTS})

set_target_properties(sfml-audio PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

target_link_libraries(eecsge sfml-audio sfml-graphics sfml-system sfml-window gtest gtest_main)

target_include_directories(eecsge PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
#--------
IF(test AND test STREQUAL "on")
    add_subdirectory(tests)
ENDIF()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
