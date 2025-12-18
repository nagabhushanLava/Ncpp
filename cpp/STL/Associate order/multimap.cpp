/*
In C++, multimap is an associative container similar to map, but it can have multiple
 elements with same keys. It stores all the elements in increasing order based on their keys 
 by default but can be changed if required.
 It provides fast insertion, deletion and search on this sorted data.*/

 #include<bits/stdc++.h>
 using namespace std;

int main() {
    
    // Creating an empty multimap
    multimap<int, string> mm1;
    
    // Creating multimap using initializer list
    multimap<int, string> mm2 = {{1, "Inida"},
                      {2, "For"}, {1, "C++"}};

    for (auto i : mm2)
        cout << i.first << ": " << i.second
        << endl;

        mm2.insert({2,"Raja"});
        mm2.erase(1);

        for (auto i : mm2)
        cout << i.first << ": " << i.second
        << endl;

    return 0;
}
