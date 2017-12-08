//OOPS using C++
//AIRLINE RESERVATION SYSTEM
//Project created by:
//1.Dhruv Kumar Palrecha



#include<iostream>                                                      //Header file
using namespace std;                                                    //Define scope for the identifier

//creating a class for travellers

class traveller
{
    string name;
    int age;
    char gender;
public:
    void acceptdata();
    void displaydata();
    void cancel();
}t[100];                                                                //Objects of class traveller
class flight:public traveller                                           //Inheritance
{
    int count=0;                                                        //Count for the number of passengers
    int flyno;                                                          //Flight number
    string from;                                                        //Departure city
    string to;                                                          //Destination
    long int fare;
    int business;
    int economy;
public:
    int book();                                                         //To book seats
    void cancelling(int);                                               //To cancel seats
    void display();                                                     //To display information on flights
    void getdetails(int,string,string,long int,int,int);                //To store details of flights
    flight();
}f[5];

flight::flight()                                                        //Default constructor
{
    
}
void flight::cancelling(int x)                                          //Cancellation of a ticket
{
    if(x==1)
        business++;
    else if(x==2)
        economy++;
    else
        cout<<"\nInvalid selection";
}

void flight::display(void)                                              //display flight information
{
    cout<<"Flight No: "<<flyno;
    cout<<"\t\n From:🛫 "<<from<<"\t To:🛬 "<<to;
    cout<<"\t\n Fare: "<<fare<<endl;
}

void flight::getdetails(int fno,string fr,string t,long int far,int bsness,int ecnmy)  //Input flight details
{
    flyno = fno;
    from = fr;
    to = t;
    fare = far;
    business = bsness;
    economy = ecnmy;
}

int flight :: book()                                                    //Booking a ticket
{
    int preference;
    cout<<"\nPlease select your preferred class:💺💺💺\n 1.Business(2x fare) 2.Economy\n";
    cin>>preference;
    if(preference==1)
    {
        try {                                                           //Exception Handling
            if(business==0)
                throw(business);
            else
            {
                                    //Business class booking
                cout<<"\nAvailable seats in business class are:💺 "<<business<<endl;
                business--;
                cout<<"\nYour ticket booking is under process...\n";
                cout<<"\n------------";
                cout<<"\nTotal Fare = "<<fare*2*1.05;                   //1.05 is 5 % GST
                cout<<"\nTotal seats now available on plane in business class:💺 "<<business<<endl;\
                cout<<"\nYour selected class is BUSINESS";
                cout<<"\n------------";
            }
        } catch (int x) {
            cout<<"\nNo seats available";
            EXIT_FAILURE;
        }
        
    }
    else if(preference==2)
    {
        try {                                                           //Exception handling
            if(economy==0)
                throw(economy);
            else
            {
                                //Economy class booking
                cout<<"\nAvailable seats in economy class are:💺 "<<economy<<endl;
                economy--;
                cout<<"\nYour ticket booking is under process...🎟\n";
                cout<<"------------";
                cout<<"\nTotal Fare = "<<fare*1.05;
                cout<<"\nTotal seats available now available on plane in economy class:💺 "<<economy<<endl;
                cout<<"\nYour selected class is ECONOMY";
                cout<<"\n------------";
            }
        } catch (int x) {
            cout<<"\nNo seats available";
            EXIT_FAILURE;
        }
        
    }
    count++;
    return count;
}

void traveller::cancel()                                                //Cancellation of ticket
{
    name = "Cancelled❌";
    age = 00;
    gender = 'X';
}
void traveller::acceptdata()                                            //Input flyer details
{
    cout<<"\nEnter you details"<<endl;
    cout<<"Name: ";
    cin>>name;
    cout<<"Age: ";
    cin>>age;
    cout<<"Gender: ";
    cin>>gender;
    
}

