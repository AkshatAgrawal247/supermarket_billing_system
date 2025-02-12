#include<iostream>
#include<fstream>
using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string pname;
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu()
{
    while (true) {
        int choice;
        string email;
        string password;

        cout<<" \t\t\t\t ________________________ \n";
        cout<<" \t\t\t\t|                         |\n";
        cout<<" \t\t\t\t|  Supermarket Main Menu  |\n";
        cout<<" \t\t\t\t|_________________________|\n";
        cout<<" \t\t\t\t                           \n";
        cout<<" \t\t\t\t| 1) Administrator        |\n";
        cout<<" \t\t\t\t| 2) Buyer                |\n";
        cout<<" \t\t\t\t| 3) Exit                 |\n";
        cout<<" \t\t\t\t|_________________________|\n";
        cout<<"\n\t\t Please select! ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\t\t\t Please Login \n";
                cout<<"\t\t\t Enter Email  \n";
                cin>>email;
                cout<<"\t\t\t Password \n";
                cin>>password;

                if(email=="robby@email.com" && password=="robby@123")
                {
                    administrator();
                }
                else
                {
                    cout<<"Invalid email/password";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                exit(0);

            default:
                cout<<"Please select from the given options";
        }
    }
}

void shopping::administrator()
{
    while (true) {
        int choice;

        cout<<"\n\n\n\t\t\t\t|  Administrator Menu";
        cout<<"\n\t\t\t\t|____ 1) Add Product          |\n";
        cout<<"\n\t\t\t\t|____ 2) Modify the Product   |\n";
        cout<<"\n\t\t\t\t|____ 3) Delete the Product   |\n";
        cout<<"\n\t\t\t\t|____ 4) Back to the main men |\n";
        cout<<"\n\t\t\t\t|_________________________|\n";
        cout<<"\n\t\t Please enter your choice ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                rem();
                break;
            case 4:
                return;

            default:
                cout<<"Please select from the given options";
        }
    }
}

void shopping::buyer()
{
    while (true) {
        int choice;

        cout<<"\n\n\n\t\t\t\t|  Buyer  ";
        cout<<"\t\t\t_____________\n";
        cout<<"\t\t\t\t____ 1)Buy Products \n";
        cout<<"                     \n";
        cout<<"\n\t\t\t\t____ 2) Go back \n";
        cout<<"\t\t\t\t____ 3) Enter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 1:
                receipt();
                break;
            case 2:
                return;
            default:
                cout<<"Please select from the given options";
        }
    }
}

void shopping::add()
{
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\t\t\t Enter the product code: ";
    cin>>pcode;
    cout<<"\n\t\t\t Enter the product name: ";
    cin>>pname;
    cout<<"\n\t\t\t Enter the product price: ";
    cin>>price;
    cout<<"\n\t\t\t Enter the product discount: ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if (!data){
        data.open("database.txt",ios::out);
        data<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        data.close();
    }
    else {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token == 1){
            cout << "\n\t\t\t Product code already exists!";
        }
        else {
            data.open("database.txt",ios::app|ios::out);
            data<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
            data.close();
            cout<<"\n\t\t\t Product added successfully";
        }
    }
}

void shopping::edit()
{
    fstream data, data1;
    int c;
    int pkey;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Edit product";
    cout<<"\n\t\t\t Enter the product code: ";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if (!data){
        cout<<"Database is empty";
    }
    else {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\t\t\t Enter the new product code: ";
                cin>>c;
                cout<<"\n\t\t\t Enter the product name: ";
                cin>>n;
                cout<<"\n\t\t\t Enter the product price: ";
                cin>>p ;
                cout<<"\n\t\t\t Enter the product discount: ";
                cin>>d ;
                data1<< c<<"\t"<<n<<"\t"<<p<<"\t"<<d<<"\n";
                cout<<"\n\t\t\t Product edited successfully";
                token++;
            }
            else {
                data1<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\t\t\t Product not found";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t\t\t Delete product";
    cout<<"\n\t\t\t Enter the product code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"Database is empty";
    }
    else {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\t\t\t Product deleted successfully";
                token++;
            }
            else {
                data1<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\t\t\t Product not found";
        }
    }
}

void shopping::list()
{
    fstream data;

    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________\n";
    cout<<"product code\tproduct name\tprice\tdiscount\n";
    cout<<"|__________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float discount = 0;
    float total = 0;

    cout<<"\n\n\t\t\t\t|  Receipt  ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"Database is empty";
    }
    else {
        data.close();
        list();
        cout<<"\n_________________________________\n";
        cout<<"\n|                                 \n";
        cout<<"\n        Please place your order     \n";
        cout<<"\n_________________________________\n";

        do
        {m:
            cout<<"\n\n\t\t\t Enter the product code: ";
            cin>>arrc[c];
            cout<<"\n\t\t\t Enter the quantity: ";
            cin>>arrq[c];
            for (int i = 0; i < c; i++)
            {
                if(arrc[i]==arrc[c]){
                    cout<<"\n\t\t\t Product already added";
                    goto m;
                }
            }
            c++;
            cout<<"\n\t\t\t Do you want to add more products? (y/n)";
            cin>>choice;
        } while (choice=='y');

        cout<<"\n\n\t\t\t\t|  Receipt  ";
        cout<<"\n_________________________________\n";
        cout<<"product No\tproduct name\tprice\t Product quantity\tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount = price*arrq[i];
                    discount = dis*amount/100;
                    total = total + (amount - discount);
                    cout<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<arrq[i]<<"\t"<<amount<<"\t"<<amount - discount<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }
        cout<<"\n\n\t\t\t Total amount: "<<total;
    }
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}