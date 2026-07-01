#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//================ COLORS =================
void setColor(int color)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

//================ Employee =================

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    Employee(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }

    void display() {
        setColor(3);
        cout << "\nEmployee Information\n";
        setColor(7);

        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << " EGP" << endl;
        cout << "------------------------\n";
    }
};

//================ Sold Product =================

class SoldProduct {
private:
    string productName;
    string date;
    double price;

public:
    SoldProduct(string p, string d, double pr) {
        productName = p;
        date = d;
        price = pr;
    }

    void display() {
        setColor(6);
        cout << "\nSold Product\n";
        setColor(7);

        cout << "Product: " << productName << endl;
        cout << "Date: " << date << endl;
        cout << "Price: " << price << " EGP" << endl;
        cout << "------------------------\n";
    }
};

//================ Product Base =================

class Product {
protected:
    string name;
    double price;
    string brand;

public:
    Product(string n, double p, string b) {
        name = n;
        price = p;
        brand = b;
    }

    double getPrice() {

         return price;

          }
    string getName() {

         return name;

         }

    void display() {
        setColor(2);
        cout << "Name: ";
        setColor(7);
        cout << name << endl;

        setColor(2);
        cout << "Brand: ";
        setColor(7);
        cout << brand << endl;

        setColor(2);
        cout << "Price: ";
        setColor(7);
        cout << price << " EGP" << endl;
    }

    friend double operator+(Product p1, Product p2) {
        return p1.price + p2.price;
    }
};

//================ Lipstick =================

class Lipstick : public Product {
private:
    string shade;

public:
    Lipstick(string n, double p, string b, string s)
        : Product(n, p, b) {
        shade = s;
    }

    void display() {
        setColor(5);
        cout << "\n--- LIPSTICK ---\n";
        setColor(7);

        Product::display();

        setColor(5);
        cout << "Shade: " << shade << endl;
        cout << "-----------------\n";
    }
};

//================ Foundation =================

class Foundation : public Product {
private:
    string skinType;

public:
    Foundation(string n, double p, string b, string st)
        : Product(n, p, b) {
        skinType = st;
    }

    void display() {
        setColor(1);
        cout << "\n--- FOUNDATION ---\n";
        setColor(7);

        Product::display();

        setColor(1);
        cout << "Skin Type: " << skinType << endl;
        cout << "-----------------\n";
    }
};

//================ Skincare =================

class Skincare : public Product {
private:
    string use;

public:
    Skincare(string n, double p, string b, string u)
        : Product(n, p, b) {
        use = u;
    }

    void display() {
        setColor(3);
        cout << "\n--- SKINCARE ---\n";
        setColor(7);

        Product::display();

        setColor(3);
        cout << "Use: " << use << endl;
        cout << "-----------------\n";
    }
};

//================ MAIN =================

int main()
{
    Lipstick lip[2] = {
        Lipstick("Matte Lipstick",300,"Maybelline","Red"),
        Lipstick("Gloss Lipstick",250,"Essence","Pink")
    };

    Foundation fd[2] = {
        Foundation("Fit Me",450,"Maybelline","Oily"),
        Foundation("True Match",600,"Loreal","Dry")
    };

    Skincare sc[2] = {
        Skincare("Face Wash",200,"Nivea","Cleaning"),
        Skincare("Moisturizer",350,"Cetaphil","Hydration")
    };

    Employee emp("Ashrakat",230,8000);
    SoldProduct sold("Fit Me Foundation","20/6/2026",450);

    int choice;

    while (true)
    {
        setColor(6);
        cout << "\n====================================\n";
        setColor(4);
        cout << "      MAKEUP STORE SYSTEM           \n";
        setColor(6);
        cout << "====================================\n";

        setColor(7);
        cout << "1. Employee Info\n";
        cout << "2. Sold Product\n";
        cout << "3. Available Products\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            emp.display();
        }

        else if (choice == 2)
        {
            sold.display();
        }

        else if (choice == 3)
        {
            int sub;

            while (true)
            {
                setColor(6);
                cout << "\n========== PRODUCTS ==========\n";
                setColor(7);

                cout << "1. Lipsticks\n";
                cout << "2. Foundations\n";
                cout << "3. Skincare\n";
                cout << "4. Back\n";

                cout << "Enter Choice: ";
                cin >> sub;

                if (sub == 1)
                {
                    double total = lip[0] + lip[1];

                    lip[0].display();
                    lip[1].display();

                    cout << "Total Lipsticks = " << total << " EGP\n";
                }

                else if (sub == 2)
                {
                    double total = fd[0] + fd[1];

                    fd[0].display();
                    fd[1].display();

                    cout << "Total Foundations = " << total << " EGP\n";
                }

                else if (sub == 3)
                {
                    double total = sc[0] + sc[1];

                    sc[0].display();
                    sc[1].display();

                    cout << "Total Skincare = " << total << " EGP\n";
                }

                else if (sub == 4)
                {
                    break;
                }
            }
        }

        else if (choice == 4)
        {
            setColor(4);
            cout << "Good Bye!\n";
            setColor(7);
            break;
        }
    }

    return 0;
}
