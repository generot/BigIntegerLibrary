#include "bigint.h"

using namespace std;
int main() {
	BigInt a("3");

	for(BigInt i = BigInt("0"); i != BigInt("11"); i = i + BigInt("1")) {
		BigInt pow = a.pow(i);
		cout << "3 ^ " << i.GetValue() << " = " << pow.GetValue() << endl;
	}

	return 0;
}
