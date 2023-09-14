#ifndef _STRINGARRAYLIST_HPP
#define _STRINGARRAYLIST_HPP

#include <string>

using namespace std;

class StringArrayList {
    private :
        int numElements;
        int maxElements;
        string * list;

    public :
        StringArrayList ( int mxSz = 10);
        ~ StringArrayList ();
        bool add ( const string &s );
        bool add ( const int index , const string &s );
        int size () const ;
        int maxSize () const ;
        bool isEmpty () const ;
        bool isFull () const ;
        bool get ( const int index , string &s );
        bool set ( const int index , const string &s );
        bool remove ( const int index );
        bool contains ( const string & s );
        int indexOf ( const string &s );
        int indexOf ( int index , const string & s );
        void clear ();
        string str () const;
};
# endif