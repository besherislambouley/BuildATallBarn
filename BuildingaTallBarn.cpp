/*
 * lets define f(i,x) = a[i]/x - a[i]/(x+1) as the benefit of adding a new cow to this building, the brute force solution is to loop k times choosing the max f(i,x)
 * instead we can use bianry search to choose the limit of the previous benifit and check if we can achieve it
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
//#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
ll n , k ;
ll a[100009];
ll check ( double x ) {
	ll sum = 0 ;
	for ( int i = 0 ; i < n ;i ++ ) {
		sum += ll (( sqrt(1 + 4*a[i]/x)-1)/2);
	}
	return sum ;
}
int main (){
	ifstream fin ("tallbarn.in");
	ofstream fout ("tallbarn.out");
	fin >> n >> k ;
	k -= n ;
	for ( int i = 0 ; i < n ; i ++ ) fin >> a[i];
	double l = 0  , r = 1e18;
	for ( int i = 0 ; i < 200 ; i ++ ) {
		double mid = ( r + l ) / 2 ;
		if ( check ( mid ) >= k ) l = mid ;
		else r = mid ;	
	}
	double ans = 0 ;
	ll sum = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		ll x = ll((sqrt(1+4*a[i]/l)-1)/2);
		ans += 1.0*a[i]/(x+1);
		sum += x ;
	}
	fout << (ll) round ( ans - ( k - sum ) * l ) << endl ;
}
