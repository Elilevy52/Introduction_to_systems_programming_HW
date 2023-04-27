#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "matrix.h"
#include "str.h"

void cleanBuffer();

	int main(void) {
		srand(time(NULL));
		char mat[BIG_MAT_ROWS][BIG_MAT_COLS];
		char smallMat[SMALL_MAT_SIZE][SMALL_MAT_SIZE];
		int resMat[SMALL_MAT_SIZE][SMALL_MAT_SIZE];
		int resSize = SMALL_SIZE;
		char str[LEN];
		char *pStr, *pRev;

		char maxLetterAppears = '\0';
		int maxCounter = 0;

		printf("\nBig matrix:\n");
		fillRandomMat(mat, BIG_MAT_ROWS, BIG_MAT_COLS);
		printMat(mat, BIG_MAT_ROWS, BIG_MAT_COLS);

		printf("\nSmall matrix:\n");
		fillRandomMat(smallMat, SMALL_MAT_SIZE, SMALL_MAT_SIZE);
		printMat(smallMat, SMALL_MAT_SIZE, SMALL_MAT_SIZE);

		printf("\nResult matrix:\n");
		Count(mat, smallMat, resMat, BIG_SIZE, SMALL_SIZE, resSize, &maxLetterAppears, &maxCounter);
		printResMat(resMat, SMALL_MAT_SIZE, SMALL_MAT_SIZE);

		printf("\nMost repetitive:");
		if (maxCounter == 0) {
			printf("NO COMMON LETTERS (max = 0)\n");
		} else {
			printf("%c...%d times\n", maxLetterAppears, maxCounter);
		}

		printf("\nCreate string out of small matrix.\n");
		pStr = MakeString(smallMat, SMALL_MAT_SIZE, SMALL_MAT_SIZE, &str);
		pRev = RevWords(pStr, LEN);
		printf("\npRev = -->%s<--\n", pRev);
		cleanBuffer();
		return EXIT_SUCCESS;
	}

	void cleanBuffer() {
		char c;
		do {
			c = getchar();
		} while (c != '\n' && c != EOF);
	}
