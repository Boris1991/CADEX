cmake_minimum_required(VERSION 3.22)
project(cadex)

set(CMAKE_CXX_STANDARD 17)

#target_include_directories(cadexlib PUBLIC include)

# Create an executable using the SO library
add_executable(cadex main.cpp src/Curves.cpp 
    src/Circles.cpp 
    src/Elipses.cpp 
    src/Helixes3D.cpp 
    src/Point3D.cpp 
    src/Vector3D.cpp
    include/Curves.h 
    include/Circles.h 
    include/Elipses.h 
    include/Helixes3D.h 
    include/Point3D.h 
    include/Vector3D.h)
#target_link_libraries(cadex PRIVATE cadexlib)

target_include_directories(cadex PUBLIC include src)
		
add_test(test cadex)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak -fsanitize=undefined ")
