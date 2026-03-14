#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph
{
public:
    int size;
    map<int, vector<int>> adj;

    Graph(int size)
    {
        this->size = size;
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void dfs(int key, vector<bool> &visited)
    {
        visited[key] = true;
        for (int v : adj[key])
            if (!visited[v])
                dfs(v, visited);
    }

    int connectedSize()
    {
        vector<bool> visited(size, false);
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    Graph g(N); 

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.addEdge(a, b);
    }

    cout << g.connectedSize() << endl;
}
