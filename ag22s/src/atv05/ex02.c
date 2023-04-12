#include <stdio.h>
#include <string.h>

void* achar(void *p, char str[]){
	int achou = 0;
	for (int i = *(int *) p; i < strlen(str); i++) {
		char c = str[i];
		
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			p = &str[i];
			achou = 1;
			
			break;
		}
	}
	
	if (achou == 0) {
		p = &str[strlen(str) - 1];
	}
	
	return p;
}


int main(void) {
	int n = 0;
    void* p = &n;
    char frase[62] = "algoritmos";
    p = achar(p, frase);
    printf("%c", *(char*) p);
}