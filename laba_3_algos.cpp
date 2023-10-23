#include <iostream>
#include <ctime>

using namespace std;

using namespace std;

struct Task {
    int priority;
    int taskTime;
    int durationTime;
};

struct TaskList {
    Task *taskValues;
    TaskList* next;
};

class Stack{
private:
    TaskList *head;
public:
    Stack(){
        head = nullptr;
    }
    ~Stack(){
        TaskList *current = head;
        while (current != nullptr){
            TaskList *next = current->next;
            delete current->taskValues;
            delete current;
            current = next;
        }
    }
    void push_front(Task *value){
        TaskList *newTask = new TaskList;
        newTask->taskValues = new Task(*value);
        newTask->next = head;
        head = newTask;
    }
    bool empty(){
        return (head == nullptr);
    }
    Task *non(){
        Task *value = head->taskValues;
        return value;
    }
    Task *exit(){
        if(empty()){
            return nullptr;
        }
        Task *value = head->taskValues;
        TaskList *temp = head;
        head = head->next;
        delete temp;
        return value;
    }
    void showstack(){
        TaskList *current = head;
        cout << "Stack contents:\n";
        while (current != nullptr) {
            Task *task = current->taskValues;
            cout << "Task Time: " << task->taskTime << " Priority: " << task->priority << " Duration: " << task->durationTime << "\n";
            current = current->next;
        }
    }
};

const int max_size = 2;

class Queue{
private:
    int first;
    int last;
    Task *massive[max_size];
public:
    Queue(){
        first = -1;
        last = -1;
    }
    bool isFull(){
        return (last == max_size - 1);
    }
    void pushFront(Task *task){
        if(isFull()){
            cout << "The queue is full\n";
            return;
        }
        if (empty()){
            first = 0;
            last = 0;
            massive[last] = task;
        } 
        else{
            last++;
            massive[last] = task;
        }
    }
    bool empty(){
        return (first == -1 && last == -1);
    }
    Task *exit(){
        if(empty()){
            return nullptr;
        }
        Task *value = massive[first];
        if (first == last){
            first = -1;
            last = -1;
        } 
        else{
            first++;
        }
        return value;
    }
    void showqueue(int n, Queue queue){
        if(empty()){
            cout << "The queue " << n << " is empty.\n";
            return;
        }
        cout << n << " Queue contents:\n";
        if(queue.isFull()) cout << "queue " << n << " is full\n";
        for(int i = first; i <= last; ++i){
            Task *task = massive[i];
            cout << "Task Time: " << task->taskTime << " Priority: " << task->priority << " Duration: " << task->durationTime << "\n";
        }
    }
};

class TaskGenerator{
public:
    Task *generate(int i){
        Task *newTask = new Task;
        newTask->priority = rand() % 3;
        newTask->durationTime = rand() % 5 + 1;
        newTask->taskTime = i;
        return newTask;
    }
    Task *keyboard(int i){
        Task *newTask = new Task;
        int pr;
        int dur;
        cout << "Enter a priority of your " << i << " Task: \n";
        cin >> pr;
        cout << "Enter a duration time of your " << i << " Task: \n";
        cin >> dur;
        newTask->priority = pr;
        newTask->durationTime = dur;
        newTask->taskTime = i;
        return newTask;
    }
};

