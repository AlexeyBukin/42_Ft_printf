#include "printf.h"

#define STR "%#08x"
#define ARGS 42

int main()
{
   ft_printf("ft_printf: \'"STR"\'\n\0", ARGS);
   printf("gg printf: \'"STR"\'", ARGS);
   return 0;
}

//'0x00002a'
//'0x000000002a'
