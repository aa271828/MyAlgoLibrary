#pragma once
#include "../template/main.hpp"

template<
    class S,
    S (*op)(S, S),
    S (*e)()
>
struct segtree {

    ll N = 1ll << 32; // 扱う区間の幅
    struct Node {
        ll l;
        ll r;
        S data;
        Node() : l(-1), r(-1), data(e()) {}
    };

    vector<Node> D;

    ll new_node() {
        D.push_back(Node());
        return D.size() - 1;
    }

    segtree() {
        D.reserve(4000000); // 必要に応じて調整
        new_node(); // ルートノード (index 0)
    }

    void pull(ll idx) {
        S left_data = (D[idx].l == -1) ? e() : D[D[idx].l].data;
        S right_data = (D[idx].r == -1) ? e() : D[D[idx].r].data;
        D[idx].data = op(left_data, right_data);
    }

    // 点更新: D[pos] = x
    void set_inner(ll idx, ll L, ll R, ll pos, S x) {
        if (R - L == 1) {
            D[idx].data = x;
            return;
        }
        ll mid = (L + R) >> 1;
        if (pos < mid) {
            if (D[idx].l == -1) D[idx].l = new_node();
            set_inner(D[idx].l, L, mid, pos, x);
        } else {
            if (D[idx].r == -1) D[idx].r = new_node();
            set_inner(D[idx].r, mid, R, pos, x);
        }
        pull(idx);
    }

    void set(ll pos, S x) {
        set_inner(0, 0, N, pos, x);
    }

    // 区間取得: [ql, qr)
    S prod_inner(ll idx, ll L, ll R, ll ql, ll qr) {
        if (qr <= L || R <= ql || idx == -1) return e();
        if (ql <= L && R <= qr) return D[idx].data;
        
        ll mid = (L + R) >> 1;
        S a = prod_inner(D[idx].l, L, mid, ql, qr);
        S b = prod_inner(D[idx].r, mid, R, ql, qr);
        return op(a, b);
    }

    S prod(ll l, ll r) {
        return prod_inner(0, 0, N, l, r);
    }

    // 特定の点の値を取得
    S get(ll pos) {
        return prod(pos, pos + 1);
    }
};
