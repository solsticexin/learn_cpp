#ifndef  LEARN_CPP_TREE_H
#define LEARN_CPP_TREE_H


struct Tree{
    int data;
    Tree* left;
    Tree* right;
};
void level_order(Tree* T);
#endif