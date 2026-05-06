#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll , ll>;
using vl = vector<ll> ; //1D
using vvl = vector<vl> ;//2D
using vvvl = vector<vvl> ;//3D
using vp = vector<pll> ; //1D
using vvp = vector<vp> ;//2D
using vvvp = vector<vvp> ;//3D
using vi = vector<int> ; //1D
using vvi = vector<vi> ;//2D
using vvvi = vector<vvi> ;//3D
using vb = vector<bool> ; //1D
using vvb = vector<vb> ;//2D
using vvvb = vector<vvb> ;//3D
using vs = vector<string> ; //1D
using vvs = vector<vs> ;//2D
using vvvs = vector<vvs> ;//3D
const ll INF = 2e18 ;
const ll MOD = 998244353;
#define rep(i,a,b) for(ll i=(ll)a; i<(ll)b; i++)
#define rrep(i,a,b) for(ll i=(ll)b-1; i>=(ll)a; i--)
#define all(vec1) (vec1).begin(), (vec1).end()
#define rall(vec1) (vec1).rbegin(), (vec1).rend()
#define yn(b,ex) if(1){if(b)cout << "Yes" << endl;else cout << "No" << endl ;if(ex)return 0;}
#define debug(var) cerr << #var << " : " << var << endl;

//fastio
struct FastIO {
   FastIO() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
   }
};
inline FastIO fastio;
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
template <typename T>
void in(vector<T> &A) {
   for(auto&&a:A) cin >> a;
}
template <typename T, typename S>
void in2(vector<T> &A, vector<S> &B) {
   assert(A.size() == B.size());
   for (size_t i = 0; i < A.size() ; i ++ ) {
      cin >> A[i] >> B[i];
   }
}
const vi dx = {-1,0,1,0};
const vi dy = {0,1,0,-1};

