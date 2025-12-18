#include<iostream>
#include<bits\stdc++.h>
using namespace std;
class reciver{//reciver
    private  : string name;
    public: reciver(string s):name(s){};
    void turnon(){
        cout<<name;
        cout<<"turn onn TV"<<endl;
    }
    void turnoff(){
        cout<<name;
        cout<<"turn off TV"<<endl;}
};
class command{//abstract class command
    public: virtual void execute()=0;
};
class commandActON :public command//concurent command
{
    private: reciver obj;
    public: 
    commandActON(reciver &obj1):obj(obj1){};
    void execute(){obj.turnon();}
};
class commandActOFF : public command //concurrent command
{
    private: reciver obj;
    public:commandActOFF(reciver obj2):obj(obj2){};

    void execute(){obj.turnoff();}
};
class remote_controller {//Invoker
private: vector<command *> c1;
public: void set_command(command *cmd);
        void press_cmd(int slot);

};

void remote_controller::set_command(command *cmd)
{
    c1.push_back(cmd);
}
void remote_controller::press_cmd(int slot)
{
    if(slot>=0 && slot< c1.size())
    {

        c1[slot]->execute();
    }


}
int main()
{
    reciver tv("TV");
    reciver lights("Lights");

    commandActON TTvon(tv);
    commandActOFF TTvoff(tv);

cout<<"____________\n";
    commandActON LLightson(lights);
    commandActOFF LLightsoff(lights);


cout<<"_______________\n";
    
    remote_controller remote;

    remote.set_command(&TTvon);
    remote.set_command(&TTvoff);
    remote.set_command(&LLightson);
    remote.set_command(&LLightsoff);

    remote.press_cmd(0);
    remote.press_cmd(1);
    remote.press_cmd(2);
    remote.press_cmd(3);





    return 0;
}