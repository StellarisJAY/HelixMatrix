#include <stdio.h>

int main(void)
{
	int N, i, j, n, num = 1;
	int matrix[100][100] = { 0 };

	while (scanf("%d", &N) != EOF)
	{
		i = 0;
		j = 0;

		// * 主要思路是每次循环为旋转一周，到达主对角线时缩小圈；
		// * n <= (N + 1) / 2： 将n看作是主对角线上元素的行标，一共会经过主对角线 （N + 1）/ 2次，N 为矩阵阶数；
		for (n = 1; n <= (N + 1) / 2; n++)
		{
			for (i; i < N - n; i++)
			{
				matrix[j][i] = num++;
			}

			for (j; j < N - n; j++)
			{
				matrix[j][i] = num++;
			}

			for (i; i > n - 1; i--)
			{
				matrix[j][i] = num++;
			}

			for (j; j > n - 1; j--)
			{
				matrix[j][i] = num++;
			}
			i = n;
			j = n;
		}

		//如果矩阵阶数是奇数，需要手动添加中心元素， 不要问我为什么，数学归纳法 ：》
		if (N % 2 != 0)
		{
			matrix[(N) / 2][(N) / 2] = num;
		}


		//打印矩阵
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				printf("%-3d", matrix[i][j]);
			}
			putchar('\n');
		}
		num = 1;
	}
	return 0;
}