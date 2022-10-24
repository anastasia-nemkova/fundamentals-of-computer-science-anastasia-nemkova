#include <assert.h>
#include <stdio.h>
int ipow(int base, int exp);

int main(void) {
	int base, exp;
	scanf_s("%d%d",&base,&exp);
	int result = ipow(base, exp);
	printf("%d", result);
	return 0;
}

int ipow(int base, int exp) {
	int result = 1;
	for (; exp != 0; ) {
		if (exp % 2 == 0) {
			exp = exp / 2;
            base *= base;	
		}
		else {
			--exp;
			result *= base;
		}		
	}
	return result;
}
