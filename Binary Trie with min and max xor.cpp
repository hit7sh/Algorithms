class Trie {
public:
  struct node {
    node* child[2];
    node() {
      child[0] = child[1] = nullptr;
    }
  };
  node* root;

  Trie() {
    root = new node();
  }

  void insert(int n) {
    node* t = root;
    for (int i = 29; i >= 0; i--) {
      if (n >> i & 1) {
        if (!t->child[1]) t->child[1] = new node();
        t = t->child[1];
      } else {
        if (!t->child[0]) t->child[0] = new node();
        t = t->child[0];
      }
    }
  }

  int mxxor(int n) {
    // what is the max xor with n
    int ans = 0;
    node* t = root;
    for (int i = 29; i >= 0; i--) {
      if (n >> i & 1) {
        if (t->child[0]) t = t->child[0], ans |= 1 << i;
        else t = t->child[1];
      } else {
        if (t->child[1]) t = t->child[1], ans |= 1 << i;
        else t = t->child[0];
      }
    }
    return ans;
  }
  
  int minxor(int n) {
    // what is the min xor with n
    int ans = 0;
    node* t = root;
    for (int i = 29; i >= 0; i--) {
      if (n >> i & 1) {
        if (t->child[1]) t = t->child[1];
        else t = t->child[0], ans |= 1 << i;
      } else {
        if (t->child[0]) t = t->child[0];
        else t = t->child[1], ans |= 1 << i;
      }
    }
    return ans;
  }
};
