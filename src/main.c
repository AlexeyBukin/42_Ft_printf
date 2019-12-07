#include "printf.h"

#define STR "%-5.10o"
#define ARGS 2500

int main()
{
   ft_printf("ft_printf: \'"STR"\'\n\0", ARGS);
   printf("gg printf: \'"STR"\'", ARGS);
   return 0;
}
