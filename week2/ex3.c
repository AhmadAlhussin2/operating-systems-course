#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long toDec(long long num,int base)  //function to convert given number from base "base" to base "10"
{
    char numAsString[19]="";
    sprintf(numAsString,"%lld",num);
    long long ret=0,basePower=1; // the number to be returned, the power of base during iterations
    for (int i=strlen(numAsString)-1; i>=0; i--)
    {
        ret=ret+(numAsString[i]-'0')*basePower; // the number can be written as base^0*digit[0] + base^1*digit[1] ...
        basePower=basePower*base; // increase the base power
    }
    return ret;
}

char ans[66];
void convert(long long num,int base1,int base2)  // function to convert a number from base1 to base 2 and store the answer in "ans"
{
    if (base1>10||base1<2||base2>10||base2<2)
    {
	strcpy(ans,"cannot convert!");
	return ;
    }
    strcpy(ans,""); //clear the ans
    char numAsString[19]="";
    sprintf(numAsString,"%lld",num); // convert the number to string
    for (int i=0; i<strlen(numAsString); i++)
    {
        if (numAsString[i]-'0'>=base1)  // given number is not in the correct form
        {
            strcpy(ans,"cannot convert!");
            return ;
        }
    }
    num=toDec(num,base1); // convert the number to decimal format
    sprintf(numAsString,"%lld",num);
    int len=0;
    while (num)
    {
        ans[len]=(char)(num%base2+'0'); // convert from decimal to the given base
        num/=base2;
        len++;
    }
    ans[len]='\0';
    for (int i=0; i<len/2; i++) //reverse the string
    {
        char tmp=ans[i];
        ans[i]=ans[strlen(ans)-i-1];
        ans[strlen(ans)-i-1]=tmp;
    }
}


int main()
{
    long long num;
    int base1,base2;
    scanf("%lld %d %d",&num,&base1,&base2);
    convert(num,base1,base2);
    fputs(ans,stdout);
    return 0;
}

