add_definitions("-std=c++11")

file(GLOB_RECURSE SOURCES *.h *.cpp ../*.cpp)

add_executable(${BINARY} ${SOURCES})
