#include <iostream>

using namespace std;

class graph{
private:
    int vis;
    int shir;
    int **Graph;
public:
    graph(int count){
        shir = count;
        vis = count;
        Graph = new int*[vis];
        for(int i = 0; i < vis; i++){
            Graph[i] = new int[shir];
        }
        for(int i = 0; i < vis; i++){
            for(int j = i + 1; j < shir; j++){
                cout << "Is the " << i + 1 <<" person familiar with the " << j + 1 << "? 1 - yes; 0 - no\n";
                cin >> Graph[i][j];
                Graph[j][i] = Graph[i][j];
            }
        }
        for(int i = 0; i < shir; i++){
            Graph[i][i] = 0;
        }
    }
    void vivod(){
        cout << "Your graph\n";
        for(int i = 0; i < vis; i++){
            for(int j = 0; j < shir; j++){
                cout << Graph[i][j] << " ";
            }
            cout << '\n';
        }
    }
    void task(int first, int second){
        for(int k = 0; k < vis; k++){
            for(int i = 0; i < vis; i++){
                for(int j = i+1; j < shir; j++){
                    if(Graph[i][k] == 1 && Graph[k][j]==1){
                        Graph[i][j] = 1;
                        Graph[j][i] = 1;
                    }
                }
            }
        }
        if(Graph[first][second]==1) cout << "They know each other\n";
        else cout << "they are dont know each other\n";
    }
};

int main(){
    cout << "Enter number of person \n";
    int kol;
    cin >> kol;
    graph Gr(kol);
    Gr.vivod();
    graph original = Gr;
    int chelovek1, chelovek2;
    int n;
    while(n!=4){
        cout <<"Enter 1 if you want to find out if 2 people can be acquainted \n";
        cout <<"Enter 2 if you want to output the matrix\n";
        cout <<"Enter 3 if you want to output the matrix after all the acquaintances\n";
        cout <<"Enter 4 if you want to break the programm\n";
        cin >> n;
        switch(n){
        case 1:{
            cout << "Enter the first person:\n";
            cin >> chelovek1;
            cout << "Enter the second person:\n";
            cin >> chelovek2;
            Gr.task(chelovek1-1, chelovek2-1);
            break;
        }
        case 2:{
            original.vivod();
            break;
        }
        case 3:{
            Gr.vivod();
            break;
        }
        case 4:{
            cout << "The end of programm\n";
            break;
        }
        default:{
            break;
        }
        }
    }
}