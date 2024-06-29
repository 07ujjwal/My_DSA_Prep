#include<iostream>
using namespace std;

// square......

void patter1(int n){
    int i = 1;
    while (i <= n)
    {   int j = 1;
        while(j <= n){
            cout << "*" << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

//1 1 1
//2 2 2
//3 3 3

void patter2(int n){
    int i = 1;
    while (i <= n)
    {   int j = 1;
        while(j <= n){
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

// 1 2 3
// 1 2 3
// 1 2 3

void patter3(int n){
    int i = 1;
    while (i <= n)
    {   int j = 1;
        while(j <= n){
            cout << j << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

// 3 2 1
// 3 2 1
// 3 2 1

void patter4(int n){
    int i = 1;
    while (i <= n)
    {   int j = n;
        while(j > 0){
            cout << j << " ";
            j--;
        }
        cout << endl;
        i++;
    }
}


// 1 1 1 1  4 4 4 4      1 2 3 4   4 3 2 1
// 2 2 2    3 3 3        2 3 4     3 2 1
// 3 3      2 2          3 4       2 1
// 4        1    n-i+1   4     j   1     n-j+1


void patter5(int n){
    int i = 1;
    while (i <= n)
    {   int j = i; // j = i
        while(j <= n){
            cout << i << " "; 
            j++;
        }
        cout << endl;
        i++;
    }
}

// 1 2 3
// 4 5 6
// 7 8 9 

void patter6(int n){
    int i = 1;
    int k = 1;
    while (i <= n)
    {   int j = 1; 
        while(j <= n){
            cout << k << " "; 
            j++;
            k++;
        }
        cout << endl;
        i++;
    }
}

// *
// * * 
// * * *

void patter7(int n){
    int i = 1;
    while (i <= n)
    {   int j = n-i+1; 
        while(j <= n){
            cout << "*" << " "; 
            j++;
        }
        cout << endl;
        i++;
    }
}

// 1
// 2 2 
// 3 3 3

void patter8(int n){
    int i = 1;
    while (i <= n)
    {   int j = n-i+1; 
        while(j <= n){
            cout << i << " "; 
            j++;
        }
        cout << endl;
        i++;
    }
}

// 1
// 2 3 
// 4 5 6

void patter9(int n){
    int i = 1;
    int count = 1;
    while (i <= n)
    {   int j = n-i+1; 
        while(j <= n){
            cout << count << " "; 
            j++;
            count++;
        }
        cout << endl;
        i++;
    }
}


// 1
// 2 3 
// 3 4 5
// 4 5 6 7

void patter10(int n){
    int i = 1;
    while (i <= n)
    {  
        // int j = n-i+1; 
        // int count = i;
        int j = 1;
        while(j <= i){
            cout << i + j - 1 << " "; 
            j++;
            // count++;
        }
        cout << endl;
        i++;
    }
}


// 1
// 2 1 
// 3 2 1
// 4 3 2 1

void patter11(int n){
    int i = 1;
    while (i <= n)
    {   int j =  1; 
        // int count = i;
        while(j <= i){
            cout << i-j+1 << " "; 
            j++;
            // count--;
        }
        cout << endl;
        i++;
    }
}


// A A A
// B B B
// C C C 

void patter12(int n){
    int i = 1;
    
    while (i <= n)
    {   int j = 1; 
        while(j <= n){
            char ch = 'A' + i  - 1;
            cout << ch << " "; 
            j++;
           
        }
        cout << endl;
        i++;
    }
}


// A A A                  A B C
// B B B                  D E F
// C C C 'A' + i  - 1;    I J K  take a variable 

void patter13(int n){
    int i = 1;
   
    while (i <= n)
    {   int j = 1; 
        while(j <= n){
            char ch = 'A' + i + j - 2;
            cout << ch << " "; 
            j++;
           
        }
        cout << endl;
        i++;
    }
}


// A
// B B 
// C C C

void patter14(int n){
    int i = 1;
    while (i <= n)
    {   int j = 1; 
        while(j <= i){
            char ch = 'A' + i - 1;
            cout << ch << " "; 
            j++;
        }
        cout << endl;
        i++;
    }
}


// A
// B C 
// C D E

void patter15(int n){
    int i = 1;
    
    while (i <= n)
    {   int j = 1; 
        while(j <= i){
            char ch = 'A' + i + j - 2;
            cout << ch << " "; 
            j++;
             ch = ch + 1;
        }
        cout << endl;
        i++;
    }
}

// D
// B C 
// A B C 

void patter16(int n){
    int i = 1;
    
    while (i <= n)
    {   int j = 1; 
         char ch = 'A' + n - i;
        while(j <= i){
            cout << ch << " "; 
            j++;
            ch = ch + 1;
        }
        cout << endl;
        i++;
    }
}


// spaces 
//     *
//   * *
// * * * 

void patter17(int n){
    int i = 1;
    
    while (i <= n)
    {   int s = n-i;

        while(s > 0){
            cout << " " << " ";
            s--;     
        }
   
       int j = 1;

        while(j <= i){
            cout << "*" << " "; 
            j++;     
        }
      cout << endl;
        i++;
    }
}

// * * * *
//   * * *
//     * * 
//       *  

void patter18(int n){
    int i = 1;
    
    while (i <= n)
    {   int s = i-1;
        while(s > 0 ){
            cout << " " << " ";
            s--;     
        }
        int j = n - i + 1;
        while(j > 0){
            cout << "*" << " "; 
            j--;     
        }
        cout << endl;
        i++;
    }
}

// 1 1 1 
//   1 1
//     1 
 

void patter19(int n){
    int i = 1;
    
    while (i <= n)
    {   int s = i-1;
        while(s > 0 ){
            cout << " " << " ";
            s--;     
        }

        int j = n - i + 1;

        while(j > 0){
            cout << i << " "; 
            j--;     
        }
        cout << endl;
        i++;
    }
}


//     1       1
//   2 2     2 3
// 3 3 3   4 5 6 take count


void patter20(int n){
    int i = 1;
    int count = 1;

    while (i <= n)
    {   int s = n-i;
        while(s > 0 ){
            cout << " " << " ";
            s--;     
        }

        int j = 1 ;
        
        while(j <= i){
            cout << count << " "; 
            j++;  
            count++;   
        }
        cout << endl;
        i++;
    }
}

//     1
//   1 2 1
// 1 2 3 3 2 1 

void Tpattern(int n) {
    int i = 1;

    while (i <= n) {
        int s = n - i;

        while (s > 0) {
            cout << " " << " ";
            s--;
        }

        int j = 1;

        while (j <= i) {
            cout << j << " ";
            j++;
        }

        int k = i - 1;
       
        while (k >= 1) {
            cout << k << " ";
            k--;
        }

        cout << endl;
        i++;
    }
}




int main(){

    int n;
    cout << "Enter the no of rows";
    cin >> n;
    Tpattern(n);


    return 0;
}