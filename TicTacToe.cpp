#include<bits/stdc++.h>
using namespace std;


int randomGen(){
    srand(time(0));
    return rand()%10;
}


char win(char arr[]){
    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0]!=' '&& arr[1]!=' '&& arr[2]!=' '){
        return arr[0];
    }
    else if (arr[3] == arr[4] && arr[4] == arr[5] && arr[3]!=' '&& arr[4]!=' '&& arr[5]!=' '){
        return arr[3];
    }
    else if (arr[6] == arr[7] && arr[7] == arr[8] && arr[6]!=' '&& arr[7]!=' '&& arr[8]!=' '){
        return arr[6];
    }
    else if (arr[0] == arr[3] && arr[3] == arr[6] && arr[0]!=' '&& arr[3]!=' '&& arr[6]!=' '){
        return arr[0];
    }
    else if (arr[1] == arr[4] && arr[4] == arr[7] && arr[1]!=' '&& arr[4]!=' '&& arr[7]!=' '){
        return arr[1];
    }
    else if (arr[2] == arr[5] && arr[5] == arr[8] && arr[2]!=' '&& arr[5]!=' '&& arr[8]!=' '){
        return arr[2];
    }
    else if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0]!=' '&& arr[1]!=' '&& arr[2]!=' '){
        return arr[0];
    }
    else if (arr[0] == arr[4] && arr[4] == arr[8] && arr[0]!=' '&& arr[4]!=' '&& arr[8]!=' '){
        return arr[0];
    }
    else if (arr[2] == arr[4] && arr[4] == arr[6] && arr[2]!=' '&& arr[4]!=' '&& arr[6]!=' '){
        return arr[2];
    }
    else if(arr[0]!=' '&& arr[1]!=' ' && arr[2]!=' '&& arr[3]!=' ' && arr[4]!=' ' && arr[5]!=' ' && arr[6]!=' ' && arr[7]!=' ' && arr[8]!=' '){
        return 'D';
    }
    else{
        return 'C';
    }
}



void showBoard(char arr[]){
    cout<<"   "<<"   |      "<<"    |   "<<endl;
    cout<<"   "<<arr[0]<<"  |     "<<arr[1]<<"    |   "<<arr[2]<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"   "<<"   |      "<<"    |   "<<endl;
    cout<<"   "<<arr[3]<<"  |     "<<arr[4]<<"    |   "<<arr[5]<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"   "<<"   |      "<<"    |   "<<endl;
    cout<<"   "<<arr[6]<<"  |     "<<arr[7]<<"    |   "<<arr[8]<<endl<<endl<<endl;
}



