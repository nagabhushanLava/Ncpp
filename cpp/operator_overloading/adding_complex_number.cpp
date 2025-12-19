#include<iostream>
using namespace std;

class complex {
    public : double real,image;

        complex(double r,double i):real(r),image(i){}

        complex* operator+(complex &obj)
        {
           

            return new complex(this->real+obj.real,this->image+obj.image);
        }
        
};

int main()
{   
    complex *s1= new complex(10.1,11.2);
    complex *s2= new complex(3.1,2.1);
    // add the two complex numbers via their objects
    // pointer + object addition (returns a new allocated complex*)
    complex *s3 = s1->operator+(*s2); // uses global operator+(complex*, const complex&)

    cout<<"the results are real "<<s3->real<<" image "<<s3->image<<endl;

    return 0;
}

