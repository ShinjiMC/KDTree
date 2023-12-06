cmake_minimum_required(VERSION 3.10)
project(KDTree)
set(CMAKE_CXX_STANDARD 14)
enable_testing()
## List of options:
option(BUILD_EXAMPLE "Builds the example" OFF)
option(SILENCE_DEBUG_OUTPUT "Silence debugs" OFF)
# Include directories for header files
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/kdtree")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/reader")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/point")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/tester")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Components/googleTest/include")

# List source files for KDtree
file(GLOB_RECURSE KDTREE_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/kdtree/*.cpp")
file(GLOB_RECURSE KDTREE_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/kdtree/*.hpp")

# List source files for Reader
file(GLOB_RECURSE READER_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/reader/*.cpp")
file(GLOB_RECURSE READER_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/reader/*.hpp")

# List source files for Point
file(GLOB_RECURSE POINT_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/point/*.cpp")
file(GLOB_RECURSE POINT_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/point/*.hpp")

# List source files for Tester
file(GLOB_RECURSE TESTER_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Components/tester/*.cpp")

# Add Google Test libraries
add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/Components/googleTest/lib/libgtest.a" # Ruta a la biblioteca estática de Google Test
)

add_library(gmock STATIC IMPORTED)
set_target_properties(gmock PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/Components/googleTest/lib/libgmock.a" # Ruta a la biblioteca estática de Google Mock
)

# Create libraries for Kdtree, Reader, Point and Tester
add_library(KDtree ${KDTREE_SRC} ${KDTREE_HEADERS})
add_library(Reader ${READER_SRC} ${READER_HEADERS})
add_library(Point ${POINT_SRC} ${POINT_HEADERS})
add_library(Tester ${TESTER_SRC})

# Set compile definitions
if(SILENCE_DEBUG_OUTPUT)
    target_compile_definitions(KDtree PRIVATE "SILENCE_DEBUG")
    target_compile_definitions(Reader PRIVATE "SILENCE_DEBUG")
    target_compile_definitions(Point PRIVATE "SILENCE_DEBUG")
    target_compile_definitions(Tester PRIVATE "SILENCE_DEBUG")
endif()

# Link libraries as needed
if(BUILD_EXAMPLE)
    add_executable(example "${CMAKE_CURRENT_LIST_DIR}/main.cpp")
    target_link_libraries(example PRIVATE KDtree Reader Point Tester gtest gmock )
    set_target_properties(example PROPERTIES OUTPUT_NAME "program")
endif()