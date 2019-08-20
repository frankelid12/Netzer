#include <cstdio>
#include <algorithm>
using namespace std;

long long base(long long n)
{
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int main() {
    int num_of_test_cases;
    scanf("%d", &num_of_test_cases );
    for( int i = 1; i <= num_of_test_cases; i++ ) {
        long long l, h, n, d1, d2;
        scanf("%lld%lld%lld%lld%lld", &l, &h, &n, &d1, &d2 );
        long long firstt = base( n + l* h - 1 ) ^ base( n - 1 );
        long long secondt = 0;
        long long xo, yo, xt, yt;
        xo = ( d1 - n ) / l + 1;
        yo = (d1 - n + 1 ) - ( xo - 1 ) * l;
        xt = ( d2 - n ) / l + 1;
        yt = ( d2 - n + 1 ) - ( xt - 1 ) * l;
        if( xo > xt ) swap( xo, xt );
        if( yo > yt ) swap( yo, yt );

        for( int j = xo; j <= xt; j++ ) {
            long long le = n + yo - 1 + ( j - 1 ) * l;
            long long ri = n + yt + ( j - 1 ) * l - 1;
            secondt ^= base( ri ) ^ base( le - 1 );
        }
        long long result = firstt ^ secondt;
        printf("%lld\n", result );
    }
    return 0;
}