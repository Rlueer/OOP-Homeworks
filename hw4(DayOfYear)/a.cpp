#include <iostream>
#include <cstdlib>
#include <vector>
#include <initializer_list>
#include "abc.h"

using namespace std;
using namespace emre;

DayOfYearSet::DayOfYearSet(initializer_list<DayOfYear> a) {
    deneme=new DayOfYear[370];
    temp=new DayOfYear[370];
    count_ob=0;
    for(auto i : a){
        deneme[count_ob]=i;
        count_ob++;
    }
}
DayOfYearSet::DayOfYearSet(){
    count_ob=0;
    deneme=new DayOfYear[370];
    temp=new DayOfYear[370];  
};

#pragma region OPERATOR OVERLOADS

ostream& emre::operator<<(ostream& stream, const DayOfYearSet& set){
    if(set.count_ob==0){
        cout<<"EMPTY SET"<<endl;
    }
    for(int i=0;i<set.count_ob;i++){
        stream<<i+1<<". element of set : {" <<set.deneme[i].getDay()<<","<<set.deneme[i].getMonthNumber()<<"}"<<endl;  
    }
        return stream;
};
DayOfYearSet& emre::operator+(DayOfYearSet& set,DayOfYearSet::DayOfYear& element){
    int flag=0;
    for(int x=0;x<set.count_ob;x++){
        if(set.deneme[x].getDay()==element.getDay() && set.deneme[x].getMonthNumber()==element.getMonthNumber()){
            flag=1;
            break;
        }
    }
    if(flag==0){    // EGER HIC AYNI ELEMAN YOKSA EKLE 
        set.deneme[set.count_ob].set(element.getMonthNumber(),element.getDay());
        set.count_ob++;
        return set;
    }
    else{   // EGER AYNI ELEMANDAN VARSA FLAG=1 OLUR SO HICBISEY YAPMA
        return set;
    }
    
};
DayOfYearSet& emre::operator-(DayOfYearSet& set,DayOfYearSet::DayOfYear& element){/// REMOVES element and RETURN TEMP_SET
    int a=0;
    for(int i=0;i<set.count_ob;i++){    
        if(set.deneme[i].getDay()==element.getDay() && set.deneme[i].getMonthNumber()==element.getMonthNumber()){}
        else{
            set.temp[a]=set.deneme[i];
            a++;
        }
    }
    set.deneme=set.temp;   
    set.count_ob--;
    return set;
};
bool emre::operator==(const DayOfYearSet& set1,const DayOfYearSet& set2){
    int counter=0;
    int max_element=set1.count_ob;
    if(set1.count_ob!=set2.count_ob){
        return false;
    }
    for(int i=0;i<max_element;i++){
        for(int j=0;j<max_element;j++){
            if(set1.deneme[i].getDay()==set2.deneme[j].getDay() && set1.deneme[i].getMonthNumber()==set2.deneme[j].getMonthNumber()){
                counter++;
            }
        }
    }
    if(counter==max_element){
        return true;
    }
    else{
        return false;
    }
}
bool emre::operator!=(const DayOfYearSet& set1,const DayOfYearSet& set2){
    int counter=0;
    int max_element=set1.count_ob;
    if(set1.count_ob!=set2.count_ob){
        return true;
    }
    for(int i=0;i<max_element;i++){
        for(int j=0;j<max_element;j++){
            if(set1.deneme[i].getDay()==set2.deneme[j].getDay() && set1.deneme[i].getMonthNumber()==set2.deneme[j].getMonthNumber()){
                counter++;
            }
        }
    }
    if(counter==max_element){
        return false;
    }
    else{
        return true;
    }
}
DayOfYearSet& emre::operator+(DayOfYearSet& set1,DayOfYearSet& set2){  
    vector <int> index_y;
    int flag=0;
    for(int x=0;x<set1.count_ob;x++){
        for(int y=0;y<set2.count_ob;y++){
            if(set1.deneme[x].getDay()==set2.deneme[y].getDay() && set1.deneme[x].getMonthNumber()==set2.deneme[y].getMonthNumber()){
                index_y.push_back(y);
                /*cout<<"x "<<x<<"y "<<y<<endl;  
                cout<<"index y"<<index_y<<endl;*/
                break;
            }
        }
    }
    for(int i=0;i<set2.count_ob;i++){//BURADA ÖNCE EKLEYECEGIMIZ SETIN SET1DE OLUP OLMADIGINA BAKIYORUZ    
        for(int j=0;j<index_y.size();j++){  // VARSA EKLEMIYOR FLAG 1 YAPARAK 
            if(i==index_y[j]){  
                flag=1;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==1){
            // PASS GEC
        }
        else{
        set1.deneme[set1.count_ob].set(set2.deneme[i].getMonthNumber(),set2.deneme[i].getDay());   
        set1.count_ob++;
        }   
    }
    return set1;
}
DayOfYearSet& emre::operator-(DayOfYearSet& set1,DayOfYearSet& set2){ 
    vector <int> index_y;
    int flag=0;
    for(int x=0;x<set1.count_ob;x++){
        for(int y=0;y<set2.count_ob;y++){
            if(set1.deneme[x].getDay()==set2.deneme[y].getDay() && set1.deneme[x].getMonthNumber()==set2.deneme[y].getMonthNumber()){
                index_y.push_back(y);
                break;
            }
        }
    }
    for(int i=0;i<set2.count_ob;i++){//BURADA ÖNCE EKLEYECEGIMIZ SETIN SET1DE OLUP OLMADIGINA BAKIYORUZ    
        for(int j=0;j<index_y.size();j++){  // VARSA EKLEMIYOR FLAG 1 YAPARAK 
            if(i==index_y[j]){  
                flag=1;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==1){
            set1-set2.deneme[i];
        }
        else{
        }   
    }
    return set1;
}
DayOfYearSet& emre::operator^(DayOfYearSet& set1,DayOfYearSet& set2){//RETURNS SET1
    vector <int> index_y;
    int flag=0;
    int temp_count=0;
    for(int x=0;x<set1.count_ob;x++){
        for(int y=0;y<set2.count_ob;y++){
            if(set1.deneme[x].getDay()==set2.deneme[y].getDay() && set1.deneme[x].getMonthNumber()==set2.deneme[y].getMonthNumber()){
                index_y.push_back(y);
                break;
            }
        }
    }
    for(int i=0;i<set2.count_ob;i++){
        for(int j=0;j<index_y.size();j++){ 
            if(i==index_y[j]){  
                flag=1;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==1){
            set1.temp[temp_count]=set2.deneme[i];
            temp_count++;
        }
        else{
        }   
    }
    set1.deneme=set1.temp;
    set1.count_ob=temp_count;

    return set1;
}
DayOfYearSet& emre::operator!(DayOfYearSet& set){
    int months[]={32,29,32,31,32,31,32,32,31,32,31,32}; // +1 hali cunku asagida sorun cikariyor
    int deneme_count=set.count_ob;
    set.count_ob=0;
    for(int i=1;i<13;i++){
        for(int j=1;j<months[i-1];j++){
            set.temp[set.count_ob].set(i,j);
            set.count_ob++;
        }       
    }
    DayOfYearSet::DayOfYear x[deneme_count];
    for(int i=0;i<deneme_count;i++){
        x[i]=set.deneme[i];
    }
    set.deneme=set.temp;
    for(int i=0;i<deneme_count;i++){
        set.remove(x[i]);
    }
    return set;
}
DayOfYearSet::DayOfYear& DayOfYearSet::operator[](int index){// operator[] diye bir sey algılamiyor visual studio o yüzden operator| kullaniyorum
    
    this->temp[0].set(deneme[index].getMonthNumber(),deneme[index].getDay());
    return temp[0];
}

#pragma endregion 

#pragma region  DAYOFYEAR CLASS
DayOfYearSet::DayOfYear::DayOfYear(int dday,int mmonth){
    int month_max_day[]={31,28,31,30,31,30,31,31,30,31,30,31}; 
    if((mmonth)>0 && (mmonth)<13){
        month=mmonth;
    }
    else
    {
        cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
    if ((dday> 0) && (dday <= month_max_day[mmonth-1]))
        day = dday;
    else
    {
        cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
};
DayOfYearSet::DayOfYear::DayOfYear() : day(1),month(1){};
DayOfYearSet::DayOfYear::DayOfYear(const DayOfYear& n){ // copy constructor
    day=n.day;
    month=n.month;
}; 

void DayOfYearSet::DayOfYear::set(int newMonth, int newDay){
    if((newMonth)>0 && (newMonth)<13){
        month=newMonth;
    }
    else
    {
        cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
    if ((newDay > 0) && (newDay < 32))
        day = newDay;
    else
    {
        cout << "Illegal day value! Program aborted.\n";
        exit(1);
    }
};
void DayOfYearSet::DayOfYear::set(int newMonth){
    if((newMonth)>0 && (newMonth)<13){
        month=newMonth;
    }
    else
    {
        cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
    day=1;

};

int DayOfYearSet::DayOfYear::getMonthNumber( )
{
    return month;
}
int DayOfYearSet::DayOfYear::getDay( )
{
    return day;
}

void DayOfYearSet::DayOfYear::input(){ 
    cout<< "Enter day's date ";
    cin>> day;
    while(!(day>0 && day<32)){
        cin.clear();
        cin.ignore();
        cout<< "Error! enter day's date again ";
        cin>> day;
    }
    cout<< "Enter month as a number ";
    cin>> month;
    while(!(month>0 && month<13)){
        cin.clear();
        cin.ignore();
        cout<< "Error! enter month's date again ";
        cin>> month;
    }
}
void DayOfYearSet::DayOfYear::output()const{

    cout<< "Today's date is ";
    
    switch(month){

        case 1:
            cout<< "January "<<day<<endl; break;
        case 2:
            cout<< "February "<<day<<endl; break;
        case 3:
            cout<< "March "<<day<<endl; break;
        case 4:
            cout<< "April "<<day<<endl; break;
        case 5:
            cout<< "May "<<day<<endl; break;
        case 6:
            cout<< "June "<<day<<endl; break;
        case 7:
            cout<< "July "<<day<<endl; break;
        case 8:
            cout<< "August "<<day<<endl; break;
        case 9:
            cout<< "September "<<day<<endl; break;
        case 10:
            cout<< "October "<<day<<endl; break;
        case 11:
            cout<< "November "<<day<<endl; break;
        case 12:
            cout<< "December "<<day<<endl; break;
        default:
            cout << "Error "; break;
    }
}

DayOfYearSet::DayOfYear DayOfYearSet::DayOfYear::nextDay()const{
    DayOfYear next;
    int month_maxday[]={31,29,31,30,31,30,31,31,30,31,30,31};
    if(day==month_maxday[month-1]){
        next.day=1;
        next.month=(month+1)%12;
    }
    else{
        next.day=day+1;
        next.month=month;
    }
    return next;
};

bool DayOfYearSet::DayOfYear::equals(const DayOfYear &other)const{
    if(day==other.day && month==other.month){
        return true;
    }
    else{
        return false;
    }

} 
bool DayOfYearSet::DayOfYear::lessThen(const DayOfYear &other)const{
    if(month <other.month ){
        return true;
    }
    else if ( month==other.month && day<other.day){
        return true;
    }
    else{
        return false;
    }
}
#pragma endregion

#pragma region DAYOFYEARSET CLASS

void DayOfYearSet::remove(DayOfYear& element){ // REMOVES element and RETURN TEMP_SET   
    int a=0;
    for(int i=0;i<count_ob;i++){    
        if(deneme[i].getDay()==element.getDay() && deneme[i].getMonthNumber()==element.getMonthNumber()){}
        else{
            temp[a]=deneme[i];
            a++;
        }
    }
    deneme=temp;
    count_ob--;
};

int DayOfYearSet::size(){
    return count_ob;
}

#pragma endregion

