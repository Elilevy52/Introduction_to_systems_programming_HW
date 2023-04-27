#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "str.h"

char* MakeString(char *mat, int rows, int cols, char *pStr) {

	char *pMat = mat;
	char *temp = pStr;
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			*pStr = *pMat;
			pStr++;
			pMat++;
		}
		if (i != rows - 1) {
			*pStr = ' ';
			pStr++;
		}
	}
	*pStr = '\0';
	pStr = temp;
	return pStr;
}

void swap(char *s1, char *s2) {
	if (*s1 == '\0' || *s2 == '\0') {
		return;
	}

	char temp = *s2;
	*s2 = *s1;
	*s1 = temp;
	swap(s1 + 1, s2 + 1);
}

char* RevWords(char *str, int size) {
	char *startWord = str;
	char *endWord = (str + size - 1);

	int numOfWords = 1;
	int counter = 0;

	char *tempStart = str;
	char *tempEnd = str + size - 1;

	while (*str != '\0') {
		if (*str == ' ') {
			numOfWords++;
		}
		str++;
	}

	for (int i = 0; i < numOfWords / 2; i++) {
		while (*tempStart != ' ' && *tempStart != '\0') {
			tempStart++;
			endWord--;
			counter++;
		}
		*tempEnd = *tempStart ='\0';
		swap(startWord, endWord);
		*tempEnd = *tempStart =' ';
		tempStart++;
		endWord--;
		startWord = tempStart;
		*endWord = *tempEnd;
		tempEnd = endWord;
	}

	*str = '\0';
	for (int k = 0; k < size - 1; k++) {
		str--;
	}
	return str;
}

