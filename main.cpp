
#include "PaySlip.h"

int main() {
    int n;
    cout << "Enter number of payslips to generate: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        try {
            PaySlip p;
            p.generate();
            p.display();
            p.saveToFile();
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    char choice;
    cout << "\nDo you want to view all saved payslip data? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        try {
            PaySlip p;
            p.readFromFile();
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
