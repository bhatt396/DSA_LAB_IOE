/*
    Lab 4: Implementation of Priority Queue using Linked List
    Code written by Bhaskar Bhatt
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node *next;
};

// Queue class
class Queue {
    Node *head; // Pointer to the head of the list

public:
    Queue() : head(NULL) {}

    bool isEmpty() {
        return head == NULL;
    }

    void enque(int data, int prior) {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->priority = prior;
        new_node->next = NULL;

        // If the queue is empty or the new node has the highest priority
        if (isEmpty() || prior > head->priority) {
            new_node->next = head;
            head = new_node;
        } else {
            // Traverse the list to find the correct position
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority >= prior) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void deque() {
        if (isEmpty()) {
            cerr << "Error: Queue is empty." << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        cout << temp->data << " dequeued" << endl;
        delete temp;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL) {
            cout << "(" << temp->data << ", Priority: " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            deque();
        }
    }
};

int main() {
    Queue *queue_obj = new Queue();

    // Adding elements to the priority queue
    queue_obj->enque(10, 2);
    queue_obj->enque(20, 1);
    queue_obj->enque(30, 3);
    queue_obj->enque(40, 2);

    cout << "Queue: ";
    queue_obj->display();

    queue_obj->deque();

    cout << "Queue after dequeue: ";
    queue_obj->display();

    delete queue_obj;

    return 0;
}
