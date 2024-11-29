set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.22.1)
# cmake_minimum_required(VERSION 3.21)
project(PhysicsSim)

find_package(SFML 2.5 REQUIRED graphics window system)

file(GLOB SOURCES "src/*.cpp" "src/**/*.cpp" "src/*.h" "src/**/*.h" "src/*.hpp" "src/**/*.hpp")
# list(FILTER SOURCES EXCLUDE REGEX "../src/custom/.*\\.cpp")

add_definitions(-DLOCAL)
add_executable(PhysicsSim ${SOURCES})

target_include_directories(PhysicsSim PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(PhysicsSim sfml-graphics sfml-window sfml-system)


