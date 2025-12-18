#include<iostream>
#include<cstring>

using namespace std;

class str{

    private: char * st;

    public:
    
            str(const char *s){
        st = new char[strlen(s)+1];
        strcpy(st,s);
        cout<<"the parametarized constructor called "<<endl;

    }
         /*   str(str &obj)
            {
                st= new char[strlen(obj.st)+1];
                strcpy(st,obj.st);
            cout<<"copy construcotr is called that to with object"<<endl;
            }*/

            str& operator=(const str& obj)
            {
                if(this == &obj)
                {
                    return *this;

                }
                delete [] st;

                st= new char[strlen(obj.st)+1];
                strcpy(st,obj.st);
                cout<<"copy constructor with assignment ="<<endl;
                return *this;
            }

            str(str&& obj)noexcept{

                strcpy(st,obj.st);
                obj.st=nullptr;
                cout<<"calling move constructor "<<endl;

            }
            ~str() {
                cout << "Destructor called for: " << (st ? st : "nullptr") << endl;
                delete[] st;
            }

            void display()
            {if(this!=nullptr)
                {    cout<<"the string of obj's ="<<st<<endl;
                           }
                else{
                    cout<<"it's nullptr no data "<<endl;
                }           }


        };
int main()
{
    cout<<"calling from s1"<<endl;
    str s1("hellow INDIA ");
    s1.display();

    cout<<"calling from s2"<<endl;
  //  str s2(s1);
  //  s2.display();

    
    cout<<"calling from s3"<<endl;
    str s3=s1;
    s3.display();

 /*   cout<<"calling from s4"<<endl;
    str s4=move(s1);
    s4.display();
    s1.display();*/

    return 0;
}