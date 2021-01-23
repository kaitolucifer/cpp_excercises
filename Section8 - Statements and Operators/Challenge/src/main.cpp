#include <iostream>

using namespace std;

int main() {
    const int dollar_value {100};
    const int quarter_value {25};
    const int dime_value {10};
    const int nickel_value {5};
    int change_amount {};
    cout << "Enter an amount in cents: ";
    cin >> change_amount;
    int balance {}, dollars {}, quarters {}, dimes {}, nickels {}, pennies {};
    dollars = change_amount / dollar_value;
    balance = change_amount % dollar_value;
    quarters = balance / quarter_value;
    balance %= quarter_value;
    dimes = balance / dime_value;
    balance %= dime_value;
    nickels = balance / nickel_value;
    balance %= nickel_value;
    pennies = balance;
    cout << "\nYou can provide this change as follows:" << endl;
    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;

    return 0;
}