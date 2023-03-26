
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> st;
    int mex = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.count(i) == 0)
        {
            mex = i;
            break;
        }
    }
    if (mex < k)
    {
        cout << mex << "\n";
    }
    else
    {
        cout << k << "\n";
    }

    return 0;
}
