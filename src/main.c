#include "printf.h"

//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|%10.6f|"
#define ARGS 42.2356462f

int		main() {
	ft_printf("ft_printf: \'"STR"\'\n", ARGS);

	printf("gg_printf: \'"STR"\'", ARGS);
	return 0;
}
