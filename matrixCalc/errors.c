#include "error.h"
int isError(int *args)
{
    if (args[0] < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}