#include<iostream>

using namespace std;

void AdjustMarks(int marks, bool late){
    if(late && (marks > 40)){
          marks = 40;
    }

};


int main(){
    int main_marks = 50;

    AdjustMarks(main_marks, true);

    cout << main_marks << endl;

    return 0;
}

//Pass by Value: Changes to function parameters passed by value do not affect the original arguments.
//Conditional Logic: Conditions inside functions can change local copies of parameters.
//Function Effectiveness: To modify the original argument, consider passing by reference or using pointers.