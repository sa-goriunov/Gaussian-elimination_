struct matrix {
	int columns;
	int strings;
	double* array;
	int condition; //решаема ли система
};

//struct matrix a;

void trianglize(struct matrix *matr);

void Answer(struct matrix *matr);

void printTEST(struct matrix matr);

void enter(struct matrix *matr);

void error();