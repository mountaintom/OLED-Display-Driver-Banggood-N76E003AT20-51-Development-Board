#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"


#include "NuTiny8051.h"

int putchar (int c)  {
   if (c == '\n') {
        while (!TI);
        SBUF = '\r';
        TI = 0;
    }
    while (!TI);
    SBUF = c;
    TI = 0;
    return(c);
}

