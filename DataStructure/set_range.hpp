#pragma once
#include "../template/main.hpp"
struct RANGE{
    set<pair<ll,ll>> a;
    ll add(ll l , ll r){
        auto it = a.lower_bound(make_pair(r+1 , -1));
        if(it == a.begin()){
            a.insert({l , r});
            return 0;
        }
        it--;
        //ここでitは最も右のかぶってるのを指してる(はず)
        set<pair<ll,ll>> tmp;
        while(true){
            if((it -> second) < l){
                break;
            }
            tmp.insert(*it);

            if(it == a.begin())break;
            it--;
        }
        for(pair<ll,ll> x : tmp){
            a.erase(x);
        }
        ll minl = l , maxr = r;
        for(pair<ll,ll> x : tmp){
            minl = min(minl , x.first) ;
            maxr = max(maxr , x.second);
        }
        a.insert(make_pair(minl , maxr));
        return tmp.size();
    }
    ll printall(){
        for(pair<ll,ll> x : a){
            cout << x.first << ' ' << x.second << endl;
        }
        cout << "end" << endl << endl;
        return 0;
    }
};
