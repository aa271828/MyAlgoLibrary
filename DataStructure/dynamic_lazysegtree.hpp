#pragma once
#include "../template/main.hpp"

template<
    class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(F, S),
    F (*composition)(F, F),
    F (*id)()
>
struct segtree {

   ll N=1ll<<32;
   ll H=32;
   struct Node {
      ll l;
      ll r;
      S data;
      F lazy;
      Node() {
         l = -1;
         r = -1;
         data = e();
         lazy = id();
      }
   };
   vector<Node> D;
   ll new_node() {
      D.push_back(Node());
      return D.size() - 1;
   }
   segtree() {
      D.reserve(4000000);
      new_node();
   }
   //反映
   void node_apply(ll idx, F f) {
      D[idx].data = mapping(f, D[idx].data);
      D[idx].lazy = composition(D[idx].lazy, f);
   }
   //伝搬
   void push(ll idx) {
      if (D[idx].lazy == id()) return;
      if (D[idx].l == -1) D[idx].l = new_node();
      if (D[idx].r == -1) D[idx].r = new_node();
      node_apply(D[idx].l, D[idx].lazy);
      node_apply(D[idx].r, D[idx].lazy);
      D[idx].lazy = id();
   }
   void pull(ll idx) {
      D[idx].data = op(D[idx].l == -1 ? e() : D[D[idx].l].data, D[idx].r == -1 ? e() : D[D[idx].r].data);
   }

   void apply_inner(ll idx, ll L, ll R, ll ql, ll qr, F f) {
      if (qr <= L || R <= ql) return;
      if (ql <= L && R <= qr) {
         node_apply(idx, f);
         return;
      }
      push(idx);
      ll mid = (L + R) >> 1;
      if (D[idx].l == -1) D[idx].l = new_node();
      if (D[idx].r == -1) D[idx].r = new_node();
      apply_inner(D[idx].l, L, mid, ql, qr, f);
      apply_inner(D[idx].r, mid, R, ql, qr, f);
      pull(idx);
   }
   void apply(ll l, ll r, F f) {
      apply_inner(0, 0, N, l, r, f);
   }
   S prod_inner (ll idx, ll L, ll R, ll ql, ll qr) {
      if (qr<=L || R <= ql) return e();
      if (ql<=L && R <= qr) return D[idx].data;
      push(idx);
      ll mid = (L + R) >> 1;
      S a = e(), b = e();
      if (D[idx].l != -1) a = prod_inner(D[idx].l, L, mid, ql, qr);
      if (D[idx].r != -1) b = prod_inner(D[idx].r, mid, R, ql, qr);
      return op(a, b);
   }
   S prod(ll l, ll r) {
      return prod_inner (0, 0, N, l, r);
   }
   void set_point_inner(ll idx, ll L, ll R, ll pos, S x) {
      if (R - L == 1) {
         D[idx].data = x;
         return ;
      }
      push(idx);
      ll mid = (L + R) >> 1;
      if (pos < mid) {
         if (D[idx].l == -1) D[idx].l = new_node();
         set_point_inner(D[idx].l, L, mid, pos, x);
      }
      else {
         if (D[idx].r == -1) D[idx].r = new_node();
         set_point_inner(D[idx].r, mid, R, pos, x);
      }
      pull(idx);
   }
   void set(ll idx, S x) {
      set_point_inner(0, 0, N, idx, x);
   }
};
