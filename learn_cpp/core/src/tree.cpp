module tree;

import queue;
import <print>;

using Tree = struct Tree;

void visit (Tree* val) {
    std::println ("{}", val->data);
}

void level_order (Tree* T) {
    LinkQueue q;
    init_link_q (q);
    using Node = Tree;
    Node* temp;
    en_link_q (q, T);
    while (!link_queue_empty (q)) {
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