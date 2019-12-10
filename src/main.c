#include "printf.h"

#define STR "%c - %c 123456789"
#define ARGS 0, 'z'

int main()
{
   ft_printf("ft_printf: \'"STR"\'\n", ARGS);
   printf("gg printf: \'"STR"\'", ARGS);
   return 0;
}
