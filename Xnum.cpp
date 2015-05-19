#include <iostream>
#include "Xnum.h"

/** template <T> **/
template<class T> Xnum<T>::Xnum(T *arg) : re(&arg[0]), img(&arg[1]) {}
template<class T> Xnum<T>::Xnum(T r) {
    re = new T;
    *re = r;
    img = new T;
    *img = 0;
}
template<class T> Xnum<T>::Xnum(T r, T i) {
    re = new T;
    *re = r;
    img = new T;
    *img = i;
}
template<class T> Xnum<T>::Xnum(T *r, T *i) : re(r), img(i) {}
template<class T> Xnum<T>::~Xnum() {
    delete this->re;
    delete this->img;
}
template<class T> T *Xnum<T>::Re() { return this->re; }
template<class T> T *Xnum<T>::Img() { return this->img; }
template<class T> Xnum<T> Xnum<T>::norm() {
    Xnum<T> temp(0.0,0.0);
    *temp.re = *this->re;
    *temp.img = *this->img;

    temp = temp / temp.conjugate();

    return temp;
}
template<class T> Xnum<T> Xnum<T>::conjugate() {
    Xnum<T> temp(0.0,0.0);
    *temp.re = *this->re;
    *temp.img = -(*this->img);

    return temp;
}
template<class T> Xnum<T> Xnum<T>::Q() {
    Xnum<T> temp(0.0,0.0);
    *temp.re = *this->re;
    *temp.img = *this->img;

    temp = temp * temp.conjugate();
    return temp;
}

/** overload operators **/
template<class T> void Xnum<T>::operator= (const Xnum<T> &arg) {
    *this->re = *arg.re;
    *this->img = *arg.img;
}
template<class T> Xnum<T> Xnum<T>::operator+ (const Xnum<T> &arg) {
    Xnum<T> temp(0.0,0.0);
    *temp.re = *this->re + *arg.re;
    *temp.img = *this->img + *arg.img;

    return temp;
}
template<class T> Xnum<T> Xnum<T>::operator- (const Xnum<T> &arg) {
    Xnum<T> temp(0.0,0.0);
    *temp.re = *this->re - *arg.re;
    *temp.img = *this->img - *arg.img;

    return temp;
}
template<class T> Xnum<T> Xnum<T>::operator* (const Xnum<T> &arg) {
    Xnum<T> temp(0.0,0.0);
    *temp.re = (*this->re * *arg.re) - (*this->img * *arg.img);
    *temp.img = (*arg.img * *this->re) + (*arg.re * *this->img);

    return temp;
}
template<class T> Xnum<T> Xnum<T>::operator/ (const Xnum<T> &arg) {
    Xnum<T> temp(0.0,0.0);

    *temp.re = (*this->re * *arg.re + *this->img * *arg.img)/((*arg.re * *arg.re) + (*arg.img * *arg.img));
    *temp.img = -(*arg.img * *this->re - *arg.re * *this->img)/((*arg.re * *arg.re) + (*arg.img * *arg.img));
    return temp;
}
template<class T> Xnum<T> Xnum<T>::operator^ (const int p) {
    Xnum<T> temp1(0.0,0.0);
    Xnum<T> temp2(0.0,0.0);

    *temp1.re = *this->re;
    *temp1.img = *this->img;

    *temp2.re = *this->re;
    *temp2.img = *this->img;
    if(p > 0) {
        for(int i = 0; i < (p -1); i++) {
            temp1 = temp1 * temp2;
        }
    } else if(p < 0) {
        for(int i = 0; i < (-1*p -1); i++) {
            temp1 = temp1 * temp2;
        }
        temp1 = static_cast< Xnum<T> > (1.0)/ temp1;
    } else {
        *temp1.re = 1;
        *temp1.img = 0;
    }

    return temp1;
}

template<class T> Xnum<T>::operator double () const{
    return *this->re;
}
/** print overloads **/
void print(const Xnum<int> &arg) {
    std::cout   << "Re: " << *arg.re << std::endl
                << "Img: " << *arg.img << std::endl;
}
void print(const Xnum<double> &arg) {
    std::cout   << "Re: " << *arg.re << std::endl
                << "Img: " << *arg.img << std::endl;
}
void print(const Xnum<long double> &arg) {
    std::cout   << "Re: " << *arg.re << std::endl
                << "Img: " << *arg.img << std::endl;
}

template class Xnum<int>;
template class Xnum<double>;
