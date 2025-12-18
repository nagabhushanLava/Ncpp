#include<iostream>
#include<vector>
#include<thread>
using namespace std;

#define max_value 5000
vector<int> v1;
int arr[max_value];
int i=0;
void push_data(int a)
{
if( i==max_value)
{
    cout<<"stack is over flow "<<endl;
    exit(0);
}
arr[i]=a;
i++;

}
void pop_data(){
if(i==-1)
{
    cout<<"stack is under flow "<<endl;
    return;
}
else{
i--;
cout<<"poped ";
}

}
void display()
{
    for(int k=0;k<i;k++)
    {
        cout<<arr[k]<<" ";
    }

}
void call(int a)
{
    for(int n=0;n<a;n++)
    {
        push_data(n);
    }
}
void decall(int b)
{
    for(int m=0;m<b;m++)
    {_sleep(0.01);
        pop_data();
    }
}

int main()
{

push_data(10);
push_data(20);
push_data(30);
push_data(40);
push_data(50);

pop_data();
pop_data();

thread t1(call,100);
thread t2(decall,100);

t1.join();
t2.detach();

display();



    return 0;
}