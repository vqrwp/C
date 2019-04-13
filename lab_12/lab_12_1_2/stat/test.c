#include <stdio.h>

int mysorttest(void);
int keytest(void);

int main(void)
{
    if ((!mysorttest()) && (!keytest()))
    {
        printf("Approved!");
    }
    else
    {
        printf("The program works incorrectly!");
    }
}