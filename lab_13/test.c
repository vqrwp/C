#include "list.h"
#include <stdio.h>
#include "test1.h"
#include "test2.h"
#include "test3.h"

int main()
{
    if (!test1() && !test2() && !test3())
    {
        puts("Correct!\n");
    }
    else
    {
        puts("Wrong results!\n");
    }
}