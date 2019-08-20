#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long llu;

int main( void ) {
    int Q;
    scanf("%d", &Q );
    while( Q-- ) {
        llu a, b;
        scanf("%llu%llu", &a, &b );
        int sol = 0;
        llu at = a, bt = b;
        int de1 = 0, de2 = 0;
        while( at > 0 ) {
            de1++;
            at /= 2LLU;
        }
        while( bt > 0 ) {
            de2++;
            bt /= 2LLU;
        }
        if( de1 > de2 ) {
            swap( a, b );
            swap( de1, de2 );
        }
        b /= ( llu )( 1 << ( llu )( de2 - de1 ) );
        sol += de2 - de1;
        while( a != b ) {
            a /= 2LLU;
            b /= 2LLU;
            sol += 2;
        }
        printf("%d\n", sol);
    }
    return 0;
}