#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void main()
{
	int n, i = 0, q, w, c = 0, r, rt1 = 0, rt2 = 0, rr, cow = 0, bull = 0, c1 = 0, c2 = 0, rc1, rc2;
	long long in, nt;
	int rnd[N] = { 0 }, ain[N] = { 0 }, ord[N];
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(0));
	//���� ����� �����
	do
	{
		printf("������� ����� ����� �� 2 �� 10\n");
		scanf("%d", &n);
		if (n <= 1 || n > 10)
		{
			printf("��������� ����\n\n");
			continue;
		}
	} while (n <= 1 || n > 10);
	//��������� ���������� �����
	for (i = 0; i < N; i++)
	{
		ord[i] = i;
	}
	rc1 = rand() % 9 + 1;
	rnd[n] = rc1;
	ord[rc1] = 10;
	for (i = n - 1; i >= 0; i--)
	{
		do
		{
			rc2 = rand() % 10;
			rnd[i] = rc2;
		} while (ord[rc2] == 10);
		ord[rc2] = 10;
	}
	do
	{
		//���� �����
		nt = (long long)pow(10, n);
		do {
			do
			{
				c = 0;
				printf("������� %i-������� ����� � ���������� ��������\n", n);
				scanf("%lli", &in);
				if ((in < nt * 0.1) || (in > nt))
				{
					printf("��������� ����\n\n");
					continue;
				}
			} while ((in < nt * 0.1) || (in >= nt));
			for (i = 0; i < n; i++)
			{
				ain[i] = in - (int)(in * 0.1) * 10;
				in /= 10;
			}
			for (q = 0; q < n; q++)
			{
				for (w = q + 1; w <= n; w++)
				{
					if (ain[q] == ain[w])
					{
						printf("��������� ����\n\n");
						c++;
						break;
					}
				}
				break;
			}
		} while (c != 0);
		//���������
		cow = 0;
		bull = 0;
		for (c1 = 0; c1 < n; c1++)
		{
			for (c2 = 0; c2 < n; c2++)
			{
				if (rnd[c1] == ain[c2] && c1 == c2) bull++;
				if (rnd[c1] == ain[c2] && c1 != c2) cow++;
			}
		}
		if (bull != n)
			printf("%d �����(�), %d ����(��)\n", cow, bull);
	} while (bull != n);
	printf("��� ���� �������\n");
}
