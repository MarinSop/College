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
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.
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
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
	if (bst == NULL)
		return 1;
	int left = BSTHeight(bst->left) + 1;
	int right = BSTHeight(bst->right) + 1;
	return left > right ? left : right;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)
	if (bst == NULL)
		return;
	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)
	if (bst == NULL)
		return;
	fprintf(fd, " %s ",bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
	if (bst == NULL)
		return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().
	char buffer[1024];
	BSTree bst = NewBSTree();
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		AddNode(&bst, _strdup(buffer));
	}
	return bst;
}
