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
public:
    int num_nodes;
    Node<T>* head;
    Node<T>* tail;

    LinkedList() {
        num_nodes = 0;
        head = NULL;
        tail = NULL;
    }

    void insert_at_end(T value){
        if (tail == NULL) {
            tail = new Node<T>(value, NULL);
            return;
        }
        tail->next = new Node<T>(value, NULL);
        tail = next;
        num_nodes++;
    }

    // modifiers
    void insert_at_front(T cargo) {
        Node<T>* front = new Node<T>(cargo, head);
        head = front;
        if (num_nodes == 0) { 
            tail = front;
            }
        num_nodes++;
    }

    T remove_from_front() {
        if (head == NULL)
            throw runtime_error("Can't remove from empty list!");
        T cargo = head->cargo;
        Node<T>* front = head;
        head = head->next;
        delete front;
        num_nodes--;
        return cargo;
    }
};

template <class T>
void print_list(Node<T>* list) {
    Node<T>* node= list;
    cout << "(";
    while (node != NULL) {
        cout << node->cargo;
        node = node->next;
        if (node != NULL) cout << ", ";
    }
    cout << ")";
}



int main(int argc, char** argv)
{


    return 0;
}