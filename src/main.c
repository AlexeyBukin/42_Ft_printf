#include "printf.h"

//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|%f|"
#define ARGS -3.85

int		main() {
	//ft_printf("ft_printf: \'"STR"\'\n", ARGS);

	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	//printf("gg_printf: \'"STR"\'", b);
	printf("gg_printf: \'"STR"\'", ARGS);
	return 0;
}
