cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(ft_printf)

#file(GLOB SOURCES "src/*.c")

#TODO change makefile, laggyy when make

# find src -type f -name '*.c' | sed "s/^/        /"
set(SOURCES
        src/strf/ft_printf.c
        src/strf/ft_printf_resolve.c
        src/strf/ft_strf.c
        src/strf/ft_strf_adjust.c
        src/strf/ft_strf_adjust_dioux.c
        src/strf/ft_strf_adjust_pfsc.c
        src/strf/ft_strf_format.c
        src/strf/ft_strf_resolve.c
        src/strf/ft_strf_parse.c
        src/strf/ft_strf_flag_cast.c
        src/strf/float/ft_strf_flag_f.c
        src/strf/float/ft_strf_flag_f_str.c
        src/strf/float/ft_strf_flag_f_special.c
        src/strf/ft_strf_flag_c.c
        src/strf/ft_strf_flag_s.c
        src/strf/ft_strf_flag_di.c
        src/strf/ft_strf_flag_p.c
        src/strf/ft_strf_flag_o.c
        src/strf/ft_strf_flag_u.c
        src/strf/ft_strf_flag_x.c
        src/strf/ft_strf_flag_perc.c
        )

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/includes
        )

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/libft/includes
        )

add_subdirectory(libft)
target_link_libraries(${PROJECT_NAME} ft)

