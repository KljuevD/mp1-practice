#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
	int mode, num, att = 0, inp, a = 0, b = 1000, lie = 0;
	char answ;
	srand((unsigned)time(0));
	setlocale(LC_ALL, "Rus");
	printf("�������� �����:\n0 � ��������� ����������,\n1 � ��������� ���������\n");
	do
	{
		scanf("%d", &mode);
		if (mode == 0)
		{
			num = rand() % (b - a - 1) + 1 + a;
			//num = (float)(b - a - 1) / RAND_MAX * rand() + 1;
			do
			{
				do
				{
					printf("������� ����� �� 1 �� 999\n");
					scanf("%d", &inp);
					if ((inp < 1) || (inp > 999))
						printf("����� ��� ���������� ��������\n");
				} while ((inp < 1) || (inp > 999));
				if (inp > num)
				{
					printf("������� �������\n");
					att++;
				}
				if (inp < num)
				{
					printf("������� ���������\n");
					att++;
				}
			} while (inp != num);
			printf("������� ������ �����, ��������� %d �������\n", ++att);
			return;
		}
		if (mode == 1)
		{
			do
			{
				printf("������� ����� �� 1 �� 999\n");
				scanf("%d", &num);
				if ((num < 1) || (num > 999))
					printf("����� ��� ���������� ��������\n");
			} while ((num < 1) || (num > 999));
			do
			{
				inp = rand() % (b - a - 1) + 1 + a;
				printf("����� %d, ������� ��� (������� '>' '=' '<')\n", inp);
				do
				{
				ent:
					scanf(" %c", &answ);
					if (!((answ == '<') || (answ == '>') || (answ == '=')))
						printf("�������� ������\n");
					//�������� �����
					if ((answ == '<') && !(num < inp) || (answ == '>') && !(num > inp) || (answ == '=') && (num != inp))
					{
						printf("������ ����\n");
						lie++;
						goto ent;
						//continue;
					}
				} while (!((answ == '<') || (answ == '>') || (answ == '=')));
				switch (answ)
				{
				case '>':
					a = inp;
					att++;
					break;
				case '=':
					att++;
					break;
				case '<':
					b = inp;
					att++;
				}
			} while (answ != '=');
			printf("\n������� ������ �����, ��������� %d �������\n", att);
			if (lie != 0) printf("������� ��������� ����: %d\n", lie);
			printf("\n");
			return;
		}
		printf("�������� �����\n");
	} while ((mode != 0) || (mode != 1));
}
