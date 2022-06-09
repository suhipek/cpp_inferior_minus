#include <iostream>
#include <string.h>
#include <queue>
#include <cstdio>

using namespace std;
#pragma optimize("", off)

template <class T>
void Print(T *p, int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << p[i] << ' ';
    }
    cout << p[n - 1] << endl;
}

template <class T>
void GtLever(T *p, int n, T lever)
{
    queue<T> greater, smaller;
    for (int i = 0; i < n; i++)
    {
        if (p[i] > lever)
            greater.push(p[i]);
        else
            smaller.push(p[i]);
    }
    int i = 0, _n = greater.size();
    while (!greater.empty())
    {
        p[i] = greater.front();
        greater.pop();
        i++;
    }
    while (!smaller.empty())
    {
        p[i] = smaller.front();
        smaller.pop();
        i++;
    }
    Print(p, _n);
}

int main()
{
    string type;
    int l, n;
    cin >> type >> l >> n;
    if (type == "char")
    {
        char arr[l + 1];
        for (int i = 0; i < l + 1; i++)
        {
            cin >> arr[i];
        }
        GtLever<char>(arr, n, arr[l]);
    }
    if (type == "int")
    {
        int arr[l + 1];
        for (int i = 0; i < l + 1; i++)
            cin >> arr[i];
        GtLever<int>(arr, n, arr[l]);
    }
    if (type == "float")
    {
        float arr[l + 1];
        for (int i = 0; i < l + 1; i++)
            cin >> arr[i];
        GtLever<float>(arr, n, arr[l]);
    }
    return 0;
}