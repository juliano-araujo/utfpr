#include <stdio.h>

int main(void) {
	int n, i;
	
	scanf("%d", &n);
	 
	double arr[n];
	
	for (i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}
	
	for (i = 0; i < n; i++) {
		printf("V[%d] = %.1f \n", i, arr[i]);
	}
	
	for (i = n - 1; i >= 0; i--) {
		printf("V[%d] = %.1f \n", i, arr[i]);
	}
	
	return 0;
}