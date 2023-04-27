#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void fillRandomMat(char *mat, int rows, int cols) {
	int i, j;
	if (rows <= 0 || cols <= 0) {
		return;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			*(mat + i * cols + j) = rand() % 26 + 'A';
		}
	}

}

void printMat(const char *mat, int rows, int cols) {
	int i, j;

	if (rows <= 0 || cols <= 0) {
		return;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%c", *(mat + i * cols + j));
		}
		printf("\n");
	}
}

void Count(const char *bigMat, const char *smallMat, int *resMat, int bigSize,
		int smallSize, int resSize, char *LetterAppears, int *maxCounter) {
	int i, j;

	int tempCounter;
	char tempLetter;
	char *pBig, *pSmall;
	int *pRes;

	*maxCounter = 0;
	*LetterAppears = '\0';
	pSmall = smallMat;
	pRes = resMat;

	for (i = 0; i < smallSize; i++, pSmall++, pRes++) {
		tempLetter = *pSmall;

		for (j = 0, pBig = bigMat, tempCounter = 0; j < bigSize; j++, pBig++) {
			if (*pSmall == *pBig) {
				tempCounter++;
			}
		}

		*pRes = tempCounter;

		if (*pRes > *maxCounter) {
			*LetterAppears = tempLetter;
			*maxCounter = tempCounter;
		}

	}
}

void printResMat(const int *mat, int rows, int cols) {
	int i, j;

	if (rows <= 0 || cols <= 0) {
		return;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%d", *(mat + i * cols + j));
		}
		printf("\n");
	}
}

