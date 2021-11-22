#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_dups(string key);

int main(int argc, string argv[])
{


    string key;

    // check if an argument is provide
    // if multiple keys provide then prompt the correct input context
    if ((argc != 2) || (argc > 2))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        // the key must and only contain 26 characters
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        key = argv[1];

        // check if the key has any dups or invalied characters
        if (check_dups(key) == false)
        {
            return 1;
        }

        //prompt the user to enter the plaintext
        string plain = get_string("plaintext: ");

        int temp, position;

        // for loop that will handle the conversion from plain to cipher
        for (int i = 0, length = strlen(plain); i < length; i++)
        {
            temp = plain[i];
            // only perform this operation if it is not space, [,] or [!]
            if ((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122))
            {
                // if the character is lower, then make sure correct case size is maintained
                if (islower(plain[i]))
                {
                    position = temp - 97;
                    plain[i] = tolower(key[position]);
                }
                else
                {
                    position = temp - 65;
                    plain[i] = toupper(key[position]);
                }
            }
        }
        // return the ciphertext when changed
        printf("ciphertext: %s\n", plain);
    }
    return 0;
}


bool check_dups(string key)
{
    // use the hashing to check for duplication
    int hash[26] = {0};
    int length = strlen(key);
    int temp, i = 0;


    while (i < length)
    {
        temp = tolower(key[i]) - 97;
        // if the character is not between a to z or A to z, then return invalid character
        if (temp < 0 || temp > 25)
        {
            printf("Invalid characters\n");
            return false;
        }

        // check hash to see if character is new or duplicate
        if (hash[temp] == 0)
        {
            hash[temp] = 1;
        }
        else
        {
            printf("Duplicate values in the key\n");
            return false;
        }
        i++;
    }
    return true;

}


