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
export void visit (ThreadTree* node) {}
export void level_order (Tree* T);
export void create_in_thread (ThreadTree* root);
ThreadTree* first_node (ThreadTree* node);
export ThreadTree* in_next_node (ThreadTree* node); //终须遍历后继结点
export void in_order (ThreadTree* root) {
	for (auto node=first_node(root);node!=nullptr;node=in_next_node(node)) {
        visit (node);
	}
}  //中序线索化二叉树进行中序遍历



/*================================*/
//前驱逆序遍历中序线索二叉树
//最后一个被中序遍历的结点
export auto last_node (ThreadTree* node);
//找到结点的前驱
export auto pre_node (ThreadTree* node);
//对中序线索二叉树进行逆向中序遍历
export void rev_inorder (ThreadTree* root);
/*================================*/


/*-----------------前序遍历线索化-----------------*/
export void create_pre_thread (ThreadTree* root);
export void pre_thread (ThreadTree* node,ThreadTree*& pre);
export void pre_visit (ThreadTree*node,ThreadTree*& pre);
/*---------------------------------------------*/


/*-----------------后序遍历线索化-----------------*/
export void create_last_thread (ThreadTree* root);
export void last_thread (ThreadTree* node, ThreadTree*& pre);
export void last_visit (ThreadTree* node, ThreadTree*& pre);
/*---------------------------------------------*/