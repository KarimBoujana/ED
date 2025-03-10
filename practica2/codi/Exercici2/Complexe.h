/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Complexe.h
 * Author: mariasalamo
 *
 * Created on 1 de marzo de 2022
 */


#ifndef COMPLEXE_H
#define COMPLEXE_H

template <class T>
class Complexe{
    private: 
        
        T v_real;
        T v_imaginari;
    public:
        Complexe<T>(T r, T i);
        T real() const; 
        T imaginari() const;
        
            
};

template <class T>
Complexe<T>::Complexe(T r , T i) : v_real(r), v_imaginari(i)
{    
}

template <class T>
T Complexe<T>::real() const
{
    return v_real;
}

template <class T>
T Complexe<T>::imaginari() const
{
    return v_imaginari; 
}

#endif /* COMPLEXE_H */

