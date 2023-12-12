#include "main.h"
#include <stdarg.h>

int _sprintf(char *buffer, const char *format, ...)
{
    va_list args;
    int count;

    va_start(args, format);
    count = vsprintf(buffer, format, args);
    va_end(args);

    return count;
}

char *_rev_atoi(int num)
{
    char *result = (char *)malloc(12 * sizeof(char));

    if (result == NULL)
    {
        return NULL;
    }

    _sprintf(result, "%d", num);

    return result;
}
