#include <iostream>

using namespace std;

int sc_method; //scheduling method
int process; //process ID
char input; //input from file

//scheduling values
struct process
{
    int arrival_time; //arrival time
    int burst_time; //burst time
    int priority; //priority
};

//final calculations
struct computations
{
    int waiting_time; //waiting time
    int awt; //average waiting time
};

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

//To read values from the file
void file_input()
{
    FILE *input;
    input = fopen("input.txt", "r");

    cout << input;

    fclose(input);
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

void FC_FS()
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
    }
}

int main()
{
    options();
    scheduling_method();
    //file_input();

    return 0;
}