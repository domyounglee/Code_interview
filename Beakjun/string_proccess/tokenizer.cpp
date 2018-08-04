//https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Geeks for Geeks";
 
    // Returns first token 
    char *token = strtok(str, " ");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
 
    return 0;
}