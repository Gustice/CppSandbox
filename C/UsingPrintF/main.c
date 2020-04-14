/**
 * @file main.c
 * @author Gustice
 * 
 * @brief C-Programm with different calls to analyze effect of modifiers on 
 *      compiled output.
 *      Compilation and source-dumps are generated with 'runMe.sh'.
 * @version 0.1
 * @date 2020-04-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "stdio.h"

void PrintingStrings(void)
{
    printf("## Printing different strings'\r\n");
    printf("  print just on character by using %%c:     '%c'\r\n", 'a');
    printf("  print some arbitrary string using %%s:     '%s'\r\n", "SomeArbitraryString");
    printf("## This is handy to print some C/Cpp compiler makros'\r\n");
    printf("  '__PRETTY_FUNCTION__': '%s' (caution: this is gnu and not standard c)\r\n", __PRETTY_FUNCTION__);
    printf("  '__func__': '%s'\r\n", __func__);
    printf("  '__FILE__': '%s'\r\n", __FILE__);
    printf("  '__LINE__': '%i'\r\n", __LINE__);
    printf("  '__DATE__': '%s'\r\n", __DATE__);
    printf("  '__TIME__': '%s'\r\n", __TIME__);
    printf("  '__VERSION__': '%s'\r\n", __VERSION__);
}

void PrintingNumbers(void)
{
    double fullnumber = 42.42;
    int number = (int)fullnumber;
    printf("## Printing numbers 42 and -42, or 42.42 and -42.42 respectively\r\n");
    printf("  Demonstration of most common usecases\r\n");
    printf("  %%d to print as signed decimal:    %d, %d\r\n", number, -number);
    printf("  %%i to print as signed decimal:    %i, %i\r\n", number, -number);
    printf("  %%u to print as unsigned decimal:  %u, %u\r\n", number, -number);
    printf("  0%%o to print as octal:            0%o, 0%o\r\n", number, -number);
    printf("  0x%%x to print as hexadezimal:     0x%x, 0x%x\r\n", number, -number);
    printf("  0X%%X to print as hexadecimal:     0X%X, 0X%X\r\n", number, -number);
    printf("  %%f to print as flaoting point :   %f, %f\r\n", fullnumber, -fullnumber);
    printf("  %%F to print as floating point:    %F, %F\r\n", fullnumber, -fullnumber);
    printf("  %%e to print in scientific form:   %e, %e\r\n", fullnumber, -fullnumber);
    printf("  %%E to print in scientific form:   %E, %E\r\n", fullnumber, -fullnumber);
    printf("  %%c to print character:           '%c'\r\n", number);
}

void PrittyPrintingNumbers(void)
{
    int number = 42;
    printf("## Printing number 42\r\n");
    printf("  '-'-flag in %%-4d => Left justify:            '%-4d'\r\n", number);
    printf("  '+'-flag in %%+d => prints also +sign:        '%+d'\r\n", number);
    printf("  ' '-flag in %% d => prints blank if no sign:  '% d'\r\n", number);
    printf("  '#'-flag in %%#x => prints width:             '%#x'\r\n", number);
    printf("  '0'-flag in %%04x => pads zeros:              '%04x'\r\n", number);
    printf("  'width %%4d => pads blanks ahead:             '%4x'\r\n", number);
    printf("  'width %%*d => maks width a parameter:        '%*x'\r\n", 4, number);
}

void PrittyPrintingFloats(void)
{
    double number = 42.123456;
    printf("## Printing float number 42.123456\r\n");
    printf("  '.p' in %%.2f => defines precision:           '%.2f'\r\n", number);
    printf("  '.*' in %%.*f => maks precision a parameter:  '%.*f'\r\n", 3, number);
    printf("  'w.p' in %%8.2f => defines widht & precision: '%8.2f'\r\n", number);
    
}

/* Main to call all functions */
int main(int argc, char const *argv[])
{
    printf("Demonstration of 'printf(format, args ...)'\r\n");
    printf("See documentation @: %s", "http://www.cplusplus.com/reference/cstdio/printf");
    printf("    Syntax of format specifier %%[flags][width][.precision][length]specifier\r\n");
    printf("\r\n");
    
    PrintingStrings();
    printf("\r\n");
    
    PrintingNumbers();
    printf("\r\n");
    
    PrittyPrintingNumbers();
    printf("\r\n");

    PrittyPrintingFloats();
    printf("\r\n");

    printf("Note 'length' qualifier appears not to be useful hence is not covered in this example\r\n");
    /* code */
    return 0;
}
