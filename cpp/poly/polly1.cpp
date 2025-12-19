#include<iostream>
using namespace std;

class polly{
    public: int *a;

            polly()
            {
                a= new int(100);
            }
            polly(int aa):a(new int(aa)){}
            virtual void get()
            {
                cout<<"the value of a"<<*a<<endl;

            }
            virtual ~polly()
            {
                cout<<"polly distructor called"<<endl;
                delete a;
            }
};
class derived : public polly{

 public:       derived(int v):polly(v){}
        ~derived()
        {
            cout<<"derived distructor got called"<<endl;
        }
        void get()
        {
            cout<<" derived the value of a"<<*a<<endl;
        }
};

int main()
{
    polly *s2=new polly(200);
    s2->get();

    polly * s1 = new derived(100);
    s1->get();

    derived *s3=new derived(250);
    s3->get();

    // demonstrate dynamic_cast: safe downcast from base pointer to derived pointer
    polly *pbase = new polly(10);
    cout << "Attempting dynamic_cast from polly* (pointing to derived) -> derived*" << endl;
    derived *d1 = dynamic_cast<derived*>(s1); // s1 actually points to derived
    if (d1) {
        cout << "dynamic_cast succeeded:\n";
        d1->get();
    } else {
        cout << "dynamic_cast failed\n";
    }

    cout << "Attempting dynamic_cast from polly* (pointing to base) -> derived*" << endl;
    derived *d2 = dynamic_cast<derived*>(pbase); // pbase points to base, cast should fail
    if (d2) {
        cout << "dynamic_cast (unexpectedly) succeeded:\n";
        d2->get();
    } else {
        cout << "dynamic_cast returned nullptr (as expected)\n";
    }

    // clean up
    delete s1;   // s1 was a derived instance
    delete s2;
    delete s3;
    delete pbase;
    return 0;
}
