#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
struct HashNode{
    string key;
    int id;
    int kol;
    HashNode* next;
};

const int maxsize = 1500;

class HashMap {
private:
    HashNode* map[maxsize];
public:
    HashMap(){
        for(int i = 0; i < maxsize; ++i){
            map[i] = NULL;
        }
        srand(time(0));
    }
    int hashFunction(const string& key){
        int hash = 0;
        for (char c : key){
            hash = (hash*7 + c*c) % maxsize;
        }
        return hash;
    }
    string create_key(){
        string key;
        for(int i = 0; i < 2; i++){
            key += '0' + rand() %10;
        }
        for(int i = 0; i < 2; i++){
            key+= 'A' + rand() %26;
        }
        for(int i = 0; i < 2; i++){
            key += '0' + rand() %10;
        }
        return key;
    }
    void insert(){
        string newKey = create_key();
        int hashValue = hashFunction(newKey);
        HashNode* newNode = new HashNode;
        newNode->key = newKey;
        newNode->id = hashValue;
        newNode->next = NULL;
        if(map[hashValue] == NULL){
            map[hashValue] = newNode;
            map[hashValue]->kol++;
        }
        else{
            HashNode* temp = map[hashValue];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            map[hashValue]->kol++;
        }
    }
    void remove(const string& key){
        int hashValue = hashFunction(key);
        HashNode* current = map[hashValue];
        HashNode* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key){
                if (prev == nullptr){
                    map[hashValue] = current->next;
                    map[hashValue]->kol--;
                } 
                else{
                    prev->next = current->next;
                    map[hashValue]->kol--;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Element with key " << key << " not found." << '\n';
    }
    void Show_table(){
        for (int i = 0; i < maxsize; i++) {
            HashNode* temp = map[i];
            cout << "id: " << i+1;
            if(temp == NULL) cout << " capacity is empty\n";
            else{
                while (temp != nullptr) {
                    cout << " key: " << temp->key << " ";
                    temp = temp->next;
                }
                cout << '\n';
            }
        }
    }
    bool find(const string& key){
        int hashValue = hashFunction(key);
        HashNode* current = map[hashValue];

        while (current != nullptr){
            if (current->key == key){
                cout << "Element with key " << key << " found at id: " << current->id + 1 << '\n';
                return true;
            }
            current = current->next;
        }
        cout << "Element with key " << key << " not found." << '\n';
        return false;
    }
    void findByID(int targetID){
        targetID = targetID - 1;
        int cnt = 0;
        HashNode* temp = map[targetID];
        while (temp != nullptr){
            if (temp->id == targetID) {
                cout << "Element with ID " << targetID+1 << " found. Key: " << temp->key << '\n';
                cnt++;
            }
            temp = temp->next;
        }
        if(cnt == 0) cout << "Element with ID " << targetID + 1 << " not found." << '\n';
    }
    friend ostream& operator<<(ostream& out, const HashMap& table);
    void keyboard(){
        string key;
        cout << "Enter key: ";
        cin >> key;
        int hashValue = hashFunction(key);
        HashNode* newNode = new HashNode;
        newNode->key = key;
        newNode->id = hashValue;
        newNode->next = nullptr;
        if(map[hashValue] == nullptr){
            map[hashValue] = newNode;
        }
        else{
            HashNode* temp = map[hashValue];
            while(temp->next != nullptr){
                temp = temp->next;
            }
            if(temp->key == newNode->key) cout << "Element already exist\n";
            else temp->next = newNode;
        }
    }
    ~HashMap(){
        for(int i = 0; i < maxsize; ++i){
            HashNode* temp = map[i];
            while(temp != nullptr){
                HashNode* prev = temp;
                temp = temp->next;
                delete prev;
            }
        }
    }
};
ostream& operator<<(ostream& out, const HashMap& table){
    for(int i = 0; i < maxsize; ++i){
        int keyCount = 0;
        HashNode* temp = table.map[i];
        while (temp != nullptr){
            keyCount++;
            temp = temp->next;
        }
        out << keyCount << '\n';
    }
    return out;
}

int main(){
    int n;
    int count = 0;
    HashMap Hahtable;
    do{
        cout << "Enter 1 if you want to fill a hashtable\n";
        cout << "Enter 2 if you want to enter new random element\n";
        cout << "Enter 3 if you want to enter new element from keydoard\n";
        cout << "Enter 4 if you want to delete your element\n";
        cout << "Enter 5 if you want to bring out your hashtable\n";
        cout << "Enter 6 if you want to  find your element\n";
        cout << "Enter 7 if you want to upload your hashtable to a text file\n";
        cout << "Enter 8 if you want to break your programm\n";
        cin >> n;
        switch(n){
        case 1:{
            int koliki;
            cout << "Enter a count of elements you want insert\n";
            cin >> koliki;
            count+=koliki;
            for(int i = 0; i < koliki; i++){
                Hahtable.insert();
                count++;
            }
            break;
        }
        case 2:{
            Hahtable.insert();
            count++;
            break;
        }
        case 3:{
            Hahtable.keyboard();
            count++;
            break;
        }
        case 4:{
            if(count == 0){
                cout << "your hashtable is empty\n";
            }
            else{
                cout << "Enter key of element you want delete\n";
                string str;
                cin >> str;
                Hahtable.remove(str);
                count--;
            }
            break;
        }
        case 5:{
            if(count == 0){
                cout << "Your hashtable is empty\n";
            }
            else{
                Hahtable.Show_table();
                cout << count << '\n';
            }
            break;
        }
        case 6:{
            if(count == 0){
                cout << "Your hashtable is empty\n";
            }
            else{
                cout << "Enter 1 if you fant to find your element of his id\n";
                cout << "Enter 2 if you want to find your element of his key\n";
                int m;
                cin >> m;
                if(m == 1){
                    int number;
                    cout << "Enter ID: ";
                    cin >> number;
                    Hahtable.findByID(number);
                }
                if(m == 2){
                    string str;
                    cout << "Enter your key:\n";
                    cin >> str;
                    Hahtable.find(str);
                }
            }
            break;
        }
        case 7:{
            ofstream out("output.txt");
            if(out.is_open()){
                out << Hahtable;
                cout << "Hash table saved to 'output.txt'\n";
                out.close();
            }
            else{
                cout << "Unable to open file!\n";
            }
            break;
        }
        case 8:{
            cout << "The end of programm\n";
            break;
        }
        default:{
            break;
        }
        }
    }while(n!=8);
}