#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
int main()
{
	char plain[10],cipher[10];
	int key,i,length;
	int result;
	printf("\n enter the plain text:");
	scanf("%s",&plain);
	printf("\n enter the key value:");
	scanf("%d",&key);
	printf("\n\n\t plaintext:%s",plain);
	printf("\n\n\t encrypted text:");
	length = strlen(plain);
	for(i=0;i<length;i++)
	{
		cipher[i]=plain[i]+key;
		if(isupper(plain[i])&&(cipher[i]>='z'))
		cipher[i]=cipher[i]-26;
		if(islower(plain[i])&&(cipher[i]>='z'))
		cipher[i]=cipher[i]-26;
		printf("%c",cipher[i]);
	}
	printf("\n\n\t after decryption:");
	for(i=0;i<length;i++)
	{
		plain[i]=cipher[i]-key;
		if(isupper(cipher[i])&&(plain[i]<='A'-1))
		plain[i]=plain[i]+26;
		if(islower(cipher[i])&&(plain[i]<='a'-1))
		plain[i]=plain[i]+26;
		printf("%c",plain[i]);
	}
	return 0;
}
