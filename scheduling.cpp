#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int sc_method; //scheduling method

//process declaration
struct process
{
    int arr_time; //arrival time
    int brs_time; //burst time
    int priority; //priority
    float waiting_time; //waiting time
    int pn;

    struct process *next;
    struct process *prev;
};

process *p_init(int id, int brs, int ars, int prs)
{
    struct process *temp;
    temp = (struct process *)malloc(sizeof(process));
    temp->pn = id;
    temp->brs_time = brs;
    temp->arr_time = ars;
    temp->priority = prs;
    temp->next = NULL;

    return temp;
}

//to display each process
void displayLL(process *header)
{
    if (header == NULL)
    {
        cout << "File is empty" << endl;
        return;
    }

    struct process *temp = header;
    cout << "PiD" << " " << "B-time" << " " << "A-time" << " " << "Priority";

    while (temp != NULL)
    {
       cout << endl << "P" << temp->pn << "     " << temp -> brs_time << "     " << temp -> arr_time << "     " << temp -> priority;
        temp = temp->next;
    }
    cout << endl;
}

//process insertion
process *pinsert(struct process *header, int id, int brs, int ars, int prs)
{
    struct process *temp = p_init(id, brs, ars, prs);
    struct process *headertemp;

    if (header == NULL)
    {
        header = temp;
        return header;
    }

    headertemp = header;

    while (headertemp->next != NULL)
        headertemp = headertemp->next;

    temp->prev = headertemp;
    headertemp->next = temp;

    return header;
}

process *allProcesses;

//to iterate each character of a line
string* getLineData(string line) {
    string* data = new string[3];
    size_t n = 0;
    string eachData;
    int i = 0;
    while ((n = line.find(":")) != string::npos) {
        eachData = line.substr(0, n);
        data[i] = eachData;
        line.erase(0, n + 1);
        i++;
    }

    data[i] = line;

    return data;
}

//To read and display values from the file
void file_input(string filename)
{
    ifstream input;
    int id = 1;

    input.open(filename);

    string line;

    while(getline(input, line)) {
        string* data = getLineData(line);

        allProcesses = pinsert(allProcesses, id++, atoi(data[0].c_str()), atoi(data[1].c_str()), atoi(data[2].c_str()));
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
void FC_FS(process *header)
{
    cout << "First Come, First Served Scheduling" << endl;
    cout << "Process waiting times: " << endl;

    process *tmp = header, *lastProcess;
    double sum = 0, avg;
    int size = 0;

    while(tmp != NULL) {
        if(tmp->pn == 1) {
            tmp->waiting_time = 0;
        } else {
            tmp->waiting_time = lastProcess->waiting_time + lastProcess->brs_time;
        }

        sum += tmp->waiting_time;
        size++;
        cout << "P" << tmp->pn << ": " << tmp->waiting_time << " ms" << endl;
        lastProcess = tmp;
        tmp = tmp->next;
    }

    avg = sum / size;
    cout << "Average waiting time: " << avg << " ms" << endl;
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
    displayLL(allProcesses);
    switch (sc_method) {
        case 1:
            none_selected();
            break;

        case 2:
            FC_FS(allProcesses);
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
    file_input(argv[2]);
    options();
    scheduling_method();
    return 0;
}