#include "Gauss.h"
#include "stdio.h"

void printTEST(struct matrix matr){  //вывод матрицы для тестов
	for (int i = 0; i < matr.columns*matr.strings; i++)
		{
			printf("%.2lf ", matr.array[i]); 
			if ((i+1)%matr.columns == 0 ) printf("\n");
		}	printf("\n");
}

void error() { printf("Fatal system error"); }

main() {
	enter(&a);
	trianglize(&a);
	switch (a.condition) {
	case 0: Answer(&a); break;
	case 8: printf("Infinity number of answers. :("); break;
	case 9: printf("Can't find answers. :("); break;
	case 5: break;
	default: error();
	}
}