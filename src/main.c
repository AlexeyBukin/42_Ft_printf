#include "printf.h"

#define STR "%015u"
#define ARGS 42

int main()
{
   ft_printf("ft_printf: \'"STR"\'\n\0", ARGS);
   printf("gg printf: \'"STR"\'", ARGS);
   return 0;
}
