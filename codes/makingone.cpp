//
//  main.cpp
//  makingone
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
int memo[1000003];

int check(int n){
    
    if(n==1) return 0;
    
    int& ret = memo[n];
    if(ret != -1) return ret;
    
    if(n%6==0)
        return ret =  1 + min(check(n/3),min(check(n/2),check(n-1)));
    
    else if(n%3==0)
        return ret = 1 + min(check(n/3),check(n-1));
    
    else if(n%2==0)
        return ret = 1 + min(check(n/2),check(n-1));
    
    else
        return ret = 1 + check(n-1);
}


int main(int argc, const char * argv[]) {
    
    memset(memo, -1, sizeof(memo));
    
    scanf("%d",&N);
    
    int result = check(N);
    
    printf("%d",result);
}
