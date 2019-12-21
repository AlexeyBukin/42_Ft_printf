#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|%.2147483649f|%2147483649f|"
#define ARGS 1.0, 1.0

int		main() {

	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	printf("gg_printf: \'"STR"\'", ARGS);

	return (0);
}
