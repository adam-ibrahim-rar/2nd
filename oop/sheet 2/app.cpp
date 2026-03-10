#include <iostream>
#include <cmath>
using namespace std;

class DMT
{
    float a[20][20];
    int p[20];
    int n;

public:
    bool isPrime(int number)
    {
        if (number == 1 || number == 0)
            return true;
        for (int i = 2; i < number; i++)
            if (number % i == 0)
                return false;
        return true;
    }
    void read()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
        {
            int max = a[i][0];
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] > max && isPrime(a[i][j]))
                    max = a[i][j];
            }
            p[i] = max;
        }
    }
    void display()
    {
        cout << n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
        for (int i = 0; i < n; i++)
        {
            cout << endl
                 << p[i];
        }
    }
    void compareIfEqual(DMT x)
    {
if(n!=x.n)
cout<<"the two objects are not equal in length \n";
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (res == 1)
            {
                cout << "the two objects are not equal\n";
                return;
            }
            for (int j = 0; j < n; j++)
                if (a[i][j] == x.a[i][j])
                    continue;
                else
                    res = 1;
        }
        cout << "the two objects are equal\n";
    }
    float avg()
    {
        float sum = 0;
        for (int i = 0; i < n; i++)
            sum += p[i];
        return sum / n;
    }
    void compareDisplay(DMT x)
    {
        avg() > x.avg() ? x.display() : display();
    }
};
class student
{
    string name;
    int id;
    float age;
    float d[2];
    char g[2];
    float gpa;

public:
    student()
    {
        name = " ";
        age = gpa = id = 0;
        for (int i = 0; i < 2; i++)
        {
            d[i] = 0;
            g[i] = 'A';
        }
        
    }
    student(string n,int i,float a,float G,float dd[],char gg[])
    {
        name = n;
        age = a;
        gpa = G;
        id = i;
        for (int i = 0; i < 2; i++)
        {
            d[i] = dd[i];
            g[i] = gg[i];
        }
        
    }
    student(string n,int i,float a,float G,float dd[],char gg[])
    :name(n),age (a),gpa (G) , id (i)
        {
        for (int i = 0; i < 2; i++)
        {
            d[i] = dd[i];
            g[i] = gg[i];
        }
    }
    void display(){
        cout << "name is" << name << endl;
        cout << "age is" << age << endl;
        cout << "gpa is" << gpa << endl;
        cout << "id is" << id << endl;
        for (int i = 0; i < 2; i++)
            cout << "the degree is " << d[i];
        for (int i = 0; i < 2; i++)
            cout << "the grade is " << g[i];
    }};
class EQ
{
    float a, b, c;

public:
    EQ()
    {
        a = b = c = 0;
    }
    void solve(float a, float b, float c)
    {
        int real = sqrt(pow(b, 2) - 4 * a * c);
        cout << "the 1st slon is " << (-b + real) / 2*a;
        cout << "the 2nd slon is " << (-b - real)/ 2*a;
    }

};

int main()
{


    return EXIT_SUCCESS;
}