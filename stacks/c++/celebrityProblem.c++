#include <vector>
using namespace std;


// more of a metrix problem


  int celebrityBrute(vector<vector<int>>& M, int N){
    for (int celeb = 0; celeb < N; celeb++)
    {   bool isCeleb = true;
         
         for (int i = 0; i < N; i++)
         {
           if(i != celeb){
              if(M[celeb][i] == 1 || M[i][celeb] == 0){
                isCeleb = false;
                break;
              }
           }
         }


         if(isCeleb){
            return celeb;
         }     
    }
    
    return -1;
  }


 int celebrity(vector<vector<int>>& M, int N) {
    
 }
