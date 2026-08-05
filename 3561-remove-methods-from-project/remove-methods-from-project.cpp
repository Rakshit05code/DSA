class Solution {
public:

    void dfs(int node, vector<vector<int>>& graph, vector<int>& suspicious)
    {
        suspicious[node] = 1;

        for(auto next : graph[node])
        {
            if(!suspicious[next])
            {
                dfs(next, graph, suspicious);
            }
        }
    }


    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        vector<vector<int>> graph(n);

        // Build graph
        for(auto &edge : invocations)
        {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
        }


        vector<int> suspicious(n,0);

        dfs(k, graph, suspicious);

        for(auto &edge : invocations)
        {
            int a = edge[0];
            int b = edge[1];


            if(!suspicious[a] && suspicious[b])
            {
                vector<int> ans;

                for(int i=0;i<n;i++)
                    ans.push_back(i);

                return ans;
            }
        }

        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(!suspicious[i])
                ans.push_back(i);
        }


        return ans;
    }
};