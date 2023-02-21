#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void login();
void registration();
void reset();

int main(){
    
    int choice;
    cout<<"\t\t\t__________________________________________________________________\n\n\n";
    cout<<"\t\t\t                    Welcome to the Login Page                     \n\n\n";
    cout<<"\t\t\t___________________           MENU             ___________________\n\n\n";

    cout<<"\t| Press 1 to LOGIN                   |"<<endl;
    cout<<"\t| Press 2 to REGISTER                |"<<endl;
    cout<<"\t| Press 3 to Forget PASSWORD     |"<<endl;
    cout<<"\t| Press 4 to EXIT                    |"<<endl;
    cout<<"\n\n\tPlease enter your choice :  ";
    cin>>choice;
    cout<<"\n"<<endl;

    switch (choice){

        case 1:
            login();
            break;
        
        case 2:
            registration();
            break;
        
        case 3:
            reset();
            break;
        
        case 4:
            cout<<"\t\t\t Thank You!! \n\n";
            break;
        
        default :
            cout<<flush;
            // system("cls");
            cout<<"\t\t\t Invalid Choice! "<<endl;
            cout<<"\t\t\t Please select from the options given above.. \n"<<endl;
            main();

    }
    return 0;
}

void login(){

    int count=0;
    string userId, password, id, pass;
    cout<<flush;
    // system("cls");
    cout<<"\t\t\t Please enter the Username and Password  \n\n"<<endl;
    cout<<"\t\t\t Username : ";
    cin>>userId;
    cout<<endl;
    cout<<"\t\t\t Password : ";
    cin>>password;
    cout<<endl;

    ifstream input("records.txt");

    while(input>>id>>pass){
        if(id == userId && pass == password){
            count = 1;
            cout<<flush;
            // system("cls");
        }
    }
    input.close();

    if(count == 1){
        cout<<"\t\t\t Welcome "<<userId<<"\n\n\t\t\t Your LOGIN is successful \n\n\t\t\t Thanks for logging in..  \n";
        cout<<"\n\n"<<endl;
        main();
    }
    else{
        cout<<"\n\n\t\t\t !!! LOGIN ERROR !!! \n\t\t\t Please check your Username and Password\n";
        cout<<"\n\n"<<endl;
        main();
    }
}


void registration(){
    string ruserId, rpassword, rid, rpass;
    cout<<flush;
    // system("CLS");
    cout<<"\t\t\t Enter the Username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the Password : ";
    cin>>rpassword;

    ofstream f1("records.txt",  ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    cout<<flush;
    // system("cls");
    cout<<"\n\n"<<endl;
    cout<<"\n\t\t\t\t\t Registration is Successful! \n";
    main();

}


void reset()
{
    int option;
    cout<<flush;
    // system("cls");
    cout<<"\t\t\t\t\t Forgot the Password? No worries \n\n\n";
    cout<<"\t\t\t Press 1 to search your ID by Username "<<endl;
    cout<<"\t\t\t Press 2 to go back to the Main Menu "<<endl;
    cout<<"\n\t\t\t Enter your choice : ";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserId, sId, spass;
            cout<<"\n\t\t\t Enter the Username which you remembered : ";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass){
                if(sId==suserId){
                    count = 1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your account is found!  \n";
                cout<<"\n\n Your password is : "<<spass;
                main();
            }
            else{
                cout<<"\n\t Sorry! your account is not found! \n";
            }
            
            break;
        }

        case 2:
        {
            main();
            break;
        }

        default :
            cout<<"\t\t\t Wrong choice! Please try again "<<endl;
            reset();

    }
}