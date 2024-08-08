#include <bits/stdc++.h>
using namespace std;

class ToDoList {
private:
    vector<string> tasks;
    vector<bool> completed;

public:
    void addTask(const string& description) {
        tasks.push_back(description);
        completed.push_back(false);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i]
                      << (completed[i] ? " [completed]" : " [not completed]") << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        completed[index - 1] = true;
        cout << "Task " << index << " marked as completed." << endl;
    }

    void removeTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        completed.erase(completed.begin() + index - 1);
        cout << "Task removed." << endl;
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string description;
    size_t index;

    while (true) {
        cout << "\nTo-Do List Menu:"<< endl;
        cout << "1. Add task"<< endl;
        cout << "2. View tasks"<< endl;
        cout << "3. Mark task as completed"<< endl;
        cout << "4. Remove task"<< endl;
        cout << "5. Exit"<< endl;
        cout << "Enter your choice: "<< endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the task : ";
            cin.ignore();
            getline(cin, description);
            todoList.addTask(description);
            break;
        case 2:
            todoList.viewTasks();
            break;
        case 3:
            cout << "Enter task number to mark as completed: ";
            cin >> index;
            todoList.markTaskCompleted(index);
            break;
        case 4:
            cout << "Enter task number to remove: ";
            cin >> index;
            todoList.removeTask(index);
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
