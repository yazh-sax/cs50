#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int encrypter(int u, int l);

int main(int argc, char *argv[])
{

    // Reject input of incorrect length
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key (26 letters)\n");
        return (1);
    }

    // Reject non-letter inputs in key
    for (int i = 0; i < 26; i++)
    {
        if (isupper(argv[1][i]) == 0 && islower(argv[1][i]) == 0)
        {
            printf("Key must only contain letters\n");
            return (1);
        }
    }

    // Reject duplicate characters
    for (int counter = 0; counter < 26; counter++)
    {
        int a = argv[1][counter];

        for (int counter_1 = counter + 1; counter_1 < 27; counter_1++)
        {
            int b = argv[1][counter_1];
            if (b == a)
            {
                printf("Key must only contain unique letters\n");
                printf("%d\n", counter_1);
                return (1);
            }
        }
    }



    // Create difference array
    int offsets[26];
    for (int counter = 0; counter < 26; counter++)
    {
        if (islower(argv[1][counter]))
        {
            offsets[counter] = argv[1][counter] - (97 + counter);
        }
        if (isupper(argv[1][counter]))
        {
            offsets[counter] = argv[1][counter] - (65 + counter);
        }
    }

    // Prompt for inputs
    string plaintext = get_string("plaintext: ");
    int input_length = strlen(plaintext);

    // Encrypt
    char ciphertext[input_length];

    for (int counter = 0; counter < input_length; counter++)
    {
        if (isupper(plaintext[counter]) || islower(plaintext[counter]))
        {
            if (isupper(plaintext[counter]))
            {
                ciphertext[counter] = plaintext[counter] + offsets[plaintext[counter] - 65];
            }
            else
            {
                ciphertext[counter] = plaintext[counter] + offsets[plaintext[counter] - 97];
            }
        }
        else
        {
            ciphertext[counter] = plaintext[counter];
        }
    }
    
    // Fixes bug where additional characters are added to end of output
    ciphertext[input_length ] = '\0';

    // Output ciphertext
    printf("ciphertext: %s\n", ciphertext);




}

