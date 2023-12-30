#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countlines(const string& filename);

int main() {
    int choice;
    int schedule;
    int schedule2;
    int lines;
    string myString;
    string mystring2;
    myString = "NONE";
    mystring2 = "OFF";
    cout << "Your input is: " << myString << endl;
    while (true) {
        cout << "                     CPU SCHEDULER SIMULATOR\n";
        cout << "  1) Scheduling Method("<<myString<<")\n";
        cout << "  2) Preemptive Mode ("<<mystring2<<")\n";
        cout << "  3) Show Result\n";
        cout << "  4) End Program\n";
        cout<<"please enter your needed thing: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting.......\n";
            break;  // Exit the loop if the user chooses 4
        }

        switch (choice) {
            case 1:
                cout << "Choose a Scheduling Method\n";
                cout << "            1)First Come, First Served Scheduling\n";
                cout << "            2)Shortest-JobFirst Scheduling\n";
                cout << "            3)Priority Scheduling\n";
                cout << "            4)Round-Robin Scheduling\n";
                cout<<"Please choose your prefered scheduling method: ";
                cin >>schedule;
                switch(schedule){
                    case 1:
                        myString = "First come first served";
                        break;
                    case 2:
                        myString = "Shortest Job first";
                        break;
                    case 3:
                        myString =" priority scheduling";
                        break;
                    case 4:
                        myString="Round-Robin ";
                        break;
                }
                break;
            case 2:
                cout << "Choose wether the Preemptive Mode is on or off\n";
                cout << "           1) ON\n";
                cout << "           2) OFF\n";
                cout<<"please choose your premptive mode: ";
                cin >>schedule2;
                switch(schedule2){
                    case 1:
                        mystring2 = "ON";
                        break;
                    case 2:
                        mystring2 = "OFF";
                        break;
                }
                break;
            case 3:
                cout << "Show Result\n";
                break;
            default:
                cout << "Invalid choice\n";
                continue; // Skip the rest of the loop and start a new iteration
        }

        lines = countlines("text.txt");

        // Uncomment the next line if you want to use the takedata function
    }

    return 0;
}

int countlines(const string& filename) {
    int count = 0;
    char D;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file.\n";
        return -1; // Return an error code
    }

    do {
        D = file.get();
        if (D == '\n') {
            count++;
        }
    } while (file.good());

    file.close();
    return count;
}
