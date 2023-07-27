#include <iostream>

class Node
{
    public:
    char data;
    Node* prev;
    Node* next;
}; 

class Double_List
{
    public:
        Double_List();
        ~Double_List();
        void Insert_begginig( char & );
        void Delete_begginig();
        bool Check_Node();
        void print_all();
        void reset_list();
        
    private:
        Node *head, *tail;
};

Double_List::Double_List()
{
    head = nullptr;
    tail = nullptr;
}

Double_List::~Double_List()
{
    while (head!= nullptr)
    {
        Delete_begginig();
    }
}

void Double_List::Insert_begginig( char &_data)
{
    Node *ptr = new Node();
    ptr->data = _data;
    ptr->prev = nullptr;
    ptr->next = nullptr;

    if (head != nullptr)
    {
    ptr->next = head;
    head->prev = ptr;
    }
    
    head = ptr;

    if (head->next == nullptr && head->prev == nullptr)
    {
        tail = ptr;
    }
    
}

void Double_List::Delete_begginig()
{
    if (head == nullptr)
    {
        std::cout << "THE LIST IS EMPTY";
        return;
    }

    Node *ptr;
    ptr = head->next;

    if (ptr->next != nullptr) 
    {
        ptr->prev = nullptr; 
    }
        delete head;
        head = ptr;
}

bool Double_List::Check_Node( )
{

    Node* tempA = head;
    Node* tempB = nullptr;
    Node* tempC = nullptr;
    
    
    int counter = 0;

    while( tempA != nullptr)
    {
        tempB = tempA;
       
        tempA = tempA->next;
        

        while( head->data == 'G' )
        {
            Delete_begginig();
            if( head->next == nullptr)
            return false;
            
        }
        
        
        if(tempA->data != 'G' && tail->data != 'G')
        {
            return true; 
        }

        if( tempA->data == 'G' && tempB->data != 'G' && tempA->next != nullptr )
        {
            if (tempA->data == tail->data)
            {
                return false;
            }
            tempB->next = tempA ->next;
            tempC = tempA->next; 
            tempC->prev = tempB;
            delete tempA;
            tempA = tempB->next;
    
        }
            
    }

     return head!=nullptr ? true: false;
}

void Double_List::reset_list()
{
    
    while (head!= nullptr)
    {
        Delete_begginig();
    }
}
void Double_List::print_all()
{
    Node *temp = head;

    while(temp != nullptr)
    {
    std::cout << "DATA: " << temp->data << '\n'
              << "DIRECTION " << temp << '\n'
              << "PREVIOUS POINTER DIRECTION: " << temp->prev << '\n'
              << "NEXT DIRECCION: " << temp->next << '\n';
              temp = temp->next;
    }
}

int main (void)
{

    Double_List obj;

    
    int number, lifes = 3;
    char value;
    std::cout << "INSERT THE NUMBER OF NODES: ";
    std::cin>>number;
  

    while(lifes != 0)
    {
    for(int i = 0; i < number ; ++i)
        {
        std::cout << '\n' << "ENTER THE VALUE IN NODE ";
        std::cin >> value;
        obj.Insert_begginig(value);
        }        
            if (obj.Check_Node(  ))
            {
            std::cout << "RETURN SUCCEDED" << '\n'
                      << "DELETED ELEMENTS POSITIONS : ";
                  
            break;
            }
            else 
            {
            --lifes;
            std::cout << "RETURN FAILURE" << '\n' << "LIFES: " << lifes;
            obj.reset_list();
            
            }
    }  

    
}