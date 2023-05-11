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
    }
}

template <class T>
Node<T>* remove_second(Node<T>* list) {

    Node<T>* first = list;
    //return null if empty or only one element
    if ((first == NULL) || (first->next == NULL)) {
        return NULL;
    }
    Node<T>* second = list->next;

    // make the first node point to the third
    first->next = second->next;

    // remove the second node from the list and return a pointer to it
    second->next = NULL;
    return second;
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

    Node<string>* nodeA = new Node<string>("1", NULL);
    Node<string>* nodeB = new Node<string>("2", NULL);
    Node<string>* nodeC = new Node<string>("3", NULL);

    nodeA->next = nodeB;
    nodeB->next = nodeC;

    Node<string>* num_node = nodeA;

    //remove the second element

    nodeA->next = NULL;
    remove_second(nodeA);
    //remove the fisrt element
    nodeA = NULL;
    remove_second(nodeA);




    return 0;
}