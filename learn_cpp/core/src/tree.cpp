module tree;

import queue;
import <print>;


void visit (Tree* val) {
    std::println ("{}", val->data);
}

void level_order (Tree* T) {
    LinkQueue q;
    init_link_q (q);
    //using LinkNode = Tree;
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
	while (node->l_tag==0){
        node = node->left;
	}
    return node;
}

ThreadTree* in_next_node (ThreadTree* node){
    if (node->r_tag == 0) return first_node (node->right);
    else return node->right;
}
/*================================*/


/*================================*/
//中序线索二叉树找中序后继

//最后一个被中序遍历的结点
auto last_node (ThreadTree* node) {
    while (node->r_tag == 0) { node = node->right; }
    return node;
}
//找到结点的前驱
auto pre_node (ThreadTree* node) {
    if (node->l_tag == 0) return last_node (node->left);
    else return node->left;
}
//对中序线索二叉树进行逆向中序遍历
void rev_inorder (ThreadTree* root) {
	for (auto node=last_node(root); node!=nullptr; node=pre_node(node)) {
        visit (node);
	}
}

/*================================*/

void create_pre_thread(ThreadTree* root) {
    if (root==nullptr)return;
	ThreadTree* pre{ nullptr };
    pre_thread (root, pre);
}
void pre_thread(ThreadTree* node ,ThreadTree*& pre) {
	if (node ==nullptr) {
		return;
	}
    pre_visit (node, pre);
    pre_thread (node->left, pre);
    pre_thread (node->right, pre);
}
void pre_visit (ThreadTree*node,ThreadTree*& pre) {
    if (node->left == nullptr) {
        node->left = pre;
        node->l_tag = 1;
    }
    if (pre != nullptr && pre->right == nullptr) {
        pre->right = node;
        pre->r_tag = 1;
    }
    pre = node;
}


/*-----------------后序遍历线索化-----------------*/
void create_last_thread (ThreadTree* root) {
    if (root == nullptr)return;
    ThreadTree* pre{ nullptr };
    last_thread (root, pre);
}
void last_thread (ThreadTree* node, ThreadTree*& pre) {
	if (node ==nullptr) return;
    last_thread (node->left, pre);
    last_thread (node->right, pre);
    last_visit (node, pre);
}
void last_visit (ThreadTree* node, ThreadTree*& pre) {
	if (node->left==nullptr) {
        node->left = pre;
        node->l_tag = 1;
	}
    if (pre!=nullptr && pre->right==nullptr) {
        pre->right = node;
        pre->r_tag = 1;
    }
    pre = node;
}
/*---------------------------------------------*/