#ifndef __C_BIG_INT__
#define __C_BIG_INT__

typedef void *CBigInt;
#define INCREMENT make_bigint("1")

#ifdef __cplusplus
extern "C" {
#endif

CBigInt make_bigint(const char*);

void assign_bint(CBigInt*, CBigInt);
void delete_bigints(size_t, ...);

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
