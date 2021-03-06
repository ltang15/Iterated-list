//
// Created by tangb on 4/21/2020.
//

#ifndef ITERATOR_LIST_H
#define ITERATOR_LIST_H

#include <iostream>
#include <cassert>
#include "node.h"
using namespace std;

template <class T>
class List {
public:

    class Iterator {

    public:
        friend class List;
        Iterator next()                     //return an iterator to the
        {                                   //  next location in the list
            return Iterator(_ptr ->_next);
        }

        Iterator(node <T> *p = NULL) : _ptr(p) {}     //ctor

        T &operator*() {                    //dereference oprator
            assert(_ptr);
            return _ptr ->_item;
        }

        const T& operator *()const {        //dereference oprator
            assert(_ptr);
            return _ptr ->_item;
        }
        T* operator ->(){                    //member access operator
            assert(_ptr);
            return &(_ptr ->_item);
        }

        const T* operator ->()const{
            assert(_ptr);
            return &(_ptr ->_item);
        }
        friend bool operator !=(const Iterator& left, const Iterator& right){        //true if left != right
            return left._ptr  != right._ptr ;
        }

        friend bool operator ==(const Iterator& left, const Iterator& right){        //true if left == right
            return left._ptr  == right._ptr ;
        }
        friend  Iterator operator ++(Iterator& it, int unused){              //friend operator: it++
            Iterator hold;
            hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

        Iterator& operator ++(){                       //member operator: ++it; or ++it = new_value
            _ptr = _ptr ->_next;
            return *this;
        }
        bool is_null(){                                  //true if _ptr is NULL
            return _ptr = NULL;
        }

    private:
        node <T> *_ptr;                    //pointer being encapsulated
    };

    List ();

    //---------------------------- big three ----------------------------------
    ~List();
    List(const List& other);
    List& operator =(const List& RHS);
    //-------------------------------------------------------------------------
    Iterator insert_head(const T& item);           //insert at the head of list
    Iterator search (const T& key);                 //search for the key
    Iterator insert_after( List<T>::Iterator marker_ptr, const T& item);    //insert after marker
    Iterator insert_before( List<T>::Iterator marker_ptr, const T& item);   //insert before marker
    Iterator previous (List<T>::Iterator prevToThis);        //previous node to marker
    Iterator Begin() const;               //Iterator to the head node
    Iterator End() const;                 //Iterator to NULL
    T delete_this(List<T>::Iterator marker_ptr);       //delete node pointed to by marker and return the item being deleted
    void clear ();
    friend ostream& operator <<(ostream& outs, const List<T>& list){

        for (List<T>::Iterator it=list.Begin(); it!=list.End(); it++){
            outs<<*it<<"|";
        }
        return outs;
    }


private:
    node <T>* _head_ptr;
};

template <class T>
List <T> :: List (){
    _head_ptr = nullptr;
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
List<T>::List(const List& other){
    _head_ptr = other._head_ptr;
    _head_ptr = _copy_list(_head_ptr);

}

template <class T>
List<T>& List<T>::operator =(const List& RHS) {
    if (this == &RHS) return *this;
    clear();
    _head_ptr = RHS._head_ptr;
    _head_ptr = _copy_list(_head_ptr);
}

template <class T>
typename List<T>::Iterator List<T> :: insert_head (const T& item){

    return Iterator(_insert_head(_head_ptr, item));
}

template <class T>
typename List<T>::Iterator List<T> :: search (const T& key){
    if (_head_ptr== nullptr) return Iterator(); //empty list case

    for (node<T>*w = _head_ptr; w!=nullptr; w =w->_next) {
        if (w->_item == key)
            return Iterator (w);
    }

    return Iterator();
}
template <class T>
typename List<T>::Iterator List<T> ::Begin() const{
    return Iterator (_head_ptr);

}


template <class T>
typename List<T>::Iterator List<T> ::End() const{
    return Iterator (nullptr);
}

template <class T>
void List<T> ::clear() {
    while (_head_ptr != NULL){
        _remove_head(_head_ptr);
    }
}
template <class T>
typename List<T>::Iterator List<T> ::insert_after(List<T>::Iterator marker_ptr, const T& item){
    node<T>* w = marker_ptr._ptr -> _next;
    //1: create a new node:
    node<T>* temp = new node<T>(item);

    if (_head_ptr == NULL)
        _insert_head(_head_ptr, item); //empty case

    // insert at the middle
    if (w != NULL) {
        //2. point this new node to the next node
        temp->_next = marker_ptr._ptr->_next;
        //3. point the after_me to this new node:
        marker_ptr._ptr->_next = temp;
    }

        //insert after the last node
    else{
        temp->_next = NULL; // temp will be the last node
        marker_ptr._ptr ->_next = temp;

    }
    return Iterator (marker_ptr._ptr ->_next);
}

template <typename T>
typename List<T>::Iterator List<T> :: previous (List<T>::Iterator prevToThis){

    //no prev node case
    if (prevToThis._ptr == _head_ptr)
        return Iterator();

    //normal case at middle of the list
    for (node<T>* w = _head_ptr; w!=nullptr; w =w->_next){
        if (w -> _next == prevToThis._ptr )
            return Iterator (w);
    }
    assert (prevToThis._ptr == NULL);// empty list
    return Iterator();
}
template <class T>
typename List<T>::Iterator List<T> ::insert_before (List<T>::Iterator marker_ptr, const T& item){

    List<T>::Iterator prev = previous(marker_ptr);

    if (prev._ptr == NULL) {
        insert_head(item);

    }
    else{
        insert_after(prev, item);
    }
    return Iterator ();
}

template <class T>
T List<T> ::delete_this(List<T>::Iterator marker_ptr) {

    //remove and delete the node pointed to by marker.
    //return T: the item form the delted node.

   assert(_head_ptr);
    List<T>::Iterator prev = previous(marker_ptr);
    T del = *marker_ptr;

    //if(prev == NULL) return Iterator();
    if (prev._ptr != NULL) {
        prev._ptr ->_next =  marker_ptr._ptr -> _next;
        delete marker_ptr._ptr;

    }
    else
        _remove_head(_head_ptr);

    return del;

}



#endif //ITERATOR_LIST_H
