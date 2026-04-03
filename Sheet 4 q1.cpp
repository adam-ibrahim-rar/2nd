#include <iostream>
using namespace std;
bool isPrime(int number)
{
    if (number == 0 || number == 1)
        return false;
    for (int i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}


class data2;
class data1
{
    float d1[20][20];
    int n;

public:
    void read()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> d1[i][j];
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            float max = d1[0][i];
            for (int j = 0; j < n; j++)

                if (d1[j][i] > max)
                    max = d1[j][i];

         

                d1[n - 1][i] = max;
        }
    }
    float sumOfPrimes()
    {
        float sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPrime(int(d1[n - 1][i])))
                sum += d1[n - 1][i];
        }
        return sum;
    }
    void display()
    {
        cout << "[ ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                {
                    cout << d1[i][j];
                    break;
                }

                cout << d1[i][j] << " ,";
            }
            cout << endl;
        }
        cout<<"]\n";
    }
    friend void compare(data1, data2);
    friend float avg(data1, data2);
};
class data2
{
    float d2[20];
    int n;

public:
    void read()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> d2[i];
        }
    }
    float sumOfPrimes()
    {
        float sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPrime(int(d2[i])))
                sum += d2[i];
        }
        return sum;
    }
    void display()
    {
        cout << "( ";
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                cout << d2[i] << ")\n";
                break;
            }
            cout << d2[i] << " ,";
        }
    }

    friend void compare(data1, data2);
    friend float avg(data1, data2);
};

void compare(data1 one, data2 two)
{
    if (one.sumOfPrimes() < two.sumOfPrimes())
    {
        one.display();
        return;
    }
    two.display();
}
float avg(data1 one, data2 two)
{
    return (one.sumOfPrimes() + two.sumOfPrimes()) / 2;
}


int main()
{
data1 d_one;
data2 d_two;
cout<<"enter the elements of d1\n";
d_one.read();
cout<<"enter the elements of d2\n";
d_two.read();
cout<<"******************************************\n";
cout<<"elements of d1\n";
d_one.display();
cout<<"elements of d2\n";
d_two.display();
cout<<"---------------------------\n";
compare(d_one,d_two);
cout<<"+++++++++++++++++++++++++\n";
cout<<"the avg is:"<<avg(d_one,d_two);
    return 0;
}
