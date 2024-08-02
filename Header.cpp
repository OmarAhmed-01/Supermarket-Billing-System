#include <iostream>
#include <fstream>

using namespace std;

class shopping {
    private: 
        int productCode;
        float price;
        float discount;
        string productName;

    public:
        void menu();
        void admin();
        void user();
        void add();
        void update();
        void remove();
        void display(); 
        void receipt();
};

void shopping :: menu(){
    
    int choice;
    string email;
    string password;
    m:
    cout<<"\t\t\t\t_____________________________________\n";
    cout<<"\t\t\t\t                                     \n";
    cout<<"\t\t\t\t             Main Menu               \n";
    cout<<"\t\t\t\t                                     \n";
    cout<<"\t\t\t\t_____________________________________\n";
    cout<<"\t\t\t\t                                     \n";

    cout<<"\t\t\t\t 1) Admin\n";
    cout<<"\t\t\t\t 2) User\n";
    cout<<"\t\t\t\t 3) Exit\n";

    cout<<"Select\n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"Enter email and password\n";
        cin>>email;
        cin>>password;

        if(email == "xyz@yahoo.com" && password == "xyz123"){
            admin();
        }
        else{
            cout<<"Invalid admin email or password\n";
        }
        break;
    case 2:
        {
            user();
        }
    case 3: 
        exit(0);
    default:
        {
            cout<<"Please select from options\n";
        }
        break;
    }
    goto m;
}
