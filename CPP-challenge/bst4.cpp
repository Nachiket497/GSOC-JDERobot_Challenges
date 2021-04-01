
#include <bits/stdc++.h>
#include "functions.h"
  
using namespace std;



int bst4(char arr[][200] , int n , int m , int i , int j ,int op , int count ){
           if( n < 0 || n>= i || m < 0 || m >= j ){
        return 0 ;
    }
    char chr = arr[n][m] ;
    int com = 46 ;
    if ( chr != com){
        return 0 ;
    }
    arr[n][m] = (char)( count+48) ;
    if( op == 0 ){
        int c2  = bst4( arr , n , m+1 , i , j , 2 , count + 1);
        int c4  = bst4( arr , n , m-1 , i , j , 4, count + 1); 
        int c1  = bst4( arr , n+1 , m , i , j, 1 , count + 1);
        return 1 + c1+c2 +c4;
    }
    else if( op == 1){
        int c2  = bst4( arr , n , m+1 , i , j , 2 , count + 1);
        int c4  = bst4( arr , n , m-1 , i , j , 4 , count +1 ); 
        int c1  = bst4( arr , n+1 , m , i , j, 1 , count + 1);
        return 1 + c1+c2  +c4;
    }
    else if( op == 2){
        int c2  = bst4( arr , n , m+1 , i , j , 2 , count +1 );
        int c1  = bst4( arr , n+1 , m , i , j, 1 , count+1);
        return 1 + c1+c2  ;
    }
    else if ( op == 3){
        int c4  = bst4( arr , n , m-1 , i , j , 4 , count +1); 
        int c2  = bst4( arr , n , m+1 , i , j , 2 , count +1);
        return 1 +c2 +c4;
    }
    int c4  = bst4( arr , n , m-1 , i , j , 4 , count +1); 
    int c1  = bst4( arr , n+1 , m , i , j, 1 , count +1);
    return 1 + c1  +c4;


}
