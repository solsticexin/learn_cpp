module queue;

void en_link_q (LinkQueue& q, struct Tree* elem) {
    LinkNode* newNode = new LinkNode;
    newNode->data = elem;
    newNode->next = nullptr;

    if (link_queue_empty (q)) {
        q.front = q.rear = newNode;
    }
    else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

bool de_link_q (LinkQueue& q, struct Tree*& elem) {
    if (link_queue_empty (q)) {
        return false;
    }

    LinkNode* temp = q.front;
    elem = temp->data;
    q.front = temp->next;

    if (q.front == nullptr) {
        q.rear = nullptr;
    }

    delete temp;
    return true;
}