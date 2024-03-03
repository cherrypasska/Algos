#include <iostream>

using namespace std;

void zadanie(int* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i] == arr[j]){
                count++;
            }
        }
        if (count > 1){
            cout << '\n';
            cout << "Element " << arr[i] << " exist in mass: " << count;
            i = i + count - 1;
        }
        count = 0;
    }
    cout << "\n";
}

void countingSort(int* arr, int n){
    cout << "Your mass: ";
    for (int i = 0; i < n; i++) cout << arr[i] << "  ";
    cout << "\n";
    int srav = 0;
    int per = 0;
    int k = 0;
    int* b = new int[n];
    for(int i = 0; i < n; i++){
        k = 0;
        for(int j = 0; j < n; j++){
            srav++;
            if((arr[j] < arr[i]) || ((arr[j] == arr[i]) && (j < i))) k++;
        }
        b[k] = arr[i];
    }
    cout << "Converted Array: \n";
    for (int i = 0; i < n; i++) { 
        if (arr[i] != b[i]) per++;
        arr[i] = b[i]; 
        cout << arr[i] << "  "; 
    }
    cout << "\n";
    cout << "Number of comparisons: " << srav << '\n';
    cout << "Number of permutations: " << per << '\n';
}

void find(int* arr, int n){
    cout << "How do you want to search for an element \n";
    cout << " Enter 1 to search ordinal position\n";
    cout << " Enter 2 to search content:\n";
    int v, x, p=0;
    cin >> v;
    switch (v) {
    case 1:
        cout << "Enter the sequence number of the element:\n";
        cin >> x;
        if ((x < 0) || (x > n)) cout << "in array " << n << " elements\n";
        else cout << "Result of search: \n" << arr[x] << '\n';
        break;
    case 2:
        cout << "Enter content of element: \n";
        cin >> x;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                cout << "Search result: " << i << " element\n";
                p = 1;
            }
        }
        if (p == 0) cout << " elements with this value in the mass\n";
        break;
    }
}

void add(int* &arr, int &n, int value) {
    cout << "Array size exceeded\n";
    cout << "Increasing the size of the array\n";

    int* newArray = new int[n + 1];
    for (int i = 0; i < n; i++){
        newArray[i] = arr[i];
    }

    newArray[n] = value;
    n++;

    delete[] arr;
    arr = newArray;
    countingSort(arr, n);
}

void del(int* &arr, int &n, int value) {
    if ((value < 0) || (value > n)) cout << "In array " << n << " elements!\n";
    else { 
        int* newArray = new int[n - 1];
        for (int j = 0; j < n - 1; j++)
        {
            newArray[j] = arr[j];
        }
        for (int i = value; i < n - 1; i++)
        {
            newArray[i] = arr[i + 1];
        }
        n--;
        delete[] arr;
        arr = newArray;
        cout << "Element delete" << '\n'; 
        countingSort(arr, n);
    }
}

int main(){
    int n = 10;
    int c=0;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cout << "Enter a value " << i << " element of array: ";
        cin >> arr[i];
    }
    countingSort(arr, n);

    while (c != 5){
        cout << "Enter:\n";
        cout << "1 if you want to find element\n";
        cout << "2 if you want add element\n";
        cout << "3 if you want delete element\n";
        cout << "4 if you want find the number of repeating numbers\n";
        cout << "5 if you want to break yor programm\n";
        cin >> c;
        int x;
        switch (c)
        {
        case 1:{
            find(arr, n);
            break;
        }
        case 2:{
            cout << "Enter value " << (n + 1) << " element of array: ";
            cin >> x;
            add(arr, n, x);
            break;
        }
        case 3:{
            cout << "Enter the sequence number of the item you want to delete: \n";
            cin >> x;
            del(arr, n, x);
            break;
        }
        case 4:{
            zadanie(arr, n);
        }
        case 5:{
            cout << "The end of programm\n";
            break;
        }
        default:
        break;
        }
    }
    return 0;
}