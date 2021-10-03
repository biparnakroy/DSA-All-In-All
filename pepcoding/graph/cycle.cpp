// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    bool cycle(int s, vector<int> adj[], bool vis[])
    {
        queue<int> q;
        q.push(s);
        while (q.empty() != true)
        {
            int curr = q.front();
            q.pop();
            if (vis[curr] == true)
                return true;
            vis[curr] = true;
            for (auto x : adj[curr])
            {
                if (vis[x] == false)
                {
                    q.push(x);
                }
            }
        }

        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        bool vis[V];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                if (cycle(i, adj, vis) == true)
                    return true;
            }
        }

        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

