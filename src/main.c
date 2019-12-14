#include "printf.h"

#define STR "=%0d=|=%00d="
#define ARGS -42, -42

int main()
{
//	ft_printf("ft_printf: \'"STR"\'\n");
//	printf("gg printf: \'"STR"\'\n");

   ft_printf("ft_printf: \'"STR"\'\n", ARGS);
   printf("gg printf: \'"STR"\'\n", ARGS);

	//int a = 5;
//	printf("ft: %d\ngg: %d\n", a, b);
   //t i = 0;
//   while (i < 256)
//	   printf("%c\n", i++);
   return 0;
}
