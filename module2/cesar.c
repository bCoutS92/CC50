#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int k1, string k2[])
{
    if (k1 != 2)
    {
        printf("Código escrito de forma incorreta (./caesar key)\n");
        return 1;
    }
    else
    {
        for(int a = 0, n = strlen(k2[1]); a < n; a++)
        {
            if(!isdigit(k2[1][a]))
            {
                printf("Código escrito de forma incorreta (./caesar key)\n");
                return 1;
            }
        }
    }
    int key = atoi(k2[1]);
    string plaintext = get_string("Plaintext: ");
    printf("Chiphertext: ");
    for(int a = 0, n = strlen(plaintext); a < n; a++)
    {
        if(isalpha(plaintext[a]))
        {
            if(isupper(plaintext[a]))
            {
                int A = (plaintext[a] - 'A' + key) % 26 + 'A';
                printf("%c", A);
            }
            else if(islower(plaintext[a]))
            {
                int B = (plaintext[a] - 'a' + key) % 26 + 'a';
                printf("%c", B);
            }
        }
        else
        {
            printf("%c", plaintext[a]);
        }
    }
    printf("\n");
}