cmake_minimum_required(VERSION 3.12)
project(libjstudio)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( GLM_TEST_ENABLE      OFF CACHE INTERNAL "" )
set( BUILD_SHARED_LIBS    OFF CACHE INTERNAL "" )
set( BUILD_STATIC_LIBS    OFF CACHE INTERNAL "" )

add_compile_definitions(-DGLM_ENABLE_EXPERIMENTAL)

add_subdirectory(lib/glm)

file(GLOB_RECURSE LIBJSTUDIO_SRC
    # libjstudio
	"include/*.h"
	"include/*.hpp"
    "src/*.cpp"
	
    # bStream
    "lib/bStream/*.cpp"
    
    # glad
    "lib/glad/src/*.c"
)

add_library(libjstudio ${LIBJSTUDIO_SRC})

target_include_directories(libjstudio PUBLIC include lib/bStream lib/glad/include)
target_link_libraries(libjstudio PUBLIC glm)
