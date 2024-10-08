#include<iostream>
#include<fstream>


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
        void removeProduct();
        void display(); 
        void receipt();
};

void shopping :: menu(){
    
    m:
    int choice;
    string email;
    string password;
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

void shopping::admin(){
    m:
    int choice;
    cout<<"\nAdmin Menu\n";
    cout<<"________________\n";
    cout<<"1) Add Product\n";
    cout<<"2) Update Product\n";
    cout<<"3) Delete Product\n";
    cout<<"4) Return to Main Menu\n";

    cin>>choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        update();
        break;
    case 3:
        removeProduct();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid Choice\n";
        break;
    }
    goto m;
}

void shopping::user(){
    int choice;
    cout<<"\nUser Menu\n";
    cout<<"________________\n";
    cout<<"1) Purchase\n";
    cout<<"2) Return to Main Menu\n";

    cin>>choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"Invalid Choice\n";
        break;
    }
}

void shopping::add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\nAdd New Product\n";
    cout<<"_____________________\n";
    cout<<"Add product code\n";
    cin>>productCode;
    cout<<"Add product name\n";
    cin>>productName;
    cout<<"Add product price\n";
    cin>>price;
    cout<<"add product disount\n";
    cin>>discount;

    data.open("database.txt",ios::in);
    if(!data){
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<productCode<<" "<<productName<<" "<<price<<" "<<discount<<endl;
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == productCode){
                token++;
            }
            data>>c>>n>>p>>d; 
        }
        data.close();

        if(token == 1){
            goto m;
        }
        else{
            data.open("database.txt", ios::app|ios::out);
            data<<" "<<productCode<<" "<<productName<<" "<<price<<" "<<discount<<endl;
            data.close();
        }
    }
    cout<<"\nProduct Added!\n";
}

void shopping::update(){
    fstream data, data1;
    int productKey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\nUpdate Products\n";
    cout<<"_____________________\n";
    cout<<"Enter product code\n";
    cin>>productKey;

    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\nFile does not exist\n";
    }
    else{
        data1.open("database2.txt", ios::app | ios::out);
        data >> productCode >> productName >> price >> discount;
        while(!data.eof()){
            if(productCode == productKey){
                cout<<"\nUpdated product code\n";
                cin>>c;
                cout<<"\nUpdated product name\n";
                cin>>n;
                cout<<"\nUpdated product price\n";
                cin>>p;
                cout<<"\nUpdated product discount\n";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<"\nProduct Updated!\n";
                token++;
            }
            else{
                data1<<" "<<productCode<<" "<<productName<<" "<<price<<" "<<discount<<endl; 
            }
            data>>productCode>>productName>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database2.txt", "database.txt");

        if(token == 0){
            cout<<"\nProduct not found\n";
        }
    }
}

void shopping::removeProduct(){
    fstream data,data1;
    int productKey = 0;
    int token = 0;
    cout<<"\nDelete Product\n";
    cout<<"_____________________\n";
    cout<<"Product code\n";
    cin>>productKey;

    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\nFile does not exist\n";
    }
    else{
        data1.open("database2.txt", ios::app | ios::out);
        data>>productCode>>productName>>price>>discount;
        while(!data.eof()){
            if(productCode == productKey){
                cout<<"\nProduct deleted!\n";
                token++;
            }
            else{
                data1<<" "<<productCode<<" "<<productName<<" "<<price<<" "<<discount<<endl;
            }
            data>>productCode>>productName>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database2.txt", "database.txt");

        if(token == 0){
            cout<<"\nProduct Not Found!"<<endl;
        }
    }
}

void shopping::display(){
    fstream data;
    data.open("database.txt", ios::in);
    data>>productCode>>productName>>price>>discount;
    while(!data.eof()){
        cout<<productCode<<"\t\t"<<productName<<"\t\t"<<price<<endl;
        data>>productCode>>productName>>price>>discount;
    }
    data.close();
}

void shopping::receipt(){
    fstream data;
    int array_of_codes[100];
    int array_of_quantites[100];
    char choice;
    int counter = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout<<"\n\nRECEIPT\n\n";
    data.open("database.txt"); 
    if(!data){
       cout<<"\n\n Empty Database \n\n"; 
    }
    else{
        data.close();
        display();
        cout<<"\n\n______________________________\n\n";
        cout<<"              Place Order             ";
        cout<<"\n\n______________________________\n\n";
        do
        {
            m:
            cout<<"Enter Product Code: ";
            cin>>array_of_codes[counter];
            cout<<endl;
            cout<<"Enter Quantity: ";
            cin>>array_of_quantites[counter];
            for(int i = 0; i < counter; i++){
               if(array_of_codes[i] == array_of_codes[counter]){
                cout<<"\n\nDuplicated product code, enter product code again: ";
                goto m; 
               }
            }
            counter++;
            cout<<"\n\n Another request (Y/N):";
            cin>>choice;
        } while (choice == 'Y' || choice == 'y');
        
        cout<<"\n\n\t\t\t Receipt \t\t\t\n\n";
        cout<<"Product Number \t Product Name \t Product Quantity \t Price \t Discount\n";
        for(int i = 0; i < counter; i++){
            data.open("database.txt", ios::in);
            data>>productCode>>productName>>price>>discount;
            while(!data.eof()){
                if(productCode == array_of_codes[i]){
                    amount = price * array_of_quantites[i];
                    discount = amount - (amount*discount/100);
                    total = total + discount;
                    cout<<"\n"<<productCode<<"\t"<<productName<<"\t"<<array_of_quantites[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<discount;
                }
                data>>productCode>>productName>>price>>discount;
            }
        }
        data.close();
    }
    cout<<"\n\n______________________\n\n";
    cout<<"Total Amount: "<<total<<endl;
}

int main(){
    shopping S;
    S.menu();
}