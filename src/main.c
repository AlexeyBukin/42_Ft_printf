#include "printf.h"

//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|%f|"
#define ARGS (double) (0.0 / 0.0)

int		main() {
	//ft_printf("ft_printf: \'"STR"\'\n", ARGS);

	float b = (0.0 / 0.0);
	ft_printf("ft_printf: \'"STR"\'", b);
	printf("gg_printf: \'"STR"\'", b);
	//printf("gg_printf: \'"STR"\'", ARGS);
	return 0;
}
