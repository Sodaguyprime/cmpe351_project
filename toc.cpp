#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int countLines(const char *filename);

int main() {
    int choice;

    do {
        cout << "                         " << "CPU SCHEDULER SIMULATOR" << endl;
        cout << "1) Scheduling Method (None)" << endl;
        cout << "2) Preemptive Mode (off)" << endl;
        cout << "3) Show Result" << endl;
        cout << "4) End Program" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Scheduling Method" << endl;
                break;
            case 2:
                cout << "Preemptive Mode" << endl;
                break;
            case 3:
                cout << "Show Result" << endl;
                break;
            case 4:
                cout << "Exiting......." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    int lines = countLines("text.txt") - 1;
    int array[lines][3];
    return 0;
}

void arraytesting(const char *filename){ // remember to add an error statement at the end
    ifstream input(filename);
    int number_only;
    int lines = countLines("text.txt");
    int array1[lines][1];

    /*if (!input.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }*/


    while(input.get(number_only)){
        
        if (){

        }else{
        for(int i=0;i<lines;i++){
            for(int j=0;j<3;j++){
                input>> = array1[i][j];
            }
        }
        }
    }
     for(int i=0;i<lines;i++){
            for(int j=0;j<3;j++){
                cout<<array[i][j];
            }
        }cout<<endl;

    input.close();

}

int countLines(const char *filename) {
    int count = 1;
    char D;
    ifstream file(filename);

    if (file.is_open()) {
        while (file.get(D)) {
            if (D == '\n') {
                count++;
            }
        }
        file.close();
    } else {
        cout << "Error opening file." << endl;
    }

    return count;
}

