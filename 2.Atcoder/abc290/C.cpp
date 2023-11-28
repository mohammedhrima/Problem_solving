#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    set<int> st;
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        st.insert(x);
    }
    
    for (int i = 0; i < K; i++)
    {
        if (st.find(i) == st.end())
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << K << "\n";

    return 0;
}