void input_symbol_pp(char arr[],int size,char P1symbol,char P2symbol,string player1,string player2){
    int index,i=0;
    char winner;
    while(i<size){
        cout<<"choose the index where u want to put symbol(Choose from 1 to 9)\n";
        if (i%2 == 0){
            cout<<player1<<" turn(symbol->"<<P1symbol<<")";
            while (!(cin >> index)){
                cout<<"Invalid number\n";
                cin.clear();
                cin.ignore(123,'\n');
            }
            
            if(index-1<0 || index-1 >9){
                cout<<"Please Enter in range(1 to 9)"<<endl;
                i--;
            }
            else if(arr[index-1]!=' '){
                cout<<"Please enter in empty space"<<endl;
                i--;
            }
            else{
                arr[index-1] = P1symbol;
                system("CLS");
                showBoard(arr);
                winner = win(arr);
            }
            if (winner == 'D'){
                cout<<"Match is Draw\n";
                break;
            }
            else if(winner == 'C'){
            }
            else{
                cout<<player1<<" is win\n";
                break;
            }
            i++;
        }
        else{
            cout<<player2<<" turn(symbol->"<<P2symbol<<")";
            while (!(cin >> index)){
                cout<<"Invalid number\n";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(index-1<0 || index-1 >9){
                cout<<"Please Enter in range(1 to 9)"<<endl;
                i--;
            }
            else if(arr[index-1]!=' '){
                cout<<"Please enter in empty space"<<endl;
                i--;
            }
            else{
                arr[index-1] = P2symbol;
                system("CLS");
                showBoard(arr);
                winner = win(arr);
            }
            if (winner == 'D'){
                cout<<"Match is Draw\n";
                break;
            }
            else if(winner == 'C'){
            }
            else{
                cout<<player2<<" is win\n";
                break;
            }
            i++;
        }

        
    }
}



void input_symbol_pc(char arr[],int size,char P1symbol,char P2symbol,string player,string comp){
    int index, i =0,random;
    char winner;
    while(i<size){
        cout<<"choose the index where u want to put symbol(Choose from 1 to 9)\n";
        while (!(cin >> index)){
                cout<<"Invalid number\n";
                cin.clear();
                cin.ignore(123,'\n');
            }
            
            if(index-1<0 || index-1 >9){
                cout<<"Please Enter in range(1 to 9)"<<endl;
                i--;
            }
            else if(arr[index-1]!=' '){
                cout<<"Please enter in empty space"<<endl;
                i--;
            }
            else{
                arr[index-1] = P1symbol;
                do{
                    if(arr[0]!=' '&& arr[1]!=' ' && arr[2]!=' '&& arr[3]!=' ' && arr[4]!=' ' && arr[5]!=' ' && arr[6]!=' ' && arr[7]!=' ' && arr[8]!=' ')
                    {
                        break;
                    }
                    else{
                         random = randomGen();
                    }
                }
                while(arr[random]!=' ');
                arr[random] = P2symbol;
                system("CLS");
                showBoard(arr);
                winner = win(arr);
            }
            if (winner == 'D'){
                cout<<"Match is Draw\n";
                break;
            }
            else if(winner == 'C'){
            }
            else{
                if(winner == P1symbol){
                    cout<<player<<" is win\n";
                    break;
                }
                else{
                    cout<<comp<<" is win\n";
                break;
                }
            }
            i++;

    }
}



void player_with_player(char arr[],int size){
    string player1,player2;
    char P1Symbol,P2Symbol;
    cin.ignore();
    cout<<"Enter Player 1 name-> ";
    getline(cin,player1);
    system("CLS");
    cout<<"Enter Player 2 name->";
    getline(cin,player2);
    system("CLS");
    cout<<player1<<" choose symbol from 0 and x-> ";
    cin>>P1Symbol;
    system("CLS");
    cout<<player2<<" choose symbol from 0 and x->";
    cin>>P2Symbol;
    system("CLS");
    if(P1Symbol == P2Symbol){
        cout<<"Symbols are same Try again\n";
        return ;
    }
    else if(P1Symbol == '0' && P2Symbol == 'x'|| P1Symbol == 'x' && P2Symbol == '0'){
        showBoard(arr);
        input_symbol_pp(arr,size,P1Symbol,P2Symbol,player1,player2);
    }
    else{
        cout<<"Invalid symbol\n";
        return;
    }   
}


void player_with_comp(char arr[],int size){
    string player,comp ;
    char P1symbol,P2symbol;
    cin.ignore();
    cout<<"Enter your name\n";
    getline(cin,player);
    system("CLS");
    comp = "computer";
    cout<<"Choose Symbol(from x and 0)\n";
    cin>>P1symbol;
    system("CLS");
    if(P1symbol == '0' || P1symbol == 'x'){
        if (P1symbol == 'x'){
            P2symbol = '0';
        }
        else{
            P2symbol = 'x';
        }
    }
    else{
        cout<<"Invalid choice\n";
        return;
    }
    showBoard(arr);
    input_symbol_pc(arr,size,P1symbol,P2symbol,player,comp);
    

}




void chooseMode(char arr[],int size){
    int run=1;
    string choose;
    while(run == 1){
            cout<<"______________________________________________Tic Tac Toe_______________________________________________\n\n";
            cout<<"Choose Mode\n";
            cout<<"1.Player-1 Vs Player-2\n2.Player Vs Comnputer\n3.Exit\n\n";
            cin>>choose;
        if (choose == "1"){
            player_with_player(arr,size);
        }
        else if(choose == "2"){
            player_with_comp(arr,size);
        }
        else if (choose == "3"){
            break;
        }
        else{
            cout<<"Invalid choice\n";
        }
    cout<<"For restart press 1 otherwise press any key\n";
    for (int i=0;i<size;++i){
        arr[i] = ' ';
    }
    cin>>run;
    system("CLS");
    if(run != 1){
        break;
    }
    }
}



int main(){
    system("CLS");
    char arr_index[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int size = sizeof(arr_index)/sizeof(char);
    chooseMode(arr_index,size);
    cout<<"________________________________________________"<<"Thanks for Playing Game"<<"_____________________________________"<<endl;
    return 0;
}