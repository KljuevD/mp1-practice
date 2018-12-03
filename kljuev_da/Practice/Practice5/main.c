#include <stdio.h>
#include <locale.h>
#define N 5
#define Range 100

void Print(int a[], int n);
/*
void Input(int a[], int n, int mode)
{
    int i, j, f;
    printf("Введите массив\n");                 ///////////////////////
    if (mode != 3)
        for (i = 0; i < n; i++)
            scanf("%d", &(a[i]));
    else
        for (i = 0; i < n;)
        {
            scanf("%d", &(a[i]));
            f = 0;
            for (j = 0; j < i; j++)
                if (a[j] - a[i] > Range - 1 || a[i] - a[j] > Range - 1)
                    f = 1;
            if (f == 1)
                continue;
            i++;
        }
}*/

void Input(int a[], int n, int mode)
{
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
}
void ChooseSort(int a[], int n)
{
    int i, j, min, ind;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        ind = i;
        for (j = i + 1; j < n; j++)
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
    for (i = 1; i < n; i++)
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

void BubbleSort(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n - i; j++)
            if (a[j - 1] > a[j])
            {
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
    }
}

void CountingSort(int a[], int n)
{
    int count[Range] = { 0 };
    int i, j, min = a[0], ind = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    for (i = 0; i < n; i++)
        count[a[i] - min]++;
    for (i = 0; i < Range; i++)
        for (j = 0; j < count[i]; j++)
            a[ind++] = i + min;
}

void QuickSplit(int a[], int *i, int *j, int p)
{
    do
    {       
        while (a[*i] < p)
            (*i)++;
        while (a[*j] > p)
            (*j)--;
        if (*i <= *j)
        {
            int tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
    } while (*i < *j);
}

void QuickSort(int a[], int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    QuickSplit(a, &i, &j, a[m]);
    if (i > n1)
        QuickSort(a, n1, i - 1);
    if (j < n2)
        QuickSort(a, j + 1, n2);
}

void Merge(int a[], int l, int m, int r)
{
    int i = l, j = m, c = 0, tarr[N], k = 0;
    while (i < m && j < r)
    {
        if (a[i] < a[j])
            tarr[c++] = a[i++];
        else
            tarr[c++] = a[j++];
    }
    while (i < m)
        tarr[c++] = a[i++];
    while (j < r)
        tarr[c++] = a[j++];
    while (k < r - l)
        a[i] = tarr[i];
    Print(a, r - l);
}

void MergeSort(int a[], int l, int r)
{
    int m = (l + r) / 2;
    if (l >= r)
        return;
    printf("ff\n");     ///////////
    MergeSort(a, l, m);
    MergeSort(a, m, r);
    Merge(a, l, m, r);
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
    printf("Выберите режим:\n0 – выбором, 1 – вставкой, "
      "2 – пузырьком, 3 – подсчётом,\n4 – быстрая, "
      "5 – слиянием\n");
    do
    {
        scanf("%d", &mode);
    } while (mode < 0 || mode > 5);
    Input(a, N, mode);
    printf("\nСортировка по возрастанию\n\n");
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
    case 4:
        QuickSort(a, 0, N - 1);
        break;
    case 5:
        MergeSort(a, 0, N - 1);
    }
    Print(a, N);
}
