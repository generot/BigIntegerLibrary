#include "bigint.h"

using namespace std;
int main() {
	BigInt a("0"), b("1");
	
	for(int i = 0; i < 200; i++) {
		cout << a.GetValue() << endl;

		BigInt c = a + b;
		a = b;
		b = c;
	}

	return 0;
}
