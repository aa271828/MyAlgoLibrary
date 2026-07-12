#pragma once
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using pl = pair<ll, ll>;
using vl = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

const ll INF = 2e18 ;
const ll MOD = 998244353;
#define rep(i,a,b) for(ll i=(ll)a; i<(ll)b; i++)
#define rrep(i,a,b) for(ll i=(ll)b-1; i>=(ll)a; i--)
#define all(vec1) (vec1).begin(), (vec1).end()
#define rall(vec1) (vec1).rbegin(), (vec1).rend()
#define len(x) ll(x.size())
#define eb emplace_back
#define elif else if
#define debug(var) cerr << #var << " : " << var << endl;

#include <unistd.h>
