//This is the header file pfarray.h. This is the interface for the class 
//PFArray. Objects of this type are partially filled arrays with base type T.
#ifndef PFARRAY_H
#define PFARRAY_H

#include <iostream>
#include <memory>

using namespace std;

namespace PFArraySavitch
{
    template<class T>
    class PFArray
    {
    public:
#pragma region Iterator

        class Iterator{
        private:
            T* m_ptr;
            
        public:
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::forward_iterator_tag;
            Iterator(){}
            Iterator(T* ptr): m_ptr(ptr){}
            //Iterator(Iterator&& other): m_ptr(other.m_ptr){}
            //T operator*() const{}
            T& operator*() const { return *this->m_ptr; }
            T* operator->() { return m_ptr; }

            // Prefix increment
            Iterator& operator++() { m_ptr++; return *this; }  
            Iterator& operator--() { m_ptr--; return *this; }  

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

            Iterator operator=(const Iterator& a){this->m_ptr=a.m_ptr; return *this; }
            //Iterator operator=(const Iterator&& other){this->m_ptr=other.m_ptr; return *this; }


            friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };   
            friend bool operator<(const Iterator& a, const Iterator& b) { return a.m_ptr < b.m_ptr; }
            friend bool operator>(const Iterator& a, const Iterator& b) { return a.m_ptr > b.m_ptr; }  
            friend bool operator<=(const Iterator& a, const Iterator& b) { return a.m_ptr <= b.m_ptr; }
            friend bool operator>=(const Iterator& a, const Iterator& b) { return a.m_ptr >= b.m_ptr; }
       
            //Iterator& operator+=(T x);
            //friend Iterator operator+(const Iterator& a , T x);
            //friend Iterator operator+(T x, const Iterator& a);
            //Iterator& operator-=(T x);  
            //friend Iterator operator-(const Iterator& a, T x);
            T& operator[](T x) const;

            friend difference_type operator-(Iterator a, Iterator b){ return a.m_ptr-b.m_ptr;}
        };

        PFArray<T>& erase(const Iterator& pointed){
            T* depo=new T[used];
            PFArray<T>::Iterator p;
            int k=0;

            for(p=begin();p!=end();p++){
                if(p!=pointed){
                    depo[k]=*p;
                    k++;
                }
            }
            delete [] a;
            this->used=used-1;
            this->a=depo;

            return *this;

        }

        void clear(){
            delete [] a;
            this->used=0;
            a=new T[used];
        }

        void empty(){
            if(a[0]==a[used]){
                std::cout<<"it is empty"<<endl;
            }
            else{
                std::cout<<"it is not empty"<<endl;
            }
        }
        
        int size(){
            return capacity;
        }
        
        void print(){
            for(auto x=begin();x!=end();x++){
                cout<< *x  << " ";
            } 
            cout<<endl;
        }
        
        Iterator begin() const { return Iterator(&a[0]); }

        Iterator end() const{ return Iterator(&a[used]); }
#pragma endregion 

#pragma region Constant_Iterator 
    //NORMAL ITERATORDAN TEK FARKI READONLY OLMASI YANI DEGISTIREMIYORUZ SONRADAN
        class Constant_Iterator{
        private:
            T* m_ptr;
            
        public:
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::forward_iterator_tag;
            Constant_Iterator(){ m_ptr = new T;}
            Constant_Iterator(T* ptr): m_ptr(ptr){}
            //~Iterator(){delete [] m_ptr;} // ITERATORLARLE DESTRUCTOR KULLANILMIYORMUS
            //2. BIR CLASS ACILACAK CONSTANT ITERATOR ICIN SIRF USTTEKI SATIR YUZUNDEN
            const T& operator*() { return *this->m_ptr; }
            T* operator->() { return m_ptr; }

            // Prefix increment
            Constant_Iterator& operator++() { m_ptr++; return *this; }  
            Constant_Iterator& operator--() { m_ptr--; return *this; }  

            // Postfix increment
            Constant_Iterator operator++(int) { Constant_Iterator tmp = *this; ++(*this); return tmp; }
            Constant_Iterator operator--(int) { Constant_Iterator tmp = *this; --(*this); return tmp; }

            friend bool operator== (const Constant_Iterator& a, const Constant_Iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const Constant_Iterator& a, const Constant_Iterator& b) { return a.m_ptr != b.m_ptr; };   

        };

        PFArray<T>& erase(const Constant_Iterator& pointed){
            T* depo=new T[used];
            PFArray<T>::Constant_Iterator p;
            int k=0;

            for(p=begin();p!=end();p++){
                if(p!=pointed){
                    depo[k]=*p;
                    k++;
                }
            }
            delete [] a;
            this->used=used-1;
            this->a=depo;

            return *this;

        }
           
        Constant_Iterator cbegin() const { return  Constant_Iterator(&a[0]) ; }

        Constant_Iterator cend() const { return  Constant_Iterator(&a[used])  ; }

#pragma endregion Constant
 
#pragma region pfarray things
        PFArray( ); //Initializes with a capacity of 50.

        PFArray(int capacityValue);

        PFArray(const PFArray<T>& pfaObject);

        void addElement(const T& element);
        //Precondition: The array is not full.
        //Postcondition: The element has been added.

        bool full( ) const; //Returns true if the array is full, false otherwise.

        int getCapacity( ) const;

        int getNumberUsed( ) const;

        void emptyArray( );
        //Resets the number used to zero, effectively emptying the array.

        T& operator[](int index);
        //Read and change access to elements 0 through numberUsed - 1.

        PFArray<T>& operator =(const PFArray<T>& rightSide);

        virtual ~PFArray( );

#pragma endregion
    private:
        T *a; //for an array of T.
        int capacity; //for the size of the array.
        int used; //for the number of array positions currently in use.
    };

}// PFArraySavitch
#endif //PFARRAY_H
