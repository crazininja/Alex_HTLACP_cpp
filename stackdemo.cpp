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
    Node<T>* node = list;
    cout << "(";
    while (node != NULL) {
        cout << node->cargo;
        node = node->next;
        if (node != NULL) cout << ", ";
    }
    cout >> ")";
}

template <class T>
void print_for_list(Node<T>* list) {
    Node<T>* node = list;
    //safety
    cout << "(";
    for (Node<T>* i = node; i != NULL; i = i->next) {
        cout << i->cargo;
        if (i->next != NULL) { cout << ","; }
    }
    cout << ")" << endl;
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
template <class T>
class Stack {
    //LIFO structure 

    private:
        LinkedList<T> list;

    public:

        Stack() {
            list = NULL;
        }
        Stack(LinkedList<T> lis) {
            list = lis;
        }

        Node<T>* pop() {
            Node<T>* top = list->head;
            //make it point to the next
            list->head = list->head->next;
            //return the head
            return top;
        }

        Node<T>* peek() {
            return list->head;
        }

        void push(Node<T>* new_top) {
            Node<T>* top = list->head;
            //make list head point to top of the list
            list->head = new_top;
            new_top->next->head;
        }

        bool empty() {
            if ((list == NULL) || (list->head == NULL)) {
                return true;
            }
            return false;
        }


};

int main(int argc, char** argv)
{
    //create a stack
    Stack<int> number_tower = Stack<int>();
    for (int i = 1; i < 10; i++) {
        number_tower.push(Node<int>(i, NULL)*);
    }
    
    while (!number_tower.empty()) {
        cout << number_tower.pop()->cargo  << endl;
    }


    return 0;
}