#include<stdio.h>
#include<math.h>
int main() {
	int num[100], n, i, j, k, m, A, B;
	float mean = 0, SD = 0, sum = 0;
	//Input
	scanf_s("%d %d", &A, &B);
	//Process
	if (A > B) {
		n = (A - B) + 1;
		num[0] = A;
		for (i = 1; i < n - 1; i++) {
			num[i] = A - i;
		}
		num[i] = B;
	}
	else 
	{
		n = (B - A) + 1;
		num[0] = A;
		for (i = 1; i < n - 1; i++) {
			num[i] = A + i;
		}
		num[i] = B;
	}
	for (j = 0; j < n; j++)//fine Mean
	{
		mean += ((float)num[j] / (float)n);
	}
	for (k = 0; k <= n; k++)//fine S.D.
	{
		if (k == n)
		{
			if (A == B) break;
			else
			{
				SD += sqrt(sum / (float)(n - 1));
				break;
			}
		}
		if (A == B) sum = 0;
		else sum += (float)(pow((((float)num[k]) - mean), 2));
	}
	//Output
	printf("Input : %d %d\nOutput :\n  ", A, B);
	for (m = 0; m < n; m++)
	{
		printf("%d ", num[m]);
	}
	if (A == B) printf("\n  Average = %.1f\n  SD = \"Indeterminate\"", mean);
	else printf("\n  Average = %.1f\n  SD = %.2f", mean, SD);
	return 0;
}