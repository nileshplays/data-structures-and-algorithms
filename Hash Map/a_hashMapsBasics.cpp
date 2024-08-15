#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // Map Creation
    unordered_map<string, int> mp;

    // Insertion in map
    // 1.
    pair<string, int> pair1 = make_pair("Nilesh", 20);
    mp.insert(pair1);

    // 2.
    pair<string ,int> pair2("Sarkar" , 21);
    mp.insert(pair2);

    // 3.
    mp["NileshSarkar"] = 19;

    // SEARCH
    cout<<mp["Nilesh"]<<endl;
    cout<<mp.at("Sarkar")<<endl;

    // SIZE
    cout<<"Size:"<<mp.size()<<endl;

    //To Check Presence
    cout<<"(If Present:1 , else :0)         : "<<mp.count("nileshSarkar")<<endl;
    cout<<"(If Present:1 , else :0)         : "<<mp.count("NileshSarkar")<<endl;
    //ERASE
    mp.erase("NileshSarkar");
    cout<<"Size : "<<mp.size()<<endl;

    // Traverse
    for(auto i: mp){
        cout<<i.first <<" : "<<i.second<<endl;
    }
    // Iterator
    unordered_map<string,int> :: iterator it = mp.begin();
    while(it != mp.end()){
        cout<< it ->first <<" : "<<it->second <<endl;
        it++;
    }


}