#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // linhas
    for (int i = 0; i < height; i++)
    {
        // colunas
        for (int j = 0; j < width; j++)
        {
            float vermelho = image[i][j].rgbtRed;
            float azul = image[i][j].rgbtBlue;
            float verde = image[i][j].rgbtGreen;

            // media
            float media = 0;
            media = round((vermelho + azul + verde) / 3);

            image[i][j].rgbtRed = media;
            image[i][j].rgbtBlue = media;
            image[i][j].rgbtGreen = media;

        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagem[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            float sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            float sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            float sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // atualiza o pixel se ultrapassar 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            imagem[i][j].rgbtRed = sepiaRed;
            imagem[i][j].rgbtGreen = sepiaGreen;
            imagem[i][j].rgbtBlue = sepiaBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imagem[i][j];
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // linhas
    for (int i = 0; i < height; i++)
    {

        // colunas
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE imagem = image[i][j];
            int x = width - j - 1;
            image[i][j] = image[i][x];
            image[i][x] = imagem;
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagem[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagem[i][j] = image[i][j];
        }
    }

    // linhas
    for (int i = 0; i < height; i++)
    {
        // colunas
        for (int j = 0; j < width; j++)
        {
            float soma_vermelho, soma_azul, soma_verde;
            int c;

            soma_vermelho = 0;
            soma_azul = 0;
            soma_verde = 0;
            c = 0;

            // Para cada pixel, loop vertical e horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int a = i + k;
                    int b = j + l;

                    // Verifica se o pixel está fora das linhas e colunas
                    if (!(a < 0 || a >= height || b < 0 || b >= width))
                    {
                        soma_vermelho = soma_vermelho + imagem[a][b].rgbtRed;
                        soma_azul = soma_azul + imagem[a][b].rgbtBlue;
                        soma_verde = soma_verde + imagem[a][b].rgbtGreen;
                        c = c + 1;
                    }
                }
            }

            // Obtém imagem média e desfocada
            float y = round(soma_vermelho / c);
            float w = round(soma_azul / c);
            float z = round(soma_verde / c);

            image[i][j].rgbtRed = y;
            image[i][j].rgbtBlue = w;
            image[i][j].rgbtGreen = z;

        }
    }
    return;
}