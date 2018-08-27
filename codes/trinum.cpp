//
//  main.cpp
//  tri_num
//
//  Created by 정혜진 on 2018. 3. 29..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int memo[501][501];
int value[501][501];


int sum(int p, int q){
    
    if(p==N-1) return value[p][q];
    
    int& ret = memo[p][q];
    if(ret != -1) return ret;
    
    return ret = max(sum(p+1,q), sum(p+1, q+1)) + value[p][q];
    
}


int main(int argc, const char * argv[]) {
   
    memset(memo, -1, sizeof(memo));
    
    scanf("%d",&N);
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<i; j++){
            scanf("%d",&value[i-1][j]);
        }
    }
    
    int result = sum(0,0);
    
    printf("%d",result);
}

