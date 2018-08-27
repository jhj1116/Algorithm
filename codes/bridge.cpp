//
//  main.cpp
//  bridge
//
//  Created by 정혜진 on 2018. 6. 27..
//  Copyright © 2018년 정혜진. All rights reserved.
//


// Combination 조합 이용하면 끝
// = mCn
// binomial coefficient 참고

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[31][31];

int count(int n, int k){
    if(n<k) return 0;
    else if(k==0 || k==n) return 1;
    
    int& ret = memo[n][k];
    if(ret != -1) return ret;
    
    return ret = count(n-1, k-1) + count(n-1, k);
    
}

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d", &T);
    
    int N, M;
    while(T--){
        memset(memo,-1, sizeof(memo));
        scanf("%d %d", &N, &M);
        printf("%d\n", count(M,N));
    }
}
