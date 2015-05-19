#ifndef TRINION_H
#define TRINION_H

static const int TRINION_MATRIX = 3;

enum {_I=0,_J=1,_K=2};

template <class T> class Xnum;

template <class T> class Trinion {
    private:
        T *i;
        T *j;
        T *k;
    protected:
        T *I();
        T *J();
        T *K();
    public:
        Trinion(T,T,T);
        Trinion(T*,T*,T*);
        //~Trinion();

    friend void print(const Trinion &);
};
template <class T> class Trinion< Xnum<T> > {
    private:
        Xnum<T> *i;
        Xnum<T> *j;
        Xnum<T> *k;
    protected:
        Xnum<T> *I();
        Xnum<T> *J();
        Xnum<T> *K();
    public:
        Trinion(T [][TRINION_MATRIX]);
        Trinion(T *,T *,T *);
        Trinion(Xnum<T> *,Xnum<T> *,Xnum<T> *);
        void additiveReduction();
        //~Trinion();

    friend void print(const Trinion &);
};
#endif // TRINION_H
