#include <iostream>
using namespace std;

template <class T>
class s_ptr {
private:
    T* ptr;
    int* resources;

    void release() {
        if (resources) {
            (*resources)--;
            if (*resources == 0) {
                delete ptr;
                delete resources;
                cout << "Resources released.\n";
            }
        }
    }

public:
    // Constructor
    explicit s_ptr(T* p = nullptr) {
        ptr = p;
        resources = new int(1);
    }

    // Copy constructor
    s_ptr(const s_ptr& obj) {
        ptr = obj.ptr;
        resources = obj.resources;
        ++(*resources);
    }

    // Copy assignment operator
    s_ptr& operator=(const s_ptr& obj) {
        if (this != &obj) {
            release();  // release current resources
            ptr = obj.ptr;
            resources = obj.resources;
            ++(*resources);
        }
        return *this;
    }

    // Destructor
    ~s_ptr() {
        release();
    }

    // Dereference operators
    T& operator*() const {
        cout<<"igot called"<<endl;
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    // Get raw pointer
    T* get() const {
        return ptr;
    }

    // Get use count
    int use_count() const {
        return *resources;
    }
};


class base 
{
private:
    /* data */
public:
    base (/* args */);
  //virtual ~base();
  //to resolve dynamically distruct an issue 
    ~base ();
};

base ::base (/* args */)
{
    cout<<"constructor base\n";
}

base ::~base ()
{
    cout<<"distructor base"<<endl;

//cout<<"distructor"<<endl;
}

class  derived : public base 
{
private:
    /* data */
public:
     derived(/* args */);
    ~ derived();
};

 derived:: derived(/* args */)
{
    cout<<"constructor derived"<<endl;
}

 derived::~ derived()
{
    cout<<"i am at dreived distructor "<<endl;
}

int main()
{

    s_ptr<base> ptr;
    s_ptr<derived> ptr1;
    s_ptr<base> *ptr2;
    return 0;
}