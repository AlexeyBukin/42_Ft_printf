#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|%#03x|%#05x|%#037lx|"
#define ARGS 0, 43, 22337203685477ul

int		main() {
	//ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	printf("gg_printf: \'"STR"\'", ARGS);
	//printf("gg_printf: \'"STR"\'", b);

	return 0;
}

