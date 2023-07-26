#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Para validacao da chave
bool is_valid_key(string s);

int main(int argc, string argv[])
{
    //Verifica se tem + de 1 argumento de linha de comando
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!is_valid_key(argv[1]))
    {
        //Mensagem de erro em caso de nao ter o nro de argumentos necesarios.
        printf("A chave deve conter 26 caracteres.\n");
        return 1;
    }
    //Solicita um texto simples ao usuário
    string s = get_string("Plaintext: ");
    string difference = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
        difference [i - 'A'] = toupper(difference [i - 'A']) - i; // 'J' - 'A'
    printf("ciphertext: ");
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if(isalpha(s[i]))
            s[i] = s[i] + difference[s[i] - (isupper(s[i]) ? 'A' : 'a')];
        // s[i] -> 'J' + diff
        printf("%c", s[i]);
    }
    printf("\n");
}
bool is_valid_key(string s)
{
    // Valida que o texto fornecido tenha 26 letras, caso contrario repita o processo
    int len = strlen(s);
    if (len != 26)
        return false;

    // valida que a frequencia é igual a 26 caracteres
    int freq[26] = {0};

    // Valida se o conteudo inserido esta em formato alfabeto, caso contrario repita.
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
            return false;
        // aqui guardamos apenas letras maiusculas
        int index = toupper(s[i]) - 'A';
        if(freq[index] > 0)
            return false;
        freq[index]++;
    }

    return true;
}