#include <stdio.h>
#include <locale.h>
#define N 5
#define Range 100



void Input(int a[], int n, int mode)
{
    int i, j, f;
    printf("Введите массив\n");
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

void Transpose(int a[], int t1, int t2)
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
                Transpose(a, j, j - 1);
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
      "2 – пузырьком, 3 – подсчётом\n");
    do
    {
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