class Processor{
public:
    void processorloop(Queue &queue_0, Queue &queue_1, Queue &queue_2, Stack &Stack, TaskList *mass) {
        int timer = 1;
        Task *inpros = nullptr;

        while (true){
            cout << "Entering takt " << timer << '\n';
            cout << "----------------------------------------\n";
            if(mass != nullptr){
                Task *newTask = new Task(*mass->taskValues);
                if(newTask->priority == 0 && !queue_0.isFull()){
                    queue_0.pushFront(newTask);
                    mass = mass->next;
                }
                else if(newTask->priority == 1 && !queue_1.isFull()){
                    queue_1.pushFront(newTask);
                    mass = mass->next;
                } 
                else if(newTask->priority == 2 && !queue_2.isFull()){
                    queue_2.pushFront(newTask);
                    mass = mass->next;
                }
            }
            if(!Stack.empty() && (inpros==nullptr || inpros->priority > Stack.non()->priority)){
                inpros = Stack.exit();
            }
            if(!queue_0.empty()){
                if (inpros == nullptr) {
                    inpros = queue_0.exit();
                } 
                else if (inpros->priority > 0) {
                    Stack.push_front(inpros);
                    inpros = queue_0.exit();
                }
            } 
            else if(!queue_1.empty()){
                if (inpros == nullptr){
                    inpros = queue_1.exit();
                }
                else if(inpros->priority > 1){
                    Stack.push_front(inpros);
                    inpros = queue_1.exit();
                }
            }
            else if(!queue_2.empty()){
                if(inpros == nullptr){
                    inpros = queue_2.exit();
                }
            }
            cout << "Input tasks:\n";
            TaskList *taskl = mass;
            while(taskl != nullptr){
                Task *task = taskl->taskValues;
                cout << "Task Time: " << task->taskTime << " Priority: " << task->priority << " Duration: " << task->durationTime << "\n";
                taskl = taskl->next;
            }
            cout << "----------------------------------------\n";
            if (inpros != nullptr){
                cout << "In processor: \n";
                cout << "Task Time: " << inpros->taskTime << " Priority: " << inpros->priority << " Duration: " << inpros->durationTime << '\n';
                inpros->durationTime--;
            }
            else{
                cout << "Processor is idle.\n";
            }
            cout << "----------------------------------------\n";
            queue_0.showqueue(1, queue_0);
            queue_1.showqueue(2, queue_1);
            queue_2.showqueue(3, queue_2);
            cout << "----------------------------------------\n";
            Stack.showstack();
            cout << "----------------------------------------\n";
            if(queue_0.empty() && queue_1.empty() && queue_2.empty() && Stack.empty() && inpros == nullptr){
                cout << "All process of processor are complited\n";
                break;
            }
            if(inpros->durationTime == 0){
                delete inpros;
                inpros = nullptr;
            }
            timer++;
        }
    }
};

int check(){
    int j; 
    cin >> j;
    while(cin.fail() || cin.get()!='\n'){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "wrong intering pleace try again\n";
        cin >> j;        
    }
    return j;
}

int main(){
    srand(time(0));

    Queue Queue_1;
    Queue Queue_2;
    Queue Queue_3;
    Stack Stack;
    Processor Processor;
    TaskGenerator taskgenerator;
    int vibor = 0;
    do{
        cout << "Enter 1 if you want to see how the program works with random tasks\n";
        cout << "Enter 2 if you want to enter values from the keyboard\n";
        cout << "Enter 3 if you want to break your programm\n";
        vibor = check();
        switch(vibor){
        case 1:{
            cout << "Enter number of Tasks: \n";
            int n;
            cin >> n;
            TaskList *mass = nullptr;
            TaskList *currentTask = nullptr;
            for(int i = 0; i < n; i++){
                Task *newTask = taskgenerator.generate(i);
                TaskList *newTaskList = new TaskList;
                newTaskList->taskValues = newTask;
                newTaskList->next = nullptr;

                if(mass == nullptr){
                    mass = newTaskList;
                    currentTask = mass;
                } 
                else{
                    currentTask->next = newTaskList;
                    currentTask = currentTask->next;
                }
            }
            Processor.processorloop(Queue_1, Queue_2, Queue_3, Stack, mass);
            TaskList *current = mass;
            while(current != nullptr){
                TaskList *temp = current;
                current = current->next;
                delete temp->taskValues;
                delete temp;
            }
            break;
        }
        case 2:{
            cout << "Enter a number of Tasks: \n";
            int n;
            cin >> n;
            TaskList *mass = nullptr;
            TaskList *currentTask = nullptr;
            for(int i = 0; i < n; i++){
                Task *newtask = taskgenerator.keyboard(i);
                TaskList *newTaskList = new TaskList;
                newTaskList->taskValues = newtask;
                newTaskList->next = nullptr;
                if(mass == nullptr){
                    mass = newTaskList;
                    currentTask = mass;
                }
                else{
                    currentTask->next = newTaskList;
                    currentTask = currentTask->next;
                }
            }
            Processor.processorloop(Queue_1, Queue_2, Queue_3, Stack, mass);
            TaskList *current = mass;
            while(current != nullptr){
                TaskList *temp = current;
                current = current->next;
                delete temp->taskValues;
                delete temp;
            }
            break;
        }
        case 3:{
            cout << "End of your programm";
            break;
        }
        default:{
            break;
        }
        }
    }while(vibor!=3);
    return 0;
}