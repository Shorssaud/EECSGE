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

# set default modules to build
eecsge_set_option(EECSGE_BUILD_PHYSICS TRUE BOOL "TRUE to build EECSGE's Physics module. This setting is ignored, if the graphics module is built.")
eecsge_set_option(EECSGE_BUILD_GRAPHICS TRUE BOOL "TRUE to build EECSGE's Graphics module.")
eecsge_set_option(EECSGE_BUILD_AUDIO TRUE BOOL "TRUE to build EECSGE's Audio module.")

if(EECSGE_BUILD_GRAPHICS AND NOT EECSGE_BUILD_PHYSICS)
    message(WARNING "You're trying to build EECSGE's PHYSICS module without the Graphics module. Forcing building of the Graphics module as a dependency.")
    set(EECSGE_BUILD_PHYSICS TRUE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)

set(SFML_BUILD_NETWORK FALSE)

add_subdirectory(EECSGE)

#--------
IF(test AND test STREQUAL "on")
    add_subdirectory(tests)
ENDIF()