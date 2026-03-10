#include <iostream>
using namespace std;
typedef int elementType;

class node
{
private:
    static int counter;

public:
    elementType data;
    node* next;
    node()
    {
        counter++;
    }

};
int node::counter = 0;
class list
{
    node* head;
public:
    //المفروض اضيف ف كل الدوال دي لو القيمه او المكان مش موجودين يرجع ده ويريترن 
    list()
    {
        head = new node;
        head->data = 0;
        head->next = NULL;
    }
    void insertElements(int numberOfElements) {
        for (int i = 0; i < numberOfElements; i++)
        {
            elementType value;
            cout << "enter the value of element " << i + 1 << ": ";
            cin >> value;
            insertFrist(value);
        }
    }
    void insertFrist(elementType value)
    {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = head->next;
        head->next = newNode;
    }
    void insertAfterVAlue(elementType value, elementType newValue)
    {
        node* temp = head;
        while (temp->data != value)
            temp = temp->next;
        node* newNode = new node;
        newNode->data = newValue;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertAfterPosition(elementType Position, elementType value)
    {
        node* temp = head;
        for (int i = 0; i < Position; i++)
            temp = temp->next;
        node* newNode = new node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertBeforeVAlue(elementType value, elementType newValue)
    {
        node* temp = head;
        while (temp->next->data != value)
            temp = temp->next;
        node* newNode = new node;
        newNode->data = newValue;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertLast(elementType value){
        node * temp=head;
        while (temp->next!=NULL)
        temp=temp->next;
        node * newnode=new node;
        newnode->data=value;
        newnode->next=NULL;
        temp->next=newnode;
    }
    void insertBeforePosition(elementType Position, elementType value)
    {
        node* temp = head;
        for (int i = 0; i < Position - 1; i++)
            temp = temp->next;
        node* newNode = new node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteValue(elementType value) {
        node* temp = head;
        while (temp->next->data != value)
            temp = temp->next;
        node* TheNode = temp->next;
        temp->next = TheNode->next;
        delete TheNode;
    }
    void deleteAfterValue(elementType value) {
        node* temp = head;
        while (temp->data != value)
            temp = temp->next;
        node* TheNode = temp->next;
        temp->next = TheNode->next;
        delete TheNode;
    }
    void locateValue(elementType value) {
        int i = 0;
        node* temp = head;
        while (temp->data != value) {
            temp = temp->next;i++;
        }
        cout << "the value " << value << " is in the " << i << "index\n";
    }
    void searchValue(elementType value) {
        node* temp = head;
        int i = 0;
        while (temp->data != value) {
            if (temp->next == NULL)
            {
                cout << "value does not exsist\n";
                return;
            }
            temp = temp->next;
            i++;
        }
        cout << "value is exsist in the position " << i << endl;
    }
    void ValueNextToValue(elementType value) {
        node* temp = head;
        while (temp->data != value)
        temp = temp->next;
        if (temp->next==NULL)
        {
            cout << "there is no values after this value\n";
            return;
        }
        cout << "the value is " << temp->next->data << endl;
    }
    void ValuePerivousToValue(elementType value) {
        node* temp = head;
        if (temp->next->data == value)
        {
            cout << "there is no values before this value\n";
            return;
        }
        while (temp->next->data != value)
        temp = temp->next;
        cout << "the value is " << temp->data << endl;
        
    }
    void display() {
        node* temp = head->next;
        cout << "your list is [";
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << ',';
            }
            temp = temp->next;
        }
        cout << "]\n";
    }

};

int main()
{
    list li;
    li.insertFrist(4);
    li.insertFrist(2);
    li.insertFrist(1);
    li.insertAfterPosition(3, 6);
    li.display();
    li.insertBeforeVAlue(6, 5);
    li.insertBeforeVAlue(4, 3);
    li.locateValue(5);
    li.display();
    li.deleteAfterValue(5);
    li.deleteValue(2);
    li.display();
    li.searchValue(5);
    li.ValueNextToValue(4);
    li.ValuePerivousToValue(1);

    return EXIT_SUCCESS;
}
