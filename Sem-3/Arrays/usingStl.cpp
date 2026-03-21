#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v1 = {1,4,8,3,6};
    vector<int> v2 = {2,22,12,3,6};
    //Inserting element into vector
    v1.insert(v1.begin()+5, 2);
    v1.push_back(4);
    //Delete element from vector
    v1.pop_back();

    // auto it = find(v1.begin(), v1.end(), 2);
    // cout << distance(v1.begin(), it);
    // v1.erase(it);

    vector<int> v3(v1.size()+v2.size());
    sort(v1.begin(), v1.end(),greater<>());
    sort(v2.begin(), v2.end(),greater<>());
    vector<int>::iterator st = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin());
    // for(int i=0; i<v1.size(); i++){
    //     cout << v1.at(i) << " ";
    // }
    vector<int>::iterator it;
    for(it = v3.begin(); it != st; ++it){
        cout << " " << *it;
    }
    

}
