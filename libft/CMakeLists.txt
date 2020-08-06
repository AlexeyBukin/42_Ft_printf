cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(ft)

#file(GLOB SOURCES "src/*.c")

# find src     -type f -name '*.c' | sed 'N;N;s/\n/ /g' |  sed '$s/\\\\\\//' | column -t

#src/ft_free.c

set(${PROJECT_NAME}_SOURCES
        src/.arr/ft_arr_add.c         src/.arr/ft_arr_delete.c      src/.arr/ft_arr_dup.c
        src/.arr/ft_arr_free.c        src/.arr/ft_arr_join.c        src/.arr/ft_arr_new.c
        src/atoi_itoa/ft_atoi.c       src/atoi_itoa/ft_atoi_base.c  src/atoi_itoa/ft_itoa.c
        src/atoi_itoa/ft_itoa_base.c  src/atoi_itoa/ft_lltoa.c      src/atoi_itoa/ft_mtob.c
        src/atoi_itoa/ft_mtob_raw.c   src/atoi_itoa/ft_ulltoa.c     src/atoi_itoa/ft_utoa.c
        src/atoi_itoa/ft_utoa_base.c  src/ft_abs.c                  src/ft_bzero.c
        src/ft_char_to_str.c          src/ft_free_char_2d_arr.c     src/ft_pow.c
        src/ft_power_ten.c            src/ft_return.c               src/ft_tolower.c
        src/ft_toupper.c              src/ft_word_count.c           src/is/ft_isalnum.c
        src/is/ft_isalpha.c           src/is/ft_isascii.c           src/is/ft_isblank.c
        src/is/ft_isdigit.c           src/is/ft_isprint.c           src/lst/ft_lstadd.c
        src/lst/ft_lstappend.c        src/lst/ft_lstdel.c           src/lst/ft_lstdelone.c
        src/lst/ft_lstiter.c          src/lst/ft_lstmap.c           src/lst/ft_lstnew.c
        src/math/ft_abs.c             src/math/ft_pow.c             src/math/ft_power_ten.c
        src/math/ft_tolower.c         src/math/ft_toupper.c         src/mem/ft_bzero.c
        src/mem/ft_free.c             src/mem/ft_mem_rev.c          src/mem/ft_memalloc.c
        src/mem/ft_memccpy.c          src/mem/ft_memchr.c           src/mem/ft_memcmp.c
        src/mem/ft_memcpy.c           src/mem/ft_memdel.c           src/mem/ft_memdup.c
        src/mem/ft_memmove.c          src/mem/ft_memset.c           src/put/ft_putchar.c
        src/put/ft_putchar_fd.c       src/put/ft_putendl.c          src/put/ft_putendl_fd.c
        src/put/ft_putendl_free.c     src/put/ft_putendl_int_var.c  src/put/ft_puterror.c
        src/put/ft_putnbr.c           src/put/ft_putnbr_fd.c        src/put/ft_putstr.c
        src/put/ft_putstr_fd.c        src/put/ft_putstr_free.c      src/str/ft_str_arr_free.c
        src/str/ft_str_div_by.c       src/str/ft_str_div_by_ins.c   src/str/ft_str_dup_rev.c
        src/str/ft_str_from_char.c    src/str/ft_str_low.c          src/str/ft_str_spam.c
        src/str/ft_str_up.c           src/str/ft_str_word_count.c   src/str/ft_strcat.c
        src/str/ft_strcfnr.c          src/str/ft_strchr.c           src/str/ft_strclr.c
        src/str/ft_strcmp.c           src/str/ft_strcpy.c           src/str/ft_strdel.c
        src/str/ft_strdup.c           src/str/ft_strequ.c           src/str/ft_strfnr.c
        src/str/ft_striter.c          src/str/ft_striteri.c         src/str/ft_strjoin.c
        src/str/ft_strjoin_free.c     src/str/ft_strlcat.c          src/str/ft_strlen.c
        src/str/ft_strmap.c           src/str/ft_strmapi.c          src/str/ft_strncat.c
        src/str/ft_strncmp.c          src/str/ft_strncpy.c          src/str/ft_strnequ.c
        src/str/ft_strnew.c           src/str/ft_strnstr.c          src/str/ft_strrchr.c
        src/str/ft_strrev.c           src/str/ft_strsplit.c         src/str/ft_strstr.c
        src/str/ft_strsub.c           src/str/ft_strtrim.c          src/test/insert_func.c
        )

#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )
include_directories(${PROJECT_SOURCE_DIR}/include )

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

#add_subdirectory(src)