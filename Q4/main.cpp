#include <chrono>
#include <iomanip>
#include <iostream>
class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    static Money fromPaise(long long p){ Money m; m.paise=p; return m; }
    Money operator+(const Money& b) const { return fromPaise(paise+b.paise); }
    Money operator-(const Money& b) const { return fromPaise(paise-b.paise); }
    Money& operator+=(const Money& b){paise+=b.paise;return *this;}
    bool operator==(const Money& b)const{return paise==b.paise;}
    bool operator<(const Money& b)const{return paise<b.paise;}
    friend std::ostream& operator<<(std::ostream& os,const Money& m){
        long long v=m.paise;
        if(v<0){os<<"-Rs ";v=-v;} else os<<"Rs ";
        return os<<v/100<<'.'<<std::setw(2)<<std::setfill('0')<<v%100<<std::setfill(' ');
    }
    friend std::istream& operator>>(std::istream& is,Money& m){
        long long r; int p; char dot;
        if(is>>r>>dot>>p && dot=='.') m=fromPaise(r*100+(r<0?-p:p));
        else is.setstate(std::ios::failbit);
        return is;
    }
};
int main(){
    std::cout<<"Q4 - MONEY OPERATOR OVERLOADING\n";
    Money a(0,75),b(0,50);
    std::cout<<"Carry: "<<a+b<<'\n';
    Money bill=Money(120,75)+Money(79,25);
    std::cout<<"Bill: "<<bill<<"\nEquals Rs 200: "<<std::boolalpha<<(bill==Money(200))<<'\n';
    std::cout<<"Negative subtraction policy (signed amount): "<<Money(1,0)-Money(2,0)<<'\n';
    bill+=Money(0,25); std::cout<<"After += : "<<bill<<'\n';
    long long integer=0; double floating=0.0;
    auto s=std::chrono::steady_clock::now();
    for(int i=0;i<1000000;++i) integer+=1;
    auto t=std::chrono::steady_clock::now();
    for(int i=0;i<1000000;++i) floating+=0.01;
    auto u=std::chrono::steady_clock::now();
    std::cout<<"Integer-paise benchmark us: "<<std::chrono::duration_cast<std::chrono::microseconds>(t-s).count()
             <<", result "<<integer<<'\n';
    std::cout<<"Double benchmark us: "<<std::chrono::duration_cast<std::chrono::microseconds>(u-t).count()
             <<", result "<<floating<<'\n';
}
