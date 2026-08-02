// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//


// #include <iostream>
#include <vector>
#include <string>
using namespace std;

// Funct
    

    do

        cout << "     TO-DO LIST MENU\n";
        cout << "============================\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Delete task\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;

        case 2:
            viewTasks(tasks);
            break;

        case 3:
            deleteTask(tasks);
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}

// Function to add a task
void addTask(vector<string>& tasks)
{
    string task;

    cout << "Enter task: ";
    getline(cin, task);

    tasks.push_back(task);

    cout << "Task added: \"" << task << "\"" << endl;
}

// Function to display all tasks
void viewTasks(const vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;

    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }

    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    cin.ignore();

    if (taskNumber >= 1 && taskNumber <= tasks.size())
    {
        cout << "Task \"" << tasks[taskNumber - 1] << "\" has been removed." << endl;
        tasks.erase(tasks.begin() + (taskNumber - 1));
    }
    else
    {
        cout << "Error: Invalid task number." << endl;
    }
}