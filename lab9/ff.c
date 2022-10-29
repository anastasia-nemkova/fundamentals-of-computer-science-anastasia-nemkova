#include <stdio.h>
#include<stdlib.h>
#include<math.h>


int main() {
	int i0, j0, l0, i, j, l, f, g;
	i0 = 6;
	j0 = 27;
	l0 = -15;

	for (int k = 0; k <= 50; k++) {

		i = (i0 * i0 * i0 - j0 * j0 * j0 + l0 * l0 * l0 - k) % 20;
		j = min(i0 * j0 * l0 - k, min(i0 * i0 * l0 - k, j0 * l0 * l0 - k)) % 30;
		l = max(i0 * j0 * l0 - k, max(i0 * i0 * l0 - k, j0 * l0 * l0 - k)) % 30;
		l0 = l;
		i0 = i;
		j0 = j;
		f = pow((i - (-10)), 2) + pow((j - (-10)), 2);
		g = pow((i - (-20)), 2) + pow((j - (-20)), 2);

		printf("k=%d i=%d j=%d l=%d 100<%d 100<%d\n", k, i, j, l, f, g);
	}

	return 0;
}
