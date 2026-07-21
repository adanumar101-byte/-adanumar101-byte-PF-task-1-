#include <iostream>
#include <iomanip>
using namespace std;

string customerName;
int customerID;
string customerType;
string paymentMethod;

string groceryItems[8] =
{
    "Rice 1 KG",
    "Sugar 1 KG",
    "Cooking Oil 1 Litre",
    "Milk Pack",
    "Tea Pack",
    "Flour 5 KG",
    "Eggs Dozen",
    "Detergent"
};

double prices[8] =
{
    350,
    180,
    580,
    220,
    450,
    950,
    320,
    600
};

double grossBill = 0;
double totalTax = 0;

void registerCustomer();
void displayGroceryList();
void addItemsToCart();

double calculateGrossBill();
double calculateSalesTax();
double calculateMembershipDiscount(double amount);
double calculateBillDiscount(double amount);
double calculateCardCharges(double amount);

int calculateLoyaltyPoints(double amount);

void displayFinalBill();
void displayCustomerDetails();

void registerCustomer()
{
    cout << "========== CUSTOMER REGISTRATION ==========\n";

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Customer ID: ";
    cin >> customerID;

    cout << "\nSelect Customer Type:\n";
    cout << "1. Regular Customer\n";
    cout << "2. Member Customer\n";
    cout << "Enter Choice: ";

    int choice;
    cin >> choice;

    if(choice == 1)
    {
        customerType = "Regular";
    }
    else
    {
        customerType = "Member";
    }

    cout << "\nSelect Payment Method:\n";
    cout << "1. Cash\n";
    cout << "2. Card\n";
    cout << "Enter Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        paymentMethod = "Cash";
    }
    else
    {
        paymentMethod = "Card";
    }

    cout << "\nCustomer Registered Successfully!\n";
}

void displayGroceryList()
{
    cout << "\n========== GROCERY ITEMS ==========\n";

    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". "
             << groceryItems[i]
             << " - Rs. "
             << prices[i]
             << endl;
    }

    cout << "===================================\n";
}

void addItemsToCart()
{
    int itemNumber, quantity;
    char choice;

    do
    {
        displayGroceryList();

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

        grossBill += itemTotal;

        if(itemNumber >= 1 && itemNumber <= 7)
        {
            totalTax += itemTotal * 0.05;
        }
        else
        {
            totalTax += itemTotal * 0.10;
        }

        cout << "\nItem Added Successfully!\n";
        cout << "Current Gross Bill: Rs. "
             << grossBill << endl;

        cout << "\nDo You Want to Add More Items? (Y/N): ";
        cin >> choice;

    } while(choice == 'Y' || choice == 'y');
}

double calculateGrossBill()
{
    return grossBill;
}

double calculateSalesTax()
{
    return totalTax;
}

double calculateMembershipDiscount(double amount)
{
    if(customerType == "Member")
    {
        return amount * 0.07;
    }
    else
    {
        return 0;
    }
}

double calculateBillDiscount(double amount)
{
    if(amount >= 5000 && amount <= 10000)
    {
        return amount * 0.05;
    }
    else if(amount > 10000)
    {
        return amount * 0.10;
    }
    else
    {
        return 0;
    }
}

double calculateCardCharges(double amount)
{
    if(paymentMethod == "Card")
    {
        return amount * 0.02;
    }
    else
    {
        return 0;
    }
}

int calculateLoyaltyPoints(double amount)
{
    return amount / 100;
}

void displayFinalBill()
{
    double gross;
    double tax;
    double memberDiscount;
    double billDiscount;
    double cardCharges;
    double totalAmount;

    gross = calculateGrossBill();

    tax = calculateSalesTax();

    memberDiscount =
        calculateMembershipDiscount(gross);

    billDiscount =
        calculateBillDiscount(gross);

    cardCharges =
        calculateCardCharges(gross);

    totalAmount =
        gross +
        tax +
        cardCharges -
        memberDiscount -
        billDiscount;

    int generatedPoints =
        calculateLoyaltyPoints(totalAmount);

    int existingPoints;

    cout << fixed << setprecision(2);

    cout << "\n\n========== GROCERY MART BILL ==========\n";

    cout << "Customer Name: "
         << customerName << endl;

    cout << "Customer Type: "
         << customerType << endl;

    cout << "Payment Method: "
         << paymentMethod << endl;

    cout << "\nGross Bill: Rs. "
         << gross << endl;

    cout << "Sales Tax: Rs. "
         << tax << endl;

    cout << "Membership Discount: Rs. "
         << memberDiscount << endl;

    cout << "Bill Discount: Rs. "
         << billDiscount << endl;

    cout << "Card Charges: Rs. "
         << cardCharges << endl;

    cout << "Generated Loyalty Points: "
         << generatedPoints << endl;

    cout << "\nEnter Your Existing Loyalty Points ";
    cout << "(Enter 0 if you're a new user): ";

    cin >> existingPoints;

    int updatedPoints =
        existingPoints + generatedPoints;

    cout << "Loyalty Points after Purchase: "
         << updatedPoints << endl;

    int redeemChoice;

    cout << "\nPress 1 to redeem your loyalty points";
    cout << ", Press 2 to continue: ";

    cin >> redeemChoice;

    if(redeemChoice == 1)
    {
        totalAmount -= updatedPoints;

        cout << "\nLoyalty Points Redeemed Successfully!\n";
    }

    if(totalAmount < 0)
    {
        totalAmount = 0;
    }

    cout << "\n---------------------------------------\n";

    cout << "Total Payable Amount: Rs. "
         << totalAmount << endl;

    cout << "Thank You For Shopping :)\n";

    cout << "=======================================\n";
}

void displayCustomerDetails()
{
    cout << "\n========== CUSTOMER DETAILS ==========\n";

    cout << "Customer Name: "
         << customerName << endl;

    cout << "Customer ID: "
         << customerID << endl;

    cout << "Customer Type: "
         << customerType << endl;

    cout << "Payment Method: "
         << paymentMethod << endl;

    cout << "======================================\n";
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout << "\n========== GROCERY MART SYSTEM ==========\n";

        cout << "1. View Grocery Items\n";
        cout << "2. Add Items to Cart\n";
        cout << "3. Calculate Bill\n";
        cout << "4. View Customer Details\n";
        cout << "5. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                displayGroceryList();
                break;
            }

            case 2:
            {
                addItemsToCart();
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
