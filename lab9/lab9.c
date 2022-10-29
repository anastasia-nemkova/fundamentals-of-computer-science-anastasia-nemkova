#include <stdio.h>
#include<stdlib.h>
#include<math.h>



int main() {
	int i0, j0, l0, i, j, l;
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

		if (pow((i - (-10)), 2) + pow((j - (-10)), 2) <= 100 && pow((i - (-20)), 2) + pow((j - (-20)), 2) <= 100) {
			printf("The point fell into the specified area at step %d with coordinates (%d, %d) and the motion parameter%d\n", k, i, j, l);
			break;
		}

		else {
			if (k == 50) {
				printf("In 50 moves, the dot never got to the area we needed.\n k=%d, i=%d, j=%d, l=%d\n", k, i, j, l);
				return 0;
			}
		}
	}

	return 0;
}
