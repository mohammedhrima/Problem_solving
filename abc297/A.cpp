#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, D;

    cin >> N;
    cin >> D;

    vector<int> list;
    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        list.push_back(value);
    }
    for(int i = 0; i < N - 1; i++)
    {
        if(list[i + 1] - list[i] <= D)
        {
            cout << list[i + 1] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}