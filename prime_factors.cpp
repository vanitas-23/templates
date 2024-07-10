#define ll long long
#include<bits/stdc++.h>
using namespace std;
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