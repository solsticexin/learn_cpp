export module tree;

export struct Tree {
    int data;
    Tree* left;
    Tree* right;
};
export void level_order (Tree* T);