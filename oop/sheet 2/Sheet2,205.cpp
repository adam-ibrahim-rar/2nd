#include <iostream>
#include <cmath>
using namespace std;

//  Write a program contains a function to return the factorial of a given positive
// element. It contains a class Series that has data members: x[40] (float), n
// (number of elements), S1 (double), S2 (double). It contains a function  to read
// data members x , n , and set the elements of  S1 and S2 such that:

long long factorial(int number)
{
    long long x = 1;
    for (int i = number; i >= 1; i--)
        x *= i;
    return x;
}

class Series
{
    float x[40];
    int n;
    double s1 = 0, s2 = 0;

public:
    void read()
    {
        int j = 0,k=0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i += 2)
        {
            s1 += pow(-1, j++) * (factorial(i) / sqrt(pow(x[i], i) + (pow(-1, j++) *i)));
        }

        for (int i = 1; i < n; i += 2)
        {
            s2 += pow(-1,k++) * (factorial(i) / sqrt(pow(x[i], i) + (pow(-1,k++) *i)));
        }
    }
    double sum(){
        return s1+s2;
    }
    void compare(Series a, Series b){
        a.sum()==b.sum()?cout<<"objects are equal":cout<<"objects are not equal";
    }
    void display(){
        for (int i = 0; i < n; i++)
        {
            cout<<x[i]<<endl;
            
        }
        cout<<" s1="<<s1<<" s2="<<s2;
        
    }
};

int main()
{
    return 0;
}
