#include <cmath>
#include <iostream>
#include <stdexcept>
#include <complex>
class Complex {
    double re, im;
public:
    Complex():re(0),im(0){}
    Complex(double r):re(r),im(0){}
    Complex(double r,double i):re(r),im(i){}
    double real()const{return re;} double imag()const{return im;}
    double magnitude()const{return std::hypot(re,im);}
    Complex operator+(const Complex& b)const{return {re+b.re,im+b.im};}
    Complex operator-(const Complex& b)const{return {re-b.re,im-b.im};}
    Complex operator*(const Complex& b)const{return {re*b.re-im*b.im,re*b.im+im*b.re};}
    Complex operator/(const Complex& b)const{
        double d=b.re*b.re+b.im*b.im;
        if(d==0.0) throw std::domain_error("division by zero complex impedance");
        return {(re*b.re+im*b.im)/d,(im*b.re-re*b.im)/d};
    }
    bool operator==(const Complex& b)const{return std::abs(re-b.re)<1e-9&&std::abs(im-b.im)<1e-9;}
    friend std::ostream& operator<<(std::ostream& o,const Complex& z){
        return o<<z.re<<(z.im<0?" - j":" + j")<<std::abs(z.im);
    }
};
Complex parallel(const Complex& a,const Complex& b){return (a*b)/(a+b);}
int main(){
    std::cout<<"Q7 - AC CIRCUIT COMPLEX IMPEDANCE\n";
    const double pi=std::acos(-1.0), f=50.0, w=2*pi*f;
    const double R=100.0,L=0.1,C=100e-6;
    Complex zr(R,0), zl(0,w*L), zc(0,-1.0/(w*C));
    Complex series=zr+zl+zc;
    Complex parallelRLC=parallel(parallel(zr,zl),zc);
    std::cout<<"ZR = "<<zr<<"\nZL = "<<zl<<"\nZC = "<<zc<<'\n';
    std::cout<<"Series RLC = "<<series<<" ohm, magnitude "<<series.magnitude()<<'\n';
    std::cout<<"Parallel RLC = "<<parallelRLC<<" ohm, magnitude "<<parallelRLC.magnitude()<<'\n';
    try{Complex bad=zr/Complex(0,0);std::cout<<bad<<'\n';}
    catch(const std::domain_error& e){std::cout<<"Zero division safely handled: "<<e.what()<<'\n';}
    std::complex<double> standard(R,0);
    std::cout<<"std::complex comparison: "<<standard.real()<<" + j"<<standard.imag()<<'\n';
}
