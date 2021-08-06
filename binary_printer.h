
#ifndef BINARY_PRINTER_H
#define BINARY_PRINTER_H

#include <stdio.h>

typedef enum
{
	BIG_FIRST, SMALL_FIRST
} Order_t;

typedef struct
{
	FILE *out;
	Order_t byteOrder: 1;
	Order_t bitOrder: 1;
} BinaryPrinter_t;

void printBinary(char *ptr, size_t size, BinaryPrinter_t *binaryPrinter);

#endif // BINARY_PRINTER_H