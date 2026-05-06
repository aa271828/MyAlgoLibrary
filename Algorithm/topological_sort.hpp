#include "../template/main.hpp"
//トポロジカルソート topological sort
vector<ll> TS(vvl g)
{
    ll n = g.size() ;
    set<pll>st;//入次数、id
    vector<ll> ee(n , 0) ;
    rep(i,0,n){
        for(ll x : g[i]){
            ee[x] ++ ;
        }
    }
    rep(i,0,n){
        st.insert({ee[i] , i}) ;
    }
    vector<ll> ret ;
    while(!st.empty()){
        ll i = (*st.begin()).second ;
        st.erase(st.begin()) ;
        //iを削除する
        for(ll x : g[i]){
            if(st.find({ee[x] , x}) == st.end())continue ;
            st.erase({ee[x] , x}) ;
            ee[x] -- ;
            st.insert({ee[x] , x});
        }
        ret.push_back(i) ;
    }
    return ret; 
}
