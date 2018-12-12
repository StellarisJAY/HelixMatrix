#include <stdio.h>

int main(void)
{
	int N, i, j, n, num = 1;
	int matrix[100][100] = { 0 };

	while (scanf("%d", &N) != EOF)
	{
		i = 0;
		j = 0;

		// * ��Ҫ˼·��ÿ��ѭ��Ϊ��תһ�ܣ��������Խ���ʱ��СȦ��
		// * n <= (N + 1) / 2�� ��n���������Խ�����Ԫ�ص��б꣬һ���ᾭ�����Խ��� ��N + 1��/ 2�Σ�N Ϊ���������
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

		//��������������������Ҫ�ֶ��������Ԫ�أ� ��Ҫ����Ϊʲô����ѧ���ɷ� ����
		if (N % 2 != 0)
		{
			matrix[(N) / 2][(N) / 2] = num;
		}


		//��ӡ����
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