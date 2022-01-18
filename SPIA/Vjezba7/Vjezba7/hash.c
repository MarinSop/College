#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	newTable->size = size;
	newTable->load = 0;
	newTable->table = (Bin**)malloc(sizeof(Bin*));
	Bin* bin = (Bin*)malloc(sizeof(Bin));
	bin->word = NULL;
	bin->next = NULL;
	(*newTable->table) = bin;
	Bin* tmp = (*newTable->table);
	for (int i = 0; i < size-1; i++)
	{
		Bin* newBin = (Bin*)malloc(sizeof(Bin));
		newBin->word = NULL;
		newBin->next = NULL;
		tmp->next = newBin;
		tmp = tmp->next;
	}
	return newTable;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	int index = hash(word) % ht->size;
	ht->load += 1;
	Bin* tmp = (*ht->table);
	for (int i = 0; i != index; i++)
	{
		tmp = tmp->next;
	}
	tmp->word = word;
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	Bin* tmp = (*ht->table);
	while (tmp != NULL)
	{
		if (tmp->word == word)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	Bin* tmp = (*ht->table);
	while (tmp != NULL)
	{
		free(tmp->word);
		Bin* del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(ht->table);
	free(ht);
}