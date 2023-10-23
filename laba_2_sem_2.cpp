#include <iostream>

using namespace std;

struct list{
private:
    list *next;
    list *prev;
    int numero;
    list *head;
public:
    list(){
        head = NULL;
    }
    ~list(){
        list* current = head;
        while(current != NULL){
            list* next = current->next;
            delete current;
            current = next;
        }
    }
    void push_back(int vivi, bool pool){
        list *prt = new list;
        prt->numero = vivi;
        if(head == NULL){
            prt-> prev = prt;
            prt-> next = prt;
            head = prt;
        }
        else{
            list *ptr = head;
            do {
                if(ptr->numero == vivi){
                    if(pool == true){
                        cout << "element already exists\n";
                    }
                    delete prt;
                    return;
                }
                ptr = ptr->next;
            }while(ptr!=head);
            prt->prev = head->prev;
            prt->next = head;
            head->prev->next = prt;
            head->prev = prt;
        }
    }
    void delete_el(int el, bool ez){
        if (head == NULL){
            if(ez){
                cout << "List is empty\n";
            }
        } 
        else{
            list *ptr = head;
            do{
                if (ptr->numero == el){
                    if(ptr == head){
                        if (ptr->next == ptr){
                            delete ptr;
                            head = NULL;
                        } 
                        else{
                            ptr->next->prev = ptr->prev;
                            ptr->prev->next = ptr->next;
                            head = ptr->next;
                            delete ptr;
                        }
                    } 
                    else{
                        ptr->next->prev = ptr->prev;
                        ptr->prev->next = ptr->next;
                        delete ptr;
                    }
                    return;
                }
                ptr = ptr->next;
            }while (ptr != head);
            cout << "Element not found\n";
        }
    }
    void function(int homiak){
        homiak /=2;
        if(head==NULL){
            cout << "list is empty\n";
        }
        else{
            list *ptr = head;
            list *tail = head->prev;
            while(homiak > 0){
                ptr->numero = ptr->numero - tail->numero;
                tail->prev->next = tail->next;
                tail->next->prev = tail->prev;
                delete tail;
                tail = head->prev;
                ptr = ptr->next;
                homiak--;
            }
        }
    }
    void printList(){
        if(head == NULL){
            cout << "List is empty\n";
        } 
        else{
            list* current = head;
            do{
                cout << current->numero << '\n';
                current = current->next;
            }while (current != head);
        }
    }
};
int check(){
    int j = 0;
    cin >> j;
    while(cin.fail() || cin.get()!='\n'){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << "wrong intering pleace try again\n";
        cin >> j;
    }
    return j;
}
int main() {
    list list_1;
    list list_2;
    int vib;
    int go;
    int count;
    bool l_1 = true;
    bool l_2 = false;
    do{
        cout << "enter 1 if you want enter element in list\n";
        cout << "enter 2 if you want delete element in list\n";
        cout << "enter 3 if eoy want Get a sequence of length containing \n";
        cout << "the difference between the first and last element, the second and penultimate, etc\n";
        cout << "enter 4 if you want to watch yout source list\n";
        cout << "enter 5 if you want to watch your resultant list\n";
        cout << "enter 6 if you want to leave out\n";
        vib = check();
        switch (vib)
        {
        case 1:{
            cout << "Enter a element: ";
            go = check();
            list_1.push_back(go,l_1);
            list_2.push_back(go,l_2);
            cout << "Your list now: \n";
            list_1.printList();
            count++;
            break;
        }
        case 2:{
            if(count <= 0){
                cout << "Your list is empty\n";
                break;
            }
            else{
                cout << "Your list now: \n";
                list_1.printList();
                cout << "Enter a element whos you want to delete\n";
                go = check();
                list_1.delete_el(go,l_1);
                list_2.delete_el(go,l_2);
                count--;
                if(count!=0){
                    cout << "Your list now: \n";
                    list_1.printList();
                }
                else{
                    cout << "your list is empty\n";
                }
                break;
            }
        }
        case 3:{
            cout << "Your list  beefore function: \n";
            list_1.printList();
            cout << "Your list  after function: \n";
            list_1.function(count);
            list_1.printList();
            break;
        }
        case 4:{
            cout << "Your source list: \n";
            list_2.printList();
            break;
        }
        case 5:{
            cout << "Your resolted list:\n";
            list_1.printList();
        }
        default:{
            break;
        }
        }
    }while(vib!=6);
    return 0;
}