#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<string,int>station_number;
int age;

//Class for Calculating price
class CalculatingPrice{
    public:
        float price_calculator(string station1,string station2)
        {
            int fare;
            //Case for covering entire journey
            if(abs(station_number[station1]-station_number[station2])==17)
                fare=20;
            else //Case for other cases
            {
                int p=abs(station_number[station1]-station_number[station2])+1;
                if(p<=5) //If no. of stations less than 5, base money is charged
                    fare=10;
                else if(p<=10)
                    fare=15;
                else
                    fare=20; //Maximum amount of money charged is 20
            }
            float charge;
            //When Age of passenger is under 3
            if(age<3)
            charge=0;
            //When Age of passenger is under 10
            else if(age<10)
            charge=(3*((float)fare/4));
            else
            charge=fare;
            return charge; //Final price that will be charged based on passenger's age
        }
};

//Class for displaying ticket from source to destination
class Display_Ticket_Price{

    public:
        int stops;
        float cost;
        string source,dest;
        void filldata(float fare,int p,string station1,string station2)
        {
            stops=p-1;
            source=station1;
            dest=station2;
            cost=fare;
        }
        void price_displayer()
        {
            cout<<"\n\n*****************************************\n";
            cout<<"*****************************************\n";
            cout<<"*****************************************\n";
            cout<<"\n\n\tRailway Ticket\n\n";
            cout<<"\t"<<source<<"\n";
            cout<<"\t"<<dest<<"\n";
            cout<<"\t"<<stops<<" Stops\n";
            cout<<"\tRs. "<<cost<<"\n";
            cout<<"\n\n*****************************************\n";
            cout<<"*****************************************\n";
            cout<<"*****************************************\n";
        }
};

//Class for displaying Return ticket.This class extends the original ticket display class
class Return_Ticket:public Display_Ticket_Price
{
    public:
        void price_displayer_return()
        {
            cout<<"\n\n*****************************************\n";
            cout<<"*****************************************\n";
            cout<<"*****************************************\n";
            cout<<"\n\n\tRETURN Railway Ticket\n\n";
            cout<<"\tFrom: "<<source<<"\n";
            cout<<"\tTo: "<<dest<<"\n";
            cout<<"\tFrom: "<<source<<"\n";
            cout<<"\t"<<stops<<" Stops\n";
            cout<<"\tRs. "<<(7*((float)cost/4))<<"\n";
            cout<<"\n\n*****************************************\n";
            cout<<"*****************************************\n";
            cout<<"*****************************************\n";
        }
};
int main()
{
    cout<<"Chennai suburban railway Welcomes you!\n\n";
    int n,i,j;
    string station1,station2;
    string station_names[18]={
    "Chennai Beach",
    "Chennai Fort",
    "Chennai Park",
    "Chennai Egmore",
    "Chetpet",
    "Nungambakkam",
    "Kodambakkam",
    "Mambalam",
    "Saidapet",
    "Guindy",
    "St. Thomas Mount",
    "Pazhavanthangal",
    "Meenambakkam",
    "Trisulam",
    "Pallavaram",
    "Chromepet",
    "Tambaram Sanatorium",
    "Tambaram"
    };
    for(i=0;i<18;i++)
    {
        station_number[station_names[i]]=i+1;
    }

    cout<<"Station names of Chennai suburban railway And Station ID\n";
    cout<<"*****************************************\n";
    for(i=0;i<18;i++)
        cout<<i+1<<" "<<station_names[i]<<"\n";

    cout<<"*****************************************\n";
    cout<<"ENTER YOUR AGE: \n";
    cin>>age;
    cout<<"\n***************************************\n";

    int id1,id2;

    //The passenger enters the station id, the id of each station is mentioned above from 1 to 18
    cout<<"Enter Source Station ID : \n";
    cin>>id1;
    cout<<"\nEnter Destination Station ID : \n";
    cin>>id2;
    station1=station_names[id1-1]; //Name of first station
    station2=station_names[id2-1]; //Name of second station

    int p = abs(station_number[station1]-station_number[station2])+1;

    CalculatingPrice obj1; //Class for calculating price of ticket
    float cost=obj1.price_calculator(station1,station2); //Cost

    Display_Ticket_Price obj2; //Class for Displaying ticket from source to destination
    obj2.filldata(cost,p,station1,station2);
    obj2.price_displayer();

    cout<<"\n\nTo Get Return Ticket enter 1,else press 2\n";
        int c;
        cin>>c;
        if(c==2)
        {
            cout<<"THANKS FOR VISITING\n";
            return 0;
        }
        else if(c==1)
        {
            Return_Ticket obj3; //Class for displaying return ticket
            obj3.filldata(cost,p,station1,station2);
            obj3.price_displayer_return();
            cout<<"THANKS FOR VISITING\n";
            return 0;
        }
        else
        {
            cout<<"INVALID CHOICE\n";
        }



    return 0;


}
