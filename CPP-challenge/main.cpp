#include <bits/stdc++.h>
#include "functions.h"
  
using namespace std;
int main(){

    int i = 0, j = 0  , k= 0 , n = 0 , m = 0 , t = 0;

    char arr[200][200] ; 

    int max_count = 0 , max_i = -1 , max_j = -1 ;
    ifstream fin; 
    ofstream fout; 

    string line; 

    fin.open("input.txt"); 
    fout.open("output.txt");

    while (fin) { 
        getline(fin, line); 
        j = line.size();
    //    std::cout << line << i << endl; 

        for (k = 0 ; k<j ; k++){
            arr[i][k] = line[k] ;
        }
        i ++ ;
    } 
    for(n = 0 ; n < i ; n++){
        for(m= 0 ; m< j ; m++){
    //        cout<<arr[n][m]  ;

            if ( arr[n][m] == '.'){
                int count = bst3(arr , n , m , i , j , 0);
                if ( count > max_count){
                    max_count = count ;
                    max_i = n ;
                    max_j = m ;
                }
            }
        }
    }
  //  cout << max_count <<max_i << max_j <<endl;
  t = 0 ;

  bst4(arr , max_i , max_j , i , j  ,0 ,0 );
    for(n = 0 ; n < i ; n++){
        for(m = 0 ; m < j ; m ++){
            if( !(arr[n][m] == '#' ||  arr[n][m] == '.' ) ){
                  t ++ ;
            }
        }
    }
    fout << t <<endl ;
    for(n = 0 ; n < i ; n++){
        line = arr[n] ;
        fout << line << endl;
    }

    return 0 ;
}
