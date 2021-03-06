﻿#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10000
#define PMAX 9999
#define PMIN 1

int code[N], price[N], discount[N],
amount[N], value[N];
int num;
char scode[N][5];
char name[40][16] =
{
    "Параметр_А0", "Параметр_А1", "Параметр_А2", "Параметр_А3", "Параметр_А4",
    "Параметр_А5", "Параметр_А6", "Параметр_А7", "Параметр_А8", "Параметр_А9",
    "параметр_Б0", "параметр_Б1", "параметр_Б2", "параметр_Б3", "параметр_Б4",
    "параметр_Б5", "параметр_Б6", "параметр_Б7", "параметр_Б8", "параметр_Б9",
    "имя_0", "имя_1", "имя_2", "имя_3", "имя_4", "имя_5", "имя_6", "имя_7",
    "имя_8", "имя_9", "вид_0", "вид_1", "вид_2", "вид_3", "вид_4", "вид_5",
    "вид_6", "вид_7", "вид_8", "вид_9"
};


void PriceDiscount()
{
    int i = 0, j = 0;
    while (i < N)
        discount[i++] = rand() % 50 + 1;
    while (j < N)
        price[j++] = rand() % (PMAX - 1) + PMIN;
}

int Discounted(int tprice, int tdisc)
{
    return (int)((long)tprice * (100 - tdisc) * 0.01);
}

int Tdiscount(int tprice, int tdisc)
{
    return (int)(tprice * tdisc * 0.01);
}

char* GetName(int tcode, int pos)
{
    int res;
    res = 10 * pos;
    if (pos == 0)
    {
        res += (int)(tcode * 0.001);
    }
    if (pos == 1)
    {
        res += (int)(tcode * 0.01) % 10;
    }
    if (pos == 2)
    {
        res += (int)(tcode * 0.1) % 10;
    }
    if (pos == 3)
    {
        res += tcode % 10;
    }
    return name[res];
}

void Scan()
{
    int i;
    do
    {
        int tamount, c;
        i = 0;
        printf("Введите штрих-код товара (0001 – 9999)\n"
          "Введите 0000 для перехода к расчёту стоимости\n");
        scanf("%s", scode[num]);
        if (num == 0 && (!strcmp(scode[num], "0000") ||
            !strcmp(scode[num], "000") || !strcmp(scode[num], "00") ||
            !strcmp(scode[num], "0")))
            continue;
        if (!strcmp(scode[num], "0000") || !strcmp(scode[num], "000")
            || !strcmp(scode[num], "00") || !strcmp(scode[num], "0"))
            i = 1;
        if (scode[num][0] == '\0' || scode[num][1] == '\0' ||
          scode[num][2] == '\0' || scode[num][3] == '\0')
            continue;
        scode[num][4] = '\0';
        code[num] = atoi(scode[num]);
        if (code[num] < 1 || code[num] > 9999)
            continue;
        if(strcmp(scode[num], "0000"))
        {
            printf("\nКод %04d\n%s %s %s %s\nСтомость %d рублей\n"
              "Скидка %d%%\nСтоимость со скидкой %d рублей\n\n",
              code[num], GetName(code[num], 0), GetName(code[num], 1),
              GetName(code[num], 2), GetName(code[num], 3),
              price[code[num]], discount[code[num]],
              Discounted(price[code[num]], discount[code[num]]));
        }
        printf("Выберите количество товаров данного вида либо нажмите 0, "
          "чтобы не добавлять\n");
        do
        {
            scanf("%d", &tamount);
        } while (tamount < 0);
        getchar();
        if (tamount == 0)
            continue;
        amount[code[num]] += tamount;
        for (c = 0; c < tamount; c++)
        {
            value[num] = code[num];
            num++;
        }
        //value[num] = code[num];
        //num++;
    } while (i == 0);
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
        printf("Код %04d\n%s %s %s %s\nСтоимость (со скидкой) %d рублей\n"
          "Количество %d штук(а)\nСуммарно %d рублей\n",
          value[i], GetName(value[i], 0), GetName(value[i], 1),
          GetName(value[i], 2), GetName(value[i], 3),
          tprice, amount[value[i]], tsprice);
        sum += tsprice;
        discsum += Tdiscount(price[value[i]], discount[value[i]]);
        printf("Промежуточная сумма %d рублей\nСумма скидок %d "
          "рублей\n\n", sum, discsum);
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