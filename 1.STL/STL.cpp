#include<bits/stdc++.h>
using namespace std;
void explainPair() {
    pair<int, int> pr1 = {2, 8};
    cout<<pr1.first<<" "<<pr1.second<<endl;
    // op - 2 8
    // pair<int, int> pr1 = make_pair(2, 8); // same as above
    // cout<<pr1.first<<" "<<pr1.second << endl;
    // op - 2 8
    pair<int, char> pr2 = make_pair(2, 'b');
    cout<<pr2.first<<" "<<pr2.second<<endl;
    // op - 2 b
    pair<pair<int, char>, int> pr3 = {{4, 'h'}, 8};
    cout<<pr3.first.second<<endl;
    // op - h
}
void explainVector() {
    //Define a vector
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.emplace_back(0);

    for(int i=0;i<vec.size();i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    // 1 2 0

    //Iterator
    vector<int>::iterator beginItr = vec.begin();
    vector<int>::iterator endItr = vec.end();
    for(vector<int>::iterator i = beginItr; i<endItr; i++) {
        cout << *i << " ";
    }
    cout<<endl;
    // 1 2 0

    // To write simply just use word auto, automatically assign type of iterator
    // auto beginItr = vec.begin();
    // auto endItr = vec.end();
    // for(auto i = beginItr; i<endItr; i++) {
    //     cout << *i << " ";
    // }
    //  1 2 0

    // Better way to do this
    for(auto i : vec) {
        cout<<i<<" ";
    }
    cout<<endl;
    //1 2 0

    //reverse iterator
    auto reverseBegin = vec.rbegin();
    auto reverseEnd = vec.rend();
    for(auto i = reverseBegin; i<reverseEnd; i++){
        cout<< *i << " ";
    }
    cout<<endl;
    // 0 2 1

    vector<int> vec1(5);

    for(auto i : vec1) {
        cout<<i<<" ";
    }
    cout<<endl;
    // 0 0 0 0 0

    vector<int> vec2(5, 8);
    for(auto i : vec2) {
        cout<<i<<" ";
    }
    // 8 8 8 8 8 
    cout<<endl;

    vector<int> vec3 = {7, 8};
    vec3.push_back(1);
    vec3.push_back(5);
    vec3.push_back(9);
    for(auto i : vec3) {
        cout<<i<<" ";
    }
    // 7 8 1 5 9
    cout<<endl;

    vector<int> dupVec(vec3);
    for(auto i : dupVec) {
        cout<<i<<" ";
    }
    // 7 8 1 5 9
    cout<<endl;

    vector<int> dupVec1(vec3.begin() + 1, vec3.end());
    for(auto i : dupVec1) {
        cout<<i<<" ";
    }
    // 8 1 5 9
    cout<<endl;

    cout<<vec3.front(); // 7
    cout<<endl;
    cout<<vec3.back(); // 9 
    cout<<endl;

    // vec3.pop_back(); // remove last element
    // for(auto i : vec3) {
    //     cout<<i<<" ";
    // }
    // // 7 8 1 5

    // vec3.erase(vec3.begin()); // 1st element
    // for(auto i : vec3){
    //     cout<<i<<" ";
    // }
    // // 8 1 5 9

    // vec3.erase(vec3.begin() + 2); // 3rd element
    // // 7 8 5 9 

    //Accessing element by index
    cout<<vec3[1]; // 8
    //OR
    cout<<endl;
    cout<<vec3.at(1); // 8
    cout<<endl;

    //Swapping the vector
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    swap(v1, v2);
    for (int i : v1) {
        cout << i << " ";
    }
    // 4 5 6
    cout<<endl;

    vector<int> v = {10, 30};
    v.insert(v.begin() + 1, 20);
    for (int i : v) {
        cout << i << " ";
    }

}
void explainList() {
    list<int> lst;
    lst.push_front(20);
    lst.emplace_front(10);  // Constructs 10 at the beginning
    for (int i : lst) {
        cout << i << " ";
    }
    // 10 20
    cout<<endl;
    cout << "Front element: " << lst.front(); // 10
}
void explainDeque(){
    deque<int> dq = {10, 20, 30};
    dq.push_front(0);  // Insert at the beginning
    dq.push_back(40);  // Insert at the end
    for (int i : dq) {
        cout << i << " ";
    }
    // 0 10 20 30 40 
}
void explainStack(){
    stack<int> st;
    st.push(10);
    st.push(20);

    cout<<st.top()<<" ";
    st.pop();
    cout<<st.top()<<" ";
    st.pop();

    // cout<<st.top()<<" "; // wont print anything runtime error , doesnt have element

    stack<int> st1;
    st1.push(50);
    st1.push(60);
    st1.push(70);
    st1.push(80);
    // print all
    while(st1.empty() == false) {
        cout<<st1.top()<<" ";
        st1.pop();
    }
    // 80 70 60 50
    cout<<endl;
    
    stack<int> s1, s2;
    s1.push(10);
    s2.push(20);
    s1.swap(s2);

    cout<<s1.top()<<endl;
    cout<<s2.top();
}
void explainQueue(){
    queue<int> q;
    q.push(2);
    q.push(22);
    q.push(23);
    q.push(24);
    q.push(25);
    while(q.empty() == false){
        cout<< q.front()<< " ";
        q.pop();
    }
}
void explainPQ(){
    //stores highest element at top
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(10);
    pq.push(8);

    while(pq.empty() == false) {
        cout<<pq.top()<<" ";
        pq.pop();
        cout<<endl;
    } 
}
void explainSet(){
    //stores only unique elements
    //and in ascending order

    set<int> st;
    st.insert(2);
    st.insert(21);
    st.insert(21);
    st.insert(21);
    st.insert(12);
    st.insert(21);

    for(auto it : st) {
        cout<<it<<" ";
    }
    // 2 12 21 

    // find
    auto it = st.find(12);
    if(it != st.end()) {
        cout<<*it;
    }
    //12
    cout<<endl;

    // count
    cout<<st.count(12); // 1 (True)
    cout<<endl; 

    st.erase(21);
    for(auto it : st) {
        cout<<it<<" ";
    } // 2 12
    cout<<endl;

    set<int> st1;
    st1.insert(2);
    st1.insert(21);
    st1.insert(21);
    st1.insert(21);
    st1.insert(12);
    st1.insert(21);

    // 2 12 21 
    auto it1 = st1.end();
    it1--; it--;
    st1.erase(it1);
    for(auto it1 : st1) {
        cout<<it1<<" ";
    } // 2 21
    cout <<endl;

    set<int> st2;
    st2.insert(2);
    st2.insert(21);
    st2.insert(12);
    st2.insert(211);
    st2.insert(213);
    

    for(auto i : st2) {
        cout<<i<<" ";
    } // 2 12 21 211 213
    cout << endl;

    //erasing 12 21 211
    auto it11 = st2.begin();
    it11++;

    auto it22 = st2.end();
    it22--;

    st2.erase(it11, it22);
    for(auto i : st2){
        cout<<i<<" ";
    }// 2 213
    cout<<endl;

    set<int> st3;
    st3.insert(2);
    st3.insert(21);
    st3.insert(12);
    st3.insert(211);
    st3.insert(213);
    // 2 12 21 211 213


    //lower bound - returns an iterator that points to element that is 
    // >= number gives
    // auto i = st3.lower_bound(11);
    // cout<<*i; // 12

    auto i = st3.lower_bound(214);
    if(i==st3.end()) {
        cout<<"end";
    }

    //same as upper_bound see notes
    //upper bound - returns an iterator that points to element that is 
    // > number gives

}
void explainMultiSet(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(0);
    ms.insert(21);
    ms.insert(21);

    // auto it = ms.find(1); //point out to 1st one of ones

    // auto it = ms.erase(1);
    // for(auto it: ms){
    //     cout<<it<<" ";
    // }
    // 0 2 21 21

    // To delete one of ones
    auto it = ms.erase(ms.find(1));
    for(auto it: ms) {
        cout<<it<<" ";
    } // 0 1 1 1 2 21 21 

    //count
    cout<<ms.count(1); // 3
}
void explainUnorderedSet(){
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(1);
    st.insert(11);
    st.insert(11);
    st.insert(12);
    st.insert(12);
    st.insert(12);

    for(auto it: st){
        cout<<it<<" ";
    }// 12 2 11 1
    cout<<endl;

    // auto it = st.find(11); //O(1) constant time complexity 

    auto it = st.find(21);
    if(it != st.end()){
        cout<<"Found"<<*it;
    } else {
        cout<<"Not Found";
    }
    // Not Found 
    // for st.find(2) --> Found 2
}
void explainMap(){
    map<int, string> mpp;
    mpp.insert({4, "Rujal"});
    mpp[1] = "abc";
    mpp[2] = "bcd";
    mpp[3] = "cat";

    for(auto it: mpp){
        cout<<it.first<<"-->"<<it.second<<endl;
    }
    // 1-->abc
    // 2-->bcd
    // 3-->cat
    // 4-->Rujal

    auto it = mpp.find(4);
    cout<<(*it).first<<"-->"<<(*it).second<<endl;
    // 4-->Rujal

    auto it1 = mpp.find(5);
    if(it1==mpp.end()) {
        cout<<"not found";
    }
    //not found
}
void explainMultiMap(){
    multimap<int, char> mpp;
    mpp.insert({3, 'b'});
    mpp.insert({1, 'a'});
    mpp.insert({1, 'b'});
    mpp.insert({1, 'a'});
    mpp.insert({2, 'a'});
    mpp.insert({2, 'a'});
    mpp.insert({2, 'b'});

    for(auto it : mpp) {
        cout<<it.first<<"-->"<<it.second<<endl;
    }
    // 1-->a
    // 1-->b
    // 1-->a
    // 2-->a
    // 2-->a
    // 2-->b
    // 3-->b

    auto it1 = mpp.equal_range(2);
    for(auto i = it1.first; i != it1.second; i++) {
        cout<<(*i).first<<"-->"<<(*i).second<<endl;
    }
    // 2-->a
    // 2-->a
    // 2-->b
}

void explainSort(){
    int arr[5] = {6, 2, 1, 7, 8};
    sort(arr, arr+5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    // 1 2 6 7 8 
    cout<<endl;

    int arr1[5] = {6, 2, 1, 7, 8};
    sort(arr1+1, arr1+4);
    for(int i=0; i<5; i++){
        cout<<arr1[i]<<" ";
    }
    // 6 1 2 7 8
    cout<<endl;

    vector<int> vec = {5, 7, 8, 8, 1};
    sort(vec.begin(), vec.end());
    for(auto it: vec) {
        cout<<it<<" ";
    }
    // 1 5 7 8 8
    cout<<endl;

    vector<int> vec1 = {5, 7, 1, 0, 1};
    sort(vec1.begin()+1, vec1.begin()+3); //sorted 1st and 2nd index
    for(auto it: vec1) {
        cout<<it<<" ";
    }
    // 5 1 7 0 1

}
void explainAccumulate(){
    int arr[5] = {6, 2, 1, 7, 0};
    cout<<accumulate(arr, arr+5, 1); //17

    cout<<accumulate(arr+4, arr+5, 1); //1
}
void explainCount(){
    int arr[5] = {6, 2, 1, 1, 0};
    int num = 7;
    cout<<count(arr, arr+5, num); //0

    int num1 = 1;
    cout<<count(arr, arr+5, num1); //2
}
void explainFind(){
    int arr[5] = {6, 2, 1, 1, 0};
    auto it = find(arr, arr+5, 1);

    if(it!=(arr+5)){
        cout<<"Found "<<*it; // 1
    }

    if(it== (arr+5)){
        cout<<"not found";
    }
}
void explainNextPermutation(){
    string str = "abc";
    do {
        cout<< str << endl;
    } while(next_permutation(str.begin(), str.end()));

    // abc
    // acb
    // bac
    // bca
    // cab
    // cba

    //for string bca
    // bca
    // cab
    // cba

    do {
        cout<< str << endl;
    } while(next_permutation(str.begin(), str.begin()+2)); // for only ab
    // abc
    // bac
    cout<<endl;

    do {
        cout<< str << endl;
    } while(prev_permutation(str.begin(), str.begin()+3));
    //abc  cause theres no previous permutation
    cout<<endl;

    string str1 = "bac";
    do {
        cout<< str1 << endl;
    } while(prev_permutation(str1.begin(), str1.begin()+3));
    // bac
    // acb
    // abc
}
void explainMaxElement(){
    int arr[] = {7, 6, 5, 10, 9};
    auto it = max_element(arr, arr+5);
    cout<<*it; // 10

    auto it1 = min_element(arr, arr+5);
    cout<<*it1; //5 
}
void explainReverse(){
    int arr[] = {7, 6, 5, 10, 9};
    reverse(arr, arr+5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    } //9 10 5 6 7  
}

bool internalComparator(int el1, int el2){
    // to make sorting in descending order
    if(el1 < el2) return false;
    return true;
    // viceversa for ascending order
}
void explainComparator(){
    //el1 is 6
    //el2 is 1
    //internal comparator that takes el1 and el2
    //and tells you if el1 should before el2 or not
    int arr[] = {5, 6, 1, 2};
    sort(arr, arr+4, internalComparator);
    for(int i=0; i<4; i++){
        cout<<arr[i]<<" ";
    } // 6 5 2 1 
}

bool internalComparator1(pair<int, int> el1, pair<int, int> el2){
    if(el1.second > el2.second) return true;
    if(el1.second < el2.second) return false;
    if(el1.first < el2.first) return true;
    return false;
}
void explainComparator1(){
    pair<int, int> arr[] = {{1,6}, {1,5}, {2,6}, {2,9}, {3,9}};
    //sort it according to second elemnt of pair
    sort(arr, arr+5, internalComparator1);
    for(int i=0; i<5; i++){
        cout<<"{" << arr[i].first <<","<< arr[i].second <<"} ";
    } 
    // {2,9} {3,9} {1,6} {2,6} {1,5} 
}

int main() {
    // explainPair();
    // explainVector();
    // explainList();
    // explainDeque();
    // explainStack();
    // explainQueue();
    // explainPQ();
    // explainSet();
    // explainMultiSet();
    // explainUnorderedSet();
    // explainMap();
    // explainMultiMap();


    // explainSort();
    // explainAccumulate();
    // explainCount();
    // explainFind();
    // explainNextPermutation();
    // explainMaxElement();
    // explainReverse();
    
    // explainComparator();
    // explainComparator1();
    return 0;
} 