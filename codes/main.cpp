//
//  main.cpp
//  palindrome
//
//  Created by 정혜진 on 2018. 9. 21..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <cstdio>
#include <cstring>

using namespace std;

int arr[2002];
int memo[2002][2002];

int result(int start, int end){
    if(start==end) return 1;
    if(end-start==1){
        if(arr[start]==arr[end]) return 1;
    }
    
    int& ret = memo[start][end];
    if(ret!=-1) return ret;
    
    if(arr[start]!=arr[end]) return ret = 0;
    return ret = result(start+1, end-1);
}

int main(int argc, const char * argv[]) {
    
    memset(memo,-1,sizeof(memo));
    
    int N, M;
    scanf("%d", &N);
    
    for (int i=1; i<N+1; i++) {
        scanf("%d", &arr[i]);
    }
    
    int start, end;
    
    scanf("%d", &M);
    while(M--){
        scanf("%d %d", &start, &end);
        printf("%d\n", result(start, end));
    }
    
    
}
