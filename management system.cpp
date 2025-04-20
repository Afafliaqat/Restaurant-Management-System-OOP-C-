#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem(string name, double price) : name(name), price(price) {}

    string getName() const { return name; }
    double getPrice() const { return price; }

    void display() const {
        cout << name << " - Rs. " << fixed << setprecision(2) << price << endl;
    }
};

class Restaurant {
private:
    vector<MenuItem> menu;
    vector<MenuItem> currentOrder;

public:
    void addMenuItem() {
        string name;
        double price;
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter item price: ";
        cin >> price;
        menu.push_back(MenuItem(name, price));
        cout << "✅ Item added to menu.\n";
    }

    void showMenu() const {
        if (menu.empty()) {
            cout << "⚠️ Menu is empty.\n";
            return;
        }

        cout << "\n📋 --- MENU ---\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". ";
            menu[i].display();
        }
    }

    void takeOrder() {
        if (menu.empty()) {
            cout << "⚠️ Cannot take order. Menu is empty.\n";
            return;
        }

        int choice;
        while (true) {
            showMenu();
            cout << "\nEnter item number to add to order (0 to finish): ";
            cin >> choice;
            if (choice == 0) break;
            if (choice < 1 || choice > menu.size()) {
                cout << "❌ Invalid choice.\n";
            }
            else {
                currentOrder.push_back(menu[choice - 1]);
                cout << "✔️ Added to order: " << menu[choice - 1].getName() << "\n";
            }
        }
    }

    void generateBill() const {
        if (currentOrder.empty()) {
            cout << "⚠️ No items in order.\n";
            return;
        }

        double total = 0;
        cout << "\n🧾 --- BILL ---\n";
        for (const auto& item : currentOrder) {
            item.display();
            total += item.getPrice();
        }
        cout << "-------------------------\n";
        cout << "Total: Rs. " << fixed << setprecision(2) << total << "\n\n";
    }

    void clearOrder() {
        currentOrder.clear();
    }
};

void showMainMenu() {
    cout << "\n=========== Restaurant System ===========\n";
    cout << "1. Add Menu Item (Admin)\n";
    cout << "2. Show Menu\n";
    cout << "3. Take Order\n";
    cout << "4. Generate Bill\n";
    cout << "5. Exit\n";
    cout << "=========================================\n";
    cout << "Choose option: ";
}

int main() {
    Restaurant r;
    int choice;

    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            r.addMenuItem();
            break;
        case 2:
            r.showMenu();
            break;
        case 3:
            r.takeOrder();
            break;
        case 4:
            r.generateBill();
            r.clearOrder();  // Optional: clear order after bill
            break;
        case 5:
            cout << " Thank you for using Restaurant System!\n";
            break;
        default:
            cout << " Invalid option.\n";
        }

    } while (choice != 5);

    return 0;
}
