#include "printf.h"

#define STR "@moulitest: %c  "
#define ARGS 42

int main()
{
//	int a = ft_printf("ft_printf: \'"STR"\'\n");
//	int b = printf("gg printf: \'"STR"\'\n");

   int a = ft_printf("ft_printf: \'"STR"\'\n", ARGS);
   int b = printf("gg printf: \'"STR"\'\n", ARGS);

	//int a = 5;
	printf("ft: %d\ngg: %d\n", a, b);
   //t i = 0;
//   while (i < 256)
//	   printf("%c\n", i++);
   return 0;
}
