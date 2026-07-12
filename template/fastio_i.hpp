#pragma once

namespace interactive_internal {
    template <typename T>
    void send_single(const T& val) {
        cout << val;
    }
    template <typename T>
    void send_single(const vector<T>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i] << (i + 1 == vec.size() ? "" : " ");
        }
    }

    // 入力用ヘルパー
    template <typename T>
    void read_single(T& val) {
        cin >> val;
    }
    template <typename T>
    void read_single(vector<T>& vec) {
        for (auto& x : vec) cin >> x;
    }
    template <typename T>
    void read_single(vector<vector<T>>& vec) {
        for (auto& v : vec) {
            for (auto& x : v) cin >> x;
        }
    }
} // namespace interactive_internal

// --- インタラクティブ用 I/O 関数 ---
// 引数なしの場合は改行＋フラッシュのみ
void print() {
    cout << endl;
}

// 可変長引数を空白区切りで順に出力し、最後に改行＋フラッシュ
template <typename Head, typename... Tail>
void print(Head&& head, Tail&&... tail) {
    interactive_internal::send_single(forward<Head>(head));
    if constexpr (sizeof...(Tail) > 0) {
        cout << " ";
        print(forward<Tail>(tail)...);
    } else {
        cout << endl; // 最後の要素の後に改行とフラッシュ(endl)を行う
    }
}

void read() {}
template <typename Head, typename... Tail>
void read(Head& head, Tail&... tail) {
    interactive_internal::read_single(head);
    read(tail...);
}

// --- 入力マクロ ---
#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                         \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

// --- 高速化用の構造体 ---
struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup; // インスタンスを生成することで、mainの前にコンストラクタが走る
