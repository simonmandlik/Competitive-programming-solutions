#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

double dp[560][3400];
int main() 
{
	int i , j , k ;
	memset( dp , 0 , sizeof( dp ) ) ;
	for( i = 1 ; i < 7 ; i++ )
	 dp[1][i] =(double) 1.0 / 6.0;
	for( i = 2 ; i <= 550 ; i++ )
	 {
	 	for( j = 1 ; j <= 3300 ; j++ )
	 	 {
	 	 	for( k = 1 ; k < 7 ; k++ )
	 	 		if( ( j - k ) >= 0)
	 	 			dp[i][j] += ( dp[i-1][j-k] / 6.0 ) ;
	 	 }
	 }
	int t ;
	scanf("%d",&t);
	while ( t-- )
	{
		int n , k ;
		scanf("%d%d",&n,&k);
		if( n > 550 || k > 3300 )
		 	printf("0\n");
		else
			{
				long long int ans = ( dp[n][k] * 100.0 );
				printf("%lld\n",ans);
			}
	}
	return 0;
}
