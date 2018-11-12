#include <stdio.h>
#include <locale.h>

#define N 1000

int code [N], price [N];
char name[N][15];
int discount[N];
int tnum = 0;

void Scan()
{
    printf("Введите штрих-код товара (0001 — 9999)\n"
      "Введите 0000 для перехода к расчёту стоимости\n");
    scanf("%d", &code[tnum]);
    if (code[tnum] == 0) ///////
    {
        printf("\n%d\n", code[tnum]);
        return;
    }
    else
    {
        printf("\n%d\nТовар%d\nСтомость %d рублей\nСкидка %d\n",
          code[tnum], code[tnum], price[tnum], discount[tnum]);
        tnum++;
    }
}
void PriceDiscount()
{
    int i = 0, j = 0;
    srand((unsigned)time(0));
    while (i < N)
        discount[i] = rand() % 49 + 1;
    while (j < N)
        price[j] = rand() % 9998 + 1;
    printf("1");
}

void main()
{
    
    setlocale(LC_ALL, "Rus");
    //PriceDiscount;
    while (1)
        Scan();
}