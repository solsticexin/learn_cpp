module chapter3;
import <print>;
import <vector>;
using elemtp = int;
bool Judge (char* A) {
    int i{}, j{}, k{};
    while (A[i] != '\0') {
        switch (A[i]) {
        case 'I':
            j++;
            break;
        case 'O':
            k++;
            if (k > j) {
                std::println ("序列非法");
                exit (0);
            }
            break;
        }
        i++;
    }
    if (j != k) {
        std::println ("非法序列");
        return 0;
    }
    else {
        std::println ("序列合法");
        return 1;
    }
}

int dc (question4::LinkList L, int n) {
    int i{};
    // char S[n/2];
    std::vector<char> S{};
    question4::LNode* p{ L->next };
    for (; i < n / 2; i++) {
        S[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1) {
        p = p->next;
    }
    while (p != nullptr && S[i] == p->data) {
        i--;
        p = p->next;
    }
    if (i == 1)
        return 1;
    else
        return 0;
}

int push (int i, elemtp x) {
    if (i < 0 || i > 1) {
        std::println ("stack 号输入不对");
        exit (0);
    }
    if (question5::s.top[1] - question5::s.top[0] == 1) {
        std::println ("stack已满");
        return 0;
    }
    switch (i) {
    case 0:
        question5::s.stack[++question5::s.top[0]] = x;
        return 1;
        break;
    case 1:
        question5::s.stack[--question5::s.top[1]] = x;
        return 1;
    }
}