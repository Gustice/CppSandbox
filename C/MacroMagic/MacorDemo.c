#include <stdio.h>
#include <string.h>

#define MACRO_simpleVar "StringConstant"
#define MACRO_Part1 "Hello"
#define MACRO_Part2 "World"
#define MACRO_simpleConcat MACRO_Part1 MACRO_Part2
#define MACRO_simpleConcatA MACRO_Part1 " " MACRO_Part2
#define MACRO_simpleConcatB "Hello " MACRO_Part2

#define MACRO_Stringify(symbol) #symbol
#define MACRO_Combine(symbol1,symbol2) #symbol1 #symbol2

#define PrintedSymbol MACRO_Stringify(SomeArbitrarySymbol)
#define PrintedSymbols MACRO_Combine(ArbitraryPrefix, ArbitrarySuffix)

/// Just try everything out
#define FILESource(fileName, ext) const char * FileSource ##fileName (void) {  \
    static const char * file = "FileName is : " #fileName "." #ext;             \
    return file;                                                                \
}               
FILESource(NewSource, exe)

int main(int argc, char const *argv[])
{
    /* code */
    printf("MACRO_simpleVar value is: '%s' \n", MACRO_simpleVar);
    printf("MACRO_simpleConcat value is: '%s' \n", MACRO_simpleConcat);
    printf("MACRO_simpleConcatA value is: '%s' \n", MACRO_simpleConcatA);
    printf("MACRO_simpleConcatB value is: '%s' \n", MACRO_simpleConcatB);
    
    printf("PrintedSymbol value is : '%s' \n", PrintedSymbol);
    printf("PrintedSymbols value is : '%s' \n", PrintedSymbols);

    printf("FILESource value is: '%s' \n", FileSourceNewSource());
    return 0;
}
