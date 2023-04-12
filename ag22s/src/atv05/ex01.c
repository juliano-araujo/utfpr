#include <stdio.h>

void ordenar(int *a, int *b, int *c) {
	int *aux = NULL;
	
	if (*a > *b) {
		aux = a;
		a = b;
		b = aux;
	}
	
	if (*a > *c) {
		aux = a;
		a = c;
		c = aux;
	}
	
	if (*b > *c) {
		aux = b;
		b = c;
		c = aux;
	}


	printf("%d %d %d", *a, *b, *c)	
}

int main(void) {
	int a, b, c;
	a=13;
	b=13;
	c=13;
	
	ordenar(&a, &b, &c);

	return 0;
}