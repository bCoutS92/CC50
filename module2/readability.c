#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letters = 0;
int words = 0;
int sentences = 0;

int main (void){

    string input = get_string("Texto: ");

    int n = strlen(input);
    int i = 0;

   do{
    i++;
    if (isalpha(input[i]) || input[i] == '\0'){
        letters++;
    }
    if (isblank(input[i]) || input[i] == '\0'){
        words++;
    }
    if (input[i] == '!' || input[i] == '.' || input[i] == '?'){
        sentences++;
    }
   }
   while (i < n);

   float L =  letters / (float) words * 100;
   float S =  sentences / (float) words * 100;

   float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    if (grade >= 1 && grade <= 16){
        printf("Grade %i\n", grade);
    }
    else if (grade < 1){
        printf("Before Grade 1\n");
    }
    else if (grade > 16){
        printf("Grade 16+\n");
    }

}