cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(ft_printf)

#file(GLOB SOURCES "src/*.c")

#TODO change makefile, laggyy when make

# find src -type f -name '*.c' | sed "s/^/        /"
set(SOURCES
        src/flags/f/f_after_dot.c
        src/flags/f/f_special.c
        src/flags/f/flags_f.c
        src/flags/f/good_way_after.c
        src/flags/f/good_way_before.c
        src/flags/f/width_format.c
        src/flags/flags_c.c
        src/flags/flags_di.c
        src/flags/flags_o.c
        src/flags/flags_p.c
        src/flags/flags_perc.c
        src/flags/flags_s.c
        src/flags/flags_u.c
        src/flags/flags_x.c
        src/ft_printf.c
        src/strf/ft_strf.c
        src/main/main.c
        src/parse_flags.c
        src/resolve_arg.c
        )

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/libft/include
        )

add_subdirectory(libft)
target_link_libraries(${PROJECT_NAME} ft)

