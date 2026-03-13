#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long long factorial(int num)
{
    num > 0 ? num = num : num = -num;
    long long sum = 1;
    for (int i = num; i > 1; i--)
        sum *= i;
    return sum;
}
double comb(int a, int b)
{
    return (factorial(a) / (factorial(b) * factorial(a - b)));
}
bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}
struct Series
{
    int a, b, n;
    float x[20];
    double s[20];
    void read()
    {
        cout << "insent n, a" << endl;
        cin >> n >> a;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "x[" << i + 1 << "] =";
            cin >> x[i];
        }
        cout << endl;
        for (int i = 0; i <= n - 1; i++)
        {
            double res = 0;
            for (int k = 0; k < i; k++)
                res += comb(i + 1, k) * x[i] * pow(a, i - k + 1);
            s[i] = res;
        }
    }
    double max()
    {
        double max = s[0];
        for (int i = 0; i < n; i++)
            s[i] > max ? max = s[i] : max = max;
        return max;
    }
    void display()
    {
        cout << "x elements \t s elements" << endl;
        for (int i = 0; i < n; i++)
            cout << "x[" << i + 1 << "] = " << x[i] << " \t s[" << i + 1 << "] = " << s[i] << endl;
    }
};
struct Num
{
    float n[10];
    int m;
    string t[10];
    void read()
    {
        cout << "insent m" << endl;
        cin >> m;
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            cout << "N[" << i + 1 << "] =";
            cin >> n[i];
        }
        cout << endl;
        for (int i = 0; i <= m; i++)

            isPrime(n[i]) ? t[i] = "Yes" : t[i] = "No";
    }
    long long summation()
    {
        long long sum = 0;
        for (int i = 0; i < m; i++)
            t[i] == "Yes" ? sum += factorial(n[i]) : sum += 0;
        return sum;
    }
    long long products()
    {
        long long sum = 1;
        for (int i = 0; i < m; i++)
            t[i] == "No" ? sum *= factorial(n[i]) : sum += 0;
        return sum;
    }
    void display()
    {
        cout << "n elements \t t elements" << endl;
        for (int i = 0; i < m; i++)
            cout << "n[" << i + 1 << "] = " << n[i] << " \t t[" << i + 1 << "] = " << t[i] << endl;
    }
};
void compareSummations(Num a, Num b)
{
    a.summation() > b.summation() ? a.display() : b.display();
}
Num compareProducts(Num a, Num b)
{
    if (a.products() > b.products())
        return b;
    return a;
}
int main()
{
    Num n1, n2;
    n1.read();
    n2.read();
    cout << "n1 is :" << endl;
    n1.display();
    cout << "n2 is :" << endl;
    n2.display();
    cout << "n1 summation elements is : " << n1.summation() << "\t\tn2 summation elements is :" << n2.summation() << endl;
    cout << "n1 products elements is : " << n1.products() << "\t\t n2 products elements is :" << n2.products() << endl;
    compareProducts(n1, n2);
    compareSummations(n1, n2);
    return 0;
}
