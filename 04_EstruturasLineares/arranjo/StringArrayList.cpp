#include <sstream>
#include "StringArrayList.hpp"

StringArrayList::StringArrayList(int mxSz){
    maxElements = (mxSz <= 0)? 10 : mxSz;
    list = new string[maxElements];
    numElements = 0;

}

StringArrayList::~StringArrayList (){
    delete[] list;
}

bool StringArrayList::add ( const string &s ){
    if(numElements >= maxElements) return false;
    list[numElements++] = s;
    return true;
}

bool StringArrayList::add ( const int index , const string &s ){
    if(numElements >= maxElements) return false;

    for(int i = numElements; i > index; --i){
        list[i] = list[i -1];
    }

    list[index] = s;

    numElements++;
    return true;
}

int StringArrayList::size () const{
    return numElements;
}

int StringArrayList::maxSize () const{
    return maxElements;
}

bool StringArrayList::isEmpty () const{
    return numElements == 0;
}

bool StringArrayList::isFull () const{
    return numElements == maxElements;
}

bool StringArrayList::get ( const int index , string &s ){
    if(index < 0 || index >= numElements) return false;
    s = list[index];
    return true;
}

bool StringArrayList::set ( const int index , const string &s ){
    if( index < 0 || index >= numElements) return false;

    list[index] = s;

    return true;
}

bool StringArrayList::remove ( const int index ){
    if( index < 0 || index >= numElements) return false;

    for(int i = index; i < numElements; ++i){
        list[i] = list[i + 1];
    }

    numElements--;

    return true;
}

bool StringArrayList::contains ( const string & s ){
    for(int i = 0; i < numElements; ++i){
        if(s == list[i]){
            return true;
        }
    }
    return false;
}

int StringArrayList::indexOf ( const string &s ){
   return indexOf(0, s);
}

int StringArrayList::indexOf ( int index , const string & s ){
    for(int i = index; i < numElements; ++i){
        if(s == list[i]){
            return i;
        }
    }
    return -1;
}

void StringArrayList::clear (){
    for(int i = 0; i < numElements; ++i){
        list[i] = "";
    }
    numElements = 0;
}

string StringArrayList::str () const{
    stringstream ss;

    for( int i = 0; i< numElements; ++i){
        ss << list[i];
    }

    return ss.str();
}