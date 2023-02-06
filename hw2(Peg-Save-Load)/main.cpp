 
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;
using std::ofstream;

void print_board(vector<vector<char> > board){
    vector<vector<char> > temp_board(board.size()+1,vector<char> (board.size()+1));

    for(int i=0;i<board.size()+1;i++){
        for(int j=0;j<board.size()+1;j++){
            if(i==0 && j==0){
                temp_board[i][j]=' ';
            }
            else if(i==0){
                temp_board[i][j]='a'+j-1;
            }
            else if(j==0){
                temp_board[i][j]='1'+i-1;
            }
            else if(i!=0 && j!=0){
            temp_board[i][j]=board[i-1][j-1];
            }
        }
    }

    for(int i=0;i<temp_board.size();i++){
        for(int j=0;j<temp_board.size();j++){
            cout<<temp_board[i][j];
        }
        cout<<endl;
    }
}

/*void print_board(vector<vector<char> > board,int board_row,int board_col){
    vector<vector<char> > temp_board(board_row,vector<char> (board_col));

    cout<<"girdiiiiii\n\n";
    for(int i=0;i<board_row+1;i++){
        for(int j=0;j<board_col+1;j++){
            if(i==0 && j==0){
                temp_board[i][j]=' ';
            }
            else if(i==0){
                temp_board[i][j]='a'+j-1;
            }
            else if(j==0){
                temp_board[i][j]='1'+i-1;
            }
            else if(i!=0 && j!=0){
            temp_board[i][j]=board[i-1][j-1];
            }
        }
    }

    for(int i=0;i<board_row+1;i++){
        for(int j=0;j<board_col+1;j++){
            cout<<temp_board[i][j];
        }
        cout<<endl;
    }
}*/


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
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if((i==1 && j==1)||(i==5 && j==5)||(i==1 && j==5)||(i==5 && j==1)){
                board[i][j]='P';
            } 
            else if((i<2 && j<2)||(i>4 && j<2)||(i<2 && j>4)||(i>4 && j>4)){
                board[i][j]=' ';
            }
            else if(i==2 && j==3){
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
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if((i<3 && j<3)||(i>5 && j<3)||(i<3 && j>5)||(i>5 && j>5)){
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

vector<vector<char> >& create_map3(vector<vector<char> >& board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i<3 && j<2)||(i>5 && j<2)||(i<3 && j>4)||(i>5 && j>4)){
                board[i][j]=' ';
            }
            else if(i==4 && j==3){
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
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if((i<2 && j<2)||(i>4 && j<2)||(i<2 && j>4)||(i>4 && j>4)){
                board[i][j]=' ';
            }
            else if(i==3 && j==3){
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
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if((((i+j)<4)||(i+j)>12)||((j>4)&&((j-i)>4))||((i>4)&&((i-j)>4))){
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

vector<vector<char> >& create_map6(vector<vector<char> >& board){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((i+j)<5){
                board[i][j]='P';
            }
            else {
                board[i][j]=' ';
            }
        }
    }
    board[0][0]='.';
    return board;
}

vector<vector<char> >& board_type_function(vector<vector<char> >& board,int board_type){
    if(board_type==1){
        vector<vector<char>> map1(7,vector<char>(7));
        board=create_map1(map1);
    }
    else if(board_type==2){
        vector<vector<char>> map2(9,vector<char>(9));
        board=create_map2(map2);
    }
    else if(board_type==3){
        vector<vector<char>> map3(8,vector<char>(8));
        board=create_map3(map3);
    }
    else if(board_type==4){
        vector<vector<char>> map4(7,vector<char>(7));
        board=create_map4(map4);
    }
    else if(board_type==5){
        vector<vector<char>> map5(9,vector<char>(9));
        board=create_map5(map5);
    }
    else if(board_type==6){
        vector<vector<char>> map6(5,vector<char>(5));
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
        if(column<2||board[row][column]!='P'){
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
        if(row<2||board[row][column]!='P'){
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
                if(((j+2)<board.size())&&board[i][j+1]=='P'&&board[i][j+2]=='.'){
                    flag=1;
                    return true;
                }
                else if((j>1)&&board[i][j-1]=='P'&&board[i][j-2]=='.'){
                    flag=1;
                    return true;
                }
                else if(((i+2)<board.size())&&board[i+1][j]=='P'&&board[i+2][j]=='.'){
                    flag=1;
                    return true;
                }
                else if((i>1)&&board[i-1][j]=='P'&&board[i-2][j]=='.'){
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
    col=rand() % (board.size()) ;
    raw=rand() % (board.size()) ;
    i=rand()%4;
    if(i==0){direc='L';}else if(i==1){direc='R';}else if(i==2){direc='U';}else if(i==3){direc='D';}
      
    input.push_back(char(col+64));
    input.push_back(char(raw+48));
    input.push_back('-');
    input.push_back(direc);

    if((if_movelegal_doit(board,input)==true)){return input;}
    input.clear();
        
    }
}

vector<vector<char> > loadgame(int& numberofmove,char& player_type,int& board_size){
    ifstream file("save.txt");
    //cout<<"loadgame\n";
    //int board_row=0;
    //int board_col=0;
    string lastline,s_number,s_player,s_board,line;
    while(!file.eof()){
        //board_row++;
        getline(file,lastline);
    }
    file.close();

    //board_col=lastline.size();
    //cout<<board_row<<" "<<board_col<<"\n\n";

    //SIMDILIK BUNU YAPAMIYORUZ CUNKU SUANA KADAR KI TUM KODDA BOARDI KARE OLARAK ALDIK 
    // O YUZDEN COK ISLEM DEGISIKLIGI GEREKIYOR AMELELIK SADECE BILGI ICERMIYOR O YUZDEN YAPMIYORUM  
    /*for(int i=0;i<lastline.size();i++){

        if(lastline[i]=='P'){
            numberofmove=0;
            cout<<"For the loaded game is player h or c?\n";
            cin>>player_type;
            ifstream file2("save.txt");
        vector<vector<char> >board(board_row,vector<char> (board_col));
        for(int i=0;i<board_row;i++){
            getline(file2,line);
            for(int j=0;j<board_col;j++){
                board[i][j]=line[j];
            }
        }
        print_board(board);
        file2.close();
        return board;
        }
    }
    */
    
    if(lastline[1]==' '){
    numberofmove=lastline[0]-'0';
    player_type=lastline[1];
        if(lastline[5]==' '){//1 c 8
            board_size=lastline[4]-'0';
        }
        else if(lastline[6]==' '){//1 c 18
        board_size=(lastline[4]-'0')*10+(lastline[5]-'0');
        }
    }
    else if(lastline[2]==' '){
    numberofmove=(lastline[0]-'0')*10+(lastline[1]-'0');
    player_type=lastline[3];
        if(lastline[6]==' '){   //14 c 8
        board_size=lastline[5]-'0';
        }
        else if(lastline[7]==' '){  //14 c 18
            board_size=(lastline[5]-'0')*10+(lastline[6]-'0');
        }
    }

    //cout<<numberofmove<<" "<<player_type<<" "<<board_size<<endl;

    ifstream file2("save.txt");
    vector<vector<char> >board(board_size,vector<char> (board_size));
    for(int i=0;i<board.size();i++){
        getline(file2,lastline);
        for(int j=0;j<board.size();j++){
            board[i][j]=lastline[j];
        }
    }
    print_board(board);
    file2.close();
    return board;

}


void savegame(vector<vector<char> > board,int numberofmove,char player_type){
    ofstream file("save.txt");
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            file<<board[i][j];
        }
        file<<'\n';
    }
    file<<numberofmove<<" "<<player_type<<" "<<board.size()<<" ";
    file.close();

}   

int main(){

    vector<vector<char>> board;
    int board_type,numberofmove=0,board_size;
    char player_type;
    string input;
    cout << "Which type you want for your board (1-6).(0 for load game)\n";
    cin >> board_type;
    //board_type=0; 
    if(board_type==0){
        board=loadgame(numberofmove,player_type,board_size);
        //cout<<"INSIDE LOADGAME\n";
        getchar();
        if(player_type=='h'||player_type=='H'){
        while((are_there_move(board)==true)){
        cout << "Please make a move like B4-R\n";
        getline(cin,input);
        if(input=="SAVE"){
            savegame(board,numberofmove,player_type);
            cout<<"Game Saved!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        }
        else if(if_movelegal_doit(board,input)==true) {
            numberofmove++;
            cout<<"After "<<numberofmove<<". move board :\n";
            print_board(board);
        }
        else cout << "Move is not legal.\n";    
        }
        final_score(board);   
        }
        else if(player_type=='C'|| player_type=='c'){
        do{
        string what_next;
        cout<<"Press Enter for next move.\n";
        getline(cin,what_next);
        
        if(what_next=="SAVE"){
            savegame(board,numberofmove,player_type);
            cout<<"GAME SAVED!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            continue;
        }
       else if(what_next!="SAVE"){
            
        numberofmove++;
        input=random_valid_move(board);
        cout<<numberofmove<<"."<<"Random valid move is :"<<input<<"\n";
        cout<<"-----------------------------------------------\n";
        print_board(board);
        cout<<"-----------------------------------------------\n";
            
        }    
        }while((are_there_move(board)==true));
        final_score(board);
    }   
    }
    else{
    board =board_type_function(board,board_type);
    print_board(board);
    
    cout << "Human player game or a computer game(h-c)\n";
    cin >> player_type;
    //player_type='c';
    getchar();

    if(player_type=='h'||player_type=='H'){
        while((are_there_move(board)==true)){
        cout << "Please make a move like B4-R\n";
        getline(cin,input);
        if(input=="SAVE"){
            savegame(board,numberofmove,player_type);
            cout<<"Game Saved!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        }
        else if(if_movelegal_doit(board,input)==true) {
            numberofmove++;
            cout<<"After "<<numberofmove<<". move board :\n";
            print_board(board);
        }
        else cout << "Move is not legal.\n";    
        }
        final_score(board);   
    }
    else if(player_type=='C'|| player_type=='c'){
        int numberofmove=0;
        do{
        string what_next;
        cout<<"Press Enter for next move.\n";
        getline(cin,what_next);
        
        if(what_next=="SAVE"){
            savegame(board,numberofmove,player_type);
            cout<<"GAME SAVED!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            continue;
        }
        else if(what_next!="SAVE"){
            
        numberofmove++;
        input=random_valid_move(board);
        cout<<numberofmove<<"."<<"Random valid move is :"<<input<<"\n";
        cout<<"-----------------------------------------------\n";
        print_board(board);
        cout<<"-----------------------------------------------\n";
            
        }    
        }while((are_there_move(board)==true));
        final_score(board);
    }   
    
    }
    system("pause"); 
    return 0;
}
