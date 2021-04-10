#include<bits/stdc++.h>
using namespace std;

class task {
private:
    string name, symbol, desc;
    int priority;
public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setSymbol(string s) {
        symbol = s;
    }

    string getSymbol() {
        return symbol;
    }

    void setDesc(string d) {
        desc = d;
    }

    string getDesc() {
        return desc;
    }

    void setPriority(int p) {
        priority = p;
    }

    int getPriority() {
        return priority;
    }
};

void newTask(string newName, string newSymbol, string newDesc, int newPriority);
void markAsDone(int req);
void showCurrentTask();
void showAllTasks();
void changePriority(int req);
void deleteTask(int req);
void deleteAllTasks();
bool checkSymbol(string s);
bool checkPriority(int pr);
void updateTaskList();

vector<task> taskList;

int main()
{
    int tmp;

    cout << "___________________Task Manager____________________" << "\n";
    cout << "_________By: Praveen S && Rishi Mahadevan__________\n" << "\n";
    cout << "1] New task" << "\n";
    cout << "2] Mark as done" << "\n";
    cout << "3] Show current task" << "\n";
    cout << "4] Show all tasks" << "\n";
    cout << "5] Change priority" << "\n";
    cout << "6] Exit" << "\n";
    cout << "7] Delete task" << "\n";
    cout << "8] Delete all tasks" << "\n";
    cout << "9] Update task list" << "\n";
    cout << "Option: ";
    cin >> tmp;
    if (cin.fail()){
     cin.clear();
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     cin>>tmp;
    }

    switch (tmp) {
    case 1:
    {
        system("cls");
        string taskName, taskSymbol, taskDesc;
        int taskPriority;
        cout << "-----------------------------------------" << "\n";
        cout << "Task name: ";
        cin >> taskName;
        cout << "Task symbol (A-Z, eg. BC): ";
        cin >> taskSymbol;
        cout << "Task description: ";
        cin >> taskDesc;
        cout << "Task priority (1-5; 1 meaning urgent, 5 meaning irrelevant): ";
        cin >> taskPriority;
        if (!checkSymbol(taskSymbol) || !checkPriority(taskPriority)) {
            cout << "Input incorrect. Please Check following Rules:" << "\n";
            cout << "1- symbol is made out of 2 letters and is A-Z" << "\n" ;
            cout << "2- there are no letters put into priority" << "\n";
            cout << "3- priority is not a negative number" << "\n";
        }
        else {
            newTask(taskName, taskSymbol, taskDesc, taskPriority);
            cout << "New task added!" << "\n";
        }
        system("pause");
        system("cls");
        main();
        break;
    }
    case 2:
    {
        int req;
        system("cls");
        cout << "Task id: ";
        cin >> req;
        markAsDone(req);
        system("pause");
        system("cls");
        main();
        break;
    }
    case 3:
        system("cls");
        showCurrentTask();
        system("pause");
        system("cls");
        main();
        break;
    case 4:
        system("cls");
        showAllTasks();
        system("pause");
        system("cls");
        main();
        break;
    case 5:
    {
        int req;
        system("cls");
        cout << "Task id: ";
        cin >> req;
        changePriority(req);
        system("pause");
        system("cls");
        main();
        break;
    }
    case 6:
        return 0;
        break;
    case 7:
    {
        int req;
        system("cls");
        cout << "Task id: ";
        cin >> req;
        deleteTask(req);
        system("pause");
        system("cls");
        main();
        break;
    }
    case 8:
        system("cls");
        deleteAllTasks();
        system("pause");
        system("cls");
        main();
        break;
    case 9:
        updateTaskList();
        cout << "Done" << "\n";
        system("pause");
        system("cls");
        main();
        break;
    default:
        cout << "Error! Please Enter a Valid Option" << "\n";
        system("pause");
        system("cls");
        main();
        break;
    }

    return 0;
}

void newTask(string newName, string newSymbol, string newDesc, int newPriority) {
    task tmpTask;
    tmpTask.setName(newName);
    tmpTask.setSymbol(newSymbol);
    tmpTask.setDesc(newDesc);
    tmpTask.setPriority(newPriority);

    taskList.push_back(tmpTask);
    updateTaskList();
}

