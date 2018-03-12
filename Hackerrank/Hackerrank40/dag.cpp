#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sd(n) scanf("%d",&n)
using namespace std;

typedef vector<int> VI;

#define MAXN 500000
VI adj[MAXN];
int indeg[MAXN];
int tmp[MAXN];
int ord[MAXN];
int n;

void reduce(int * deg, int pos, set<int>& q){
    q.erase(pos);
    for(auto &i: adj[pos]){
        deg[i]--;
        if(not deg[i]) q.insert(i);
    }
}

void getstate(int * deg, set <int> &q, int till){
    for(int i=0; i<n; i++)
        if(not deg[i]) q.insert(i);
    for(int i=0; i<till; i++)
        reduce(deg, ord[i], q);
}

bool check(int till){
    memcpy(tmp, indeg, sizeof(indeg));
    set < int > q;
    getstate(tmp, q, till);
    int cnt=0;
    while(not q.empty()){
        int p = *q.rbegin();
        if(p != ord[cnt + till])return false;
        reduce(tmp, p, q);
        cnt++;
    }
    return true;
}

int main()
{
    int m,u,v;
    sd(n), sd(m);
    for(int i=0; i<m; i++){
        sd(u), sd(v);
        u--,v--;
        adj[u].pb(v);
        indeg[v]++;
    }
    for(int i=0; i<n; i++){
        sd(ord[i]);
        ord[i]--;
    }

    int l=-1,r=n-1;
    while(r-l > 1){
        int mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    if(l==-1){
        printf("-1\n");
        return 0;
    }


    for(int i=0; i<l; i++)printf("%d ", ord[i]+1);

    set<int> q;
    getstate(indeg, q, l);
    assert(*q.rbegin() > ord[l]);
    auto it = q.find(ord[l]);  it++;
    printf("%d ", 1+*it);
    reduce(indeg, *it, q);
    while(not q.empty()){
        int p = *q.begin();
        printf("%d ", p+1);
        reduce(indeg, p, q);
    }
    printf("\n");

    return 0;
}
