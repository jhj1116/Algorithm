//
//  main.cpp
//  pinary
//
//  Created by 정혜진 on 2018. 7. 15..
//  Copyright © 2018년 정혜진. All rights reserved.
//


#include <stdio.h>
#include <cstring>


using namespace std;

int n;
long long memo[91][2];

long long pinary(int wh, int st){
    if(wh>=n) return 1;
    
    long long& ret = memo[wh][st];
    if(ret!=-1) return ret;
    
    if(st==0)
        return ret= pinary(wh+1, 1) + pinary(wh+1, 0);
    
    else
        return ret = pinary(wh+1, 0);
}

int main(int argc, const char * argv[]) {
    memset(memo, -1, sizeof(memo));
    scanf("%d", &n);
    printf("%lld\n", pinary(1,1));
}
