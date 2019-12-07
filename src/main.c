#include "printf.h"

#define STR "%-.2s is a string"
#define ARGS "this"

int main()
{
   ft_printf("ft_printf: \'"STR"\'\n\0", ARGS);
   printf("gg printf: \'"STR"\'", ARGS);
   return 0;
}
