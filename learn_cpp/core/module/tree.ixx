export module tree;

export typedef struct Tree {
    int data;
    Tree* left;
    Tree* right;
}Tree;
export struct ThreadTree {
    int data;
    ThreadTree* left;
    ThreadTree* right;
    int l_tag;
    int r_tag;
};
export void level_order (Tree* T);
export void create_in_thread (ThreadTree* root);