#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 256

typedef struct trieNode{
    struct trieNode *links[MAX];
    bool flag;
} node;

node *createNode(){
    node *newNode = (node*)malloc(sizeof(node));
    if (!newNode){
        printf("\nMemory Allocation for Creating Node Failed ...\n");
        return NULL;
    }

    // Traversing & Assigning every array element with NULL [TC :- O(N)]
    for (int i = 0; i < MAX; i++){
        newNode->links[i] = NULL;
    }

    newNode->flag = false; // not a terminal
    return newNode;
}

/*

Double Pointer to root is passed because under some circumstances the root may be need to be changed.
SignedText : because in some machines "char" is signed (we don't want a -ve index coming to the lookup table)

*/
bool trieInsert(node **root, char *signedText){
    if (*root == NULL){
        *root = createNode(); // if single pointer is passed then it's just changing the value of a "copy".e
    }

    unsigned char *text = (unsigned char*)signedText;
    node *temp = *root;
    int length = strlen(signedText);

    for (int i = 0; i < length; i++){
        if (temp->links[text[i]] == NULL){
            // Create New Node
            temp->links[text[i]] = createNode();
        }
        temp = temp->links[text[i]]; // traversal                                                                                                        
    }

    if (temp->flag){ // temp->flag == true
        return false;
    }

    temp->flag = true;
    return true;
}

void printTrieRec(node *head, unsigned char *prefix, int length){
    unsigned char newPrefix[length + 2]; // add 1 more symbol and NULL 
    memcpy(newPrefix, prefix, length);

    newPrefix[length+1] = 0;

    if (head->flag){
        printf("WORD -> %s\n", prefix);
    }

    for (int i = 0; i < MAX; i++){
        if (head->links[i] != NULL){
            newPrefix[length] = i;
            printTrieRec(head->links[i], newPrefix, length+1);
        }
    }
}

void printTrie(node *root){
    if (!root){
        printf("\nEmpty Trie\n");
        return;
    }
    printTrieRec(root, NULL, 0);
}

bool searchTrie(node *root, char *signedText){
    unsigned char *text = (unsigned char *)signedText;
    int length = strlen(signedText);

    node *temp = root;

    for (int i = 0; i < length; i++){
        if (temp->links[text[i]]){
            return false;
        }
        temp = temp->links[text[i]];
    }
    return temp->flag;
}

bool deleteStr(node **root, char *signedText){
    if (!*root) return false;

    unsigned char *text = (unsigned char *)signedText;
    int length = strlen(signedText);
    bool result = false; // TRUE : if we delete something

    *root = deleteStrRec(root, text, &result);
}

int main(){

    node *root = NULL;

    trieInsert(&root, "APPLE");
    trieInsert(&root, "CAT");
    trieInsert(&root, "BAT");
    trieInsert(&root, "BATTLE");
    trieInsert(&root, "CATTLE");

    printTrie(root);

    return 0;
}
