#include <stdio.h>
#include "cbigint.h"

int main(void) {
	CBigInt i1 = NULL, i2 = NULL;

	make_bigint(&i1, "3");
	make_bigint(&i2, "5");

	CBigInt res = powc(i1, i2);

	printf("%s", get_value(res));

	delete_bigint(&i1);
	delete_bigint(&i2);
	delete_bigint(&res);

	return 0;
}
