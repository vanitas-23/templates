#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD=1e9+7;

class DisjointSet {
    public:
        DisjointSet(int n) : N(n), sz(n), pars(n, -1) {
        }
        void reset() { sz = N, fill(pars.begin(), pars.end(), -1); }
        int find(int x) { return pars[x] < 0 ? x : pars[x] = find(pars[x]); }
        int size() { return sz; }
        int count(int x) { return -pars[find(x)]; }
        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) { return false; }
            --sz;
            if (pars[x] < pars[y]) { swap(x, y); }
            pars[y] += pars[x];
            pars[x] = y;
            return true;
        }
        bool isSame(int x, int y) { return find(x) == find(y); }
    private:
        int N, sz;
        vector<int> pars;
};
class FenwickTree {
 
public:
   FenwickTree(int n) : maxPositions(n),tree(n+1){}
  void add(int pos, long long val) {
    int treePos = pos + 1;
    while (treePos <= maxPositions) {
      tree[treePos] += val;
      treePos += (treePos & -treePos);
    }
  }
   void update(int pos, long long val, long long curr) {
    int treePos = pos + 1;
    while (treePos <= maxPositions) {
      tree[treePos] -= val;
      tree[treePos]+=curr;
      treePos += (treePos & -treePos);
    }
  }
  long long sum(int begin, int end) {
    long long beginValue = accumulatedValue(begin);
    long long endValue = accumulatedValue(end);
    return endValue - beginValue;
  }
 
private:
  long long accumulatedValue(int pos) {
    long long value = 0;
    while (pos) {
      value += tree[pos];
      pos -= (pos & -pos);
    }
    return value;
  }
   int maxPositions =  1;
 
  vector<ll> tree;
};

struct Tree {
	typedef long long T;
	static constexpr T unit = INT_MIN; //unit value
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

ll mod_expo(ll a,ll b)
{
    int m=998244353;
    ll ans = 1;
    while(b>0){
        if(b&1)
        ans = (ans*a)%m;
        b = b >> 1;
        a = (a * a)%m;
    }
    return ans%m;
}
bool isprime(int x)
{
    if(x <= 1) return false;
    if(x == 2 || x == 3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    if((x - 1) % 6 != 0 && (x + 1) % 6 != 0) return false;
    for(int i = 5; i * i <= x; i += 6)
    {
        if(x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}
 std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

std::vector<int> searchKMP(const std::string& s, const std::string& a) {
    std::vector<int> result;
    int n = s.length();
    int m = a.length();
    std::vector<int> lps = computeLPS(a);
    
    int i = 0;
    int j = 0;
    
    while (i < n) {
        if (a[j] == s[i]) {
            j++;
            i++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && a[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}

ll nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    ll ans = 1;
    for (int i = n - k + 1; i <= n; i++) ans *= i;
    for (int i = 1; i <= k; i++) ans /= i;
    return ans;
}

vector<int> seiveOFE(int n) {
    vector<int> primes;
    vector<int> primesFound;
    primesFound.push_back(2);
    for (int num = 3; num <= n; num += 2) {
        bool isPrime = true;
        for (int prime : primesFound) {
            if (prime * prime > num) {
                break;
            }
            if (num % prime == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primesFound.push_back(num);
        }
    }
    return primesFound;
}
 vector<int> findFactors(int n) {
    vector<int> factors;
    int sqrtN = static_cast<int>(sqrt(n));
    for (int i = 1; i <= sqrtN; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

map<ll,ll> primeFactors(ll n) {
    map<ll,ll> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (ll d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization[n]++;;
    return factorization;
}
typedef pair<ll, int> pli;
ll noF(ll a)
{
  auto x=primeFactors(a);
       ll ans=1;
       for(auto i:x)
      {
          ans*=(1+i.second);
      }
      return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(12);
    const int MAXN = 2000010;
    vector<long long> FS(MAXN, 1), IFS(MAXN, 1), invs(MAXN, 1);
    for (int i = 2; i < MAXN; ++i) {
        FS[i] = FS[i - 1] * i % MOD;
        invs[i] = MOD - MOD / i * invs[MOD % i] % MOD;
        IFS[i] = IFS[i - 1] * invs[i] % MOD;
    }
    auto nCr = [&](int n, int r) {
        if (r < 0 || r > n) {
            return 0LL;
        }
        return FS[n] * IFS[r] % MOD * IFS[n - r] % MOD; 
    };
    
    
    int t=1;
    
    //cin>>t;
   
    while(t--)
    {
      
        
    }
 return 0;
}