#include <stdio.h>

int min(int a, int b);

int main() {
	int i,j;
	int chunk = 10;
	int bufsize = 76;
	printf("Non strip mining:\n");
	for(i = 0; i < bufsize; i++) {
		printf("%d\n", i);
	}
	printf("Strip mining:\n");	
	for(i = 0; i < bufsize; i += chunk) {
		for(j = i; j < min(bufsize, i+chunk); ++j) {
			printf("%d\n", j);
		}
	}
	return 0;
}

int min(int a, int b) {
	if(a < b) {
		return a;
	}
	else {
		return b;
	}
}