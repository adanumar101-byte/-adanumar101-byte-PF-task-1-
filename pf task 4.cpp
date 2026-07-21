#include <iostream>
#include <iomanip>
using namespace std;

string userName;
string email;
string city;
string customerType;
string paymentMethod;

string products[8] =
{
    "T-Shirt",
    "Jeans",
    "Shoes",
    "Watch",
    "Handbag",
    "Headphones",
    "Mobile Cover",
    "Perfume"
};

double prices[8] =
{
    1200,
    3500,
    5000,
    2500,
    4200,
    3000,
    700,
    2800
};

double productTotal = 0;

void registerUser();
void displayProducts();
void addProductsToCart();

double calculateProductTotal();
double calculateGST(double amount);
double calculateDeliveryCharges(string cityName);
double calculateCustomerDiscount(double amount);
double calculateOrderDiscount(double amount);
double calculatePaymentCharges(double amount);

void displayCheckoutBill();
void displayUserDetails();

void registerUser()
{
    cout << "========== USER REGISTRATION ==========\n";

    cin.ignore();

    cout << "Enter User Name: ";
    getline(cin, userName);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "\nSelect Customer Type:\n";
    cout << "1. New Customer\n";
    cout << "2. Returning Customer\n";
    cout << "Enter Choice: ";

    int choice;
    cin >> choice;

    if(choice == 1)
    {
        customerType = "New Customer";
    }
    else
    {
        customerType = "Returning Customer";
    }

    cout << "\nSelect Payment Method:\n";
    cout << "1. Cash on Delivery\n";
    cout << "2. Debit/Credit Card\n";
    cout << "Enter Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        paymentMethod = "Cash on Delivery";
    }
    else
    {
        paymentMethod = "Debit/Credit Card";
    }

    cout << "\nUser Registered Successfully!\n";
}

void displayProducts()
{
    cout << "\n========== PRODUCT LIST ==========\n";

    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". "
             << products[i]
             << " - Rs. "
             << prices[i]
             << endl;
    }

    cout << "==================================\n";
}

void addProductsToCart()
{
    int productNo, quantity;
    char choice;

    do
    {
        displayProducts();

        cout << "\nEnter Product Number: ";
        cin >> productNo;

        while(productNo < 1 || productNo > 8)
        {
            cout << "Invalid Product Number! Enter Again: ";
            cin >> productNo;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;

        while(quantity <= 0)
        {
            cout << "Invalid Quantity! Enter Again: ";
            cin >> quantity;
        }

        double itemTotal =
            prices[productNo - 1] * quantity;

        productTotal += itemTotal;

        cout << "\nProduct Added Successfully!\n";
        cout << "Current Product Total: Rs. "
             << productTotal << endl;

        cout << "\nDo You Want to Add More Products? (Y/N): ";
        cin >> choice;

    } while(choice == 'Y' || choice == 'y');
}

double calculateProductTotal()
{
    return productTotal;
}

double calculateGST(double amount)
{
    return amount * 0.17;
}

double calculateDeliveryCharges(string cityName)
{
    if(cityName == "Lahore" ||
       cityName == "Karachi" ||
       cityName == "Islamabad")
    {
        return 250;
    }
    else
    {
        return 500;
    }
}

double calculateCustomerDiscount(double amount)
{
    if(customerType == "New Customer")
    {
        return amount * 0.05;
    }
    else
    {
        return amount * 0.10;
    }
}

double calculateOrderDiscount(double amount)
{
    if(amount >= 5000 && amount <= 10000)
    {
        return amount * 0.05;
    }
    else if(amount > 10000)
    {
        return amount * 0.12;
    }
    else
    {
        return 0;
    }
}

double calculatePaymentCharges(double amount)
{
    if(paymentMethod == "Debit/Credit Card")
    {
        return amount * 0.025;
    }
    else
    {
        return 0;
    }
}

void displayCheckoutBill()
{
    double total;
    double gst;
    double deliveryCharges;
    double customerDiscount;
    double orderDiscount;
    double paymentCharges;
    double finalAmount;

    total = calculateProductTotal();

    gst = calculateGST(total);

    deliveryCharges =
        calculateDeliveryCharges(city);

    customerDiscount =
        calculateCustomerDiscount(total);

    orderDiscount =
        calculateOrderDiscount(total);

    paymentCharges =
        calculatePaymentCharges(total);

    finalAmount =
        total +
        gst +
        deliveryCharges +
        paymentCharges -
        customerDiscount -
        orderDiscount;

    cout << fixed << setprecision(2);

    cout << "\n\n========== ONLINE SHOPPING BILL ==========\n";

    cout << "User Name: "
         << userName << endl;

    cout << "City: "
         << city << endl;

    cout << "Customer Type: "
         << customerType << endl;

    cout << "\nProduct Total: Rs. "
         << total << endl;

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Delivery Charges: Rs. "
         << deliveryCharges << endl;

    cout << "Customer Discount: Rs. "
         << customerDiscount << endl;

    cout << "Order Discount: Rs. "
         << orderDiscount << endl;

    cout << "Payment Charges: Rs. "
         << paymentCharges << endl;

    cout << "\n------------------------------------------\n";

    cout << "Final Payable Amount: Rs. "
         << finalAmount << endl;

    cout << "Thank You for Shopping :)\n";

    cout << "==========================================\n";
}

void displayUserDetails()
{
    cout << "\n========== USER DETAILS ==========\n";

    cout << "User Name: "
         << userName << endl;

    cout << "Email: "
         << email << endl;

    cout << "City: "
         << city << endl;

    cout << "Customer Type: "
         << customerType << endl;

    cout << "Payment Method: "
         << paymentMethod << endl;

    cout << "==================================\n";
}

int main()
{
    registerUser();

    int choice;

    do
    {
        cout << "\n========== ONLINE SHOPPING SYSTEM ==========\n";

        cout << "1. View Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. Calculate Checkout Bill\n";
        cout << "4. View User Details\n";
        cout << "5. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                displayProducts();
                break;
            }

            case 2:
            {
                addProductsToCart();
                break;
            }

            case 3:
            {
                displayCheckoutBill();
                break;
            }

            case 4:
            {
                displayUserDetails();
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
