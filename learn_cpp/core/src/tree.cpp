module tree;

import queue;
import <print>;


void visit (Tree* val) {
    std::println ("{}", val->data);
}

void level_order (Tree* T) {
    LinkQueue q;
    init_link_q (q);
    //using Node = Tree;
    en_link_q (q, T);
    while (!link_queue_empty (q)) {
        Tree* temp{};
        de_link_q (q, temp);
        visit (temp);
        if (temp->left != nullptr) {
            en_link_q (q, temp->left);
        }
        if (temp->right != nullptr) {
            en_link_q (q, temp->right);
        }
    }
}



void visit (ThreadTree*& current, ThreadTree*& pre_ptr) {
    if (current->left == nullptr) {
        current->left = pre_ptr;
        current->l_tag = 1;
    }
    if (pre_ptr != nullptr && pre_ptr->right == nullptr) {
        pre_ptr->right = current;
        pre_ptr->r_tag = 1;
    }
    pre_ptr = current;
}

void in_thread (ThreadTree* current, ThreadTree*& pre_ptr) {
    if(current == nullptr){ return; }
    in_thread (current->left, pre_ptr);
    visit (current,pre_ptr);
    in_thread (current->right, pre_ptr); 
}
void create_in_thread (ThreadTree* root) {
    if (root == nullptr) { return; }
    ThreadTree* pre_ptr = nullptr;
    in_thread (root, pre_ptr);
    if (pre_ptr != nullptr) {
        pre_ptr->right = nullptr;
        pre_ptr->r_tag = 1;
    }
}


/*================================*/
//中序线索二叉树找中序后继

//第一个被中序遍历的结点
ThreadTree* first_node(ThreadTree* node){
	while (node->l_tag==true){
        node = node->left;
	}
    return node;
}

ThreadTree* in_next_node (const ThreadTree* node){
    if (node->r_tag == false) return first_node (node->right);
    else return node->right;
}
/*================================*/