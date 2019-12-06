#include "printf.h"

#define STR "%05d"
#define ARGS 42

int main()
{
   ft_printf(STR"\n", ARGS);
   printf(STR, ARGS);
   return 0;
}
