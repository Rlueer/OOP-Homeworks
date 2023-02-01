#include <iostream>
#include <cstdlib>
#include <vector>
#include <initializer_list>

#ifndef _abc_HPP_
#define _abc_HPP_

using namespace std;

namespace emre{
    
class DayOfYearSet {

    public:
    class DayOfYear{
    public:
        DayOfYear();
        DayOfYear(int dday,int mmonth);
        DayOfYear(const DayOfYear& n);

        void input();
        void output()const;

        void set(int newMonth, int newDay); //Precondition: newMonth and newDay form a possible date.
        void set(int newMonth); //Precondition: 1 <= newMonth <= 12
        //Postcondition: The date is set to the first day of the given month.
        int getMonthNumber( ); //Returns 1 for January, 2 for February, etc.
        int getDay( );

        bool equals(const DayOfYear &other)const;
        bool lessThen(const DayOfYear &other)const;
        DayOfYear nextDay()const;
       
    private:
        int month;
        int day;
    };
    private:
    DayOfYear* deneme;
    DayOfYear* temp;
    int count_ob;

    public:
    DayOfYearSet(initializer_list<DayOfYear> a);
    DayOfYearSet();
    
    void remove(DayOfYear& element);
    int size();

    friend ostream& operator<<(ostream& stream, const DayOfYearSet& set);
    friend DayOfYearSet& operator+(DayOfYearSet& set,DayOfYear& element);
    friend DayOfYearSet& operator-(DayOfYearSet& set,DayOfYear& element);
    friend bool operator==(const DayOfYearSet& set1,const DayOfYearSet& set2);
    friend bool operator!=(const DayOfYearSet& set1,const DayOfYearSet& set2);
    friend DayOfYearSet& operator+(DayOfYearSet& set1,DayOfYearSet& set2);
    friend DayOfYearSet& operator-(DayOfYearSet& set1,DayOfYearSet& set2);
    friend DayOfYearSet& operator^(DayOfYearSet& set1,DayOfYearSet& set2);
    friend DayOfYearSet& operator!(DayOfYearSet& set);
    DayOfYear& operator[](int index);
    // operator[] diye bir sey algılamiyor visual studio o yüzden operator| kullaniyorum
};

}

#endif /* _TETROMINO_HPP_ */