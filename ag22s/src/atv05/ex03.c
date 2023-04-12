#include <stdio.h>

double* max(double arr[], int n) {
	int i;
	double *max_ptr = &arr[0];
	
	for (i = 0; i < n; i++) {
		if (*max_ptr < arr[i]) {
			max_ptr = &arsr[i];
		}
	}
	
	return max_ptr;
}

int main(void) {
	double v[5]={2.6, 13.2, 1.65, 0.99, 11.9};
	double *p_max;
	p_max = max (v, 5);
	printf("%.2lf\n", *p_max);
}