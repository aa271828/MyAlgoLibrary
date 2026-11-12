// Prime Count O(N ^ 2/3)
#include<atcoder/fenwicktree>
using namespace atcoder;
ll count(ll N) {
   LL(N);

   ll ans = 0;
   ll Y = max(1ll, (ll)(pow(N, 0.333) * pow(log(N), 0.666)));
   if (N < 10000000) Y = max(1ll, (ll)pow(N, 0.33333));
   if (N < 100) Y = 1;
   // N / Y 以下の素数テーブル
   vc<int> prime(N / Y + 1, -1);
   vl prime_list;
   rep(i,2,N / Y + 1) {
      if (prime[i] == -1) {
         prime[i] = len(prime_list);
         prime_list.eb(i);
      }
      rep(j,0,len(prime_list)) {
         ll x = prime_list[j];
         if (x > prime_list[prime[i]]) break;
         if (i * x >= len(prime)) break;
         prime[i*x] = j;
      }
   }

   if (N < 100) {
      print(len(prime_list));
      return 0;
   }
   

   ll Y_prime_idx = 0;
   while (prime_list[Y_prime_idx + 1] <= Y) Y_prime_idx ++ ;

   ans = Y_prime_idx;

   // p * q <= N、Y < p,q
   ll q_ptr = len(prime_list) - 1;
   rep(i,Y_prime_idx + 1, INF) {
      while (i <= q_ptr && prime_list[i] * prime_list[q_ptr] > N) q_ptr -- ;
      if (i > q_ptr) break;
      ans -= q_ptr - i + 1;
   }

   // phi(N, Y_prime_idx)の導出
   vc<tlll> phi_st; // (x, a, cnt)
   auto phi = [&](auto self, ll x, ll a, ll cnt) -> void {
      if (x == 0) return;
      if (a == -1) {ans += x * cnt; return;}
      if (x <= Y) {phi_st.eb(x, a, cnt) ; return ;}
      self(self, x, a-1, cnt);
      self(self, x / prime_list[a], a-1, -cnt);
   };
   phi(phi, N, Y_prime_idx, 1);

   // phi_stをx昇順にソート
   {
      vvc<tlll> bak(Y + 1);
      while (len(phi_st)) {
         bak[get<0>(phi_st.back())].eb(phi_st.back());
         phi_st.pop_back();
      }
      for (auto x: bak) for (auto y: x) phi_st.eb(y);
   }
   fenwick_tree<ll> fw(len(prime_list));
   ll mac_m = 2;
   for (auto [x, a, cnt]: phi_st) {
      for ( ; mac_m <= x ; mac_m ++ ) {
         fw.add(prime[mac_m], 1);
      }
      ans += (x - fw.sum(0, a + 1)) * cnt; 
   }

   return ans;
}
