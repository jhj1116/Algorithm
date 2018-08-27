//
//  main.cpp
//  downhill
//
//  Created by 정혜진 on 2018. 7. 18..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <stdio.h>
#include <cstring>

using namespace std;

int N, M;
int values[501][501];
int memo[501][501];

int find(int m, int n){
    if(m==M-1 && n==N-1) return 1;
    
    if(m<0 || n<0 || m>M-1 || n>N-1) return 0;
    
    int& ret = memo[m][n];
    if(ret!=-1) return ret;
    
    ret = 0;
    if(values[m][n]>values[m][n+1]) ret += find(m,n+1);
    if(values[m][n]>values[m+1][n]) ret += find(m+1,n);
    if(values[m][n]>values[m][n-1]) ret += find(m,n-1);
    if(values[m][n]>values[m-1][n]) ret += find(m-1,n);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    memset(memo,-1,sizeof(memo));
    
    scanf("%d", &M);
    scanf("%d", &N);
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &values[i][j]);
        }
    }
    
    printf("%d\n", find(0,0));
}
