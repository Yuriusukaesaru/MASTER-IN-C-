#include <iostream>

class Node {
public:
    char data;
    Node* prev;
    Node* next;
};

class Double_List {
public:
    Double_List();
    ~Double_List();
    void Insert_begginig(char&);
    void Delete_begginig();
    bool Check_Node();
    void print_all();
    void reset_list();

private:
    Node* head;
    Node* tail;
};

Double_List::Double_List() {
    head = nullptr;
    tail = nullptr;
}

Double_List::~Double_List() {
    reset_list();
}

void Double_List::Insert_begginig(char& _data) {
    Node* ptr = new Node();
    ptr->data = _data;
    ptr->prev = nullptr;
    ptr->next = nullptr;

    if (head != nullptr) {
        ptr->next = head;
        head->prev = ptr;
    }

    head = ptr;

    if (head->next == nullptr && head->prev == nullptr) {
        tail = ptr;
    }
}

void Double_List::Delete_begginig() {
    if (head == nullptr) {
        std::cout << "THE LIST IS EMPTY";
        return;
    }

    Node* ptr = head->next;

    if (ptr != nullptr) {
        ptr->prev = nullptr;
    }

    delete head;
    head = ptr;

    if (head == nullptr) {
        tail = nullptr;
    }
}


bool Double_List::Check_Node() {
    Node* current = head;

    if( tail->data != 'G')
    {
    while (current != nullptr) {
        if (current->data == 'G') {
            Node* prevNode = current->prev;
            Node* nextNode = current->next;

            if (prevNode != nullptr) {
                prevNode->next = nextNode;
            } else {
                head = nextNode;
            }

            if (nextNode != nullptr) {
                nextNode->prev = prevNode;
            } else {
                tail = prevNode;
            }

            Node* deleteNode = current;
            current = nextNode;

            delete deleteNode;
        } else {
            
           //if( current->data == 'G' && tail->data == 'G' ) 
           //{return false ;}
           //else 
           current = current->next;
        }
    }
    }//else { return false;}

    //if( head == nullptr)
    //{
      //  return false;
    //}

    return tail->data != 'G' ? true : false;
}



void Double_List::reset_list() {
    while (head != nullptr) {
        Delete_begginig();
    }
}

void Double_List::print_all() {
    Node* temp = head;

    while (temp != nullptr) {
        std::cout << "DATA: " << temp->data << '\n'
                  << "DIRECTION " << temp << '\n'
                  << "PREVIOUS POINTER DIRECTION: " << temp->prev << '\n'
                  << "NEXT DIRECCION: " << temp->next << '\n';
        temp = temp->next;
    }
}

int main(void) {
    Double_List obj;

    int number, lifes = 3;
    char value;
    std::cout << "INSERT THE NUMBER OF NODES: ";
    std::cin >> number;

    while (lifes != 0) {
        obj.reset_list();

        for (int i = 0; i < number; ++i) {
            std::cout << '\n' << "ENTER THE VALUE IN NODE ";
            std::cin >> value;
            obj.Insert_begginig(value);
        }

        if (obj.Check_Node()) {
            std::cout << "ESCAPE SUCCEEDED" << '\n'
                      << "DELETED ELEMENTS POSITIONS: ";
            obj.print_all();
            break;
        } else {
            --lifes;
            std::cout << "ESCAPE FAILURE" << '\n' << "LIFES: " << lifes;
        }
    }

    if (lifes == 0) {
        std::cout << "ESCAPE FAILURE" << '\n';
    }

    return 0;
}
