cmake_minimum_required(VERSION 3.26)
project(Minimal_SDL3 C)

include(FetchContent)


set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(MYGAME_VENDORED "Use vendored libraries" ON)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.2.16
)
FetchContent_MakeAvailable(SDL3)

# WIN32 causes it to create a GUI program
add_executable(${PROJECT_NAME} WIN32 main.c)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# disable exploit protections
add_compile_options(-fno-stack-protector)
add_link_options(-Wl,--dynamicbase,no -Wl,--nxcompat,no)

target_sources(${PROJECT_NAME}
PRIVATE
    main.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)