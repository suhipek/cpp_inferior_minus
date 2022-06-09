#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <unordered_set>

using namespace std;

void uniq(int *arr, int m)
{
    unordered_set<int> exist;
    vector<int> ordArr;
    for (int i = 0; i < m; i++)
    {
        if (exist.find(arr[i]) == exist.end())
        {
            exist.emplace(arr[i]);
            ordArr.push_back(arr[i]);
        }
    }
    for (auto it = ordArr.begin(); it != ordArr.end(); it++)
    {
        cout << *(it);
        if (next(it) == ordArr.end())
            cout << endl;
        else
            cout << ' ';
    }
}

int main()
{
    int q, m;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        int *msg = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> msg[j];
        }
        reverse(msg, msg + m);
        uniq(msg, m);
    }
    return 0;
}