#include <stdio.h>
#include <stdarg.h>

#include "output.h"

FILE *file = 0;
int file_count = 0;
char file_prefix[256];
int use_file = 0;

void setup_file_output(const char* output_prefix)
{
    if (output_prefix == 0)
        return;
    sprintf(file_prefix, "%s", output_prefix);

    use_file = 1;
}

void write_to_output(OUTPUT_TYPE type, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    if (type == STD_ERR)
        vfprintf(stderr, format, args);
    else if (use_file != 1)
        vfprintf(stdout, format, args);
    else
    {
        if (file == 0)
        {
            char buff[256];
            sprintf(buff, "%s_%08d.txt", file_prefix, file_count);
            file = fopen(buff, "w");
        }
        vfprintf(file, format, args);
    }
    va_end(args);
}

void close_output()
{
    if (use_file == 1)
    {
        if (file)
        {
            fclose(file);
            file = 0;
        }
        file_count++;
    }
}

void clear_output()
{
    if (use_file == 1)
        close_output();
    else
    {
        printf("\033[2J");
        printf("\033[1;1H");
    }
}
