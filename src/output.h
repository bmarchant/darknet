#ifndef OUTPUT_H
#define OUTPUT_H

typedef enum {
    STD_ERR, STD_OUT
} OUTPUT_TYPE;

void setup_file_output(const char* output_prefix);

void write_to_output(OUTPUT_TYPE type, const char* format, ...);

void close_output();

void clear_output();

#endif
