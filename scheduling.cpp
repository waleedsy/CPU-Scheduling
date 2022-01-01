#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int sc_method; //scheduling method
char input; //input from file
long waiting_time; //waiting time
double awt; //average waiting time

int brt, art, prt;

//process declaration
struct process
{
    int arr_time; //arrival time
    int brs_time; //burst time
    int priority; //priority

    struct process *next;
};

process *lst;
process *pid, *no;

//To read and display values from the file
void file_input()
{
  string line;

    ifstream input("input.txt");
    int init = 0;

    do {
            for (char i: line)
            {
                if (isnumber(i))
                {
                    for (int j = 0; j <= init; j++)
                    {

                    }
                    init++;
                    if (init == 0)
                    {
                        art += i;
                        cout << art;
                    }

                    else if (init == 1)
                    {
                        brt += i;
                        cout << brt;
                    }

                    else if (init == 2)
                    {
                        prt += i;
                        cout << prt;
                    }
                    cout << endl << i;
                }
            }
        }
    while(!input.eof() and getline (input, line));

    struct process *head = (process*) (malloc(sizeof(struct process)));
    head -> arr_time = art;
    head -> brs_time = brt;
    head -> priority = prt;
    head -> next = NULL;

    //struct process p1 = {art, brt, prt};
    input.close();
    //no = lst;
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

int main(int argc, char** argv)
{
    //options();
    //scheduling_method();
    file_input();

    return 0;
}