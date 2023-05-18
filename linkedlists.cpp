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

    void insert_at(T value, int pos) {
        if pos > num_nodes-1 {
            throw runtime_error("position is too high")
        }
        if pos < 0 {
            throw runtime_error("negative position inputted!")
        }
        if (position = 0) {
            Node<T>* next_node = head;
            head = new Node(value, next_node);
            num_nodes++;
            return;
        }

        //start at the first node and traverse
        Node<T>* node = head->next;
        Node<T>* lag_node = head;
        for (int position = 1; !(position > pos); position++) {
            node = node->next;
            lag_node = lag_node->next;
        }
        //node is the node we want to replace
        lag_node->next = new Node(value, node);
        num_nodes++;
        return;
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