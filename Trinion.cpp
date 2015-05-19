#include <iostream>
#include "Trinion.h"
#include "Xnum.h"
/** template <T> **/
template<class T> Trinion<T>::Trinion(T x,T y,T z) {
    i = new T;
    *i = x;
    j = new T;
    *j = y;
    k = new T;
    *k = z;
}
template<class T> Trinion<T>::Trinion(T *x,T *y,T *z) : i(x), j(y), k(z) {}
/*
template<class T> Trinion<T>::~Trinion() {
    delete this->i;
    delete this->j;
    delete this->k;
}
*/
template<class T> T *Trinion<T>::I() { return this->i; }
template<class T> T *Trinion<T>::J() { return this->j; }
template<class T> T *Trinion<T>::K() { return this->k; }

/** template < Xnum<T> > **/
template<class T> Trinion< Xnum<T> >::Trinion(T l[][TRINION_MATRIX]) {
    this->i = new Xnum<T> (&l[0][0], &l[0][1]);
    this->j = new Xnum<T> (&l[1][0], &l[1][1]);
    this->k = new Xnum<T> (&l[2][0], &l[2][1]);
}
template<class T> Trinion< Xnum<T> >::Trinion(T *x,T *y,T *z) {
    this->i = new Xnum<T> (&x[0], &x[1]);
    this->j = new Xnum<T> (&y[0], &y[1]);
    this->k = new Xnum<T> (&z[0], &z[1]);
}
template<class T> Trinion< Xnum<T> >::Trinion(Xnum<T> *x,Xnum<T> *y,Xnum<T> *z) : i(x), j(y), k(z) {}
template<class T> Xnum<T> *Trinion< Xnum<T> >::I() { return this->i; }
template<class T> Xnum<T> *Trinion< Xnum<T> >::J() { return this->j; }
template<class T> Xnum<T> *Trinion< Xnum<T> >::K() { return this->k; }
/**
    -x = i^2 = k^3 == -x = -1 = -k
     x = i^4 = k^1 ==  x =  1 =  k

    -y = i^3 = j^2 == -y = -1 = -i
     y = i^1 = j^4 ==  y =  1 =  i

    -z = j^3 = k^2 == -z = -1 = -j
     z = j^1 = k^4 ==  z =  1 =  j


**/
template<class T> void Trinion< Xnum<T> >::additiveReduction() {
    *this->i->re = *this->i->re + *this->k->img;
    *this->j->re = *this->j->re + *this->i->img;
    *this->k->re = *this->k->re + *this->j->img;

    *this->i->img = 0;
    *this->j->img = 0;
    *this->k->img = 0;
}
/*
template<class T> Trinion< Xnum<T> >::~Trinion() {
    i->~Xnum();
    delete this->i;
    j->~Xnum();
    delete this->j;
    k->~Xnum();
    delete this->k;
}
*/
/** print overloads **/
void print(const Trinion<int> &arg) {
    std::cout   << "i: " << *arg.i << std::endl
                << "j: " << *arg.j << std::endl
                << "k: " << *arg.k << std::endl;
}
void print(const Trinion<double> &arg) {
    std::cout   << "i: " << *arg.i << std::endl
                << "j: " << *arg.j << std::endl
                << "k: " << *arg.k << std::endl;
}
void print(const Trinion< Xnum<int> > &arg) {
    std::cout   << "--> i\tRe:\t" << *arg.i->re << std::endl
                << "\tImg:\t" << *arg.i->img << std::endl << std::endl
                << "--> j\tRe:\t" << *arg.j->re << std::endl
                << "\tImg:\t" << *arg.j->img << std::endl << std::endl
                << "--> k\tRe:\t" << *arg.k->re << std::endl
                << "\tImg:\t" << *arg.k->img << std::endl << std::endl;
}
void print(const Trinion< Xnum<double> > &arg) {
    std::cout   << "--> i\tRe:\t" << *arg.i->re << std::endl
                << "\tImg:\t" << *arg.i->img << std::endl << std::endl
                << "--> j\tRe:\t" << *arg.j->re << std::endl
                << "\tImg:\t" << *arg.j->img << std::endl << std::endl
                << "--> k\tRe:\t" << *arg.k->re << std::endl
                << "\tImg:\t" << *arg.k->img << std::endl << std::endl;
}


template class Trinion<int>;
template class Trinion<double>;
template class Trinion< Xnum<int> >;
template class Trinion< Xnum<double> >;

