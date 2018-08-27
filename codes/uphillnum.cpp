//
//  main.cpp
//  uphillnum
//
//  Created by 정혜진 on 2018. 7. 17..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <stdio.h>
#include <cstring>

using namespace std;

int n;

int memo[1001][10];

int find(int wh, int st){
    if(wh>=n) return 1;
    
    int& ret = memo[wh][st];
    if(ret!=-1) return ret;
    
    ret = 0;
    for(int i=st; i<10; i++){
        ret += find(wh+1, i)%10007;
    }
    
    return ret%10007;
}

int main(int argc, const char * argv[]) {
    memset(memo,-1,sizeof(memo));
    scanf("%d", &n);
    printf("%d\n", find(0,0));
}
