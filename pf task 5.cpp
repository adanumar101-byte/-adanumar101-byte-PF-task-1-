#include <iostream>
#include <iomanip>
using namespace std;

string clientName;
string businessName;
string businessType;
int campaignDuration;

string platforms[3] =
{
    "Instagram",
    "Facebook",
    "LinkedIn"
};

double platformCharges[3] =
{
    15000,
    12000,
    20000
};

string selectedPlatform = "";
double selectedPlatformCharge = 0;

int staticPosts = 0;
int reelPosts = 0;
int carouselPosts = 0;

double adBudget = 0;

void registerClient();
void displayPlatforms();
void selectPlatform();

double calculatePostDesignCost();
double calculateAdHandlingFee(double budget);
double calculateExtraDurationCharges(int days);
double calculateGST(double amount);
double calculateDiscount(double amount);

void displayFinalCampaignBill();
void displayClientDetails();

void registerClient()
{
    cout << "========== CLIENT REGISTRATION ==========\n";

    cin.ignore();

    cout << "Enter Client Name: ";
    getline(cin, clientName);

    cout << "Enter Business Name: ";
    getline(cin, businessName);

    cout << "\nSelect Business Type:\n";
    cout << "1. Small Business\n";
    cout << "2. Medium Business\n";
    cout << "3. Corporate Business\n";
    cout << "Enter Choice: ";

    int choice;
    cin >> choice;

    if(choice == 1)
    {
        businessType = "Small Business";
    }
    else if(choice == 2)
    {
        businessType = "Medium Business";
    }
    else
    {
        businessType = "Corporate Business";
    }

    cout << "Enter Campaign Duration (Days): ";
    cin >> campaignDuration;

    while(campaignDuration <= 0)
    {
        cout << "Invalid Input! Enter Again: ";
        cin >> campaignDuration;
    }

    cout << "\nClient Registered Successfully!\n";
}

void displayPlatforms()
{
    cout << "\n========== SOCIAL MEDIA PLATFORMS ==========\n";

    for(int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". "
             << platforms[i]
             << " - Rs. "
             << platformCharges[i]
             << endl;
    }

    cout << "============================================\n";
}

void selectPlatform()
{
    displayPlatforms();

    int choice;

    cout << "\nSelect Platform Number: ";
    cin >> choice;

    while(choice < 1 || choice > 3)
    {
        cout << "Invalid Choice! Enter Again: ";
        cin >> choice;
    }

    selectedPlatform = platforms[choice - 1];
    selectedPlatformCharge = platformCharges[choice - 1];

    cout << "\nPlatform Selected Successfully!\n";
}

double calculatePostDesignCost()
{
    cout << "\n========== POST DETAILS ==========\n";

    cout << "Enter Number of Static Posts: ";
    cin >> staticPosts;

    cout << "Enter Number of Reel/Video Posts: ";
    cin >> reelPosts;

    cout << "Enter Number of Carousel Posts: ";
    cin >> carouselPosts;

    double staticCost =
        staticPosts * 1000;

    double reelCost =
        reelPosts * 2500;

    double carouselCost =
        carouselPosts * 1800;

    double totalPostCost =
        staticCost +
        reelCost +
        carouselCost;

    return totalPostCost;
}

double calculateAdHandlingFee(double budget)
{
    if(budget < 50000)
    {
        return budget * 0.05;
    }
    else if(budget >= 50000 && budget <= 100000)
    {
        return budget * 0.08;
    }
    else
    {
        return budget * 0.10;
    }
}

double calculateExtraDurationCharges(int days)
{
    if(days > 30)
    {
        int extraDays = days - 30;
        return extraDays * 500;
    }
    else
    {
        return 0;
    }
}

double calculateGST(double amount)
{
    return amount * 0.16;
}

double calculateDiscount(double amount)
{
    if(businessType == "Small Business")
    {
        return amount * 0.05;
    }
    else if(businessType == "Medium Business")
    {
        return amount * 0.08;
    }
    else
    {
        return amount * 0.10;
    }
}

void displayFinalCampaignBill()
{
    if(selectedPlatform == "")
    {
        cout << "\nPlease Select a Platform First!\n";
        return;
    }

    double postDesignCost;
    double handlingFee;
    double extraCharges;
    double gst;
    double discount;
    double totalCost;
    double finalCost;

    postDesignCost =
        calculatePostDesignCost();

    cout << "\nEnter Advertisement Budget: Rs. ";
    cin >> adBudget;

    while(adBudget < 0)
    {
        cout << "Invalid Input! Enter Again: ";
        cin >> adBudget;
    }

    handlingFee =
        calculateAdHandlingFee(adBudget);

    extraCharges =
        calculateExtraDurationCharges(campaignDuration);

    totalCost =
        selectedPlatformCharge +
        postDesignCost +
        adBudget +
        handlingFee +
        extraCharges;

    gst =
        calculateGST(totalCost);

    discount =
        calculateDiscount(totalCost);

    finalCost =
        totalCost +
        gst -
        discount;

    cout << fixed << setprecision(2);

    cout << "\n\n========== SOCIAL MEDIA CAMPAIGN BILL ==========\n";

    cout << "Client Name: "
         << clientName << endl;

    cout << "Business Name: "
         << businessName << endl;

    cout << "Business Type: "
         << businessType << endl;

    cout << "Selected Platform: "
         << selectedPlatform << endl;

    cout << "Campaign Duration: "
         << campaignDuration
         << " Days" << endl;

    cout << "\nPlatform Management Charges: Rs. "
         << selectedPlatformCharge << endl;

    cout << "Post Design Cost: Rs. "
         << postDesignCost << endl;

    cout << "Ad Budget: Rs. "
         << adBudget << endl;

    cout << "Ad Handling Fee: Rs. "
         << handlingFee << endl;

    cout << "Extra Duration Charges: Rs. "
         << extraCharges << endl;

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Discount: Rs. "
         << discount << endl;

    cout << "\n------------------------------------------------\n";

    cout << "Final Campaign Cost: Rs. "
         << finalCost << endl;

    cout << "================================================\n";
}

void displayClientDetails()
{
    cout << "\n========== CLIENT DETAILS ==========\n";

    cout << "Client Name: "
         << clientName << endl;

    cout << "Business Name: "
         << businessName << endl;

    cout << "Business Type: "
         << businessType << endl;

    cout << "Campaign Duration: "
         << campaignDuration
         << " Days" << endl;

    if(selectedPlatform != "")
    {
        cout << "Selected Platform: "
             << selectedPlatform << endl;
    }
    else
    {
        cout << "Selected Platform: Not Selected Yet\n";
    }

    cout << "====================================\n";
}

int main()
{
    registerClient();

    int choice;

    do
    {
        cout << "\n========== SOCIAL MEDIA MANAGEMENT SYSTEM ==========\n";

        cout << "1. View Platforms\n";
        cout << "2. Select Campaign Platform\n";
        cout << "3. Calculate Campaign Cost\n";
        cout << "4. View Client Details\n";
        cout << "5. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                displayPlatforms();
                break;
            }

            case 2:
            {
                selectPlatform();
                break;
            }

            case 3:
            {
                displayFinalCampaignBill();
                break;
            }

            case 4:
            {
                displayClientDetails();
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
