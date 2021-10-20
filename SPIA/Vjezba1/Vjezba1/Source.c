#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mystrlen(char* str)
{
	int i = 0;
	int len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}

void mystrcpy(char* strA, char* strB)
{
	int i = 0;
	while (strB[i] != '\0')
	{
		strA[i] = strB[i];
		++i;
	}
	strA[i] = '\0';
}

void mystrcat(char* strA, char* strB)
{
	int i = 0;
	int j = 0;
	int bl = 0;
	while (1)
	{
		if (!bl)
		{
			if (strA[i] == '\0')
			{ 
				bl = 1;
				continue;			
			}
		}
		else
		{
			if (strB[j] == '\0')
			{
				strA[i] = '\0';
				break;
			}
			strA[i] = strB[j];
			++j;
		}
		++i;
	}

}

void reverse(char* strA, char* strB)
{
	int straLen = mystrlen(strA)-1;
	int i = 0;
	while (1)
	{
		if (i == straLen+1)
		{
			strB[i] = '\0';
			break;
		}
		strB[i] = strA[straLen - i];
		++i;
	}

}

char* mystrstr(char* strA, char* strB)
{
	int p = 0;
	int bl = 0;
	int j = 0;
	for (int i = 0; strA[i] != '\0'; i++)
	{
		if (bl == 0)
		{
			if (strA[i] == strB[j])
			{
				bl = 1;
				p = strA + i;
				j++;
				continue;
			}
		}
		else
		{
			if (strB[j] != '\0')
			{
				if (strA[i] == strB[j])
					++j;
				else
				{
					p = NULL;
					bl = 0;
					j = 0;
				}
			}
			else
				break;
		}
	}
	return p;
}

int mystrcmp(char* strA, char* strB)
{
	int res = 0;
	for (int i = 0; strA[i] != '\0'; i++)
	{
		if (strA[i] > strB[i])
		{
			res = strA[i] - strB[i];
			break;
		}
		else if (strA[i] < strB[i])
		{
			res = strA[i] - strB[i];
			break;
		}
	}
	return res;
}

int main()
{
	char strA[10] = "abcd";
	char strB[10] = "abcd";
	char strC[10] = "hellowrld";
	char strD[10] = "ello";
	printf("Strcmp : %d\n", mystrcmp(&strA, &strB));
 	int duzinaStrA = mystrlen(strA);
	mystrcat(&strA, &strB);
	printf("Spojeni stringovi: %s\n", strA);
	printf("Duzina prvog stringa: %d\n", duzinaStrA);
	mystrcpy(&strA, &strB);
	printf("Ispis kopiranog stringa: %s\n", strA);
	reverse(&strA, &strB);
	printf("Ispis reverse stringa: %s\n", strB);
	char* res = mystrstr(&strC, &strD);
	printf("Pokazivac je : %s\n", res);


	return 0;
}