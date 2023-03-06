cmake_minimum_required(VERSION 3.0.0)
project(eecsge-graphics VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC
    systems/src/draw.cpp
    systems/src/animation.cpp
)

set(HEADERS
    components/drawable.hpp

    systems/include/draw.hpp
    systems/include/animation.hpp
)

add_library(eecsge-graphics STATIC ${SRC} ${HEADERS})
target_link_libraries(eecsge-graphics eecsge-core eecsge-physics sfml-graphics sfml-system)
target_include_directories(eecsge-graphics PUBLIC include)