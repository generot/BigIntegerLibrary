#ifndef __BIG_INT__
#define __BIG_INT__

#include <iostream>
#include <cstdlib>

class BigInt {
private:
	std::string num_rep;
public:
	BigInt(const std::string&);

	bool operator!= (BigInt);
	BigInt operator+ (BigInt);

	BigInt operator* (int);
	BigInt operator* (BigInt);

	std::string GetValue();
	BigInt pow(BigInt);
};

#endif
