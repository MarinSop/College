#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	BSTree tree = (BSTree)malloc(sizeof(Node));
	tree->word = NULL;
	tree->left = tree->right = NULL;
	return tree;
}

void AddNode(BSTree* bst, char* word)
{
	// Rekurzivno se traži mjesto za novi èvor u stablu. Ako rijeè postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivaè.
	if ((*bst) == NULL || (*bst)->word == NULL) {
		BSTree novi = (BSTree)malloc(sizeof(Node));
		novi->word = word;
		novi->left = novi->right = NULL;
		*bst = novi;
		return;
	}
	if (strcmp((*bst)->word, word) == 0)
		return;
	if (strcmp((*bst)->word, word) > 0)
	{
		//if ((*bst)->left == NULL)
		//{
		//	BSTree novi = (BSTree)malloc(sizeof(Node));
		//	novi->word = word;
		//	novi->left = novi->right = NULL;
		//	(*bst)->left = novi;
		//	return;
		//}
		//else
		//{
			AddNode(&(*bst)->left, word);
			return;
		//}
	}
	if (strcmp((*bst)->word, word) < 0)
	{
		//if ((*bst)->right == NULL)
		//{
		//	BSTree novi = (BSTree)malloc(sizeof(Node));
		//	novi->word = word;
		//	novi->left = novi->right = NULL;
		//	(*bst)->right = novi;
		//	return;
		//}
		//else
		//{
			AddNode(&(*bst)->right, word);
			return;
		//}
	}
}



int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if (bst == NULL)
		return 1;
	int left = BSTHeight(bst->left) + 1;
	int right = BSTHeight(bst->right) + 1;
	return left > right ? left : right;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeèi u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, èvor, desno dijete)
	if (bst == NULL)
		return;
	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rijeè po rijeè iz stabla u tekstualnu datoteku. Rijeèi su odvojene razmakom.
	// Pre-order šetnja po stablu (ttenutni èvor pa djeca)
	if (bst == NULL)
		return;
	fprintf(fd, " %s ",bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam èvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)
	if (bst == NULL)
		return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// Uèitava rijeè po rijeè iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijeè duplicirati sa strdup().
	char buffer[1024];
	BSTree bst = NewBSTree();
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		AddNode(&bst, _strdup(buffer));
	}
	return bst;
}
