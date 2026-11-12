
cmake_minimum_required(VERSION 3.20)

project(lvgl_linux_monitor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_SOURCE_DIR}/bin
)

# --------------------------------------------------
# Existing project dependencies
# --------------------------------------------------

find_package(PkgConfig REQUIRED)
find_package(PNG REQUIRED)

# --------------------------------------------------
# LVGL
# --------------------------------------------------

pkg_check_modules(LVGL REQUIRED IMPORTED_TARGET GLOBAL lvgl)

# Get LVGL's complete static dependency list.
execute_process(
        COMMAND pkg-config --static --libs lvgl
        OUTPUT_VARIABLE LVGL_STATIC_LIBRARIES
        OUTPUT_STRIP_TRAILING_WHITESPACE
        COMMAND_ERROR_IS_FATAL ANY
)

# Convert the dependency string into a CMake list.
separate_arguments(
        LVGL_STATIC_LIBRARIES
        UNIX_COMMAND
        "${LVGL_STATIC_LIBRARIES}"
)
# Application executable
add_executable(
        lvgl_linux_monitor
        src/main.cpp
        include/ui/IScreen.h
        include/runtime/LvglRunTime.h
        src/runtime/LvglRunTime.cpp
        include/ui/UIManager.h
        src/ui/UIManager.cpp
        include/ui/screens/CoordinateScreen.h
        src/ui/screens/CoordinateScreen.cpp
)

target_include_directories(
        lvgl_linux_monitor
        PRIVATE
        include
        ${PostgreSQL_INCLUDE_DIRS}
)

# --------------------------------------------------
# Linking
# --------------------------------------------------

target_link_libraries(
        lvgl_linux_monitor
        PRIVATE

        # LVGL and its static dependencies
        ${LVGL_STATIC_LIBRARIES}

        # PNG decoder dependency
        PNG::PNG
)