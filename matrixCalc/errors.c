#include "errors.h"
#include <stdio.h>

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
void notCommandError()
{
    printf("\nthe line is missing a legal command at the start\n");
}
void notMatrixError()
{
    printf("\nthe line is missing a legal matrix in it\n");
}
void missingCommaError()
{
    printf("\nthe line is missing a comma in it\n");
}
void notRealNumberError()
{
    printf("\nthis line has a non real number in it\n");
}
void extraCharactersError()
{
    printf("\nthis line has extra characters after the proper command\n");
}
void missingSpaceError()
{
    printf("\nthis line is missing a space after the command\n");
}
void ilegalCommaError()
{
    printf("\nthis line has an ilegal comma\n");
}
void consecutiveCommaError()
{
    printf("\nthis line has consecutive comma's\n");
}
void noScalarError()
{
    printf("\nthis line has no scalar\n");
}