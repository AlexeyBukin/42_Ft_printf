#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "%c"
#define ARGS 42

int		main() {

	printf("gg_printf: \'"STR"\'", ARGS);
	ft_printf("ft_printf: \'"STR"\'\n", ARGS);

	return 0;
}
