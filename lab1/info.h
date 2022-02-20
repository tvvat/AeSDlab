#ifndef INFO_H
#define INFO_H
typedef struct Line{
	int n; 
	int *a;
} Line;
typedef struct Matrix{
	int lines; 
	Line *matr;
} Matrix;


int check_int(int *a);

void erase(Matrix *a);

int input(Matrix *rm);

void output(const char *msg, Matrix a);

int chek_num(int number);

void new_matr(Matrix *rez, Matrix a) ;



#endif

