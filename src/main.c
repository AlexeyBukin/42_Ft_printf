#include "printf.h"

//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|%.10Lf|%Lf|%.0f|"
#define ARGS 0.87650894255l, 43.43999949l, 1.6

int		main() {
	//ft_printf("ft_printf: \'"STR"\'\n", ARGS);

	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	//printf("gg_printf: \'"STR"\'", b);
	printf("gg_printf: \'"STR"\'", ARGS);
	return 0;
}

