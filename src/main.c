#include "printf.h"

#define STR "% c"
#define ARGS 0

int main()
{
   ft_printf("ft_printf: \'"STR"\'\n\0", ARGS);
   printf("gg printf: \'"STR"\'", ARGS);
   return 0;
}
