#include <stdio.h>
#include <math.h>
#include <cs50.h>

float getValue(void);
int coins(int cents);

int main(void)
{
    float owed = getValue();
    int cents = round(owed * 100);
    printf("%d\n", coins(cents));
}

//Metodo que Conta o menor numero de moedas necessarias para dar o troco:
int coins(int cents)
{
    int count = 0;

    // loop decrescendo por centavos da maior moeda possivel até centavos = 0
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            count++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            count++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            count++;
        }
        else
        {
            cents -= 1;
            count++;
        }
    }
    return count;
}

//Pede ao usuario por um valor valido de troco:
float getValue(void)
{
    float change;
    do
    {
        change = get_float("Troco devido: ");
    }
    while (change < 0.00);

    return change;
}