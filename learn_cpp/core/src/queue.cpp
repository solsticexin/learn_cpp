module queue;

void en_link_q (LinkQueue& q, struct Tree* elem) {
    const auto new_node = new LinkNode;
    new_node->data = elem;
    new_node->next = nullptr;

    if (link_queue_empty (q)) {
        q.front = q.rear = new_node;
    }
    else {
        q.rear->next = new_node;
        q.rear = new_node;
    }
}

bool de_link_q (LinkQueue& q, struct Tree*& elem) {
    if (link_queue_empty (q)) {
        return false;
    }

    const LinkNode* temp = q.front;
    elem = temp->data;
    q.front = temp->next;

    if (q.front == nullptr) {
        q.rear = nullptr;
    }

    delete temp;
    return true;
}