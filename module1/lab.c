#include <cs50.h>
#include <stdio.h>

int main(void)
{
      int x, y;
      int anos = 0;
      // TODO: Solicite o valor inicial ao usuário
      do
      {
      x = get_int("População inicial: ");
      }
      while (x < 9);
     // TODO: Solicite o valor final ao usuário
      do
      {
      y = get_int("População final: ");
      }
      while (y < x);
     // TODO: Calcule o número de anos até o limite
      while (x < y)
      {
            x = x + (x/3) - (x/4);
            anos++;
      }
     // TODO: Imprima o número de anos
      printf("Years: %i\n", anos);
}