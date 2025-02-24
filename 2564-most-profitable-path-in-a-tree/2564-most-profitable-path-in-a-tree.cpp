class Solution {
public:
int helper(vector<vector<int>>&adj,vector<int>&path,vector<int>&amount,vector<bool>&visited,int node,int time)
{
    int sum=0;
    visited[node]=1;
    if(path[node]==-1 || path[node]>time)
    sum+=amount[node];
    else if(path[node]==time)
    sum+=(amount[node]/2);
    int sum1=INT_MIN;
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        sum1=max(sum1,helper(adj,path,amount,visited,adj[node][i],time+1));
    }
    if(sum1!=INT_MIN)
    sum+=sum1;
    return sum;
}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int>bpath;
        vector<vector<int>>adj(n);
        for(vector<int>i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int>q;
        vector<bool>visited(n,0);
        vector<int>parent(n,-1);
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                if(visited[adj[node][i]])
                continue;
                visited[adj[node][i]]=1;
                parent[adj[node][i]]=node;
                q.push(adj[node][i]);
                if(adj[node][i]==bob)
                {
                    int temp=adj[node][i];
                    while(temp!=-1)
                    {
                        bpath.push_back(temp);
                        temp=parent[temp];
                    }
                   break;
                }
            }
            if(bpath.size())
            break;
        }
        vector<int>path(n,-1);
        for(int i=0;i<bpath.size();i++)
        path[bpath[i]]=i;
        fill(visited.begin(),visited.end(),0);
        return helper(adj,path,amount,visited,0,0);
    }
};