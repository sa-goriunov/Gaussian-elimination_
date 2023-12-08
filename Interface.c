#include "Gauss.h"
#include "stdio.h"
#include "stdlib.h"

void enter1(struct matrix *matr) {
	printf("Enter the system:\n"); 
	for (int i = 0; i < matr->strings; i++) {
		for (int j = 1; j < matr->columns; j++) {
			printf("X%d ", j); 
			scanf_s("%lf", &matr->array[i * matr->columns + j - 1]);
		}
		printf("="); scanf_s("%lf", &matr->array[(i + 1) * matr->columns - 1]);
	}
}



void enter(struct matrix *matr) {
	printf("System of equations calculator (Gaussian elimination)\nEnter number of variables: "); 
	int variables = 0; scanf_s("%d", &variables); 
	printf("Enter number of equations: "); //
	int equations = 0; scanf_s("%d", &equations);

	if (equations < variables) {  matr->condition = 8; } //неопределённая
	else {
		if (equations > variables) {  matr->condition = 9; } //несовместная
		else{
		matr->columns = (variables + 1);
		matr->strings = equations;
		matr->array = malloc(matr->columns * matr->strings * sizeof(double));
		if (matr->array == NULL) { error(); matr->condition = 5; }
		else { enter1(matr); matr->condition = 0; }
		}
	}
}