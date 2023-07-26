#include <stdio.h>
#include <cs50.h>

void pir(int n);
void branco(int n);

int main(void)
{
    // altura da pirâmide
    int altura;
    do
    {
    altura = get_int("Escolha a altura da piramide [1 a 8]: ");
    }
    while (altura < 1 || altura > 8);
    // contador para quantidade de ###
    int p = 1;
    //  contador para quantidade de espaçoes em branco
    int dis = altura - 1;
    // funçao para cada linha
    for (int c = altura; c > 0; c --)
    {
      // abstração para colocar espaços em branco
      branco(dis);
      // abstração para colocar ####
      pir(p);
      p ++;
      dis --;
      printf("\n");
    }
}
// abstração para ###
void pir(int n)
{
    for(int a = 0; a < n; a ++)
    {
         printf("#");
    }
}
// abstração para espaço em branco
void branco(int n)
{
    for(int a = 0; a < n; a ++)
    {
         printf(" ");
    }
} 