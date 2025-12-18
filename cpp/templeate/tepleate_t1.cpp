//template function


#include<iostream>
using namespace std;

template <typename T> 
T max1(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout<<max1<int>(1, 2) <<endl;                      // Works fine
    cout<<max1<double>(3.78, 4.90) <<endl;             // Works with implicit type conversion
    cout<<max1<string>("fg", "kl") <<endl;           // Use string instead of char for lexicographical comparison
    cout<<max1<char>('b','z')<<endl;
    return 0;
}