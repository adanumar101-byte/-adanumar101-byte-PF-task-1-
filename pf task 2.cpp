#include <iostream>
#include <iomanip>
using namespace std;

string customerName;
string contactNumber;
string orderType;
int numberOfPersons;


string foodItems[8] =
{
    "Chicken Burger",
    "Zinger Burger",
    "Pizza Small",
    "Pizza Large",
    "Chicken Biryani",
    "BBQ Platter",
    "Fries",
    "Cold Drink"
};

double prices[8] =
{
    450,
    550,
    900,
    1800,
    350,
    1200,
    250,
    120
};

double totalFoodBill = 0;

void registerCustomer();
void displayFoodMenu();
void placeOrder();

double calculateFoodBill();
double calculateServiceCharges(double amount);
double calculateGST(double amount);
double calculateDiscount(double amount);

void displayFinalBill();
void displayCustomerDetails();

void registerCustomer()
{
    cout << "========== CUSTOMER REGISTRATION ==========\n";

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Contact Number: ";
    getline(cin, contactNumber);

    cout << "\nSelect Order Type:\n";
    cout << "1. Dine-in\n";
    cout << "2. Takeaway\n";
    cout << "Enter Choice: ";

    int choice;
    cin >> choice;

    if(choice == 1)
    {
        orderType = "Dine-in";
    }
    else
    {
        orderType = "Takeaway";
    }

    cout << "Enter Number of Persons: ";
    cin >> numberOfPersons;

    cout << "\nCustomer Registered Successfully!\n";
}

void displayFoodMenu()
{
    cout << "\n========== FOOD MENU ==========\n";

    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". "
             << foodItems[i]
             << " - Rs. "
             << prices[i]
             << endl;
    }

    cout << "===============================\n";
}

void placeOrder()
{
    int itemNumber, quantity;
    char choice;

    do
    {
        displayFoodMenu();

        cout << "\nEnter Item Number: ";
        cin >> itemNumber;

        while(itemNumber < 1 || itemNumber > 8)
        {
            cout << "Invalid Item Number! Enter Again: ";
            cin >> itemNumber;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;

        while(quantity <= 0)
        {
            cout << "Invalid Quantity! Enter Again: ";
            cin >> quantity;
        }

        double itemTotal =
            prices[itemNumber - 1] * quantity;

        totalFoodBill += itemTotal;

        cout << "\nItem Added Successfully!\n";
        cout << "Current Bill: Rs. "
             << totalFoodBill << endl;

        cout << "\nDo You Want to Order More? (Y/N): ";
        cin >> choice;

    } while(choice == 'Y' || choice == 'y');
}

double calculateFoodBill()
{
    return totalFoodBill;
}

double calculateServiceCharges(double amount)
{
    if(orderType == "Dine-in")
    {
        return amount * 0.10;
    }
    else
    {
        return amount * 0.05;
    }
}

double calculateGST(double amount)
{
    return amount * 0.16;
}

double calculateDiscount(double amount)
{
    if(amount >= 3000 && amount <= 5000)
    {
        return amount * 0.05;
    }
    else if(amount >= 5001 && amount <= 10000)
    {
        return amount * 0.10;
    }
    else if(amount > 10000)
    {
        return amount * 0.15;
    }
    else
    {
        return 0;
    }
}

void displayFinalBill()
{
    double foodBill;
    double serviceCharges;
    double gst;
    double discount;
    double totalAmount;

    foodBill = calculateFoodBill();

    serviceCharges =
        calculateServiceCharges(foodBill);

    gst =
        calculateGST(foodBill);

    discount =
        calculateDiscount(foodBill);

    totalAmount =
        foodBill +
        serviceCharges +
        gst -
        discount;

    cout << fixed << setprecision(2);

    cout << "\n\n========== RESTAURANT BILL ==========\n";

    cout << "Customer Name: "
         << customerName << endl;

    cout << "Order Type: "
         << orderType << endl;

    cout << "Number of Persons: "
         << numberOfPersons << endl;

    cout << "\nFood Bill: Rs. "
         << foodBill << endl;

    cout << "Service Charges: Rs. "
         << serviceCharges << endl;

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Discount: Rs. "
         << discount << endl;

    if(totalAmount > 5000)
    {
        cout << "\nFree Delivery Applied!\n";
    }

    cout << "\n------------------------------------\n";

    cout << "Total Payable Amount: Rs. "
         << totalAmount << endl;

    cout << "Enjoy Your Meal :)\n";

    cout << "====================================\n";
}

void displayCustomerDetails()
{
    cout << "\n========== CUSTOMER DETAILS ==========\n";

    cout << "Customer Name: "
         << customerName << endl;

    cout << "Contact Number: "
         << contactNumber << endl;

    cout << "Order Type: "
         << orderType << endl;

    cout << "Number of Persons: "
         << numberOfPersons << endl;

    cout << "======================================\n";
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout << "\n========== RESTAURANT MANAGEMENT SYSTEM ==========\n";

        cout << "1. View Food Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Calculate Bill\n";
        cout << "4. View Customer Details\n";
        cout << "5. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                displayFoodMenu();
                break;
            }

            case 2:
            {
                placeOrder();
                break;
            }

            case 3:
            {
                displayFinalBill();
                break;
            }

            case 4:
            {
                displayCustomerDetails();
                break;
            }

            case 5:
            {
                cout << "\nProgram Exited Successfully!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice! Try Again.\n";
            }
        }

    } while(choice != 5);

    return 0;
}
