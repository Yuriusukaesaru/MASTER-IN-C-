#include <iostream>
#include <stdlib.h>

class Node {
private:
    int data;
    Node* next;
    friend class Linked_list;
};

class Linked_list {
public:
    Linked_list();
    ~Linked_list();
    void add_front(int);
    void add_end(int);
    void remove_last();
    void remove_front();
    int get_front() const;
    void get_all() const;
private:
    Node* head;
};

Linked_list::Linked_list() {
    head = nullptr;
}

void Linked_list::add_front(int _data) {
    Node* pnt = new Node;
    pnt->next = head;
    pnt->data = _data;
    head = pnt;
}

void Linked_list::add_end(int _data) {
    Node* pnt = new Node;
    pnt->next = nullptr;
    pnt->data = _data;

    if (head == nullptr) {
        head = pnt;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = pnt;
    }
}

void Linked_list::remove_last() {
    if (head == nullptr) {
        // If the list is empty, there is nothing to remove
        return;
    }

    if (head->next == nullptr) {
        // If there is only one node in the list, remove it
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    
    delete current;
    previous->next = nullptr;
}

void Linked_list::remove_front() {
    if (head != nullptr) {
        Node* pnt = head->next;
        delete head;
        head = pnt;
    }
}

int Linked_list::get_front() const {
    if (head != nullptr) {
        return head->data;
    }
    return -1; // or throw an exception to handle empty list case
}

Linked_list::~Linked_list() {
    while (head != nullptr) {
        remove_front();
    }
}


void Linked_list::get_all() const {
    Node* current = head;

    std::cout << "DISPLAYING DATA: " << std::endl;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Linked_list test;
    
    test.add_front(1); // adding 1
    test.get_all(); // Output: 1
    test.add_front(2); // 2,1
    test.add_front(3); // 3,2,1
    test.add_front(4); // 4,3,2,1
    test.add_end(5); // add 5 at the end
    test.get_all(); // Output: 1 5
    test.add_end(6); // 1,5,6
    test.get_all(); // Output: 1 5 6
    test.remove_last();
    test.get_all();
    test.remove_last();
    test.get_all();

    return 0;
}

/*

    void remove_last()
    {
        Node* current = head;
        while(current != nullptr)
        {
            current = current->next;
        }
        current = nullptr;
    }
*/