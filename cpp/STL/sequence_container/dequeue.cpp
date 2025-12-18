/*
In C++, deque container provides fast insertion and deletion at both ends.
 Stands for Double Ended QUEue, it is a special type of queue where insertion and 
 deletion operations are possible at both the ends in constant time complexity.
 */ 
#include<bits/stdc++.h>
using namespace std;
class dq{

    public : deque<int> d;
            dq(deque<int> &f):d(f){}
            void input_front(int x){
                d.push_front(x);

            }
            void input_back(int c)
            {
                d.push_back(c);
            }

            void input_pos(int x,int pos)
            {
                d[pos]=x;

            }
            void display()
            {
                deque<int>::iterator it;
                for(it=d.begin();it!=d.end();it++)
                {

                    cout<<" "<<*it;
                }
                cout<<endl;
            }

};

int main()
{
    deque d={1,2,3,4,4,5,7,6,5,4,4,3,2,1};
    dq f(d);
    f.display();
    f.input_front(23);
    f.display();
    f.input_back(24);
    f.display();
    f.input_pos(36000,1);
    f.display();

    return 0;
}