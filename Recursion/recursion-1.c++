#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void func(int n){
    if(n>0){
        cout << n << endl;

        func(n-1);
    }

}

void func2(int n){
    if(n > 0){
      func2(n-1);

      cout << n << endl;
    }
}

stack<int> fstatic(int n){
    static int x = 0;
    stack<int> ans;


    if (n == 0) {
        return ans;
    }

    x++;
    ans = fstatic(n - 1);
    if (!ans.empty()) {
        int val = ans.top() + x;
        ans.push(val);
    } else {
        ans.push(x);
    }
   
    return ans;
}

void TreeRec(int n){
    if(n > 0){
        cout << n << endl;

        TreeRec(n - 1);

        TreeRec(n - 1);
    }
}

int sumOfNum(int n){
    if(n == 0){
        return 0;
    }else{
        return sumOfNum(n-1) + n;
    }
}

int prodOfN(int n){
    if(n == 1){
        return 1;
    }else{
        return prodOfN(n-1) * n;
    }
}

int power(int m, int n){
   if(n == 1){
      return m;
   }else{
    return power(m,n-1)*m;
   }
}

int powOpt(int m, int n){
     if(n == 1){
      return m;
    }
    if(n%2 == 0) {
        return powOpt(m*m, n/2);
    }else{
        return m * powOpt(m*m, (n-1)/2);
    }

}

// void func3(int n){
//    if(n >= 10 ){
//     return;
//    }
//    func3(n+1);
//    cout << n << endl;
// }


int main(){
  
//   TreeRec(5);


  int re = powOpt(2, 2);
  cout << re << endl;
//   stack<int> a = fstatic(5);
  
//   while (!a.empty())
//   {
//       cout << a.top() << endl;
//       a.pop();
//   }
  

    return 0;
}