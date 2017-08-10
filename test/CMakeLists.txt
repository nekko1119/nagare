project(nagare_test)

enable_testing()

include_directories(../Catch/include)

add_executable(
    nagare_test
    nagare_test.cpp
    nagare_add_test.cpp
)