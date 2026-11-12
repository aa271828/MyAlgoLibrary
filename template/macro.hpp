#pragma once
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
using tlll = tuple<ll,ll,ll>;
using tllll = tuple<ll,ll,ll,ll>;
using vp = vector<pl>;
using vvp = vector<vp>;
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
#define rep1(i,a) for(ll i=(ll)0; i<(ll)a; i++)
#define rep2(i,a,b) for(ll i=(ll)a; i<(ll)b; i++)
#define rrep1(i,a) for(ll i=(ll)b-1; i>=(ll)0; i--)
#define rrep2(i,a,b) for(ll i=(ll)b-1; i>=(ll)a; i--)
#define REP(_1, _2, _3, NAME, ...) NAME
#define rep(...) REP(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define RREP(_1, _2, _3, NAME, ...) NAME
#define rrep(...) RREP(__VA_ARGS__, rrep2, rrep2)(__VA_ARGS__)
#define all(vec1) (vec1).begin(), (vec1).end()
#define rall(vec1) (vec1).rbegin(), (vec1).rend()
#define len(x) ll(x.size())
#define eb emplace_back
#define elif else if
#define debug(var) cerr << #var << " : " << var << endl;

#include <unistd.h>
