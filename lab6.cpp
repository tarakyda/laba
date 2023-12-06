#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class link {
public:
    link();
    link(int data);
    bool add_element(int data);
    void Print();
    void ReversePrint();
    void Sort();
    void delete_element(int value);
    bool find_element(int k);
    bool insert_element(int data, int pos);

private:
    Node* first;
    Node* last;
};

link::link() {
    first = nullptr;
    last = nullptr;
}

bool link::add_element(int data) {
    Node* nd = new Node{ data, nullptr, nullptr };
    if (last == nullptr) {
        first = nd;
        last = nd;
    }
    else {
        nd->prev = last;
        last->next = nd;
        last = nd;
    }
    return true;
}
void link::Print() {
    Node* PP = first;
    while (PP) {
        cout << PP->data << " ";
        PP = PP->next;
    }
}
void link::ReversePrint() {
    Node* PP = last;
    while (PP) {
        cout << PP->data << " ";
        PP = PP->prev;
    }
}
bool link::find_element(int k) {
    Node* nd = last;
    while (nd) {
        if (nd->data == k) {
            return 1;
        }
        nd = nd->prev;
    }
    return 0;
}
void link::delete_element(int value) {
    Node* current = first;
    while (current != nullptr) {
        if (current->data == value) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            if (current == first) {
                first = current->next;
            }
            if (current == last) {
                last = current->prev;
            }
            delete current;
            break;
        }
        current = current->next;
    }
}
bool link::insert_element(int data, int pos) {
    Node* nd1 = first;
    Node* nd2 = new Node{ data, nullptr, nullptr };

    if (pos == 0) {
        nd2->next = first;
        first->prev = nd2;
        first = nd2;
        return true;
    }
    int i = 0;
    while (nd1 != nullptr) {
        if (i == pos - 1) {

            nd2->prev = nd1;
            nd2->next = nd1->next;

            if (nd1->next != nullptr) {
                nd1->next->prev = nd2;
            }

            nd1->next = nd2;
            break;
        }
        nd1 = nd1->next;
        i++;
    }
}
void link::Sort() {
    Node* nd = new Node;
    Node* left = first;
    Node* right = first->next;
    while (left->next) {
        while (right) {
            if ((left->data) > (right->data)) {
                nd->data = left->data;
                left->data = right->data;
                right->data = nd->data;
            }
            right = right->next;
        }
        left = left->next;
        if (left != nullptr) {
            right = left->next;
        }
    }
    delete nd;
}

int main() {
    link l1;
    l1.add_element(1);
    l1.add_element(2);
    l1.add_element(3);
    l1.add_element(4);
    l1.add_element(5);
    l1.add_element(6);
    link l2;
    l2.add_element(4);
    l2.add_element(6);
    l2.add_element(3);
    l2.Print();
    cout << endl;
    l2.Sort();
    l2.Print();
    cout << endl;
    cout << endl;
    l1.delete_element(2);
    cout << endl;
    cout << l1.find_element(11);
    cout << " is there 2 in string" << endl;
    l1.insert_element(3, 4);
    l1.insert_element(112, 0);
    l1.Print();
    cout << endl;
    l1.ReversePrint();
    return 0;
    l1.Print();
    cout << endl;
    return 0;
}