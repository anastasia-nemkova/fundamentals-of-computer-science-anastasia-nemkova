#include <stdio.h>

void column(int n, int h[n]){
	int money = 0;
	int energy = 0;
	h[0] = 0;
    for (int i = 1; i <= n; i++) {
		if (h[i - 1] < h[i] && energy < (h[i] - h[i - 1])) {
		    money += h[i] - h[i - 1]; 
		} else {
		    energy += h[i - 1] - h[i];
		}	   
    }
    printf("%d\n", money);
}

int scan_array() {
    int n;
    scanf("%d\n", &n);
    int h[n];
    for (int i = 1; i <= n; i++) {
		scanf("%d\n", &h[i]);	
    }
    column(n,h);
    return 0;
}

int main() {
    scan_array();
    return 0;
}
