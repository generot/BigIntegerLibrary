#include "../include/bigint.h"
#include "../include/cbigint.h"

#include <stdarg.h>
#include <cstring>

CBigInt make_bigint(const char *str) {
	BigInt *ptr = new BigInt(std::string(str));
	return (CBigInt)ptr;
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
	*res = ((BigInt*)i1)->pow((*((BigInt*)i2)));
	
	return (CBigInt)res;
}

///Unimplemented///
CBigInt mult_i(CBigInt, int) { return NULL; };

void delete_bigints(size_t amount, ...) {
	va_list ls;
	va_start(ls, amount);

	for(size_t i = 0; i < amount; i++)
		free(*va_arg(ls, CBigInt*));

	va_end(ls);
}

void assign_bint(CBigInt *out, CBigInt to_assign) {
	BigInt *ptr = (BigInt*)*out;
	*ptr = *((BigInt*)to_assign);

	*out = (CBigInt)ptr;
}

const char *get_value(CBigInt val) {
	BigInt *ret_val = (BigInt*)val;

	size_t sz = ret_val->GetValue().length() + 1;
	char *str = new char[sz];

	std::strncpy(str, ret_val->GetValue().c_str(), sz);
	return str;
}
