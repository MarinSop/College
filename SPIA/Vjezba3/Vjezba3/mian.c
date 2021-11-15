#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* presjek(int* a, int* b, int nA,int nB,int* nC)
{
	clock_t start = clock();
	printf("Start presjek %ld \n", start);
	int* pres = (int*)malloc(*nC *sizeof(int));
	int k = 0;
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < nB; j++)
		{
			if (a[i] == b[j])
			{
				*nC += 1;
				pres = (int*)realloc(pres, *nC*sizeof(int));
				pres[k] = a[i];
				k++;
				break;
			}
		}
	}
	clock_t end = clock();
	printf("Kraj presjek %ld \n", end);
	double total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Ukupno presjek %f \n", total);
	return pres;
}


int* presjek_jedan_sortiran(int* a, int* b, int nA, int nB, int* nC)
{
	clock_t start = clock();
	printf("Start presjek_jedan_sortiran %ld \n", start);
	qsort(b,nB,sizeof(int),cmpfunc);
	int* pres = (int*)malloc(*nC * sizeof(int));
	int j = 0;
	for (int i = 0; i < nA; i++)
	{
		int key = a[i];
		int* num = (int*)bsearch(&key, b, nB, sizeof(int), cmpfunc);
		if (num != NULL)
		{
		*nC += 1;
		pres = (int*)realloc(pres, *nC * sizeof(int));
		pres[j] = *num;
		j++;
		}
	}

	clock_t end = clock();
	printf("Kraj presjek_jedan_sortiran %ld \n", end);
	double total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Ukupno presjek_jedan_sortiran %f \n", total);

	return pres;
}



int* presjek_oba_sortirana(int* a, int* b, int nA, int nB, int* nC)
{
	clock_t start = clock();
	printf("Start presjek_oba_sortirana %ld \n", start);
	qsort(a, nA, sizeof(int), cmpfunc);
	qsort(b, nB, sizeof(int), cmpfunc);
	int* pres = (int*)malloc(*nC * sizeof(int));
	int k = 0;
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < nB; j++)
		{
			if(a[i] == b[j])
			{
				*nC += 1;
				pres = (int*)realloc(pres, *nC * sizeof(int));
				pres[k] = a[i];
				k++;
				break;
			}
		}
	}

	clock_t end = clock();
	printf("Kraj presjek_oba_sortirana %ld \n", end);
	double total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Ukupno presjek_oba_sortirana %f \n", total);
	return pres;
}


int main()
{
	srand(time(NULL));
	int nA;
	int nB;
	int nC = 0;
	int nD = 0;
	int nE = 0;
	printf("Unesi duzinu niza A i B: ");
	scanf("%d %d", &nA, &nB);
	int* nizA = generiraj(nA);
	int* nizB = generiraj(nB);
	shuffle(nizA, nA);
	shuffle(nizB, nB);
	int* nizC = presjek(nizA, nizB, nA, nB, &nC);
	int* nizD = presjek_jedan_sortiran(nizA, nizB, nA, nB, &nD);
	int* nizE = presjek_oba_sortirana(nizA, nizB, nA, nB, &nE);
	//for (int i = 0; i < nA; i++)
	//{
	//	printf("[%d]", nizA[i]);
	//}
	//printf("\n");
	free(nizA);

	//for (int i = 0; i < nB; i++)
	//{
	//	printf("[%d]", nizB[i]);
	//}
	//printf("\n");
	free(nizB);

	//for (int i = 0; i < nC; i++)
	//{
	//	printf("[%d]", nizC[i]);
	//}
	//printf("\n");
	free(nizC);

	//for (int i = 0; i < nD; i++)
	//{
	//	printf("[%d]", nizD[i]);
	//}
	//printf("\n");
	free(nizD);

	//for (int i = 0; i < nE; i++)
	//{
	//	printf("[%d]", nizE[i]);
	//}
	//printf("\n");
	free(nizE);


	return 0;
}