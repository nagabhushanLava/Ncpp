#include<iostream>
#include<bits\stdc++.h>
using namespace std;
int main()
{


    auto greet = []() {
        std::cout << "Hello, World!" << std::endl;
    };

    greet(); // Calling the lambda

cout<<"--------------------------------"<<endl;


vector<int> v={10,20,30,40,50};
int n=10;
//cout<<"enter the value to be found "<<endl;
//cin>>n;
//[=] means read only 
auto p1=find_if(v.begin(),v.end(),[=](int a){
    return (a==n);
});

if(p1!=v.end())
{
cout<<"found the value of "<<n<<" "<<endl
;}
else{
    cout<<"not found "<<endl;
}
cout<<"--------------------------------"<<endl;

 auto add = [](int a, int b) -> int {
        return a + b;
    };

    std::cout << "Sum: " << add(5, 3) << std::endl; 


cout<<"--------------------------------"<<endl;
int x = 10;
    int y = 5;

    // Capture x by value and y by reference
    auto modify = [x, &y]() {
        // x is captured by value, cannot be modified
        // y is captured by reference, so it can be modified
        std::cout << "Inside Lambda - x: " << x << ", y: " << y << std::endl;
        y++;
    };

    modify();
    std::cout << "Outside Lambda - x: " << x << ", y: " << y << std::endl;

cout<<"--------------------------------"<<endl;


    auto print = [](auto value) {
        std::cout << value << std::endl;
    };

    print(42);       // prints an integer
    print(3.14);     // prints a double
    print("Hello");  // prints a string

cout<<"--------------------------------"<<endl;
  std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use a lambda to print all elements
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });

    return 0;
}