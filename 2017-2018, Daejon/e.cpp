#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Min-max flow : Dinic Algorithm

const int M = 505, INF = 1e9;
pair<int, pair<int, int>> edges[M];

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> parent;
    vector<int> Q;
    
    Dinic(int N) : N(N), G(N), parent(N), Q(N) {}
    
    void AddEdge(int from, int to, int cap, int revcap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, revcap, 0, G[from].size() - 1));
    }
    
    ll BlockingFlow(int s, int t) {
        fill(parent.begin(), parent.end(), (Edge *) NULL);
        parent[s] = &G[0][0] - 1;
        
        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!parent[e.to] && e.cap - e.flow > 0) {
                    parent[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!parent[t]) return 0;
        
        ll totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != parent[s]; e = parent[e->from]) {
                if (!e) { amt = 0; break; }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != parent[s]; e = parent[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }
    
    ll GetMaxFlow(int s, int t) {
        ll totflow = 0;
        while (ll flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {w, {u, v}};
    }
    sort(edges, edges + m);
    Dinic go(n);
    ll ans = 0;
    for(int i = 0, j = 0; i < m; i++)
    {
        while(j < i && edges[j].first < edges[i].first)
        {
            go.AddEdge(edges[j].second.first, edges[j].second.second, 1, 1);
            ++j;
        }
        for (int j = 0; j < n; ++j)
        {
            for (auto & it : go.G[j])
                it.flow = 0;
        }
        ans += go.GetMaxFlow(edges[i].second.first, edges[i].second.second);
    }
    cout << ans << endl;
    return 0;
}
