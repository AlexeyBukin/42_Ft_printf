#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "%p"
#define ARGS NULL

int		main() {
//	ft_printf("ft_printf: \'"STR"\'\n");
//	printf("gg_printf: \'"STR"\'");

	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	printf("gg_printf: \'"STR"\'", ARGS);

	return 0;
}

