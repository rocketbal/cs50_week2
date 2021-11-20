
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sent(string text);
int assess_grade(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sent(text);
    int grade = assess_grade(letters, words, sentences);


    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);
    if (grade >= 1 && grade <= 16)
    {
        printf("%i grade(s)\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
    return 0;
}


int count_letters(string text)
{
    //function that cals number of letters
    int length = strlen(text);
    int letters = 0, i = 0;
    while (i < length)
    {

       if (isalpha(text[i]))
       {

           letters++;
       }

       i++;


    }
    return letters;

}

int count_words(string text)
{
    // calculate the number of words
    int length = strlen(text);
    int words = 0, i = 0;
    char c[1];
    c[0] = 'a';
    while (i < length)
    {
        // if there is space, (.), (!) or (?), use that to figure out new word
        if (isspace(text[i]) || text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            //when starting a new sentence, there is space after period (.)
            // In that case, dont count the space as end of word
            if (c[0] != 46 && c[0] != 33 && c[0] != 63)
            {
                words++;
            }
            c[0] = text[i];
        }
        i++;
    }

    return words;
}


int count_sent(string text)
{
    // calculate number of sentences
    int length = strlen(text);
    int sentence = 0, i = 0;
    while (i < length)
    {
        // use (.), (!) or (?) to determine end of the sentence
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence++;
        }
        i++;
    }

    return sentence;


}

int assess_grade(int letters, int words, int sentences)
{
    // cast double to the int inorder to pervent loss of decimals after division
    double L = ((double) letters / words) * 100.0;
    double S = ((double) sentences / words) * 100.0;
    double index = 0.0;
    // Use order to operations with paranthesis to compute correctly
    index = (0.0588 * L) - (0.296 * S) - 15.8;

    // round index at the end and cast it to int
    return (int) round(index);
}

