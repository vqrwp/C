#include <stdio.h>
#include "strreplacetest.h"
#include "getlinetest.h"

int main(int argc, char **argv)
{
    if (!teststrreplace() && !testgetline())
    {
        printf("Correct!");
    }
    else
    {
        printf("Mistake!");
    }
}