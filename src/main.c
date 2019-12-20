#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
#define STR "|% -+#8f|% 10f|%10f|"
#define ARGS (0.0 / 0.0), (1.0 / 0.0), (-1.0 / 0.0)

//int		main() {
//	//ft_printf("ft_printf: \'"STR"\'\n", ARGS);
//
//	printf("gg_printf: \'"STR"\'", ARGS);
//	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
//	//printf("gg_printf: \'"STR"\'", b);
//
//	return 0;
//}

