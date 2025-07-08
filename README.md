# Minimal SDL3 Project

This is a minimal template for a C project using SDL3.
It uses CMake to automatically download and build SDl3 as a dependency. 

`main.c` creates a simple window with a background color that cycles smoothly through different hues.

***
## Dependencies

-   A C compiler 
-   CMake 
-   Git 

***

## Building

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/dmitrikaramazov/minimal_sdl3.git
    cd minimal_sdl3
    ```

2.  **Configure the project with CMake:**
    This will create a `build` directory and download dependencies.
    ```bash
    cmake -B build
    ```

3.  **Compile the code:**
    ```bash
    cmake --build build
    ```

4.  **Run the executable:**
    The compiled program will be located in the `build/bin` directory.
    ```bash
    ./build/bin/Minimal_SDL3.exe
    ```