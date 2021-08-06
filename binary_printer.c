
#include "binary_printer.h"
#include <limits.h>
#include <stdlib.h>

#define LSB_MASK (1u)

static void printByte(unsigned char byte, BinaryPrinter_t *binaryPrinter)
{
	char charBits[CHAR_BIT + 1];
	charBits[CHAR_BIT] = '\0';
	int i, flag = 1;
	switch (binaryPrinter->bitOrder)
	{
		case BIG_FIRST:
			i = CHAR_BIT -1;
			break;
		case SMALL_FIRST:
			i = 0;
	}
	while (flag)
	{
		charBits[i] = (byte & LSB_MASK) ? '1' : '0';
		byte >>= 1u;
		switch(binaryPrinter->bitOrder)
		{
			case BIG_FIRST:
				--i;
				if (i < 0) flag = 0;
				break;
			case SMALL_FIRST:
				++i;
				if (i >= CHAR_BIT) flag = 0;
		}
	}
	fprintf(binaryPrinter->out, "%s ", charBits);
}

void printBinary(char *ptr, size_t size, BinaryPrinter_t *binaryPrinter)
{
	switch (binaryPrinter->byteOrder)
	{
		case BIG_FIRST:
			ptr += size - 1;
			for (size_t st = 0; st < size; st++) printByte(*(ptr--), binaryPrinter);
			break;
		case SMALL_FIRST:
			for (size_t st = 0; st < size; st++) printByte(*(ptr++), binaryPrinter);
			break;
		default:
			exit(1);
	}
	printf("\n");
}
