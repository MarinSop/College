#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Object3D
{
	struct Trokut* t;
	int n;
};
struct Vrh
{
	float x, y, z;
};

struct Trokut
{
	float n[3];
	struct Vrh v[3];
	unsigned short color;
};


void createTriangle(struct Trokut* t)
{
	printf("Unesite normale i->j->k\n");
	scanf(" %f %f %f", &t->n[0], &t->n[1], &t->n[2]);
	printf("Unesite kordinate x->y->z\n");
	for (int i = 0; i < 3; i++)
	{
		scanf(" %f %f %f", &t->v[i].x, &t->v[i].y, &t->v[i].z);
	}
}
void createObject(struct Object3D* o)
{
	printf("Koliko trokuta?\n");
	scanf("%d", &o->n);
	o->t = (struct Trokut*)malloc(sizeof(struct Trokut) * o->n);
	for (int i = 0; i < o->n; i++)
	{
		createTriangle(&o->t[i]);
	}
}


void createTxtStl(char* str, struct Object3D* o)
{
	FILE* f = fopen(str, "w");
	if (!f)
		return;
	fprintf(f,"solid Objekt\n");
	for (int i = 0; i < o->n; i++)
	{
		fprintf(f, "  facet normal %f %f %f\n", o->t[i].n[0], o->t[i].n[1], o->t[i].n[2]);
		fprintf(f, "    outer loop\n");
		for (int j = 0; j < 3; j++)
		{
			fprintf(f, "      vertex %f %f %f\n", o->t[i].v[j].x, o->t[i].v[j].y, o->t[i].v[j].z);
		}
		fprintf(f, "    endloop\n");
		fprintf(f, "  endfacet\n");
	}
	fprintf(f, "endsolid");
	fclose(f);
}

void readTxtStl(char* str,struct Object3D* o)
{
	FILE* f = fopen(str, "r");
	if (!f)
		return;
	char temp[50];
	o->n = 0;
	while (fgets(temp,50,f) != NULL)
	{
		if (strstr(temp, "facet normal") != NULL)
			o->n += 1;
	}
	rewind(f);
	o->t = (struct Trokut*)malloc(sizeof(struct Trokut) * o->n);
	int tCounter = 0;
	int vCounter = 0;
	while (fgets(temp, 50, f) != NULL)
	{
		char* tempStrStr;
		if ((tempStrStr = strstr(temp, "facet normal")) != NULL)
			sscanf(tempStrStr, "facet normal %f %f %f", &o->t[tCounter].n[0], &o->t[tCounter].n[1], &o->t[tCounter].n[2]);
		else if ((tempStrStr = strstr(temp, "vertex")) != NULL)
		{
			sscanf(tempStrStr, "vertex %f %f %f", &o->t[tCounter].v[vCounter].x, &o->t[tCounter].v[vCounter].y, &o->t[tCounter].v[vCounter].z);
			vCounter++;
		}
		else if (strstr(temp, "endloop") != NULL)
		{
			vCounter = 0;
			tCounter++;
		}
	}
	fclose(f);

}

void deleteObject3D(struct Object3D* o)
{
	free(o->t);
	free(o);

}

void printObject3D(struct Object3D* o)
{
	printf("solid Objekt\n");
	for (int i = 0; i < o->n; i++)
	{
		printf("  facet normal %f %f %f\n", o->t[i].n[0], o->t[i].n[1], o->t[i].n[2]);
		printf("    outer loop\n");
		for (int j = 0; j < 3; j++)
		{
			printf("      vertex %f %f %f\n", o->t[i].v[j].x, o->t[i].v[j].y, o->t[i].v[j].z);
		}
		printf("    endloop\n");
		printf("  endfacet\n");
	}
	printf("endsolid");
}


void createBinStl(char* str, struct Object3D* o)
{
	char* head = (char*)malloc(sizeof(char) * 80);
	for (int i = 0; head[i] != '\0'; i++)
	{
		head[i] = '0';
	}
	unsigned int triNum = o->n;
	FILE* f = fopen(str, "wb");
	if (!f)
		return;
	fwrite(&head, sizeof(head), 1, f);
	//fprintf(f, "%s", head);
	fwrite(&triNum, sizeof(unsigned int), 1, f);
	for (int i = 0; i < triNum; i++)
	{
		fwrite(&o->t[i].n, sizeof(o->t[i].n), 1, f);
		for (int j = 0; j < 3; j++)
		{
			fwrite(&o->t[i].v[j], sizeof(o->t[i].v[j]), 1, f);
		}
		unsigned short shrt = 0;
		fwrite(&shrt, sizeof(unsigned short), 1, f);
	}
}



int main()
{
	struct Object3D obj;
	//createObject(&obj);
	readTxtStl("primjertxt.stl", &obj);
	//createTxtStl("tekst.stl", &obj);
	//printObject3D(&obj);
	createBinStl("bin.stl", &obj);
	//deleteObject3D(obj);

	return 0;
}