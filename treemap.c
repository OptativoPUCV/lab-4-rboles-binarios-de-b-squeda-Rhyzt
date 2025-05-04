#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int lower_than(void* key1, void* key2){
    int k1 = *((int*) (key1));
    int k2 = *((int*) (key2));
    return k1<k2;
}

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}

TreeNode *createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap *createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    TreeMap *nuevoArbol = malloc(sizeof(TreeMap));
    nuevoArbol -> lower_than = lower_than;
    nuevoArbol -> current = NULL;
    nuevoArbol -> root = NULL;
    return nuevoArbol;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
    
}

TreeNode *minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair *searchTreeMap(TreeMap * tree, void* key) {
    TreeNode *aux = tree -> root;
    while(aux != NULL) {
        if (lower_than(key, aux -> pair -> key))
            aux = aux -> left;  
        else {
            if (!lower_than(key, aux -> pair -> key))
                aux = aux -> right;
            else {
                if (is_equal(tree, key, aux -> pair -> key))
                    return aux -> pair;
            }
        }
    }
    return NULL;
}


Pair *upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair *firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair *nextTreeMap(TreeMap * tree) {
    return NULL;
}
