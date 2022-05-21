#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
string garbage;

class plans
{
public:
    float amount;
    float year;
    float rate;
};

class user
{
private:
    /* data */
public:
    string name;
    string username;
    string password;
    float type;
    void setter();
};

void user :: setter()
{
    string garbage;
    cout << "enter the type of user:lender(0),borrower(1)";
    cin >> type;
    getline(cin, garbage);
    cout << "enter the name:";
    getline(cin, name);
    cout << "enter the username:";
    getline(cin, username);
    cout << "enter the password:";
    getline(cin, password);
}

class borrower : private user
{
private:
    float borrowerId;

public:
    borrower();
    void plansdisplay();
    float total_amount_paid(plans obj);
    float calcRate(float amount, float years);
    // void EMI(plans obj);
};

float borrower::calcRate(float amount, float years)
{
    float r = 4;
    return r;
}


float borrower::total_amount_paid(plans obj)
{
    return (float)obj.amount * (float)(1.0 + (float)(obj.rate / 100)) * (1.0 + (float)(obj.rate / 100));
}

void borrower::plansdisplay()
{
    cout << "\n welcome to plans page";
    plans obj;
    ifstream fin;
    fin.open("plans.txt", ios::in);
    fin.seekg(0, ios::beg);
    fin.read((char *)&obj, sizeof(obj));
    while (!fin.eof())
    {
        cout << "\nplans";
        cout << obj.amount << " " << obj.year << " " << obj.rate;
        fin.read((char *)&obj, sizeof(obj));
    }
    plans obj1;
    cout << "enter the amount that you lend";
    cin >> obj1.amount;
    cout << "enter the years:";
    cin >> obj1.year;
    cout << "corresponding rate:";
    obj1.rate = calcRate(obj1.amount, obj1.year);
    // cout << "\nEMI:";
    // EMI(obj1);
    cout << "\ntotal amount to be paid ";
    float t = total_amount_paid(obj1);
    cout << t;
}

borrower::borrower()
{
    setter();
    cout << "enter the Id:";
    cin >> borrowerId;
    getline(cin, garbage);
}

class lender : public user
{
private:
    float lenderId;

public:
    lender();
    void adminpower();
    void showAllAccount();
};

void lender ::showAllAccount()
{
    ifstream fin;
    fin.open("user.txt", ios::in);
    fin.seekg(0, ios::beg);
    user obj;
    fin.read((char *)&obj, sizeof(obj));
    while (!fin.eof())
    {
        if (obj.type == 1)
        {
            cout << "book found\n";
            cout << obj.name << endl
                 << obj.username << endl;
        }
        fin.read((char *)&obj, sizeof(obj));
    }
}

void lender::adminpower()
{
    plans obj;
    char ch = 'y';
    while (ch == 'y')
    {

        cout << "enter the amount ";
        cin >> obj.amount;
        cout << "enter the years ";
        cin >> obj.year;
        cout << "rate:";
        cin >> obj.rate;
        ofstream fout;
        fout.open("plans.txt", ios::app);
        fout.write((char *)&obj, sizeof(obj));
        cout << " do you want to add anonther plan(y) otherwise press any key:\n";
        cin >> ch;
    }
}

lender::lender()
{
    setter();
    cout << "enter the lender Id:";
    cin >> lenderId;
    getline(cin, garbage);
}

int main()
{
start:
    cout << "**********welcome to chuna laga ke banking:**********";
    cout<<"\ncreating initial objects of lender and borrower:";
    lender len2;
    borrower bor2;
    cout << "\nMenu list:";
    cout << "\n1. user input:";
    cout << "\n2. borrow menu:";
    cout << "\n3 .lender menu:";
    int n;
    cin >> n;
    if (n == 1)
    {
        /* code */
        /* code */
        cout << "\nenter the type of user( borrower(0),lender(1):";
        int m;
        cin >> m;
        if (m)
        {
            lender len;
            goto start;
        }
        else
        {
            borrower bor;
            goto start;
        }
    }

    else if (n == 2)
    {
        /* code */
        /* code */
        cout << "\nborrower:";
        bor2.plansdisplay();
        goto start;
    }

    else if (n == 3)
    {
        /* code */
        cout << "\nlender:";
        len2.adminpower();
        goto start;
    }
    else{
        cout<< "\nwrong choice:";
    }
    
    return 0;
}