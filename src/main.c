#include "printf.h"

#define STR "%d"
#define ARGS 424

int main()
{
	//12 17 19
   ft_printf("ft_printf: \'"STR"\'\n\0", ARGS);
   printf("gg printf: \'"STR"\'", ARGS);
   return 0;
}
