#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;


vector<int> countCharacters (string st){
     int length = st.length();
     vector<int> arr(26, 0);

     for(int i = 0; i<length; i++){
        char ch = st[i];
        if (ch >= 'a' && ch <= 'z') { 
            arr[ch - 'a']++;
        }
     }

     return arr;
}

map<char, int> countCharacters2 (string st){
    int length = st.length();
    map<char, int> mpp;
   
   for (int i = 0; i < length; i++)
   {
        
   }
   

}

// int main(){

//    string st = "ujjwal is my name";

//    vector<int> charmap = countCharacters(st);
  
//    for(int i = 0; i<charmap.size(); i++){
//        if (charmap[i] > 0) {
//             char ch = 'a' + i;
//             cout << "Occurrence of " << ch << " is " << charmap[i] << endl;
//         }
//    }
//     return 0;
// }


// using unordered_map;

int main (){

   //creation
    unordered_map<string, int> mpp;

   //insertion
   pair<string, int> p = make_pair("ujjwal", 1);
   mpp.insert(p);

   mpp["kumar"] = 1;
   mpp["kumar"] = 2; // second insertion is updation in map...
   mpp["singh"] = 1;

  cout << mpp["kumar"] << endl;
  cout << mpp.at("ujjwal") << endl;
   
  //cout << mpp.at("unknoen") << endl; will print error as no entry is found and it will create a 0 entry
  // cout<< mpp["unknown"]<< endl; will print 0 as entry

  cout<< mpp.size() << endl;

  cout<< mpp.count("ujjwal") << endl;

  mpp.erase("ujjwal");

  for(auto i : mpp) {
    cout << i.first << " " << i.second << endl;
  }
  
    return 0;
}