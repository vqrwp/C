#include <stdio.h>
#include "popbacktest.h"
#include "popfronttest.h"
#include "appendtest.h"
#include "sorttest.h"

//have to test popback, popfront, append and sort
int main()
{
    if (popbacktest() && popfronttest() && appendtest() && sorttest())
    {
        puts("Correct!\n");
    }
    else
    {
        puts("Wrong answer!\n");
    }
}