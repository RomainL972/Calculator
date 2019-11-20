cmake_minimum_required(VERSION 3.10)

# set the project name
project(Calculator VERSION 0.1.0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -ansi -pedantic -O0 -g -Werror")

# add the executable
add_executable(Calculator main.c args.c string.c parse_stdin.c expression.c element.c calculate.c timesdiv.c addsub.c string_struct.c element_utils.c)
