#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int sc_method; //scheduling method
char input; //input from file
int brt, art, prt, tat, noline;
string line;

//process declaration
struct process
{
    int arr_time; //arrival time
    int brs_time; //burst time
    int priority; //priority
    float tat; //turn around time
    float waiting_time; //waiting time
    float awt; //average waiting time
    int pn;

    struct process *next;
};

struct process *headG = NULL;

process *p_init(int art, int brst, int prt) {
    int count;

    process *p = (process*) malloc(sizeof (process));

    p -> arr_time = art;
    p -> brs_time = brst;
    p -> priority = prt;
    p -> pn = count++;
    p = p -> next;
    return p;
}

//process insertion
void pinsert(process *pid, int art, int brt, int prt)
{
   process *pn, *temp;
   pn = p_init(art, brt, prt);

   do{
       temp = pid;
       pid = pid -> next;

       if (pid -> arr_time > art)
       {
           pn -> next = temp;
           temp -> next = pn;

           return;
       }
       pid -> next = pn;

   }
   while(pid -> next != NULL);

}

//To read and display values from the file
void file_input()
{
    ifstream input("input.txt");
    int init = 0;
    do {
        getline(input, line);
        noline ++;
        for (int i = 0; i <= line[i]; i++)
        {
            if (line[i] == ':')
                {
                    init++;
                    if (init == 0)
                    {
                        art += line[i];
                    }

                    if (init == 1)
                    {
                        brt += line[i];
                    }

                    if (init == 2)
                    {
                        prt += line[i];
                    }
                    i++;
                    pinsert(headG, art, brt, prt);
            }
           cout << noline;
        }
    }
    while(!input.eof());
    input.close();
}

//to display process
void pdip(process *p)
{
    process *temp = p -> next;
    float twt, tbt;
    twt = tbt = 0;

    while (temp != NULL)
    {
        cout << "P\n" << p -> pn;

        tbt += p -> brs_time;
        twt += p -> waiting_time;
        cout << "P" << ": " << temp -> pn << ": " << temp -> waiting_time;
        temp = temp -> next;
    }

    cout << "Average waiting time: " << twt / noline;

}

//waiting time calculation
void wt(process *pn)
{
    process *temp = pn -> next;
    while (temp != NULL)
    {
        temp -> tat = temp -> priority - temp -> arr_time;
        temp -> waiting_time += temp -> tat - temp -> brs_time;
        temp -> tat += temp -> waiting_time;
        temp = temp -> next;

    }
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
    file_input();
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
    process *head = NULL;
    int pn, cnt;

    for (cnt = 1; cnt <= noline; cnt++)
    {
        switch (cnt)
        {
            case 1:
                pinsert(head, art, brt, prt);
        }
        wt(head);
    }
    p_init(art, brt, prt);
    pdip(head);
    cout << art;

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
    options();
    scheduling_method();

    return 0;
}