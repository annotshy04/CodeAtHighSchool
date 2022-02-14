#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;
 
array<vector<pair<int,int>>,50001> g;
int m,n,q;
vector<pair<int,int>> b;
array<long long,50001> d,diff;
array<vector<int>,50001> buf;

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
 
void dijkstra(){
    fill(d.begin(),d.end(),1e18);
    d[1] = 0;
    priority_queue<pair<long long,int>> pq;
    pq.push({0,1});
    while(pq.size()){
        int u = pq.top().second;
        long long val = -pq.top().first;pq.pop();
        if(d[u] != val) continue;
        for(auto v : g[u]) if(d[v.first] > d[u] + v.second){
            d[v.first] = d[u] + v.second;
            pq.push({-d[v.first],v.first});
        }
    }
}

void recalc(){
    fill(diff.begin(),diff.end(),50000);
    diff[1] = 0;
    buf[0].push_back(1);
    for(int i = 0;i <= n;i++){
        for(int j = 0;j < buf[i].size();j++){
            int u = buf[i][j];
            if(diff[u] != i) continue;
            for(auto v : g[u]) if(diff[v.first] > diff[u] + v.second - d[v.first] + d[u]){
                    diff[v.first] = diff[u] + v.second - d[v.first] + d[u];
                    if(diff[v.first] <= n) buf[diff[v.first]].push_back(v.first);
            }
        }
        buf[i].clear();
    }
    for(int i = 1;i <= n;i++) if(diff[i] < 50000) d[i] += diff[i];
}
 
int main(int argc, char *argv[]){
    freopen("dsp.inp","r",stdin);
    freopen("dsp.out","w",stdout);
    n = readInt(),m = readInt(),q = readInt();
    for(int i = 1;i <= m;i++){
        int x = readInt(),y = readInt(),w = readInt();
        b.push_back({x,g[x].size()});
        g[x].push_back({y,w});
    }
    dijkstra();
    while(q--){
        int k = readInt();
        if(k == 1) {
            int x = readInt();
            if (d[x] >= 1e18) printf("-1\n");
            else printf("%d\n",d[x]);
        }else{
            int cnt = readInt();
            for(int i = 0;i < cnt;i++){
                int x = readInt(); x--;
                g[b[x].first][b[x].second].second++;
            }
            recalc();
        }
    }
    return 0;
}
