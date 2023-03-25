#include <iostream>
#include <ctime>    // for generating a random seed
#include <cstdlib>   // for generating random numbers
#include <string>   // for string manipulation

using namespace std;

// Function to generate a random number with distinct digits
int random_valid_number(int digit){
    int numbers[10]={0,1,2,3,4,5,6,7,8,9};
    int r_number[digit],index=0;
    int n_return=0,a=1;
    int ran=rand()%10;
    // Loop to ensure the generated number has distinct digits
    for(int i=0;i<digit;i++){
        while(numbers[index]<0 || i==index){ // if the digit has been used or has already been assigned, find another number
        index=rand()%10;
        }
        r_number[i]=numbers[index];
        numbers[index]=-1;  // set the assigned digit to -1 for used ones
    }
    
    for(int i=digit-1;i>=0;i--){ // convert array to integer value for return
        n_return+=r_number[i]*a;
        a=a*10;
    } 

    return n_return;
}
// Function to compare the secret number and user number
bool compare_numbers(int secret_number,int user_number,int digit){
    int C_exact=0,C_misplaced=0;
    string secret=to_string(secret_number);
    string user=to_string(user_number);
    if(secret_number==user_number)return true;// if the secret number and user number are the same, return true
    else if(secret_number!=user_number){
        // Loop to count the number of exact matches and misplaced digits
        for(int i=0;i<digit;i++){
            if(secret[i]==user[i])C_exact++; // count the C_exact matches
            for(int j=0;j<digit;j++){// count the C_misplaced digits
                if(secret[i]==user[j] && secret[j]!=user[j]) C_misplaced++;  //                         
            }
        }
        cout<<C_exact<<" "<<C_misplaced<<endl;
    }
        return false;
}
//find the number of digits in a given number
int find_digit(int number){
    int temp=number,digit=1;
    while(temp>9){
        temp=temp/10;
        digit++;
    }
    return digit;
}
//check if a given string is an integer
bool is_it_integer(string user_number){
    int counter=0; 
    string numbers={"0123456789"};
    for(auto i: user_number){
        for(auto j: numbers){
            if(i==j){
                counter++;
            }
        }
        if(counter!=1) return false;
        else counter=0;    
    }
    return true;
}

//check if a given string is an integer and returns integer version of it
int int_cin_check(string user_number){  
    if(is_it_integer(user_number))return stoi(user_number);
    else cerr<<"E2\n";exit(1);//E2 ERROR
}
// Function for the mastermind game
void mastermind(string player,int digit){
    int secret_number,user_number,iteration=0,i_user_number;
    string s_user_number,temp;
    srand(time(NULL));rand();// generate a random seed , warm up

    if(player=="-r")    secret_number=random_valid_number(digit);
    else if(player=="-u"){
        secret_number=digit;
        digit=find_digit(secret_number);
    }
    //cout<<"generated secret number is "<<secret_number<<endl;   // for debug

    do{
        iteration++;
        cin>>s_user_number;
        i_user_number=int_cin_check(s_user_number);  // check if s_user_number is an integer; E2 ERROR if not

        if(player=="-r" && find_digit(i_user_number)!=digit){ // E1 ERROR if the number of digits is not the same
            cerr<<"E1\n";exit(1);}     
        if(player=="-u" && find_digit(secret_number)!=find_digit(i_user_number)){ // E1 ERROR if the number of digits is not the same
            cerr<<"E1\n";exit(1);}
    
        if(iteration==100){cout<<"FAILED\n";exit(1);}// Fail if the user has not guessed the secret number within 100 iterations
          
    }while(false==compare_numbers(secret_number,i_user_number,digit));// Repeat the loop until the user guesses the correct number
    // The user has correctly guessed the secret number. Print the number of iterations it took to guess.
    if(true==compare_numbers(secret_number,i_user_number,digit)){
        cout<<"FOUND "<<iteration<<endl;
        exit(1);
    }
}

int main(int argc, char** argv){
    int digit;
    if(argv[1]==NULL || argv[2]==NULL){cerr<<"E0\n";exit(1);}//E0 ERROR
    string arg1=string(argv[1]);
    string arg2=string(argv[2]);
    if((arg1=="-r" || arg1=="-u") && arg2.size()==0){cerr<<"E0\n";exit(1);}//E0 ERROR
    if(arg1!="-r" && arg1!="-u"){cerr<<"E0\n";exit(1);} //E0 ERROR
    if(is_it_integer(arg2)!=true){cerr<<"E2\n";exit(1);}  //E2 ERROR
    if(arg1=="-r" && (stoi(argv[2])>9 || stoi(argv[2])<1 || stoi(argv[2])==0)){cerr<<"E0\n";exit(1);}//E0 ERROR
    
    if(arg1=="-u" ){
        if(arg2.size()<1 || arg2.size()>9){ cerr<<"E0\n"; exit(1);}//E0 ERROR

        int_cin_check(argv[2]);// E2 ERROR
        
        digit=find_digit(stoi(argv[2]));
        for(int i=0;i<digit;i++){       
            for(int j=0;j<digit;j++){
                if(arg2[i]==arg2[j] && i!=j){cerr<<"E0\n"; exit(1);}  // E0 ERROR     
            }
        }
    }
    mastermind(arg1,stoi(argv[2]));

    return 1;
}