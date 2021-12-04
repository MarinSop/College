#include "dictionary.h"

Dictionary create()
{
    Dictionary newDic = (Word*)malloc(sizeof(Word));
    newDic->count = 0;
    newDic->next = NULL;
    newDic->word = NULL;
    return newDic;
}

void add(Dictionary dict, char* str)
{
    if (dict->word == NULL)
    {
        dict->word = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(dict->word, str);
    }
    else if (dict->next == NULL)
    {
        Dictionary newDic = create();
        newDic->word = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(newDic->word, str);
        if (strcmp(dict->word, str) > 0)
        {
            strcpy(newDic->word, dict->word);
            strcpy(dict->word, str);
            dict->next = newDic;
        }
        else
        {
            dict->next = newDic;
        }
    }
    else
    {
        Dictionary tmp = dict;
        while (tmp->next != NULL)
        {
            if (strcmp(tmp->next->word, str) == 0)
            {
                tmp->next->count += 1;
                break;
            }
            else if (strcmp(tmp->next->word, str) > 0)
            {
                Dictionary newDic = create();
                newDic->word = (char*)malloc(sizeof(char) * strlen(str));
                strcpy(newDic->word, str);
                newDic->next = tmp->next;
                tmp->next = newDic;
                break;
            }
            tmp = tmp->next;
        }
    }
}

int filter(Word* w)
{
    if((w->count >= 5 && w->count <= 10) && (strlen(w->word) > 3))
        return 1;
    else
        return 0;
}

Dictionary filterDictionary(Dictionary indict, int(*filter)(Word* w))
{
    Dictionary newDic = indict;
    Dictionary tmp = newDic;
    while (tmp != NULL)
    {
        if (filter(tmp->next) != 1)
        {
            Dictionary t;
            t = tmp->next;
            tmp->next = tmp->next->next;
            free(t);
        }
        else
        printf("--[%s,%d]--\n", tmp->word, tmp->count);
        tmp = tmp->next;
    }
    return newDic;
}

void print(Dictionary dict)
{
    Dictionary tmp = dict;
    printf("[%s,%d]\n", tmp->word,tmp->count);
    while (tmp->next != NULL)
    {
        printf("[%s,%d]\n", tmp->next->word,tmp->next->count);
        tmp = tmp->next;
    }
}

void destroy(Dictionary dict)
{
    Dictionary tmp;
    while(dict != NULL)
    {
        tmp = dict;
        dict = dict->next;
        //free(tmp->word);
        free(tmp);
    }
}
