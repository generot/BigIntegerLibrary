#include <stdio.h>
#include "cbigint.h"

int main(void) {
	//Correct way to use loops with the library
	CBigInt counter = make_bigint("0");
	CBigInt threshold = make_bigint("20");

	CBigInt incr = INCREMENT, prev_cnt;

	while(not_equal(counter, threshold)) {
		puts("Hello, world");
		//...//
		prev_cnt = counter;
		counter = add(counter, incr);

		delete_bigints(1, &prev_cnt);
	}

	delete_bigints(3, &counter, &threshold, &incr);
	return 0;
}
