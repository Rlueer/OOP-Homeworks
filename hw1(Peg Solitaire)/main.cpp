 
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

void print_board(vector<vector<char> > board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

void final_score(vector<vector<char> > board){
    int score=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]=='P'){
                score++;
            }
        }
    }
    cout<<"Final score is "<<score<<endl<<endl;
}
vector<vector<char> >& create_map1(vector<vector<char> >& board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==0 && j==0){
                board[i][j]=' ';
            }
            else if(i==0){
                board[i][j]='a'+j-1;
            }
            else if(j==0){
                board[i][j]='1'+i-1;
            }
            else if((i==2 && j==2)||(i==6 && j==6)||(i==2 && j==6)||(i==6 && j==2)){
                board[i][j]='P';
            } 
            else if((i<3 && j<3)||(i>5 && j<3)||(i<3 && j>5)||(i>5 && j>5)){
                board[i][j]=' ';
            }
            else if(i==3 && j==4){
                board[i][j]='.';
            }
            else{
                board[i][j]='P';
            }
        }
    }
    return board;
}

vector<vector<char> >& create_map2(vector<vector<char> >& board){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i==0 && j==0){
                board[i][j]=' ';
            }
            else if(i==0){
                board[i][j]='a'+j-1;
            }
            else if(j==0){
                board[i][j]='1'+i-1;
            }
            else if((i<4 && j<4)||(i>6 && j<4)||(i<4 && j>6)||(i>6 && j>6)){
                board[i][j]=' ';
            }
            else if(i==5 && j==5){
                board[i][j]='.';
            }
            else{
                board[i][j]='P';
            }
        }
    }
    return board;
}

vector<vector<char> >& create_map3(vector<vector<char> >& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i==0 && j==0){
                board[i][j]=' ';
            }
            else if(i==0){
                board[i][j]='a'+j-1;
            }
            else if(j==0){
                board[i][j]='1'+i-1;
            }
            else if((i<4 && j<3)||(i>6 && j<3)||(i<4 && j>5)||(i>6 && j>5)){
                board[i][j]=' ';
            }
            else if(i==4 && j==4){
                board[i][j]='.';
            }
            else{
                board[i][j]='P';
            }
        }
    }
    return board;
}

vector<vector<char> >& create_map4(vector<vector<char> >& board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==0 && j==0){
                board[i][j]=' ';
            }
            else if(i==0){
                board[i][j]='a'+j-1;
            }
            else if(j==0){
                board[i][j]='1'+i-1;
            }
            else if((i<3 && j<3)||(i>5 && j<3)||(i<3 && j>5)||(i>5 && j>5)){
                board[i][j]=' ';
            }
            else if(i==4 && j==4){
                board[i][j]='.';
            }
            else{
                board[i][j]='P';
            }
        }
    }
    return board;
}

vector<vector<char> >& create_map5(vector<vector<char> >& board){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i==0 && j==0){
                board[i][j]=' ';
            }
            else if(i==0){
                board[i][j]='a'+j-1;
            }
            else if(j==0){
                board[i][j]='1'+i-1;
            }
            else if((((i+j)<6)||(i+j)>14)||((j>5)&&((j-i)>4))||((i>5)&&((i-j)>4))){
                board[i][j]=' ';
            }
            else if(i==5 && j==5){
                board[i][j]='.';
            }
            else{
                board[i][j]='P';
            }
        }
    }
    return board;
}

vector<vector<char> >& create_map6(vector<vector<char> >& board){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i==0 && j==0){
                board[i][j]=' ';
            }
            else if(i==0){
                board[i][j]='a'+j-1;
            }
            else if(j==0){
                board[i][j]='1'+i-1;
            }
            else if((i+j)<7){
                board[i][j]='P';
            }
            else {
                board[i][j]=' ';
            }
        }
    }
    board[1][1]='.';
    return board;
}

vector<vector<char> >& board_type_function(vector<vector<char> >& board,int board_type){
    if(board_type==1){
        vector<vector<char>> map1(8,vector<char>(8));
        board=create_map1(map1);
    }
    else if(board_type==2){
        vector<vector<char>> map2(10,vector<char>(10));
        board=create_map2(map2);
    }
    else if(board_type==3){
        vector<vector<char>> map3(9,vector<char>(9));
        board=create_map3(map3);
    }
    else if(board_type==4){
        vector<vector<char>> map4(8,vector<char>(8));
        board=create_map4(map4);
    }
    else if(board_type==5){
        vector<vector<char>> map5(10,vector<char>(10));
        board=create_map5(map5);
    }
    else if(board_type==6){
        vector<vector<char>> map6(6,vector<char>(6));
        board=create_map6(map6);
    }
    return board;
}

