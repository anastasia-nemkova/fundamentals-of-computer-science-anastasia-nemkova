#include <stdio.h>


int column() {
    int money = 0;
	int energy = 0;
    int n;
    scanf("%d\n", &n);
    int h[n];
    for (int i = 1; i <= n; i++) {
        h[0] = 0;
		scanf("%d\n", &h[i]);
		if (h[i - 1] < h[i] && energy < (h[i] - h[i - 1])) {
		    money = money + (h[i] - h[i - 1]) - energy;
		    energy = 0; 
		} else {
		    energy += h[i - 1] - h[i];
		}	   
    }
    printf("%d\n", money);
}
    
int main() {
    column();
    return 0;
}
