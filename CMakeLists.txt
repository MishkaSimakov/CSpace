cmake_minimum_required(VERSION 3.17)
project(FirstTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(FirstTest src/main.cpp src/classes/Body.cpp src/classes/Body.h src/classes/Player.cpp src/classes/Player.h src/constants.h src/Models.hpp)

include_directories(C:/SFML/include)

set(SFML_ROOT C:/SFML/)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(FirstTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# Copy dlls to build
if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()