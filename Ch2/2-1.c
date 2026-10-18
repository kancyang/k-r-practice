#include <float.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf(
	       "char:                        %d to %d\n"
	       "signed char:                 %hhd to %hhd\n"
	       "unsigned char:               %hhu to %hhu\n\n"

	       "(signed) short (int):        %hd to %hd\n"
	       "unsigned short (int):        %hu to %hu\n\n"

	       "(signed) int:                %d to %d\n"
	       "unsigned int:                %u to %u\n\n"

	       "(signed) long (int):         %ld to %ld\n"
	       "unsigned long (int):         %lu to %lu\n\n"

	       "(signed) long long (int):    %lld to %lld\n"
	       "unsigned long long (int):    %llu to %llu\n\n"


	       "float:                   (-) %e to %e\n"
	       "                             epsilon = %e\n\n"

	       "double:                  (-) %le to %le\n"
	       "                             epsilon = %le\n\n"

	       "long double:             (-) %Le to %Le\n"
	       "                             epsilon = %Le\n\n"

	       "--- Complete.\n",

		CHAR_MIN, CHAR_MAX,
		SCHAR_MIN, SCHAR_MAX,
		0, UCHAR_MAX,

		SHRT_MIN, SHRT_MAX,
		0, USHRT_MAX,
		
		INT_MIN, INT_MAX,
		0U, UINT_MAX,

		LONG_MIN, LONG_MAX,
		0UL, ULONG_MAX,

		LLONG_MIN, LLONG_MAX,
		0ULL, ULLONG_MAX,

		FLT_MIN, FLT_MAX, FLT_EPSILON,

		DBL_MIN, DBL_MAX, DBL_EPSILON,

		LDBL_MIN, LDBL_MAX, LDBL_EPSILON
	);
}
