//
//  main.cpp
//  filltile
//
//  Created by 정혜진 on 2018. 7. 12..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int memo[31];

int fill(int n){
    //if(n%2==1) return 0;
    if(n==0) return 1;
    
    int& ret = memo[n];
    if(ret!=-1) return ret;

    ret = 0;
    ret = fill(n-2) + fill(n-2) + fill(n-2);
    for(int i=4; i<=n; i+=2){
        ret += fill(n-i) + fill(n-i);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    memset(memo,-1,sizeof(memo));
    printf("%d\n", fill(N));
}
