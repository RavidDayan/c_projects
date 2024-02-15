#include "error.h"
int isError(int *args)
{
    if (args[0] < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}