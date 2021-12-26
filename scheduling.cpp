#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int sc_method; //scheduling method
char input; //input from file
long waiting_time; //waiting time
double awt; //average waiting time

//process declaration
struct process
{
    int arr_time; //arrival time
    int brs_time; //burst time
    int priority; //priority

    struct process *next;
    struct process *temp;
}process;

//To read and display values from the file
void file_input()
{
   ifstream inp;
   inp.open("input.txt");

    do
    {
        char ln;
        inp >> ln;
        //cout << ln;

        if ((!isspace(ln)))
            {
                cout << ln << " \n";
            }
    }
    while(!inp.eof());
    inp.close();
}

//To end a program
void program_end()
{
    cout << "Have a nice day! \n";
    exit(1);
}

//Main Menu
void options()
{
    int menu;
    do{
        cout << "\n\n*** CPU Scheduling Simulator***\n1 -> Scheduling Method (None)\n2) -> Preemptive Mode(Off)\n3) -> Show result\n4) -> End program\n\nPlease select 1 option: \n";
        cin >> menu;

    }
    while ((menu < 1) or (menu > 5));

    switch(menu)
    {
        case 1:
            cout << "\nChoose a scheduling method\n1) -> None\n2) -> First Come, First serve\n3) -> Shortest-Job-First-Scheduling\n4) -> Priority Scheduling\n5) -> Round-Robin Scheduling\nOption > ";
            cin >> sc_method;
            break;
        case 4:
            return program_end();
    }
}

//none of the scheduling methods selected
void none_selected()
{
    int select;
    do
    {
        cout << "Press 1 to go back to the main menu or press 2 to end the program: ";
        cin >> select;

        switch (select)
        {
            case 1:
                options();
                break;

            case 2:
                program_end();
        }
    }
    while ((sc_method != 1) or (sc_method != 2));
}

//first come first serve
void FC_FS()
{


}

//shortest job first
void SJB()
{

}

//Priority Scheduling
void PRS()
{

}

//Round Robin Scheduling
void RRS()
{

}


//To select a scheduling method
void scheduling_method()
{
    switch (sc_method) {
        case 1:
            none_selected();
            break;

        case 2:
            FC_FS();
            break;

        case 3:
            SJB();
            break;

        case 4:
            PRS();
            break;

        case 5:
            RRS();
            break;

        default:
            options();
            break;
    }
}

int main()
{
    //options();
    //scheduling_method();
    file_input();

    return 0;
}