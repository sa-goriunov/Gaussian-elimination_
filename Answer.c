#include "Gauss.h"
#include "stdio.h"
#include "stdlib.h"

double *enterAns(struct matrix *matr) {
	int j = (matr->columns) - 1;
	double *array = malloc(j * sizeof(double));
	return array;
}

void printAns(double* answer, int n) {
	for (int i = 0; i < n; i++)
		printf("X%d = %.2lf; ", i+1, answer[i]);
}

void Answer(struct matrix *matr){  //решение системы по матрице треугольного вида (определённая система)
	double *answer = enterAns(matr);
	if (answer == NULL) { error(); matr->condition = 5; }
	else {
	answer[matr->columns - 2] = (matr->array[matr->columns * matr->strings - 1]) / (matr->array[matr->columns * matr->strings - 2]);
	for (int i = matr->strings - 2; i >= 0; i--) {
		double result_i = matr->array[(i + 1) * matr->columns - 1];
		for (int j = matr->columns - 2; j > i; j--)
			result_i -=(answer[j] * matr->array[i*matr->columns+j]);
		answer[i] = result_i/ matr->array[i * matr->columns + i];
	}
	printAns(answer, matr->columns - 1);}
}