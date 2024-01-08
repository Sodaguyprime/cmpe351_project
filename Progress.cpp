#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//declaring functions

int countlines(const string& filename);
void setdata(const string& filename,int lines,int BT[],int At[],int Priority[]);
void FCFS(int BT[], int At[], int Priority[], int lines);
void SJF(int BT[], int At[], int Priority[],int lines);
void Priority_scheduling(int BT[], int At[], int Priority[],int lines);
void Round_Robin_scheduling(int BT[],int At[], int Priority[],int lines);

//main function:
int main() {
    //declaring variables
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
    //main menu function
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
            if (myString ==  " First-come-first-served " ){
                FCFS(BT, At, Priority, lines);
            }else if(myString == " Shortest-Job-first "){
                SJF(BT, At, Priority, lines);
            }else if(myString == " Priority-Scheduling "){
            Priority_scheduling(BT, At, Priority, lines);}
            else if(myString == " Shortest-Job-first " && mystring2 ==" ON "){
                cout<<"preemptive mode for SJF is not ready yet ";
            }else if(myString == " Priority-Scheduling " && mystring2 ==" ON "){
                cout<<"preemptive mode for priority is not ready yet ";
            }else if(myString == " Round-Robin " && mystring2 ==" ON "){
                cout<<"preemptive mode for Round-Robin is not ready yet ";
            }else if(myString == " Round-Robin " && mystring2 ==" OFF "){
                cout<<"Round-robin is not ready yet ";
            }
            else{cout<<"not ready or incorrect output";}
                cout<<"\n";
                break;
            default:
                cout << "Invalid choice\n";
                continue;
        }

    }

    return 0;
}
//code for FCFS scheduling

void FCFS(int BT[], int At[], int Priority[],int lines) {
    //calling function to give us the array
    setdata("text.txt",lines,BT,At,Priority);
    //declaring varibales needed
    int process_id[lines];
    float averagewait = 0;
    int waiting_time[lines];
    int waitingint = 0;

    for (int counting = 0; counting<lines; counting++){
        process_id[counting] = (counting + 1);
    }

     for (int i = 0; i < lines - 1; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            // Compare based on Arrival Time (At)
            if (At[j] > At[j + 1])
             {
                swap(At[j], At[j + 1]);
                swap(BT[j], BT[j + 1]);
                swap(Priority[j], Priority[j + 1]);
                swap(process_id[j], process_id[j + 1]);
            }
        }
    } 
    cout<<" The amount of Proccess we have are: "<<lines<<endl;
       for (int t=0; t<lines; t++){
        waiting_time[t] = max(0,waitingint - At[t]) ;
        waitingint = waitingint + BT[t];
        averagewait = averagewait + waiting_time[t];
    }

for (int i = 0; i < lines - 1; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            // Compare based on Burst Time (Bt)
            if (process_id[j] > process_id[j + 1]) 
            {
                swap(process_id[j], process_id[j + 1]);
                swap(waiting_time[j], waiting_time[j + 1]);
            }
        }
    }
    for (int out= 0; out<lines;out++){
        cout<<" process p"<<process_id[out]<<" waiting time is:"<<waiting_time[out]<<endl;
    }

    cout<<"                         Scheduling method: First come First served"<<endl<<"                         Average process waiting times are: "<< averagewait/lines <<endl;
}

//code for SJF scheduling

void SJF(int BT[], int At[], int Priority[],int lines) {
    //calling function to give us the array

    setdata("text.txt",lines,BT,At,Priority);

    //declaring variables needed

    int process_id[lines];
    float averagewait = 0;
    int waiting_time[lines];
    int waitingint = 0;

    for (int counting = 0; counting<lines; counting++){
        process_id[counting] = (counting + 1);
    }

   for (int i = 0; i < lines - 1; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            // Compare based on Burst Time (Bt)
            if (BT[j] > BT[j + 1]) 
            {
                swap(At[j], At[j + 1]);
                swap(BT[j], BT[j + 1]);
                swap(Priority[j], Priority[j + 1]);
                swap(process_id[j], process_id[j + 1]);
            }
        }
    }
    cout<<" the amount of Proccess we have are: "<<lines<<endl;
       for (int t=0; t<lines; t++){
        waiting_time[t] = waitingint;
        waitingint = waitingint + BT[t];
        averagewait = averagewait + waiting_time[t];
    }

    for (int i = 0; i < lines - 1; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            // Compare based on Burst Time (Bt)
            if (process_id[j] > process_id[j + 1]) 
            {
                swap(process_id[j], process_id[j + 1]);
                swap(waiting_time[j], waiting_time[j + 1]);
            }
        }
    }
    for (int out= 0; out<lines;out++){
        cout<<" process p"<<process_id[out]<<" waiting time is:"<<waiting_time[out]<<endl;
    }

    


    cout<<"                         Scheduling method: SHORTEST JOB FIRST"<<endl<<"                         Average process waiting times are: "<< averagewait/lines <<endl;
}
//code for Priority scheduling

void Priority_scheduling(int BT[], int At[], int Priority[],int lines) {
    //calling function to give us the array
    setdata("text.txt",lines,BT,At,Priority);
    //declaring variables needed

    int process_id[lines];
    float averagewait = 0;
    int waiting_time[lines];
    int waitingint = 0;

    for (int counting = 0; counting<lines; counting++){
        process_id[counting] = (counting + 1);
    }

   for (int i = 0; i < lines - 1; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            // Compare based on priority (priority)
            if (Priority[j] > Priority[j + 1]) 
            {
                swap(At[j], At[j + 1]);
                swap(BT[j], BT[j + 1]);
                swap(Priority[j], Priority[j + 1]);
                swap(process_id[j], process_id[j + 1]);
            }
        }
    }

    cout<<" the amount of Proccess we have are: "<<lines<<endl;
       for (int t=0; t<lines; t++){
        waiting_time[t] = waitingint;
        waitingint = waitingint + BT[t];
        averagewait = averagewait + waiting_time[t];
    }


for (int i = 0; i < lines - 1; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            // Compare based on Burst Time (Bt)
            if (process_id[j] > process_id[j + 1]) 
            {
                swap(process_id[j], process_id[j + 1]);
                swap(waiting_time[j], waiting_time[j + 1]);
            }
        }
    }
    for (int out= 0; out<lines;out++){
        cout<<" process p"<<process_id[out]<<" waiting time is:"<<waiting_time[out]<<endl;
    }


    cout<<"                         Scheduling method: Priority Scheduling"<<endl<<"                         Average process waiting times are: "<< averagewait/lines <<endl;
}
//code for Round-Robin scheduling

void Round_Robin_scheduling(int BT[],int At[], int Priority[],int lines){


}

//code for setting data into arrays

void setdata(const string& filename,int lines,int BT[],int At[],int Priority[]){
    int dataArray[lines][3];
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
            dataArray[k][j] = temparray[index];
            index++;
        }
    }

     for (int k = 0; k < lines; k++) {
        BT[k] = dataArray[k][0];
        At[k] = dataArray[k][1];
        Priority[k] = dataArray[k][2];
    }
}
//code for counting how many processes we have in the file
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