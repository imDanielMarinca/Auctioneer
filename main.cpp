#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <random>

void KeyToContinue() {
    char key;

    std::cout << "------------------------------\n";
    std::cout << "|Press any key to continue...|\n";
    std::cout << "------------------------------\n";

    std::cin >> key;

    system("clear");
}

bool IsClose(double number1, double number2, double percentage) {
    double difference = std::abs((number1 - number2) / number2) * 100.0;
    return difference <= percentage;
}

int main() {
    std::cout << "------------\n";
    std::cout << "|AUCTIONEER|\n";
    std::cout << "------------\n";

    std::cout << "Welcome to AUCTIONEER, a thrilling auction simulator!\n";

    KeyToContinue();

    std::string user_name;
    double budget;

    std::cout << "Enter your name: ";
    std::cin >> user_name;

    std::cout << "Enter your budget ($): ";
    std::cin >> budget;

    KeyToContinue();

    std::cout << "BUDGET: $" << budget << "\n\n";

    std::cout << "List of items at auction: \n";
    std::cout << "--------------------------------------------\n";
    std::cout << "1. Scissors -------------------------- $3.00\n";
    std::cout << "2. Rubber Chicken -------------------- $6.00\n";
    std::cout << "3. T-Shirt --------------------------- $15.00\n";
    std::cout << "4. Toaster --------------------------- $50.00\n";
    std::cout << "5. Coffee Machine -------------------- $250.00\n";
    std::cout << "6. Fake Banksy Painting -------------- $1000.00\n";
    std::cout << "7. Historic Pirate Hook -------------- $5000.00\n";
    std::cout << "8. DeLorean from Back to the Future -- $500,000.00\n";
    std::cout << "9. Private Island -------------------- $100,000,000.00\n";
    std::cout << "10. Buckingham Palace ---------------- $2,000,000,000.00\n\n\n";

    std::map<int, double> items;
    items[1] = 3.00;
    items[2] = 6.00;
    items[3] = 15.00;
    items[4] = 50.00;
    items[5] = 250.00;
    items[6] = 1000.00;
    items[7] = 5000.00;
    items[8] = 500000.00;
    items[9] = 100000000.00;
    items[10] = 2000000000.00;

    int chosen_item;

    std::cout << "Choose which one you would like to bid on (enter number): ";
    std::cin >> chosen_item;

    KeyToContinue();
    
    std::cout << "BUDGET: $" << budget << '\n';
    std::cout << "ORIGINAL PRICE: $" << items[chosen_item] << '\n';

    double bidding_price;
    double asking_price = items[chosen_item];

    bool item_sold = false;

    std::cout << "Enter your bidding price: ";
    std::cin >> bidding_price;

    while (!item_sold) {

        if (IsClose(bidding_price, asking_price, 5.0)) {
            std::cout << "SOLD!";
            item_sold = true;
            break;
        } else {
            int max = asking_price;
            int min = bidding_price;
        
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(min, max);
    
            int random_price = dist(mt);
            
            char choice;

            std::cout << "Hmm, too low. What about $" << random_price << "? (y/n)";
            std::cin >> choice;
            
            if (choice == 'y') {
                std::cout << "SOLD!";
                item_sold = true;
                break;
            } else {
                std::cout << "Enter your bidding price: ";
                std::cin >> bidding_price;
            }
        }
    }

    return 0;
}
