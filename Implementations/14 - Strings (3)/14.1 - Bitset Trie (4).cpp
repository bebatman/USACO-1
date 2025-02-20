/**
 * Description: query max xor with some int in the trie
 * Source: CF Algorithms Gym
 * Verification: January Easy 2018 - Shubham and Subarray Xor
 */

template<int MX, int MXBIT> struct Trie {
    int nex[MX][2], sz[MX], num = 0; // num is last node in trie
    // change 2 to 26 for lowercase letters

    Trie() {
        memset(nex,0,sizeof nex);
        memset(sz,0,sizeof sz);
    }

    void ins(ll x, int a = 1) { // insert or delete
        int cur = 0; sz[cur] += a;
        F0Rd(i,MXBIT) {
            int t = (x&(1LL<<i))>>i;
            if (!nex[cur][t]) nex[cur][t] = ++num;
            sz[cur = nex[cur][t]] += a;
        }
    }

    ll test(ll x) { // compute max xor
        if (sz[0] == 0) return -INF; // no elements in trie
        int cur = 0;
        F0Rd(i,MXBIT) {
            int t = ((x&(1LL<<i))>>i) ^ 1;
            if (!nex[cur][t] || !sz[nex[cur][t]]) t ^= 1;
            cur = nex[cur][t]; if (t) x ^= 1LL<<i;
        }
        return x;
    }
};
