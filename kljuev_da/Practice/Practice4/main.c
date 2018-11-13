#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

int code[N] = { 0 }, price[N] = { 0 }, discount[N] = { 0 },
  amount[N] = { 0 }, value[N] = { 0 };
int num = 0;


void PriceDiscount()
{
    int i = 0, j = 0;
    while (i < N)
        discount[i++] = rand() % 49 + 1;
    while (j < N)
        price[j++] = rand() % 9998 + 1;
}

void Scan()
{
    int i = 0;
    do
    {
        printf("Введите штрих-код товара (0001 – 9999)\n"
          "Введите 0000 для перехода к расчёту стоимости\n");
        do
        {
            scanf("%d", &code[num]);
        } while (code[num] < 0 || code[num] > 9999);
        value[num] = code[num];
        amount[code[num]]++;
        if (num == 0 && code[num] == 0)
            continue;
        if (code[num] == 0)
            i = 1;
        else
        {
            printf("\nКод %d\nТовар%d\nСтомость %d рублей\n"
              "Скидка %d%%\nСтоимость со скидкой %d рублей\n\n",
              code[num], code[num], price[code[num]], discount[code[num]],
              Discounted(price[code[num]], discount[code[num]]));
            num++;
        }
    } while (i == 0);
}

int Discounted(int tprice, int tdisc)
{
    return (int)((long)tprice * (100 - tdisc) * 0.01);
}

int Tdiscount(int tprice, int tdisc)
{
    return (int)(tprice * tdisc * 0.01);
}

void Receipt()
{
    int discsum = 0, sum = 0, i;
    printf("\nПечать чека\n\n");
    for (i = 0; i < num; i++)
    {
        if (amount[value[i]] == 0)
            continue;
        int tprice = Discounted(price[value[i]], discount[value[i]]);
        int tsprice = Discounted(price[value[i]], discount[value[i]]) *
          amount[value[i]];
        printf("Товар%d\nСтоимость (со скидкой) %d рублей\n"
          "Количество %d штук(а)\nСуммарно %d рублей\n", value[i],
          tprice, amount[value[i]], tsprice);
        sum += tsprice;
        discsum += Tdiscount(price[value[i]], discount[value[i]]);
        printf("Промежуточная сумма %d рублей\nСумма скидок %d "
          "рублей\n\n",sum, discsum);
        amount[value[i]] = 0;
    }
    printf("\nИтого к оплате %d рублей\nСумма скидок %d рублей\n", sum, discsum);
}

void main()
{
    setlocale(LC_ALL, "Rus");
    srand((unsigned)time(0));
    PriceDiscount();
    Scan();
    Receipt();
}