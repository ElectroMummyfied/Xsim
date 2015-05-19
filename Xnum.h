#ifndef XNUM_H
#define XNUM_H

template <class T> class Trinion;

template <class T> class Xnum {
    private:
        T *re;
        T *img;
    protected:
        T *Re();
        T *Img();
    public:
        Xnum(T *);
        Xnum(T);
        Xnum(T,T);
        Xnum(T *,T *);
        ~Xnum();
        Xnum<T> norm();
        Xnum<T> conjugate();
        Xnum<T> Q();

        /** operator overloads **/
        void operator= (const Xnum<T> &);
        Xnum<T> operator+ (const Xnum<T> &);
        Xnum<T> operator- (const Xnum<T> &);
        Xnum<T> operator* (const Xnum<T> &);
        Xnum<T> operator/ (const Xnum<T> &);
        Xnum<T> operator^ (const int);
        operator double () const;

    friend class Trinion< Xnum<T> >;

    friend void print(const Xnum &);
    friend void print(const Trinion<Xnum> &);
};
#endif // XNUM_H