void markAsDone(int req) {
    if ((req > taskList.size()) || (req < 0)) {
        cout << "Task with provided id wasn't found" << "\n";
        system("pause");
        system("cls");
    }
    else {
        string tmp;
        task currentTask;
        try {
            currentTask = taskList.at(req);
        }
        catch (const out_of_range& e) {
            cout << "Task with provided id wasn't found" << "\n";
            system("pause");
            system("cls");
            main();
        }

        cout << "Name: " << currentTask.getName() << "\n";
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << "\n" << "Description: " << currentTask.getDesc() << "\n";
        cout << "Priority: " << currentTask.getPriority() << "\n";

        taskList.at(req).setPriority(6);
        taskList.at(req).setDesc("| DONE | " + taskList.at(req).getDesc());
        updateTaskList();
    }
}

void showCurrentTask() {
    if (taskList.size() <= 0) {
        cout << "There are no tasks at the moment" << "\n";
    }
    else {
        task currentTask = taskList.front();
        cout << "Name: " << currentTask.getName() << "\n";
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << "\n" << "Description: " << currentTask.getDesc() << "\n";
        cout << "Priority: " << currentTask.getPriority() << "\n";
    }
}

void showAllTasks() {
    for (int i = 0; i < taskList.size(); i++) {
        task currentTask = taskList.at(i);
        cout << i << "]" << "\n";
        cout << "Name: " << currentTask.getName() << "\n";
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << "\n" << "Description: " << currentTask.getDesc() << "\n";
        cout << "Priority: " << currentTask.getPriority() << "\n";
    }
}

void changePriority(int req) {
    if ((req > taskList.size()) || (req < 0)) {
        cout << "Task with provided id wasn't found" << "\n";
        system("pause");
        system("cls");
    }
    else {
        int newPriority;
        task currentTask;
        try {
            currentTask = taskList.at(req);
        }
        catch (const out_of_range& e) {
            cout << "Task with provided id wasn't found" << "\n";
            system("pause");
            system("cls");
            main();
        }

        cout << "Name: " << currentTask.getName() << "\n";
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << "\n" << "Description: " << currentTask.getDesc() << "\n";
        cout << "Priority: " << currentTask.getPriority() << "\n";

        cout << "\n" << "Change priority to? (1-5): ";
        cin >> newPriority;
        if (cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>>newPriority;
        }

        taskList.at(req).setPriority(newPriority);
        updateTaskList();
    }
}

void deleteTask(int req) {
    string tmp;
    task currentTask;
    try {
        currentTask = taskList.at(req);
    }
    catch (const out_of_range& e) {
        cout << "Task with provided id wasn't found" << "\n";
        system("pause");
        system("cls");
        main();
    }

    cout << "Name: " << currentTask.getName() << "\n";
    cout << "Symbol: ";
    for (int i = 0; i < currentTask.getSymbol().size(); i++) {
        putchar(toupper(currentTask.getSymbol()[i]));
    }
    cout << "\n" << "Description: " << currentTask.getDesc() << "\n";
    cout << "Priority: " << currentTask.getPriority() << "\n";

    cout << "Are you sure? (y/n): ";
    cin >> tmp;
    if (cin.fail()){
     cin.clear();
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     cin>>tmp;
    }

    if ((tmp == "y") || (tmp == "yes")) {
        taskList.erase(taskList.begin() + req);
        updateTaskList();
    }
    else if ((tmp == "n") || (tmp == "no")) {
        main();
    }
}

void deleteAllTasks() {
    if (taskList.size() <= 0) {
        cout << "There are no tasks at the moment" << "\n";
    }
    else {
        taskList.clear();
    }
}

bool checkSymbol(string s) {
    if (s.size() == 2) {
        for (int i = 0; i < s.size(); i++) {
            if (((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122))) {
                return true;
            }
        }
    }
    return false;
}

bool checkPriority(int pr) {
    if ((pr >= 1) && (pr <= 5)) {
        return true;
    }
    else {
        return false;
    }
}

void updateTaskList() {
    sort(taskList.begin(), taskList.end(),
        [](task a, task b) {
        return a.getPriority() < b.getPriority();
    });
}
