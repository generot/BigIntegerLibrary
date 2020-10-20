#include "bigint.h"
#include "cbigint.h"

void make_bigint(CBigInt *to_make, const char *str) {
	BigInt *ptr = new BigInt(std::string(str));
	*to_make = (CBigInt)ptr;
}

int not_equal(CBigInt i1, CBigInt i2) {
	return *((BigInt*)i1) != *((BigInt*)i2);
}

CBigInt add(CBigInt i1, CBigInt i2) {
	BigInt *res = new BigInt("0");
	*res = *((BigInt*)i1) + *((BigInt*)i2);

	return (CBigInt)res;
}

CBigInt mult(CBigInt i1, CBigInt i2) {
	BigInt *res = new BigInt("0");
	*res = (*((BigInt*)i1)) * (*((BigInt*)i2));

	return (CBigInt)res;
}

CBigInt powc(CBigInt i1, CBigInt i2) {
	BigInt *res = new BigInt("0");
	*res = (*((BigInt*)i1)).pow(*((BigInt*)i2));

	return (CBigInt)res;
}

CBigInt mult_i(CBigInt, int) { return NULL; };

void delete_bigint(CBigInt *to_delete) {
	free(*to_delete);
}

const char *get_value(CBigInt val) {
	BigInt ret_val = *((BigInt*)val);
	return ret_val.GetValue().c_str();
}
