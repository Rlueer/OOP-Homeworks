
#include <iostream>
#include "pfarray.h"
#include "pfarray.cpp"
#include <algorithm>


using namespace std;
using namespace PFArraySavitch;


void printx3(char a)
{
    cout << a <<a <<a << " "<<endl;
}

int main(){
    
/*
    PFArray<char> integers(10);

    integers.addElement('i');
    integers.addElement('p');
    integers.addElement('x');
    integers.addElement('c');

    auto a=integers.begin();
    cout<<"a is "<<*a<<endl;
    integers.print();   


    cout<<"***************"<<endl;

    integers.erase(a);
    a=integers.begin();
    cout<<"a is "<<*a<<endl;
    integers.print(); 
    cout<<"22---------------\n";
    integers.erase(a);
    a=integers.begin();
    cout<<"a is "<<*a<<endl;
    integers.print();
    cout<<"33---------------\n";

    integers.clear();
    integers.empty();

    integers.print();

    cout<<"44---------------\n";

    integers.addElement('2');
    integers.addElement('x');
    integers.addElement('a');

    integers.empty();

    integers.erase(++integers.begin());
    integers.print();

    cout<<"55-----**************----------\n";

    auto z=++integers.cbegin();

    cout<<*z<<endl;

    auto lstConstIter = integers.cbegin();
    while (lstConstIter != integers.cend())
    {
        // Cannot assign
        *lstConstIter = 'a';
        lstConstIter++;
    }
    integers.print();
    cout<<"66-----**************----------\n";
    auto alstConstIter = integers.begin();
    while (alstConstIter != integers.end())
    {
        *alstConstIter = 'g'+5;
        alstConstIter++;
    }
    integers.print();
    
    cout<<"77-----**************----------\n";
    integers.erase(++integers.begin());

    integers.print();
    cout<<"88-----**************----------\n";
*/
    PFArray<int> sayilar(10);

    sayilar.addElement(55);
    sayilar.addElement(3);
    sayilar.addElement(111);
    sayilar.addElement(18);
    sayilar.addElement(1558);
    sayilar.addElement(12);

    //sayilar.print();

    auto i=find(sayilar.begin(),sayilar.end(),111);
    //if(i!=sayilar.end()){cout<<"there is  "<<*i<<" in sayilar"<<endl;}
    //else{cout<<"there is no number like that "<<endl;}  
    
    PFArray<char> harfler(10);
    harfler.addElement('x');
    harfler.addElement('y');

    //for_each(harfler.begin(),harfler.end(),printx3);

    //sort(sayilar.begin(),sayilar.end());
    sayilar.print();   

    auto g = (sayilar.begin()<=sayilar.begin());
    cout<< g<<endl;
    
    auto j = sayilar.end()-sayilar.begin();
    cout<< j<<endl;

}
