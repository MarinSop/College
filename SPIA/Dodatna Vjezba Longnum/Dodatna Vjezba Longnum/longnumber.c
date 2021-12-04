#include "longnumber.h"
#include <stdio.h>
#include <stdlib.h>

LongNumber reverse(LongNumber num)
{
	if (num == NULL)
		return num;
	LongNumber curr = num;
	LongNumber prev = NULL;
	LongNumber next;
	curr = curr->next;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	num->next = prev;
	return num;
}

LongNumber read_longnum(char* fname)
{
	FILE* f = fopen(fname,"r");
	if (!f)
		return NULL;
	
	LongNumber head = (LongNumber)malloc(sizeof(Digit));
	head->next = NULL;
	LongNumber tmp = head;
	char c;
	while ((c = fgetc(f)) != EOF)
	{
		int num = c - '0';
		if (tmp->next == NULL)
		{
			LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
			newNum->next = NULL;
			newNum->z = num;
			tmp->next = newNum;
			tmp = tmp->next;
		}
	}
	fclose(f);

	return head;
}

void write_longnum(LongNumber num, char* fname)
{
	FILE* f = fopen(fname, "w");
	if (!f)
		return;
	num = num->next;
	while (num != NULL)
	{
		fprintf(f, "%d", num->z);
		num = num->next;
	}
	fclose(f);
}

void print_longnum(LongNumber num)
{
	LongNumber tmpNum = num;
	tmpNum = tmpNum->next;
	while (tmpNum != NULL)
	{
		printf("%d", tmpNum->z);
		tmpNum = tmpNum->next;
	}
	printf("\n");
}

void delete_longnum(LongNumber num)
{
	while (num != NULL)
	{
		LongNumber tmp = num;
		num = num->next;
		free(tmp);
	}
}

LongNumber add_longnum(LongNumber a, LongNumber b)
{
	LongNumber tmpA = a;
	if(tmpA->next != NULL)
		reverse(tmpA);
	LongNumber tmpB = b;
	if (tmpB->next != NULL)
		reverse(tmpB);
	tmpA = tmpA->next;
	tmpB = tmpB->next;
	LongNumber res = (LongNumber)malloc(sizeof(Digit));
	LongNumber tmpRes = res;
	res->next = NULL;
	int sumNext = 0;
	while (tmpA != NULL)
	{
		LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
		newNum->next = NULL;
		int sum = tmpA->z + sumNext;
		sumNext = 0;
		if (tmpB != NULL)
		{
			sum += tmpB->z;
			tmpB = tmpB->next;
		}
		if (sum > 9)
		{
			sumNext = sum / 10;
			sum = sum % 10;
		}
		newNum->z = sum;
		tmpA = tmpA->next;
		tmpRes->next = newNum;
		tmpRes = tmpRes->next;
	}
	while (tmpB != NULL)
	{
		LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
		newNum->next = NULL;
		int sum = tmpB->z + sumNext;
		sumNext = 0;
		if (sum > 9)
		{
			sumNext = sum / 10;
			sum = sum % 10;
		}
		newNum->z = sum;
		tmpB = tmpB->next;
		tmpRes->next = newNum;
		tmpRes = tmpRes->next;
	}
	
	if(sumNext != 0)
	{ 
		LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
		newNum->next = NULL;
		newNum->z = sumNext;
		tmpRes->next = newNum;
	}
	reverse(a);
	reverse(b);
	reverse(res);
	return res;
}

LongNumber mul_by_digit(LongNumber num, int z)
{
	LongNumber res = (LongNumber)malloc(sizeof(Digit));
	res->next = NULL;
	LongNumber tmpRes = res;
	LongNumber tmpNum = num;
	reverse(tmpNum);
	tmpNum = tmpNum->next;
	int sumNext = 0;
	while (tmpNum != NULL)
	{
		LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
		newNum->next = NULL;
		int sum = tmpNum->z * z + sumNext;
		sumNext = 0;
		if (sum > 9)
		{
			sumNext = sum / 10;
			sum = sum % 10;
		}
		newNum->z = sum;
		tmpRes->next = newNum;
		tmpRes = tmpRes->next;
		tmpNum = tmpNum->next;
	}
	if (sumNext != 0)
	{
		LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
		newNum->next = NULL;
		newNum->z = sumNext;
		tmpRes->next = newNum;
	}
	reverse(res);
	return res;
}

LongNumber mul_by_pow10(LongNumber num, int pow)
{
	LongNumber res = (LongNumber)malloc(sizeof(Digit));
	res->next = NULL;
	LongNumber tmpRes = res;
	LongNumber tmpNum = num->next;
	while (tmpNum != NULL)
	{
		LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
		newNum->next = NULL;
		newNum->z = tmpNum->z;
		tmpRes->next = newNum;
		tmpRes = tmpRes->next;
		tmpNum = tmpNum->next;
	}
	for (int i = 0; i < pow; i++)
	{
		LongNumber newNum = (LongNumber)malloc(sizeof(Digit));
		newNum->next = NULL;
		newNum->z = 0;
		tmpRes->next = newNum;
		tmpRes = tmpRes->next;
	}
	return res;
}

LongNumber mul_longnum(LongNumber a, LongNumber b)
{
	LongNumber res = (LongNumber)malloc(sizeof(Digit));
	res->next = NULL;
	LongNumber tmpB = b;
	reverse(tmpB);
	tmpB = tmpB->next;
	int pow = 0;
	while (tmpB != NULL)
	{
		LongNumber tmpRes = mul_by_pow10(a, pow);
		tmpRes = mul_by_digit(tmpRes, tmpB->z);
		res = add_longnum(res, tmpRes);
		pow += 1;
		tmpB = tmpB->next;
	}
	return res;
}
