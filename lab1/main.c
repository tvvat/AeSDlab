#include <stdio.h>
#include <malloc.h>
#include "info.h"


int main() {
	Matrix matr;
	Matrix rez;
	
	if (input(&matr) != 0){ 
		printf("%s\n", "End of file occured");
		return 1;
	}
	new_matr(&rez,matr);
	output("Source matrix", matr);
	output("Rezult matrix", rez);
	erase(&matr); 
	erase(&rez); 
	return 0;

}

