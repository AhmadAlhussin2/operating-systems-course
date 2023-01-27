#include <stdio.h>
#include <string.h>
#include <stdio.h>

int count(char str[],char c)
{
    int cnt=0; // number to be returned
    for (int i=0; i<strlen(str); i++)
    {
        if (str[i]==c) // if we find an occurance increase the counter
        {
            cnt++;
        }
    }
    return cnt;
}

void countAll(char str[])
{
    for (int i=0; i<strlen(str); i++)
    {
        if (str[i]>='A'&&str[i]<='Z') // if the character is in upper case
        {
            str[i]=(char)(str[i]-'A'+'a'); // convert the character to lower case
        }
    }
    for (int i=0; i<strlen(str); i++)
    {
        printf("%c:%d",str[i],count(str,str[i])); // count the occurrences of character number "i"
        if (i!=strlen(str)-1) // if we have not finished all characters print separator
        {
            printf(", ");
        }
    }
    printf("\n");
}

int main()
{
    char str[257];
    fgets(str,257,stdin);
    int lstidx=strlen(str)-1;
    if (str[lstidx]=='\n') // erase the new line char in the end of the string
    {
        str[lstidx]='\0';
    }
    countAll(str);
}

