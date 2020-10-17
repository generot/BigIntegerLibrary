# BigIntegerLibrary
This is a C++ library that provides addition and multiplication of arbitrarily large integers.
For now, it only supports addition and multiplication, it is uncertain whether other arithmetic operations will be added.
Multiplication works with a ```BigInt``` and an ```int``` multiplier.
Addition works only between BigInts.<br>

The library has been compiled using MinGW 7.0.0(GCC 10.2.0). The provided makefile can be used for the compilation of the library. It is dynamically linked.<br>
Usage: ```g++ -o <output_name> <src_file> bigint.dll```

Example:<br>
```
  #include <bigint.h>
  
  using std::cout;
  using std::cin;
  using std::string;
  
  int main() {
    string num1, num2;
    int mult;
    
    cin >> num1 >> num2 >> mult;
    
    BigInt first(num1), second(num2);
    BigInt resultSum = first + second, resultMult = resultSum * mult;
    
    cout << resultSum.GetValue() << " " << resultMult.GetValue() << "\n";
    return EXIT_SUCCESS;
  }
```
