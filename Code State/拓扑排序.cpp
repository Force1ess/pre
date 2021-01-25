#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int in[100100];
int ans[100100];
vector<int> edge[maxn];
int main()
{
    int n, p1, p2;
    cin >> n >> p1 >> p2;
    int temp1, temp2;
    fill(in, in + maxn, 0);
    fill(ans, ans + maxn, 0);
    queue<int> q;
    for (int i = 0; i < p1;i++)
    {
        cin >> temp1 >> temp2;
        in[temp2]++;
        edge[temp1].push_back(temp2);
    }
    for (int i = 1; i<=n;i++)if(!in[i])
            q.push(i);
    int p = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        ans[v]=p++;
        for (int i = 0; i < edge[v].size();i++)
        {
            in[edge[v][i]]--;
            if(!in[edge[v][i]])
                q.push(edge[v][i]);
        }
    }
    for (int i = 0; i < p2;i++)
    {
        cin >> temp1 >> temp2;
        if(ans[temp1]>ans[temp2])
            cout << temp2 << " " << temp1 << endl;
        else
            cout << temp1 << " " << temp2 << endl;
    }
    system("pause");
}