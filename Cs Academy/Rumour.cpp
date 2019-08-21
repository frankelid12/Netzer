#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long llu;

int main( void ) {
    int Q;
    cin>>Q;
    while( Q-- ) {
        llu u, v;
        cin>>u>>v;
        int ans = 0;
        llu uu = u, vv = v;
        int depth1 = 0, depth2 = 0;
        while( uu > 0 ) {
            depth1++;
            //every time i going up level
            uu /= 2LLU;
        }
        while( vv > 0 ) {
            
            depth2++;
            vv /= 2LLU;
        }
        if( depth1 > depth2 ) {
            swap( u, v );
            swap( depth1, depth2 );
        }
        //lift the deapest node to the same level as the other one
        v /= ( llu )( 1 << ( llu )( depth2 - depth1 ) );
        //add the sub to the answer
        ans += depth2 - depth1;
        //until they wont meet in the same node the loop won't stop 
        while( u != v ) {
            u /= 2LLU;
            v /= 2LLU;
            //every loop increase the dis in 2 and going up with the nodes
            ans += 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
