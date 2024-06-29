#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//decimal to binary.....

string decimalToBinary(int n){
    string ans = "";

    while(n!=0){
        if(n%2==1){
            ans = "1" + ans;
        }else{
            ans = "0" + ans;
        }

        n = n/2;
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

// operators...
// check if the ith bit is set or not...

bool checkIthBit(int n,  int i){
  int mask = 1 << i;
  return (n & mask) != 0;
}


int convertTodecimal(string n){
    int length = n.size();
    int ans = 0;
    int power = 1;

    for (int  i = length; i >= 0; i--)
    {
      if(n[i] == '1'){
          ans =  ans + power;
      }

      power = power * 2;
}    

return ans;
}
    
// swap 2 numbers.....
// using xor operator  from xor of same number is 0 property...

void swap(int a,  int b){
    a = a^b;
    b = a^b; // b = (a^b)^b = a 
    a = a^b; // a = (a^b)^a = b

    cout << a << " " << b << endl;
}

// check if it h bit is set or not...

int main(){
    int n = 14;
    string ans = decimalToBinary(n);
    int ans1 = convertTodecimal(ans);
    swap(2, 3);
    
    cout << ans << endl; 
    cout << ans1 << endl;
    return 0;
}