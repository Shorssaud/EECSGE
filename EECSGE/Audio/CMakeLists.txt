cmake_minimum_required(VERSION 3.0.0)
project(eecsge-audio VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC
    systems/src/sound.cpp
)

set(HEADERS
    components/sound.hpp

    systems/include/sound.hpp
)

add_library(eecsge-audio STATIC ${SRC} ${HEADERS})
target_link_libraries(eecsge-audio eecsge-core sfml-audio)
target_include_directories(eecsge-audio PUBLIC include)