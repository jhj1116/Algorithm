//
//  main.cpp
//  upstair
//
//  Created by 정혜진 on 2018. 3. 31..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int memo[302][2];
int value[302];

int sum(int p, int j){
    
    if(p < 1) return 0;
    
    int& ret = memo[p][j];
    if(ret != -1) return ret;
    
    if(j==1)
        return ret = sum(p-2,2) + value[p];
    else
        return ret = max(sum(p-1,1),sum(p-2,2)) + value[p];
    
}

int main(int argc, const char * argv[]) {
    
    memset(memo, -1, sizeof(memo));
    
    scanf("%d",&N);
    
    for(int i=1; i<=N; i++){
        scanf("%d",&value[i]);
    }
    
    int result = max(sum(N,2),sum(N,1));
    
    printf("%d",result);
    
}
