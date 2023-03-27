# CMakeList.txt : CMake project for MyTetrisProject, include source and define
# project specific logic here.
#

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_PROJECT_DIR}/Bin/$<CONFIG>) 

file(GLOB_RECURSE SOURCES
"Src/*.cpp"
"Src/*.h"
)

# Add source to this project's executable.
add_executable (MyTetrisProject ${SOURCES} "Src/Core/Renderer.h")

add_subdirectory(Lib/SDL2-2.26.4)

target_include_directories(${PROJECT_NAME} PUBLIC Lib/SDL2-2.26.4/include)
target_link_libraries(${PROJECT_NAME} SDL2)