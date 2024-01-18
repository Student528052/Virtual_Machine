#Basic initalization
cmake_minimum_required(VERSION 3.21)
project(Virtual_Machine VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
add_executable(V_machine)
set(base_target V_machine)

##TODO: change this so that it doesn't use global recursion for source files(bad practice)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

target_sources(${base_target} PRIVATE ${SOURCE_FILES})
target_include_directories(${base_target} PRIVATE ./include/)
set_target_properties(${base_target} PROPERTIES CXX_EXTENSIONS OFF)

# Set options for gnu-like
target_compile_options(${base_target} PRIVATE
        # set warnings for all build types
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic -Werror -fno-omit-frame-pointer>
        # debug optimisation in Debug
        $<$<AND:$<CXX_COMPILER_ID:GNU,Clang,AppleClang>,$<CONFIG:Release>>:-O3>
        # O3 optimisation Release
        $<$<AND:$<CXX_COMPILER_ID:GNU,Clang,AppleClang>,$<CONFIG:Debug>>:-Og -g>
        )

# Set options for MSVC
target_compile_options(${base_target} PRIVATE
        # set warnings for all build types
        $<$<CXX_COMPILER_ID:MSVC>:/Wall>
        # debug optimisation in Debug
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Release>>:/O2>
        # O3 optimisation in Release
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug>>:/RTC1 /Od /Zi>
        )

#add subdirectory for Gtest
#add_subdirectory(tests)
