#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
public:
    T cargo;
    Node<T>* next;

    Node(T cargo, Node<T>* next) {
        this->cargo = cargo;
        this->next = next;
    }
};

template <class T>
class LinkedList
{
    int num_nodes;
    Node<T>* head;

public:
    LinkedList() {
        num_nodes = 0;
        head = NULL;
    }
};

template <class T>
void print_list(Node<T>* list) {
    Node<T>* node= list;
    while (node != NULL) {
        cout << node->cargo;
        node = node->next;
        if (node != NULL) cout << ", ";
    }
}

template <class T>
void print_for_list(Node<T>* list) {
    Node<T>* node = list;
    //safety
    for (Node<T>* i = node; i != NULL; i = i->next) {
        cout << i->cargo << endl;
        if (v > 10) { break; }
    }
}

int main(int argc, char** argv)
{
    //textbook tests
    Node<string>* node1 = new Node<string>("I", NULL);
    Node<string>* node2 = new Node<string>("love", NULL);
    Node<string>* node3 = new Node<string>("templates!", NULL);

    node1->next = node2;
    node2->next = node3;

    Node<string>* node = node1;

    print_for_list(node);

    return 0;
}