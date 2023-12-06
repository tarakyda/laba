#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class link {
public:
    link();
    link(int data);
    bool add_element(int data);
    void delete_element(int data);
    bool find_element(int data);
    bool insert_element(int data, int pos);
    void Print();
private:
    Node* first;
    Node* last;
};

link::link() {
    first = nullptr;
    last = nullptr;
}

bool link::add_element(int data) {
    Node* nd = new Node{ data, nullptr };
    if (last == nullptr) {
        first = nd;
        last = nd;
        return true;
    }
    last->next = nd;
    last = nd;
    return true;
}

bool link::find_element(int data) {
    Node* nd = first;
    while (nd) {
        if (nd->data == data) {
            return true;
        }
        nd = nd->next;
    }
    return false;
}

void link::delete_element(int data) {
    Node* nd1 = first;
    Node* nd2 = first->next;
    if (nd1->data == data) {
        first = nd2;
        delete nd1;
        return;
    }
    while (nd2 && nd2->data != data) {
        nd2 = nd2->next;
        nd1 = nd1->next;
    }
    if (nd2) {
        nd1->next = nd2->next;
        delete nd2;
    }
}

bool link::insert_element(int data, int pos) {
    Node* nd1 = first;
    Node* nd2 = new Node{ data, nullptr };

    if (pos == 0) {
        nd2->next = first;
        first = nd2;
        return true;
    }

    int i = 0;
    while (nd1 && i < pos - 1) {
        nd1 = nd1->next;
        i++;
    }

    if (nd1) {
        nd2->next = nd1->next;
        nd1->next = nd2;
        if (nd1 == last) {
            last = nd2;
        }
        return true;
    }

    delete nd2;
    return false;
}

void link::Print() {
    Node* PP = first;
    while (PP) {
        cout << PP->data << " ";
        PP = PP->next;
    }
}

int main() {
    link l1;
    l1.add_element(112);
    l1.add_element(113);
    l1.add_element(114);
    l1.add_element(115);
    l1.Print();
    cout << endl;
    cout << l1.find_element(116) << endl;
    l1.delete_element(113);
    l1.Print();
    l1.insert_element(23, 3);
    cout << endl;
    l1.Print();

    return 0;
}
