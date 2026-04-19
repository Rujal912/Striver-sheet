#include<iostream>
#include<set>
using namespace std;

// int main(){
//     int month;
//     cin >> month;

//     int answer;
//     if(month % 12 == 0) {
//         answer = (month / 12) * 15000;
//     }
//     else if(month % 9 == 0){
//         answer = (month / 9) *12000;
//     }
//     else if(month % 6 == 0){
//         answer = (month / 6) * 9000;
//     }
//     else if(month % 3 == 0){
//         answer = (month / 3) * 5000;
//     }
//     else if(month % 1 == 0){
//         answer = (month / 1) * 2000;
//     }
//     else {
//         cout<<"Error";
//     }

//     cout<<answer;
//     return 0;
// }

int main(){
    int n;
    cin >> n;

    set<pair<string,string>> seen;
    string sender , receiver;
    int time, amount;
    int prevTime = -1;

    for(int i=0; i<n; i++){
        cin >> sender>> receiver>> time>> amount;
    

    pair<string, string> key = {sender, receiver};

    //rule 1
    if(seen.count(key)) {
        cout<<"Duplicate transaction found";
        return 0;
    } 

    seen.insert(key);

    //rule 2
    if(prevTime != -1){
        if(time - prevTime > 60){
            cout<<"Fraud detected";
            return 0;
        }
    }
    prevTime = time;
    }
    cout<<"All transactions valid";
}