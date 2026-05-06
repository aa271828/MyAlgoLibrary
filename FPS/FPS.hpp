#pragma once
#include "../template/main.hpp"
#include <atcoder/convolution>
vl operator * (const vl &a, const vl &b) {
   vl ret = atcoder::convolution(a, b);
  return ret;
}
vl operator + (const vl &a, const vl &b) {
   vl ret = a;
   ret.resize(max(a.size(), b.size()));
   rep(i,0,b.size())(ret[i] += b[i]) %= MOD;
   return ret;
}
vl operator - (const vl &a, const vl &b) {
   vl ret = a;
   ret.resize(max(a.size(), b.size()));
   rep(i,0,b.size())(ret[i] -= b[i]) %= MOD;
   return ret;
}
vl even(vl a) {
   vl ret;
   rep(i,0,(a.size() + 1) / 2) ret.push_back(a[2 * i]);
   return ret;
}
vl odd(vl a) {
   vl ret;
   rep(i,0,a.size() / 2) ret.push_back(a[2 * i + 1]);
   return ret;
}
vl mainasu(vl a) {
   rep(i,0,a.size() / 2) a[2 * i + 1] = (-a[2 * i + 1])%MOD;
   return a;
}
