#pragma once
#include "../template/main.hpp"
#include <atcoder/convolution>
#include <atcoder/modint>
using mint = atcoder::modint998244353;
vector<mint> operator * (const vector<mint> &a, const vector<mint> &b) {
   vector<mint> ret = atcoder::convolution(a, b);
  return ret;
}
vector<mint> operator + (const vector<mint> &a, const vector<mint> &b) {
   vector<mint> ret = a;
   ret.resize(max(a.size(), b.size()));
   rep(i,0,b.size()) ret[i] += b[i];
   return ret;
}
vector<mint> operator - (const vector<mint> &a, const vector<mint> &b) {
   vector<mint> ret = a;
   ret.resize(max(a.size(), b.size()));
   rep(i,0,b.size()) ret[i] -= b[i];
   return ret;
}
vector<mint> even(vector<mint> a) {
   vector<mint> ret;
   rep(i,0,(a.size() + 1) / 2) ret.push_back(a[2 * i]);
   return ret;
}
vector<mint> odd(vector<mint> a) {
   vector<mint> ret;
   rep(i,0,a.size() / 2) ret.push_back(a[2 * i + 1]);
   return ret;
}
vector<mint> mainasu(vector<mint> a) {
   rep(i,0,a.size() / 2) a[2 * i + 1] = -a[2 * i + 1];
   return a;
}
mint bostan_mori (vector<mint> p, vector<mint> q, ll n) {
   if (n == 0) return p[0] / q[0];
   vector<mint> q0 = even(q), q1 = odd(q);
   vector<mint> r = p * mainasu(q);
   vector<mint> r0 = even(r), r1 = odd(r);
   vector<mint> s = q0 * q0 - vector<mint>({0, 1}) * q1 * q1;
   if (n % 2 == 0) return bostan_mori(r0, s, n / 2);
   else return bostan_mori(r1, s, (n - 1) / 2);
}
