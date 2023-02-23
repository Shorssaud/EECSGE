cmake_minimum_required(VERSION 3.0.0)
project(eecsge-core VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC
    src/ComponentManager.hpp
    src/Coordinator.hpp
    src/EntityManager.hpp
    src/Event.hpp
    src/EventManager.hpp
    src/IComponentArray.hpp
    src/System.hpp
    src/SystemManager.hpp
    src/Types.hpp

    dummy.cpp
)

add_library(eecsge-core STATIC ${SRC})

target_include_directories(eecsge-core PUBLIC include)