#include <stdio.h>
#include "cbigint.h"

int main(void) {
	int n;
	scanf("%d", &n);

	CBigInt a = make_bigint("0");
	CBigInt b = make_bigint("1");

	for(int i = 0; i < n; i++) {
		CBigInt res = add(a, b);
		puts(get_value(a));
		
		assign_bint(&a, b);
		assign_bint(&b, res);

		delete_bigints(1, &res);
	}

	delete_bigints(2, &a, &b);
	return 0;
}
