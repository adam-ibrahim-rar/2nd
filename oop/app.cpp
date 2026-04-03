#include <iostream>
using namespace std;
typedef int elementsType;
typedef int position;
class list
{
    public:
    elementsType *elements;
    int length = 50, last;
    list()
    {
        length = 50;
        elements = new elementsType[length];
        last = 0;
    }
    list(int n)
    {
        elements = new elementsType[n];
        length = n;
        last = 0;
    }
    void insert(elementsType value, position p)
    {
        while (p > last)
        {
            cout << "the postion is out of the range\n";
            cin >> p;
        }
        for (int i = last + 1; i > p; i--)
            elements[i] = elements[i - 1];
        elements[p] = value;
        last++;
    }
    void Delete(position p){
        while (p > last)
        {
            cout << "the postion is out of the range\n";
            cin >> p;
        }
    for ( int i = p; i < last; i++)
        elements[i]=elements[i+1];
        last--;
        length--;
    }
    position next(position p){
    return ++p;
}
    position previous(position p){
        return --p;
    }
    position locate(elementsType key){
        elementsType x=-1;
        int i=0;
        while (x=-1)
            elements[i]!=key?i++:x=i;
        if (x=-1)return end()+1;     
        return x;
}
    position frist(){
        return 0;
    }
    position end(){
    return last;
}
    elementsType retrive(position p)
    {
     return elements[p];   
    }
    void makeNull(){
        last=-1;
    }
    void display(){
        if (last==0){
        cout<<"ur list is empty\n" ;return;}
        cout<<"ur list elements are :\n";
        for (int i = 0; i < last; i++)
        cout<<elements[i]<<endl;
        
    }
    
};
void name(list &mylist){
    int n=-1;
    do{
        
        cout<<"what the operation do you want to do on your list\n";
        cout<<"0- exist\n";
        cout<<"1- insert value\n";
        cout<<"2- delete position\n";
        cout<<"3- next to position\n";
        cout<<"4- previous a position\n";
        cout<<"5- locate value\n";
        cout<<"6- retrive value\n";
        cout<<"7- make your list null values\n";
        cout<<"8- retrive the frist index\n";
        cout<<"9- retrive the last index\n";
        cout<<"10- display value\n";
       
        cin>>n;
        switch (n)
        {
        case 0:
        break;
        case 1:
            cout<<"please enter a value and position\n";
            int val,pos;
            cin>>val>>pos;
            mylist.insert(val,pos);
            cout<<"operation done successfuly\n";
            break;
        case 2:
            cout<<"please enter a position\n";
            cin>>pos;
            mylist.Delete(pos);
            cout<<"operation done successfuly\n";
            break;
        case 3:
            cout<<"please enter a position\n";
            cin>>pos;
            mylist.next(pos);
            cout<<"operation done successfuly\n";
            break;
        case 4:
            cout<<"please enter a position\n";
            cin>>pos;
            mylist.next(pos);
            cout<<"operation done successfuly\n";
            break;
        case 5:
            cout<<"please enter a value\n";
            cin>>val;
            mylist.locate(val);
            cout<<"operation done successfuly\n";
             break;
        case 6:
            cout<<"please enter a value\n";
            cin>>val;
            cout<<"the position is :"<<mylist.retrive(val);
            cout<<"operation done successfuly\n";
            break;
        case 7:
            mylist.makeNull();
            cout<<"operation done successfuly\n";
            break;
        case 8:
            cout<<"the frist is :"<<mylist.frist();
            cout<<"operation done successfuly\n";
            break;
        case 9:
            cout<<"the end is :"<<mylist.end();
            cout<<"operation done successfuly\n";
            break;
        case 10:
            mylist.display();
            cout<<"operation done successfuly\n";
            break;

        default:
        cout<<"invalid number\n";
        return ;
        }
    }
    while(n!=0);
   
}
int main()
{
    char respon;
    cout<<"want to creat a list with ur own size ? (y/n)\n";
    cin>>respon;
    if (respon='y')
    {
    int size;
    cout<<"please enter the size\n";
    cin>>size;
    list myList(size);
    cout<<"your list has been created successfuly\n";
    name(myList);
    }
    else{
     list myList;
    cout<<"your list has been created successfuly\n and the size is :"<<50;
    name(myList);
     }
    
    return EXIT_SUCCESS;
}
