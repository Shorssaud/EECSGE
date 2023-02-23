add_subdirectory(Core)

if (EECSGE_BUILD_GRAPHICS)
    add_subdirectory(Graphics)
endif()

if (EECSGE_BUILD_PHYSICS)
    add_subdirectory(Physics)
endif()

if (EECSGE_BUILD_AUDIO)
    set(SFML_BUILD_AUDIO TRUE)
    set_target_properties(sfml-audio PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
    add_subdirectory(Audio)
endif()