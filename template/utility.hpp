#pragma once
void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }

//あまり(負の数対応)
template<typename T>
T ovr(T a,T b){
   T ret=a%b;
   if(ret<0)ret+=b;
   return ret;
}
template<typename T>
bool chmax(T &a, T b) {
   if (a < b) {
      a = b;
      return 1;
   }
   return 0;
}
template<typename T>
bool chmin(T &a, T b) {
   if (a > b) {
      a = b;
      return 1;
   }
   return 0;
}

// Map with Default Value
template<typename S,typename T>
struct default_map:map<S,T>{
    T def;
    explicit default_map(T def):def(def){}
    T&operator[](const S&i){return map<S,T>::emplace(i,def).first->second;}
};
