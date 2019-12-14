#include "printf.h"

#define STR "=%015u=|=%00d="
#define ARGS 4294967295u, 0

int main()
{
//	ft_printf("ft_printf: \'"STR"\'\n");
//	printf("gg printf: \'"STR"\'\n");

   ft_printf("ft_printf: \'"STR"\'\n", ARGS);
   printf("gg printf: \'"STR"\'\n", ARGS);

	printf("\n\n%s", ft_utoa(433332158u));
	printf("\n\n%s", ft_ulltoa(4333321589234111112u));
	//int a = 5;
//	printf("ft: %d\ngg: %d\n", a, b);
   //t i = 0;
//   while (i < 256)
//	   printf("%c\n", i++);
   return 0;
}
