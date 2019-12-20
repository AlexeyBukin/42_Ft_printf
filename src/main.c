#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "%s"
#define ARGS "42"

int		main() {
	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	printf("gg_printf: \'"STR"\'", ARGS);

//	int a = 456;
//	int *d = &a;

//	int *r01 = malloc(sizeof(int));
//	printf("\n&r01 = %s\n", ft_mtob(&r01, 8));
//	printf("\nr01 = %s\n", ft_mtob(r01, 8));
//	printf("\n&r00 = %s\n", ft_mtob(&r00, 8));
//	ft_printf("ft_printf: \'"STR"\'\n", r01);
//	printf("gg_printf: \'"STR"\'", r01);

	return (0);
}

