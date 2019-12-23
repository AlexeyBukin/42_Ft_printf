#include "printf.h"
#include <float.h>
//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
//#define STR "this |%.10Lf|%.20f|%.17f|"
//#define ARGS 0.87650894255l, 1.025978542436587568678, 1.025978548534310421734

//#define STR "this %.10Lf float"
//#define ARGS (0.87650894255l - 0.0000000000000000001l)

int a1 = 9;
int a2 = 0;

//#define STR "|%#-+p|%10.20p|%30.10p|%p|%-3p|% %|% %"
//#define ARGS 0x1111, 0x00, &a1, &a2, a4

#define STR "|% %|% 10%|"
#define ARGS

//#define STR "|%.19f|%.19f|"
//#define ARGS 1.025978542436587568678, -1.025978542436587568678

//#define STR "|%.f|%.f|%.f|%.f|%.f|%.f|"
//#define ARGS 44.5, 45.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52

//#define STR "|%.f|%.f|"
//#define ARGS 44.50001, 44.5

int		main() {

	int *a4 = (int*)malloc(sizeof(int));
	ft_printf("ft_printf: \'"STR"\'\n" ARGS);
	//printf("gg_printf: \'"STR"\'\n", ARGS);
	free(a4);
	return (0);
}
