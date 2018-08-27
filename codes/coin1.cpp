
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int c[101];


int count(int m, int n){
    int memo[n+1];
    memset(memo, 0, sizeof(memo));
    memo[0] = 1;
    
    for(int i=0; i<m; i++)
        for(int j=c[i]; j<=n; j++)
            memo[j] += memo[j-c[i]];
    
    return memo[n];
    
}


int main(int argc, const char * argv[]) {
    int N,k;
    scanf("%d", &N);
    scanf("%d", &k);
    
    int i=0;
    int n=N;
    while(n--){
        scanf("%d",&c[i]);
        i++;
    }

    
    printf("%d",count(N,k));
}
