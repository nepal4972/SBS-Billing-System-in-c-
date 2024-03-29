#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
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

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t____________________________________" << endl;
    cout << "\t\t\t\t                                    " << endl;
    cout << "\t\t\t\t             Main Menu              " << endl;
    cout << "\t\t\t\t____________________________________" << endl;
    cout << "\t\t\t\t| 1)  Administrator |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t| 2)  Buyer         |" << endl;
    cout << "\t\t\t\t|                   |" << endl;
    cout << "\t\t\t\t| 3)  Exit          |" << endl;
    cout << "\t\t\t\t|                   |" << endl;

    cout << "Please Select Suitable Choice: ";
    cin >> choice;

    switch(choice)
    {
    case 1:
        cout << "Please Login" << endl;

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Password: ";
        cin >> password;

        if (email == "nepal4972@gmail.com" && password == "nepal4972")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid Email or Password"<<endl;
        }
        break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please Select Given options 1, 2 or 3" << endl;
    }
    }

    goto m:
}

void shopping :: administrator()
{
    int achoice;
    cout << "\n\n\n\n\t\t\t Administrator options" << endl;
    cout << "\t\t\t 1) Add Product" << endl;
    cout << "\t\t\t" << endl;
    cout << "\t\t\t 2) Edit Product" << endl;
    cout << "\t\t\t" << endl;
    cout << "\t\t\t 3) Delete Product" << endl;
    cout << "\t\t\t" << endl;
    cout << "\t\t\t 4) Back To Main Menu" << endl;
    cout << "\t\t\t" << endl;
    cout << "\t\t\t Enter Your Choice: ";
    cin >> achoice;

    switch (achoice)
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
        menu();
        break;

    default:
        cout << "Invalid Option!! Select Any One Option 1, 2, 3 or 4" << endl;
        break;
    }
    goto m;
}

void shopping :: buyer()
{
    int bchoice;
    cout << "\n\n\n\n\t\t\t Buyer" << endl;
    cout << "\t\t\t 1) Buy Product" << endl;
    cout << "\t\t\t" << endl;
    cout << "\t\t\t 2) Go Back To Menu" << endl;
    cout << "\t\t\t" << endl;
    cin >> bchoice;

    switch (bchoice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid option!! Please Select One Option" << endl;
        break;
    }

    goto m:
}

void shopping :: add()
{
ad:
    fstream data; // data is name of object
    int pc;
    int token = 0;
    float pr;
    float dis;
    string nm;

    cout << "\n\n\t\t\t Add new Product" << endl;
    cout << "\n\n\t\t\t Enter Product Code: " << endl;
    cin >> pcode;
    cout << "\n\n\t\t\t Enter Name of Product" << endl;
    cin >> pname;
    cout << "\n\n\t\t\t Enter Price of Product" << endl;
    cin >> price;
    cout << "\n\n\t\t\t Enter Discount of Product" << endl;
    cin >> discount;

    data.open("database.txt", ios::in); // ios::in will open file in reading mode and ios::out will open in writing mode

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out); // ios::app means append mode and out means write mode
        data << " " << pcode << " " << pname << " " << price << " " << discount << endl;
        data.close();
    }
    else
    {
        data >> pc >> nm >> pr >> dis;

        while (!data.eof())
        { // eof means end of file function
            if (pc == pcode)
            {
                token++;
            }
            data >> pc >> nm >> pr >> dis;
        }
        data.close();
    }

    if (token == 1)
    {
        goto ad;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << endl;
        data.close();
    }
    cout << "\n\t\t Added!!";
}

int main()
{
    shopping s;
    s.menu();
}
