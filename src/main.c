#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|%.0Lf|%.3Lf|%Lf|%.8Lf|"
#define ARGS LDBL_MIN, LDBL_MIN, LDBL_MIN, LDBL_MIN

//int		main() {
//	//ft_printf("ft_printf: \'"STR"\'\n", ARGS);
//
//	printf("gg_printf: \'"STR"\'", ARGS);
//	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
//	//printf("gg_printf: \'"STR"\'", b);
//
//	return 0;
//}

