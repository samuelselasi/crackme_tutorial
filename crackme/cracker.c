#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

/**
 * main - Entry point
 * @argc: wordlist
 * @argv: hash
 * Return: Password
 */

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <hash>\n", argv[0]);
		return (1);
	}

    /* Read in the hash value */
    char* pass_hash = argv[1];

    /* Open the wordlist file */
    char* wordlist_path = "./wordlist.txt";
    FILE* pass_file = fopen(wordlist_path, "r");
    if (pass_file == NULL)
    {
	    printf("[!] No such file at that path\n");
	    return (1);
    }

    /* Allocate a buffer to hold each line of the wordlist */
    char word[1024];

    /* Iterate through the wordlist */
    while (fgets(word, sizeof(word), pass_file))
    {
        /* Remove the newline character at the end of the word */
        word[strcspn(word, "\n")] = 0;

        printf("[-] Trying: %s\n", word);

        /* Compute the hash of the word */
        unsigned char md5_buf[MD5_DIGEST_LENGTH];
        MD5((unsigned char*) word, strlen(word), md5_buf);

        /* Convert the hash to a hex string for comparison */
        char md5_hex[MD5_DIGEST_LENGTH * 2 + 1];
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
            sprintf(&md5_hex[i * 2], "%02x", md5_buf[i]);
        }

        /* Compare the hash to the original value */
        if (strcmp(md5_hex, pass_hash) == 0)
	{
            printf("[+] Password found: %s\n", word);
            return (0);
        }
    }

    printf("[!!] Password not in list\n");
    return (1);
}