bool if_movelegal_doit(vector<vector<char> >& board,string move){
    int column=move[0]-64;//B
    int row=move[1]-'0';
    char direction=move[3];
    
    //cout<<column<<" "<<row<<" "<<direction<<" \n";
    if(direction=='L'){
        if(column<=2||board[row][column]!='P'){
            return false;
        }
        else if((board[row][column]=='P')&&(board[row][column-2]=='.')&&board[row][column-1]=='P'){
            board[row][column]='.';
            board[row][column-1]='.';
            board[row][column-2]='P';
            return true;
        }
    }
    else if(direction=='R'){
        if((column>=board.size()-2)||board[row][column]!='P'){
            return false;
        }
        else if((board[row][column]=='P')&&(board[row][column+2]=='.')&&board[row][column+1]=='P'){
            board[row][column]='.';
            board[row][column+1]='.';
            board[row][column+2]='P';
            return true;
        }
    }
    else if(direction=='U'){
        //cout<<"row"<<row<<"board.size"<<board.size()<<endl;
        if(row<3||board[row][column]!='P'){
            return false;
        }
        else if((board[row][column]=='P')&&(board[row-2][column]=='.')&&board[row-1][column]=='P'){
            board[row][column]='.';
            board[row-1][column]='.';
            board[row-2][column]='P';
            return true;
        }
    }
    else if(direction=='D'){
        //cout<<"row"<<row<<"board.size"<<board.size()<<endl;
        if((row+2)>=board.size()||board[row][column]!='P'){
            return false;
        }
        else if((board[row][column]=='P')&&(board[row+2][column]=='.')&&board[row+1][column]=='P'){
            board[row][column]='.';
            board[row+1][column]='.';
            board[row+2][column]='P';
            return true;
        }
    }
    return false;
}


bool are_there_move(vector<vector<char> > board){
    int flag=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]=='P'){
                if((j<board.size()-2)&&board[i][j+1]=='P'&&board[i][j+2]=='.'){
                    flag=1;
                    return true;
                }
                else if((j>2)&&board[i][j-1]=='P'&&board[i][j-2]=='.'){
                    flag=1;
                    return true;
                }
                else if(((i+2)<board.size())&&board[i+1][j]=='P'&&board[i+2][j]=='.'){
                    flag=1;
                    return true;
                }
                else if((i>=3)&&board[i-1][j]=='P'&&board[i-2][j]=='.'){
                    flag=1;
                    return true;
                }
            } 
        }
    }
    if(flag==0){return false;}  

}

string random_valid_move(vector<vector<char> >& board){
    srand((unsigned) time(NULL));
    string input;
    int raw,i,col,score;
    char direc;
    while(1){
    col=rand() % (board.size()-1) +1;
    raw=rand() % (board.size()-1) +1;
    i=rand()%4;
    if(i==0){direc='L';}else if(i==1){direc='R';}else if(i==2){direc='U';}else if(i==3){direc='D';}
      
    input.push_back(char(col+64));
    input.push_back(char(raw+48));
    input.push_back('-');
    input.push_back(direc);

    if((if_movelegal_doit(board,input)==true)){
        return input;
    }

    input.clear();

    }
    
}


int main(){

    vector<vector<char>> board;
    int board_type;
    char player_type;
    string input;
    cout << "Which type you want for your board (1-6).Please Enter.\n";
    cin >> board_type;
    cout << "Human player game or a computer game(h-c)\n";
    cin >> player_type;
    //board_type=6;
    //player_type='c';
    board =board_type_function(board,board_type);
    print_board(board);

    if(player_type=='h'||player_type=='H'){
        while((are_there_move(board)==true)){
        cout << "Please make a move like B4-R\n";
        cin >> input;

        if(if_movelegal_doit(board,input)==true) print_board(board);
           
        else cout << "Move is not legal.\n";    
        }
        final_score(board);   
    }
    else if(player_type=='C'|| player_type=='c'){
        do{
        input=random_valid_move(board);
        cout<<"Random valid move is :"<<input<<"\n";
        cout<<"-----------------------------------------------\n";
        print_board(board);
        cout<<"-----------------------------------------------\n";
        
        }while((are_there_move(board)==true));
        final_score(board);
    }
    return 0;
}
