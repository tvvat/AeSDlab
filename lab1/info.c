#include "info.h"
#include <stdio.h>
#include <malloc.h>


int check_int(int *a){

	double n;
	char *s;
	int tmp ;
	tmp = scanf("%lf", &n);
	while(((int) n!= n)||(tmp <=0 )) {
		printf("%s","You are wrong; repeat, please!\n");
		scanf("%*c");
		tmp = scanf("%lf", &n);
	
	}
		
	*a=n/1;
	return 0;
}

void erase(Matrix *a)
{
	int i;
	for (i = 0; i < a->lines; ++i)
		free(a->matr[i].a);
	free(a->matr);
	a->lines = 0;
	a->matr = NULL;
}

int input(Matrix *rm){
	int m;
	int n;
	char *error=" ";
	printf("Enter number of lines:");
	
	do{	printf("%s\n", error);
		error = "You are wrong; repeat, please!\n";
 		if(check_int(&m)) {
 			printf("%s",error);
			m = 0;
		}
	} while (m < 1);
		
	rm->lines = m;
	rm->matr = (Line *)malloc(m * sizeof(Line));
	

	for (int i = 0; i < rm->lines; ++i){
		error=" ";
		printf("Enter number of items in line %d: --> ", i + 1);
		do{	error = "You are wrong; repeat, please!\n";
			if (check_int(&n)){
				printf("%s",error);
				
			}
		}while (n < 1);
	
		rm->matr[i].n = n;
		
		int *p = (int *)malloc(sizeof(int) * n);
		rm->matr[i].a = p;
		printf("Enter items for matrix line #%d:\n", i + 1);
		for (int j = 0; j < n; ++j, ++p){
		
			if (check_int(p)) {
				printf("%s",error);
				return 1;
			}
			
		}
		
	}

	return 0;
}

void output(const char *msg, Matrix a)
{
	int *p;
	
	printf("%s:\n", msg);
	
	for (int i = 0; i < a.lines; ++i){
		p = a.matr[i].a;
		
		for (int j = 0; j < a.matr[i].n; ++j, ++p)
			printf("%d ", *p);
				
		printf("\n");	
		
	}

}

int chek_num(int number) {
	if(number < 12)
		return 1;
	int tmp ;
	
	tmp = number % 10;
	number/=10;
	
	while (number > 0){
		
		if (tmp <= number%10) {
			return 1;
		}
		tmp = number % 10;
		number/=10;
	}
	
	return 0;

}

void new_matr(Matrix *rez, Matrix a) {

	int tmp;
	int *p;
	rez->lines = a.lines;
	rez->matr = (Line *) malloc(rez->lines * sizeof(Line));
	for (int i = 0; i < a.lines; ++i){
		p = a.matr[i].a;
		int count = 0;
		rez->matr[i].n = 0;
		rez->matr[i].a= (int *) malloc(1* sizeof(int));
		for (int j = 0; j < a.matr[i].n; ++j, ++p)

			
			if (chek_num(*p) == 0) { 
				
				rez->matr[i].a[count] = *p;
				count++;
				
				rez->matr[i].a= (int *) realloc(rez->matr[i].a,count * sizeof(int ));
				
				rez->matr[i].n++;
				
				
			}

	}






}
