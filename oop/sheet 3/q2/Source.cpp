#include <iostream>
using namespace std;
void swap(int& x, int& y)
{
    int temp = y;
    y = x;
    x = temp;
}
class list
{

    int A[30];
    int n;

public:
    void read()
    {
        cout << "please enter n\n";
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> A[i];
    }
    void sort()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (A[j + 1] < A[j])
                    swap(A[j + 1], A[j]);
    }
    void display()
    {
        cout << "the number of elements is :" << n << endl;
        cout << "the list is [";
        for (int i = 0; i < n; i++)
        {
            cout << A[i];
            if (i == n - 1)
            {
                cout << "]\n";
                break;
            }
            cout << ',';
        }
    }
    friend float average(list l);
    friend list compare(list l1, list l2);
    friend list compareAvg(list l1, list l2);
};

float average(list l)
{
    float sum = 0;
    for (int i = 0; i < l.n; i++)

        sum += l.A[i];
    return sum / l.n;
}
list compare(list l1, list l2)
{
    if (l1.n != l2.n)
        cout << "the tow lists are not the same length\n";
    for (int i = 0; i < l1.n; i++)
    {
        if (l1.A[i] > l2.A[i])
            continue;
        else
            return l2;
    }
    return l1;
}
list compareAvg(list l1, list l2)
{
    if (l1.n != l2.n)
        cout << "the tow lists are not the same length\n";
    if (average(l1) > average(l2))
        return l1;
    return l2;
}

int main()
{

    list l1;
    l1.read();
    l1.sort();
    l1.display();
    list l2;
    l2.read();
    l2.sort();
    l2.display();
    compare(l1, l2).display();
    compareAvg(l1, l2).display();
    cout << "avg of 1 is " << average(l1) << endl;
    cout << "avg of 2 is " << average(l2) << endl;
    return EXIT_SUCCESS;
}
