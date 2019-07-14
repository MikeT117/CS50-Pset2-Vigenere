#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check that an argument(key) has been provided when executing the porgram.
    if (argc != 2)
    {
        printf("Please run the program with a key e.g. ./vigenere abcde\n");
        return 1;
    };

    string k = argv[1];
    //Iterate over eacj character and ensure it does not contain numbers.
    for (int l = 0, m = strlen(k); l < m; l++)
    {
        if (k[l] >= 48 && k[l] <= 57)
        {
            printf("Your plaintext must not contain number, Please try again.\n");
            return 1;
        }
    }

    string s = get_string("Plaintext: ");

    int j = 0;
    int i = 0;
    int t = strlen(s);
    //interate over each character.
    while (i < t)
    {
        //If th eloop has executed the same number of times as the length of the key then loop to the start of the key and continue.
        if (j == strlen(k))
        {
            j = 0;
        }
        //Determine the case of the character.
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = ((s[i] - 'a' + (tolower(k[j]) - 'a')) % 26) + 'a';
            j++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = ((s[i] - 'A' + (tolower(k[j]) - 'a')) % 26) + 'A';
            j++;
        }
        i++;
    }
    printf("ciphertext: %s\n", s);

    return 0;

}