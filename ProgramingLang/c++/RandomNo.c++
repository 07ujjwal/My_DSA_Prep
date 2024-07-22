#include<cstdlib>
#include<time.h>
#include<iostream>

using namespace std;

// generates random noumber from 0 to 1;
int main(){
    //srand is used to seed the random number generator.
    // The seed value determines the sequence of random numbers generated by rand.
    //time(NULL) returns the current time in seconds since the Unix epoch (January 1, 1970). 
    //Using the current time as the seed ensures that the sequence of random numbers is different each time the program runs.
     
    srand(time(NULL));

    //rand() generates a pseudo-random integer between 0 and RAND_MAX (a constant defined in <cstdlib> which is typically 32767).
    //The % 10 operation takes the remainder of dividing the random number by 10, resulting in a number between 0 and 9. 
     
    int num = rand() % 10;

    cout << num << endl;
  
    return 0;
}