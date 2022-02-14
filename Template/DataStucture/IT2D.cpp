ll t[4*maxn][4*maxn], s[4*maxn][4*maxn], lazy[4*maxn][4*maxn];
struct data{
    int node, l, r;
    data (int id, int L, int R) {node = id; l = L; r = R;}
    data left() const {return data(node*2, l, (r+l)/2);}
    data right() const {return data(node*2+1, (r+l)/2+1, r);}
    inline bool irrelevant(int L, int R) const {return (L > R || R < l || r < L);}
};
void init(const data &dx, const data &dy){
    if (dx.l == dx.r && dy.l == dy.r)
        {t[dx.node][dy.node] = s[dx.node][dy.node] = a[dx.l][dy.l]; return;}
    if (dy.l != dy.r){
        init(dx, dy.left());
        init(dx, dy.right());
        t[dx.node][dy.node] = min(t[dx.node][dy.node*2], t[dx.node][dy.node*2+1]);
        s[dx.node][dy.node] = s[dx.node][dy.node*2] + s[dx.node][dy.node*2+1];
    }
    if (dx.l != dx.r){
        init(dx.left(), dy);
        init(dx.right(), dy);
        t[dx.node][dy.node] = min(t[dx.node*2][dy.node], t[dx.node*2+1][dy.node]);
        s[dx.node][dy.node] = s[dx.node*2][dy.node] + s[dx.node*2+1][dy.node];
    }
}
void Lazy(const data &dx, const data &dy){
    if (lazy[dx.node][dy.node] == 0) return;
    t[dx.node][dy.node] = lazy[dx.node][dy.node];
    s[dx.node][dy.node] = lazy[dx.node][dy.node] * (dx.r-dx.l+1) * (dy.r-dy.l+1);
    if (dx.l != dx.r){
        lazy[dx.node*2][dy.node] = lazy[dx.node][dy.node];
        lazy[dx.node*2+1][dy.node] = lazy[dx.node][dy.node];
    }
    if (dy.l != dy.r){
        lazy[dx.node][dy.node*2] = lazy[dx.node][dy.node];
        lazy[dx.node][dy.node*2+1] = lazy[dx.node][dy.node];
    }
    lazy[dx.node][dy.node] = 0;
}
ll get_sum(const data &dx, const data &dy, int x1, int x2, int y1, int y2){
    if (dx.irrelevant(x1, x2) || dy.irrelevant(y1, y2)) return 0;
    if (x1 < 1 || x2 > n || y1 < 1 || y2 > m) return 0;
    Lazy(dx, dy);
    if (x1 <= dx.l && dx.r <= x2){
        if (y1 <= dy.l && dy.r <= y2) return s[dx.node][dy.node];
        ll trai = get_sum(dx, dy.left(), x1, x2, y1, y2);
        ll phai = get_sum(dx, dy.right(), x1, x2, y1, y2);
        return trai + phai;
    }
    ll trai = get_sum(dx.left(), dy, x1, x2, y1, y2);
    ll phai = get_sum(dx.right(), dy, x1, x2, y1, y2);
    return trai + phai;
}
ll get_min(const data &dx, const data &dy, int x1, int x2, int y1, int y2){
    if (dx.irrelevant(x1, x2) || dy.irrelevant(y1, y2)) return MM;
    if (x1 < 1 || x2 > n || y1 < 1 || y2 > m) return MM;
    Lazy(dx, dy);
    if (x1 <= dx.l && dx.r <= x2){
        if (y1 <= dy.l && dy.r <= y2) return t[dx.node][dy.node];
        ll trai = get_min(dx, dy.left(), x1, x2, y1, y2);
        ll phai = get_min(dx, dy.right(), x1, x2, y1, y2);
        return min(trai, phai);
    }
    ll trai = get_min(dx.left(), dy, x1, x2, y1, y2);
    ll phai = get_min(dx.right(), dy, x1, x2, y1, y2);
    return min(trai, phai);
}
void update(const data &dx, const data &dy, int x1, int x2, int y1, int y2, int val){
    if (dx.irrelevant(x1, x2) || dy.irrelevant(y1, y2)) return;
    if (x1 < 1 || x2 > n || y1 < 1 || y2 > m) return;
    if (x1 <= dx.l && dx.r <= x2 && y1 <= dy.l && dy.r <= y2){
        lazy[dx.node][dy.node] = val; Lazy(dx, dy); return;
    }
    Lazy(dx, dy);
    if (dy.l != dy.r){
        update(dx, dy.left(), x1, x2, y1, y2, val);
        update(dx, dy.right(), x1, x2, y1, y2, val);
        t[dx.node][dy.node] = min(t[dx.node][dy.node*2], t[dx.node][dy.node*2+1]);
        s[dx.node][dy.node] = s[dx.node][dy.node*2] + s[dx.node][dy.node*2+1];
    }
    if (dx.l != dx.r){
        update(dx.left(), dy, x1, x2, y1, y2, val);
        update(dx.right(), dy, x1, x2, y1, y2, val);
        t[dx.node][dy.node] = min(t[dx.node*2][dy.node], t[dx.node*2+1][dy.node]);
        s[dx.node][dy.node] = s[dx.node*2][dy.node] + s[dx.node*2+1][dy.node];
    }
}



///NTTK
struct dir {
    int ll, rr, id;
    dir (int L, int R, int X) {ll=L, rr=R, id=X;}
    dir left() const {return dir(ll, (ll+rr)/2, id*2);}
    dir right() const {return dir((ll+rr)/2+1, rr, id*2+1);}
    inline bool irrelevant(int L, int R) const {return ll>R || L>rr || L>R;}
};
void maximize(int &a, int b) {a=max(a, b);}
void maximize(const dir &dx, const dir &dy, int x, int y, int k, bool only_y) {
    if (dx.irrelevant(x, x) || dy.irrelevant(y, y)) return;
    maximize(Max[dx.id][dy.id], k);
    if (!only_y && dx.ll != dx.rr) {
        maximize(dx.left(), dy, x, y, k, false);
        maximize(dx.right(), dy, x, y, k, false);
    }
    if (dy.ll != dy.rr) {
        maximize(dx, dy.left(), x, y, k, true);
        maximize(dx, dy.right(), x, y, k, true);
    }
}
int max_range(const dir &dx, const dir &dy, int lx, int rx, int ly, int ry) {
    if (dx.irrelevant(lx, rx) || dy.irrelevant(ly, ry)) return 0;
    if (lx<=dx.ll && dx.rr<=rx) {
        if (ly<=dy.ll && dy.rr<=ry) return Max[dx.id][dy.id];
        int Max1 = max_range(dx, dy.left(), lx, rx, ly, ry);
        int Max2 = max_range(dx, dy.right(), lx, rx, ly, ry);
        return max(Max1, Max2);
    } else {
        int Max1 = max_range(dx.left(), dy, lx, rx, ly, ry);
        int Max2 = max_range(dx.right(), dy, lx, rx, ly, ry);
        return max(Max1, Max2);
    }
}