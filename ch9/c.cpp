#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <unordered_set>

using namespace std;

template <class T>
class useless
{
public:
    static void mysort(T *arr, int n);
};

template <class T>
void useless<T>::mysort(T *arr, int n)
{
    if (n == 0)
        return;
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
        cout << arr[i] << ' ';
    cout << arr[n - 1] << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    useless<int>::mysort(arr, n);
    cin >> n;
    char arr1[n] = {0};
    for(int i=0;i<n;i++)
    {
        cin >> arr1[i];
    }
    useless<char>::mysort(arr1, n);
    cin >> n;
    string arr2[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr2[i];
    }
    useless<string>::mysort(arr2, n);
    return 0;
}