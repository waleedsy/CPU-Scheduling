#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int sc_method; //scheduling method
char input; //input from file
int brt, art, prt, ct, tat, noline, response;
string line;

//process declaration
struct process
{
    int arr_time; //arrival time
    int brs_time; //burst time
    int priority; //priority
    int response; //response time
    int ct; //completion time
    long tat; //turn around time
    long waiting_time; //waiting time
    double awt; //average waiting time
    int pn;

    struct process *next;

};


//To read and display values from the file
void file_input()
{
    ifstream input("input.txt");
    int init = 0;

    do {
        getline(input, line);
        noline ++;
            for (char i: line)
            {
                if (isnumber(i))
                {
                    init++;
                    if (init == 0)
                    {
                        art += i;
                    }

                    else if (init == 1)
                    {
                        brt += i;
                    }

                    else if (init == 2)
                    {
                        prt += i;
                    }
                }
            }
        }
    while(!input.eof() and getline (input, line));
    input.close();
}

//process insertion
void pinsert(process **pid, int pn, int art, int brt, int prt, int response, double *pct)
{
   process *p, *n = *pid;

    p = (process*) (malloc(sizeof(process)));
    p -> pn = pn;
    p -> arr_time = art;
    p -> brs_time = brt;
    p -> priority = prt;
    p -> response = *pct - art;
    p -> ct = *pct + brt;
    p -> tat = p -> ct - art;
    p -> waiting_time = p -> tat - brt;
    p -> awt = p -> tat / brt;
    *pct = *pct + brt;

    p -> next =NULL;

    if (*pid == NULL)
    {
        *pid = p;
    }
    else
    {
        do
        {
            n = n -> next;
        }
        while (n -> next != NULL);
        n -> next = p;
    }
}

void p_init(process *p, int pid) {
    int count;
    process *n = p;

    for (count = 1; count <= pid; count++) {
        cout << "Process " << p->pn;
        p = p->next;
    }

    cout << "\n";
    cout << " " << p -> arr_time;

    for (count = 1; count <= pid; count++)
    {
        cout << " " << p -> ct;
        n = n -> next;
    }
}

//to display process
void pdip(process *p, int pid)
{
    float ttt, twt, tbt;
    ttt = twt = tbt = 0;

    cout << "\n\n Process waiting times: \n" << p -> awt;

    do {
        cout << "P\n" << p -> pn;
    }
    while (p != NULL);

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
    process *head = NULL;
    int pn, cnt;

    for (cnt =1; cnt <= noline; cnt++)
    {
        switch (cnt)
        {
            case 1:
                response = art;
                pinsert(&head, cnt, art, brt, prt, response, reinterpret_cast<double *>(&response));
        }
    }

    p_init(head, pn);


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
    file_input();

    return 0;
}