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
            head = tail;
            num_nodes++;
            return;
        }
        tail->next = new Node<T>(value, NULL);
        tail = tail->next;
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
        if (pos > num_nodes-1) {
            //insert at the end; the end position will be the number of nodes
            if (pos == num_nodes) {
                insert_at_end(value);
                return;
            }
            throw runtime_error("position is too high");
        }

        if (pos < 0) {
            throw runtime_error("negative position inputted!");
        }
        if (pos == 0) {
            Node<T>* next_node = head;
            head = new Node<T>(value, next_node);
            num_nodes++;
            return;
        }

        //now that we no it doesn't need to be at the front and the position is valid
        //simply just traverse the list until we reach our desired position

        //potential optimization: just use the lag node, but it might be less readable?

        //start at the first node so we can have a lag node and traverse
        Node<T>* node = head->next;
        Node<T>* lag_node = head;
        for (int position = 1; (position < pos); position++) {
            node = node->next;
            lag_node = lag_node->next;
        }
        //node is the node we want to replace
        cout << "lag node:" << lag_node->cargo << endl;
        cout << "next node:" << node->cargo << endl;
        lag_node->next = new Node<T>(value, node);
        num_nodes++;
        return;
    }
};

template <class T>
void print_list(LinkedList<T>* list) {
    Node<T>* node= list->head;
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
    LinkedList<int>* one_two_three = new LinkedList<int>();
    one_two_three->insert_at_front(1);
    one_two_three->insert_at_end(3);
    one_two_three->insert_at(2, 1);
    cout << one_two_three->num_nodes << endl;
    one_two_three->insert_at(4, 2);
    one_two_three->insert_at_end(5);
    print_list(one_two_three);



    return 0;
}