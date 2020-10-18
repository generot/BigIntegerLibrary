#include "bigint.h"

using namespace std;

BigInt::BigInt(const string& ref) : num_rep(ref) {}

string BigInt::GetValue() { return num_rep; }

BigInt BigInt::operator+ (BigInt ref) {
	int lenDiff = abs((int)(num_rep.length() - ref.num_rep.length()));
                string leadingZeroes = "", output = "", refStr = ref.num_rep;

                while(lenDiff--) leadingZeroes += "0";

                if(num_rep.length() < refStr.length())
                        num_rep = leadingZeroes + num_rep;
                else refStr = leadingZeroes + refStr;

                int addOne = 0, sum = 0;
                size_t len = num_rep.length();

                for(size_t i = len; i > 0; i--)
                {
                        sum = (num_rep[i-1] - '0') + (refStr[i-1] - '0') + addOne;
                        bool flag = sum >= 10;

                        int digit = sum;
                        if(flag) digit = sum % 10;

                        output.insert(output.begin(), ('0' + digit));

                        if(flag) addOne = 1;
                        else addOne = 0;
                }

                if(sum >= 10) output = "1" + output;

                return BigInt(output);
}

bool BigInt::operator!= (BigInt to_compare) {
	return num_rep != to_compare.num_rep;
}

BigInt BigInt::operator* (int multiplier) {
	BigInt _this(num_rep), ret("0");

        while(multiplier--)
		ret = ret + _this;

        return ret;
}

BigInt BigInt::operator* (BigInt multiplier) {
	BigInt _this(num_rep), ret("0");

	for(BigInt i = BigInt("0"); i != multiplier; i = i + BigInt("1"))
		ret = ret + _this;

	return ret;
}

BigInt BigInt::pow(BigInt power) {
	BigInt _this(num_rep), ret("1");

	for(BigInt i = BigInt("0"); i != power; i = i + BigInt("1"))
		ret = ret * _this;

	return ret;
}
