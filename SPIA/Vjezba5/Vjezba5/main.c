#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _Element
{
	void* a;
	int prioritet;
} Element;
void zamijeni(Element* a, Element* b)
{
	Element* tmp = b;
	*b = *a;
	*a = *tmp;
}
void popravi(Element* arr, int* size, int i)
{
	if (*size == 1) {
		printf("Single element in the heap");
	}
	else {
		int najveci = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < *size && &arr[l] > &arr[najveci])
			najveci = l;
		if (r < *size && &arr[r] > &arr[najveci])
			najveci = r;
		printf("najveci: %d\n", arr[najveci].prioritet);
		if (najveci != i) 
		{
			//zamijeni(&arr[i], &arr[najveci]);
			Element tmp = arr[najveci];
			arr[najveci] = arr[i];
			arr[i] = tmp;
			popravi(arr, size, najveci);
		}
	}
}

void add(Element* arr, int p, int* size)
{
	if (*size == 0)
	{
	arr[0].prioritet = p;
	*size += 1;
	}
	else
	{
		arr[*size].prioritet = p;
		*size += 1;
		for (int i = *size / 2-1; i >= 0; i--) {
			popravi(arr, size, i);
		}
	}
}

void print(Element* arr, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i].prioritet);
	printf("\n");
}


int main()
{
	Element arr[10000];
	int size = 0;
	add(&arr, 10, &size);
	add(&arr, 20, &size);
	add(&arr, 23, &size);
	add(&arr, 25, &size);
	add(&arr, 30, &size);
	add(&arr, 70, &size);
	add(&arr, 50, &size);
	add(&arr, 60, &size);
	add(&arr, 80, &size);
	add(&arr, 85, &size);
	print(&arr, size);
	return 0;
}