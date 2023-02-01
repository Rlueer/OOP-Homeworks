#include "abc.h"
#include "a.cpp"

using namespace emre;

int main(){

    DayOfYearSet::DayOfYear d10,d1(11,11),d2(22,11),d3(23,10),d4(24,9),d5(25,8),d6(31,12),d7(1,1),d8(2,2);

    DayOfYearSet set1({d2,d3,d4});
    DayOfYearSet set2({d1,d2,d3});
    DayOfYearSet set3({d4,d5,d6});
    DayOfYearSet set4;


    set1=set1-d3;
    cout<<set1<<endl;
    set1.remove(d4);
    cout<<set1<<endl;
    set1=set1+d1;
    cout<<set1<<endl;
    set1^set2;
    cout<<set1<<endl;
    set1=set1+d3;

    d10=set3[1];
    set4=set4+ d10;

    set4= !set4;

    cout<<"++++++++++++++++++++++\n";

    cout<<set1;

    return 0;
}