void traveller::displaydata()                                           //Dispaly flyer details
{
    cout<<"\n🛄Travller details are: ";
    cout<<"\nName: "<<name;
    cout<<"\nAge: "<<age;
    cout<<"\nGender: "<<gender<<endl;
}
int main()
{
    flight f[5];
    int selection;
    f[0].getdetails(1,"BLR","BOM",2500,10,10);                             //Bangalore to Mumbai
    f[1].getdetails(2,"BLR","MAS",2000,10,10);                             //Bangalore to Chennai
    f[2].getdetails(3,"BLR","PNQ",2000,10,10);                             //Bangalore to Pune
    f[3].getdetails(4,"BLR","DEL",4000,10,10);                             //Bangalore to Delhi
    f[4].getdetails(5,"BLR","CCU",4000,10,10);                             //Bangalore to Calcutta
    
start:cout<<"\nWelcome to 🛩Airline Reservation System🛩 - KIAL  \n";
    cout<<"\nPlease select your preferred option: \n";
    cout<<"\n1.Book Ticket🎟\n2.Quit🚫\n";
    cin>>selection;
here:    switch(selection)
    {
        case 1:
        {
            int n,count;
            for(int i=0;i<5;i++)
                f[i].display();
            cout<<"\nPlease select the desired flight route: \n";
            cin>>n;
            switch(n)
            {
                case 1:                                                 //Flight 1
                {
                    count=f[0].book();
                    t[count].acceptdata();
                    cout<<"\n----------\nYour allotted ticket number is:🏷 "<<count<<endl;
                    t[count].displaydata();
                    cout<<"\n----------";
                }
                    break;
                case 2:                                                 //Flight 2
                {
                    count=f[1].book();
                    count=count+20;
                    t[count].acceptdata();
                    cout<<"\n----------\nYour allotted ticket number is:🏷 "<<count<<endl;
                    t[count].displaydata();
                    cout<<"\n----------";
                }
                    break;
                case 3:                                                 //Flight 3
                {
                    count=f[2].book();
                    count=count+40;
                    t[count].acceptdata();
                    cout<<"\n----------\nYour allotted ticket number is:🏷 "<<count<<endl;
                    t[count].displaydata();
                    cout<<"\n----------";
                }
                    break;
                case 4:                                                 //Flight 4
                {
                    count=f[3].book();
                    count=count+60;
                    t[count].acceptdata();
                    cout<<"\n----------\nYour allotted ticket number is:🏷 "<<count<<endl;
                    t[count].displaydata();
                    cout<<"\n----------";
                }
                    break;
                case 5:                                                 //Flight 5
                {
                    count=f[4].book();
                    count=count+80;
                    t[count].acceptdata();
                    cout<<"\n----------\nYour allotted ticket number is:🏷 "<<count<<endl;
                    t[count].displaydata();
                    cout<<"\n----------";
                }
                    break;
                default:
                    cout<<"\nInvalid flight selction";
                    goto start;
                    break;
            }
            
        }
            break;
        case 2:
        {
            goto end;
        }
        default:
        {
            cout<<"\nInvalid selection";
            goto start;
        }break;
    }
    
start1:
    cout<<"\nPlease slect your preferred option:\n1. Book another ticket🎟 2. View booked ticket🖥 3. Cancel ticket❌ 4.Quit🚫\n";
    cin>>selection;
    if(selection==1)
        goto here;
    else if(selection==2)                                               //View details of booked ticket
    {
        int ticket;
        cout<<"\nEnter your ticket number: ";
        cin>>ticket;
        t[ticket].displaydata();
    }
    else if(selection==3)                                               //Cancellation
    {
        int number,fno,seat;
        cout<<"\nPlease enter your ticket number: ";
        cin>>number;
        t[number].cancel();
        cout<<"\nPlease enter yout flight number: ";
        cin>>fno;
        fno=fno-1;
        cout<<"\nKindly reconfirm the class of the ticket to be cancelled:\n 1.Business 2.Economy\n";
        cin>>seat;
        f[fno].cancelling(seat);
        t[number].displaydata();
    }
    else if(selection==4)
        goto end;
    goto start1;
end:return 0;                                                           //End of the program 😀
}
