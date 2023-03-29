#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    set<int> called;
    int last = 0;
    while (Q--)
    {
        int event;
        cin >> event;
        if (event == 1)
        {
            called.insert(++last);
        }
        else if (event == 2)
        {
            int x;
            cin >> x;
            called.erase(x);
        }
        else
        {
            cout << *begin(called) << "\n";
        }
    }
}
