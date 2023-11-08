#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <cmath>
#include <random>

// Share this code by making it an executable file!

// Have more dialogue. Instead of the asking price constantly just going down, maybe keep it as is and say its their best price.

// If the price is ridiculously low, end the game.

// Round up the numbers.

// Clean up code (prevent repetition too)

// Add a single-player and multi-player option (where you're competing to bid)

// Add comments

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

int RandomPrice(int asking_price, int bidding_price) {
    int max = asking_price;
    int min = bidding_price;
    
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    
    // Should this be int or double?
    int random_price = dist(mt);
    
    return random_price;
}

int FlipCoin() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 2);
    return dist(mt);
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

    std::cout << "BUDGET: $" << std::fixed << std::setprecision(2) << budget << "\n\n";

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
    
    if (budget < items[chosen_item]) {
        std::cout << "Not enough money!";
        return 1;
    }

    KeyToContinue();
    
    std::cout << "BUDGET: $" << std::fixed << std::setprecision(2) << budget << '\n';
    std::cout << "ORIGINAL PRICE: $" << items[chosen_item] << '\n';

    double bidding_price;
    double asking_price = items[chosen_item];

    bool item_sold = false;

    std::cout << "Enter your bidding price: ";
    std::cin >> bidding_price;
    
    if (budget - bidding_price <= 0) {
        std::cout << "Not enough money!";
        return 1;
    }
    
    if (bidding_price > asking_price) {
        std::cout << "SOLD!";
        item_sold = true;
    }
    
    int r = asking_price;;
    
    while (!item_sold) {
        double percentage;
        
        if (asking_price <= 1000) percentage = 5.0;
        else percentage = 15.0;
        if (IsClose(bidding_price, r, percentage)) {
            int flip = FlipCoin();
            if (flip == 1) {
                std::cout << "Looks like we won't be able to make a deal. Have a good day.\n";
                break;
            } else {
                std::cout << "SOLD!";
                item_sold == true;
                break;
            }
        } else {
            int random_price = RandomPrice(r, bidding_price);
            while (random_price == bidding_price && random_price == asking_price && random_price > bidding_price) {
                random_price = RandomPrice(asking_price, bidding_price);
            }
            
            r = random_price;
            
            if (random_price == bidding_price) {
                std::cout << "SOLD!";
                item_sold == true;
                break;
            }
            
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
                
                if (bidding_price == budget) { // This isnt working...
                    std::cout << "SOLD!";
                    item_sold = true;
                    break;
                } else if (budget - bidding_price < 0) {
                    std::cout << "Not enough money!";
                    return 1;
                }
                
                if (bidding_price > asking_price) {
                    std::cout << "SOLD!";
                    item_sold = true;
                    break;
                }
            }
        }
    }

    return 0;
}
