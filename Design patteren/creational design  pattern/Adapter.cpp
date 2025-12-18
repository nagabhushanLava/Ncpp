#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TargetInterface  // Target interface that the client expects      
{   
    public:
        virtual void request() = 0; // Interface method
}; 
class Adaptee  // Adaptee class that has a specific method

{
    public:
        void specificRequest()  // Method that needs to be adapted
        {
            cout << "Specific request from Adaptee." << endl;
        }
};   
class Adapter : public TargetInterface  // Adapter class that adapts the Adaptee to the Target interface
{
    private:
        Adaptee *adaptee;  // Pointer to the Adaptee object

    public:
        Adapter(Adaptee *a) : adaptee(a) {}  // Constructor that takes an Adaptee object

        void request() override  // Implementation of the Target interface method
        {
            adaptee->specificRequest();  // Call the specific method of the Adaptee
        }
};
 
// Client code that uses the Target interface
void clientCode(TargetInterface *target)    
{
    target->request();  // Call the request method on the Target interface
        
    }
// Example usage

int main()
{
    Adaptee *adaptee = new Adaptee();  // Create an Adaptee object
    Adapter *adapter = new Adapter(adaptee);  // Create an Adapter object that adap 
    clientCode(adapter);  // Call the client code with the Adapter  

    delete adaptee;  // Clean up the Adaptee object
    delete adapter;  // Clean up the Adapter object         





    return 0;
}
