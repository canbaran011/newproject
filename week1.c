// Determinant of a 3x3 matrix function uses first row to calculate
#include <stdio.h>
#include <math.h>

int determinant(int A[][3])
{
	int temp[2][2], factor = -1, i, j, k = 0, l = 0, col = 0, row = 0, sum = 0,dettemp = 0;

	while (col < 3) {
		k = 0;
		for (i = 0; i < 3; i++) {
			if (i != row) {
				l = 0;
				for (j = 0; j < 3; j++) {
					if (j != col) {
						temp[k][l] = A[i][j];
						l++;
					}
				}
				k++;
			}
		}
		dettemp = temp[0][0] * temp[1][1] - temp[1][0] * temp[0][1];
		sum += pow(factor, (float)(row + 1 + col + 1))*A[row][col]*(dettemp);
		col++;
	}
	
	return sum;
}

int main(void)
{
	int A[][3] = { {2,2,1},
				  {0,1,3},
				  {1,1,2} };
	printf("Determinant of A is %d\n", determinant(A));
	return 0;
}


