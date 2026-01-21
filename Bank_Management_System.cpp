#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

vector<string>Name;
vector<int>Auid;
vector<string>Password;
vector<string>Occupation;
vector<int>deposit;

string password()
{
    string pasw;
    cout<<"ENTER THE PASSWORD ";
    cin.ignore();
    while(true)
    {
        char ch = _getch();
        if(ch == 13)
        {
            cout<<endl;break;
        }
        else if(ch == 8)
        {
            if(!pasw.empty())
            {
                pasw.pop_back();
                cout<<"\b \b";
            }
        }
        else{
        pasw += ch;
        cout<<"*";
        }
    }
    return pasw;
}
class CreateAccount
{
    private:
     string  name;
     int     AuId;
     string  passward;
     string  occupation;

     public:
   CreateAccount(string name ,int  AuId , string  passward , string  occupation)
   {
    this->name = name;
    this->AuId = AuId;
    this->passward = passward;
    this->occupation = occupation; 
    
    Name.push_back(name);
    Auid.push_back(AuId);
    Password.push_back(passward);
    Occupation.push_back(occupation);
    deposit.push_back(0);
    cout<<"::-->>::DEAR CUSTOMER YOUR ACCOUNT IS SUCCESSFULLY CREATED::-->>::"<<endl;
   }
};

class checkBallenceAndDetails
{
    private:
    int Id;
    string PasW;
    public:
    checkBallenceAndDetails(int Id , string PasW)
    {
        this-> Id = Id;
        this->PasW = PasW;

        bool foundId = false;
        bool foundpassward = false;
     for(int i=0; i<Auid.size(); i++)
     {
      
        if( Auid[i]== Id && Password[i]==PasW)
        {
            foundId= true;
            foundpassward = true;
    cout<<"***---THE DETAILA OF YOUR ACCOUNT IS ----***"<<endl;
    cout<<" THE NAME IS::-->>::"<<Name[i]<<endl;
    cout<<" THE AU ID OF THE PERSON IS "<<Auid[i]<<endl;
    cout<<" THE OCCUPATION OF THE PERSON IS ::-->>::"<<Occupation[i]<<endl;
    cout<<" THE CURRENT BALLENCE ON THE ACCOUNT IS "<<deposit[i]<<endl;
            break;
        }

     } // outer loop end
if (!foundId && !foundpassward) 
{
    cout << "Invalid ID or password.\n";
}
    }// constructor end;

};// function end

class Deposit // using au id and password
{
    private :
    int id;
    string pas;
    public:
    Deposit(int id , string Pas)
    {
        this->id = id;
        this->pas = Pas;
    bool found = false;
    for(int i=0; i<Auid.size(); i++)
    {
       
        if(Auid[i] == id &&  Password[i] == pas)
        {
            found = true;
        
            int amount;
            cout<<"::-->>::VERIVICATION SUCCESSFULL::-->>::"<<endl;
            cout<<" ENTER THE AMOUNT YOU WANT TO DEPOSIT "<<endl; 
            cin>>amount;
            if(amount > 0)
            { 
                deposit[i]  +=  amount;
                cout<<"THE AMOUNT-->>"<<amount<<"-->>IS ADDED IN YOUR ACCOUNT"<<endl;
            }
            else
            {
                cout<<" ENTER AMOUNT GREATER THEN ZERO "<<endl;
            }
             break;
        }
            }//for loop endl
      if(!found)
     { 
        cout<<"SORRY THIS ACCOUNT IS NOT REGISTERED "<<endl;
     }
    }// constructor end
}; //class end

class Withdraw
{
    private:
    int ID;
    string passward;

    public:
    Withdraw(int ID , string passward )
{
    this->ID = ID;
    this->passward = passward;
    bool found = false;
    for(int i=0; i<Name.size(); i++)
    {
        if(Auid[i] == ID && Password[i] == passward)
        {
            int amount;
            found = true;
            cout<<"-->>::VERIFICATION SUCCESS FULL::<<--"<<endl;
            cout<<" ENETR THE AMOUNT YOU WANT TO WITHDRAW "<<endl;
            cin>>amount;
            if(deposit[i] > amount)
            {
                 deposit[i] -= amount;
                 cout<<" THE AMOUNT::>>"<<amount<<"<<::YOU ENTER IS WITHDRAW FROM THE ACCOUNT "<<endl;
            }
            else
            {
                cout<<"-->>::YOU HAVE LESS BALLENCE CHECK DETAILS THANK YOU::<<--"<<endl;
            }
               break;
        } // end of if statement
    } // for loop end 
if(! found)
{
    cout<<" THIS ACCOUNT IS NOT REGISTERED "<<endl;
}
}// constructor end
};// class end

int main()
{
    string response;
    int choice;
    do
    {
        cout<<"     ----------WELCOME IN ==**AU**== BANK------------"<<endl;
        cout<<" PRESS 1 TO OPEN THE ACCOUNT IN --==AU==-- BANK "<<endl;
        cout<<" PRESS 2 TO DEPOSIT MONEY IN YOUR ACCOUNT BY YOUR *AU* ID AND PASSWORD "<<endl;
        cout<<" PRESS 3 TO WITHDRAW YOUR MONEY BY GIVING *AU* ID AND PASSWORD "<<endl;
        cout<<" PRESS 4 TO CHECH YOUR BALLENCE AND DETAILS BY GIVING *AU* ID AND PASSWORD "<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:{
            string name ,pass , occupation;
            int  AuId ;
            cout<<" ENTER YOUR NAME "<<endl;
            cin.ignore();
            getline(cin , name);
            cout<<" ENTER YOUR AUID AND REMEMBER ID "<<endl;
            cin>>AuId;
            pass = password();
            cout<<" ENTER YOUR OCCUPATION "<<endl;
            getline(cin , occupation);
            CreateAccount cr(name , AuId , pass , occupation);
            break;
            }
            case 2:
            {
                int ID;
                cout<<" ENTER YOUR *AU* ID"<<endl;
                cin>>ID;
                string pass =  password();                
                Deposit de (ID , pass);
            break;
            }
            case 3:
            {
                int  Id;
                string pas;
                char ch;
                cout<<" ENTER YOUR *AU* ID"<<endl;
                cin>>Id;
                pas = password();
                Withdraw wd (Id , pas);
            }
            break;

            case 4:
            {
            int id;
            string pas;
            char ch;
            cout<<" ENTER YOUR *AU* ACCOUNT ID"<<endl;
            cin>>id;
            pas = password();
            checkBallenceAndDetails chBal(id , pas);
            break;
            }
            default:
            cout<<"INVALID CHOICE "<<endl;
            break;
        }
     cout<<" DO YOU WANT TO CONTINUE PRESS *Y* FOR YES AND *N* FOR NO"<<endl;
     cin>>response;
    } while (response == "y" && response != "n");

return 0;
}
