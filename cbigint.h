#ifndef __C_BIG_INT__
#define __C_BIG_INT__

typedef void *CBigInt;

#ifdef __cplusplus
extern "C" {
#endif

void make_bigint(CBigInt*, const char*);
void delete_bigint(CBigInt*);

int not_equal(CBigInt, CBigInt);

CBigInt add(CBigInt, CBigInt);
CBigInt mult(CBigInt, CBigInt);
CBigInt powc(CBigInt, CBigInt);
CBigInt mult_i(CBigInt, int);

const char *get_value(CBigInt);

#ifdef __cplusplus
}
#endif

#endif
