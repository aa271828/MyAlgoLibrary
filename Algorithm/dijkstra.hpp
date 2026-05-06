#pragma once
#include "../template/main.hpp"
// {cost, to}
vl dijkstra(ll n, vvp g) {
  vl dp(n,INF);
  set<pll> st;
  rep(i,0,n)st.insert(make_pair(INF,i));
  auto upd_sc=[&](ll i,ll x)->ll{
    if(dp[i] <= x || st.find(make_pair(dp[i],i)) == st.end()){
      return 0;
    }
    st.erase(make_pair(dp[i],i));
    dp[i] = x;
    st.insert(make_pair(dp[i],i));
    return 0;
  };
  upd_sc(0,0);
  rep(i,0,n){ //?n-1かも?
    auto beg = st.begin();
    pll begp = (*beg);
    st.erase(*beg);
    //begから伸びるもの
    for(pll x : g[begp.second]){
      upd_sc(x.second,dp[begp.second] + x.first);
    }
  }
  return dp;
}
