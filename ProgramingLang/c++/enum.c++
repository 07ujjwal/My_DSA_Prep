#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

enum DaysOfWeek {Mon, Tue, Wed, Thu, Fri, Sat, Sun};

int main(){
    DaysOfWeek matchDay;
    matchDay = Sat;

    cout << matchDay << endl;


    for (int i = Mon; i < Sun; i++)
    {
       switch (i)
       {
       case Mon:{
        cout << "Its Monday" << endl;
        break;
       }

       case Tue:{
        cout << "Its Tuesday" << endl;
        break;
       }
        
       
       default:{
          cout << "Calender dekh le" << endl;
          break;
       }
       
       }
    }
    
    srand(time(NULL));

   int day =  DaysOfWeek((rand() % 7) + 1);

   cout << day;

    return 0;
}