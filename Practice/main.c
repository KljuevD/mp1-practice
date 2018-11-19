﻿#include <stdio.h>
#include <locale.h>
#define N 5
#define K 1000


void Input(int a[], int n, int mode)
{
    int i = 0;
    printf("Введите массив\n");
    if (mode != 3)
        for (i = 0; i < n; i++)
            scanf("%d", &(a[i]));
    else
        do
        {
            scanf("%d", &(a[i++]));
        } while ((a[i] <0 || a[i] > K - 1) && i < n);
}

void ChooseSort(int a[], int n)
{
    int i, j, min, ind;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        ind = i;
        for (j = i; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                ind = j;
            }
        }
        a[ind] = a[i];
        a[i] = min;
    }
}

void InsertSort(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            a[j--] = tmp;
        }
    }
}

void Transposal(int a[], int t1, int t2)
{
    int tmp;
    tmp = a[t1];
    a[t1] = a[t2];
    a[t2] = tmp;
}

void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j++)
            if (a[j - 1] > a[j])
                Transposal(a, j, j - 1);
    }
}


void CountingSort(int a[], int n)
{
    int count[K] = { 0 };
    int i, j, ind = 0;
    for (i = 0; j < n; i++)
        count[a[i]]++;
    for (i = 0; i < n; i++)
        for (j = 0; j < count[i]; j++)
            a[ind++] = i;

}

void Print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

void main()
{
    int mode, a[N];
    setlocale(LC_ALL, "Rus");
    do
    {
        printf("Выберите режим\n");
        scanf("%d", &mode);
    } while (mode < 0 || mode > 3);
    Input(a, N, mode);
    printf("Сортировка по возрастанию\n");
    switch (mode)
    {
    case 0:
        ChooseSort(a, N);
        break;
    case 1:
        InsertSort(a, N);
        break;
    case 2:
        BubbleSort(a, N);
        break;
    case 3:
        CountingSort(a, N);
        break;
    }
    Print(a, N);
}