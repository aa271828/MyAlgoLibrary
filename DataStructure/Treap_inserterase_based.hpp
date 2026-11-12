#pragma once
#include "../template/main.hpp"

// Treapしたい
struct Treap {
   int root = -1;
   struct node {
      int key;
      int pri;
      int l;
      int r;
      node(int k, int pri): key(k), pri(pri), l(-1), r(-1) {}
   };
   vector<node> dt;
   int rRot(int t) {
      int s = dt[t].l;
      dt[t].l = dt[s].r;
      dt[s].r = t;
      return s;
   };
   int lRot(int t) {
      int s = dt[t].r;
      dt[t].r = dt[s].l;
      dt[s].l = t;
      return s;
   };

   int _insert(int t, int key, int priority) {
      if (t == -1) {
         dt.eb(node(key,priority));
         return len(dt) - 1;
      }
      if (key == dt[t].key) {
         return t;
      }
      if (key < dt[t].key) {
         dt[t].l = _insert(dt[t].l, key, priority);
         if (dt[t].pri < dt[dt[t].l].pri) {
            t = rRot(t);
         }
      }
      else {
         dt[t].r = _insert(dt[t].r, key, priority);
         if (dt[t].pri < dt[dt[t].r].pri) {
            t = lRot(t);
         }
      }
      return t;
   }
   int insert(int key) {
      return root = _insert(root, key, rand());
   }

   int erase(int key) {
      return root = erase_(root, key);
   }
   int _erase(int t, int key) {
      if (dt[t].l == -1 && dt[t].r == -1) {
         return -1;
      }
      elif (dt[t].l == -1) {
         t = lRot(t);
      }
      elif (dt[t].r == -1) {
         t = rRot(t);
      }
      else {
         if (dt[dt[t].l].pri > dt[dt[t].r].pri) {
            t = rRot(t);
         }
         else {
            t = lRot(t);
         }
      }
      return erase_(t, key);
   }
   int erase_(int t, int key) {
      if (t == -1) return -1;
      if (key < dt[t].key) {
         dt[t].l = erase_(dt[t].l, key);
      }elif (key > dt[t].key) {
         dt[t].r = erase_(dt[t].r, key);
      }
      else {
         return _erase(t,key);
      }
      return t;
   }

   int lower(int key) {
      int ret = -1;
      int s = root;
      while (s != -1) {
         if (key <= dt[s].key) {
            if (ret == -1 || dt[s].key < dt[ret].key) ret = s;
            s = dt[s].l;
         }
         else {
            s = dt[s].r;
         }
      }
      return ret;
   }
   int floor(int key) {
      int ret = -1;
      int s = root;
      while (s != -1) {
         if (key >= dt[s].key) {
            if (ret == -1 || dt[s].key > dt[ret].key) ret = s;
            s = dt[s].r;
         }
         else {
            s = dt[s].l;
         }
      }
      return ret;
   }
   void _print(int t, vl&A) {
      if (t == -1) return ;
      A.eb(dt[t].key);
      print(t, dt[t].l, dt[t].r);
      _print(dt[t].l, A);
      _print(dt[t].r, A);
   }
   void print_all() {
      vl A;
      _print(root, A);
      print(A);
   }
};

