#include<bits/stdc++.h>

using namespace std;

int main()
{

    int choice;
    cout<<"enter the choice\n";
    cin>>choice;
 try{   if(choice==1)
    {
        throw invalid_argument("inavlid argumnet");
    }
    else if (choice==2)
    {
        /* code */
        throw out_of_range("Out_of_range");
    }
    else if (choice==3)
    {
        /* code */
        throw length_error("length_error");

    }
    else if(choice ==4)
    {

        throw domain_error("domain_error");
    }
    else{

        throw "unkown error";
    }}
    catch(invalid_argument e)
    {
        cout<<e.what()<<endl;
    }
     catch(out_of_range e)
    {
        cout<<e.what()<<endl;
    }
      catch(length_error e)
    {
        cout<<e.what()<<endl;
    }
      catch(domain_error e)
    {
        cout<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"cought unkown_error"<<endl;
    }
    return 0;
        

}