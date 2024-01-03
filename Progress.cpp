#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countlines(const string& filename);
void setdAta(const string& filename,int lines,int BT[],int At[],int Priority[]);
void FCFS(int BT[], int At[], int Priority[], int lines);
int main() {
    int choice;
    int schedule;
    int schedule2;
    int lines;
    lines = countlines("text.txt");
    int BT[lines],At[lines],Priority[lines];
    string myString;
    string mystring2;
    myString = "NONE";
    mystring2 = "OFF";
    while (true) {
        cout << "                     CPU SCHEDULER SIMULAtOR\n";
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
                        myString = " First-come-first-served ";
                        break;
                    case 2:
                        myString = " Shortest-Job-first ";
                        break;
                    case 3:
                        myString =" Priority-Scheduling ";
                        break;
                    case 4:
                        myString=" Round-Robin ";
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
                        mystring2 = " ON ";
                        break;
                    case 2:
                        mystring2 = " OFF ";
                        break;
                }
                break;
            case 3:
                cout << "                   Show Result\n";
            FCFS(BT, At, Priority, lines);
                cout<<"\n";
                break;
            default:
                cout << "Invalid choice\n";
                continue;
        }

    }

    return 0;
}

void FCFS(int BT[], int At[], int Priority[],int lines) {
    setdAta("text.txt",lines,BT,At,Priority);
    cout<<" the amount of Proccess we have are: "<<lines<<endl;
    cout<<"Scheduling method: First come First served"<<endl<<"process waiting times are: "<<endl;
    
    }

void setdAta(const string& filename,int lines,int BT[],int At[],int Priority[]){
    int dAtarray[lines][3];
    int i = 0;
    int temparray[lines * 3];
    ifstream file(filename);
    char char1;
    int intitself;
    while (file.get(char1)) {
        if (char1 != ':' && char1 != '\n') {
            intitself = char1 - '0';
            temparray[i] = intitself;
            i++;
            }
    }
    file.close();
    int index = 0;
    for (int k=0;k<lines;k++){
        for(int j=0; j<3;j++){
            dAtarray[k][j] = temparray[index];
            index++;
        }
    }

     for (int k = 0; k < lines; k++) {
        BT[k] = dAtarray[k][0];
        At[k] = dAtarray[k][1];
        Priority[k] = dAtarray[k][2];
    }

    /* for (int k = 0; k < lines; k++) {
        cout << "Array 1: " << BT[k] << " | ";
        cout << "Array 2: " << At[k] << " | ";
        cout << "Array 3: " << Priority[k] <<endl;
    }
    */
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
    return count+1;
}
