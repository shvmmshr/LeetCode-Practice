class graph
{
    public:
    unordered_map<int,list<int>> g;
    int bob;
    vector<int> amount;
    unordered_map<int,bool> vis;
    stack<int> s;
    graph(unordered_map<int,list<int>>& adj,int bb,vector<int>& amt)
    {
        this->g=adj;
        this->bob=bb;
        this->amount=amt;
    }
    int profit(int node)
    {
        s.push(node);
        vis[node]=true;
        if(node==bob)
        {
            int size=s.size();
            for(int i=0;i<size/2;i++)
            {
                amount[s.top()]=0;
                s.pop();
            }
            if(size%2==1)
            {
                amount[s.top()]/=2;
            }
            while(s.size()<size)
            {
                s.push(0);
            }
        }
        int ans=INT_MIN;
        for(int nbr:g[node])
        {
            if(!vis[nbr])
            {
                ans=max(ans,profit(nbr));
            }
        }
        if(ans==INT_MIN) ans=0;
        s.pop();
        return ans+amount[node];
    }
};
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        graph ob(adj,bob,amount);
        return ob.profit(0);
    }
};