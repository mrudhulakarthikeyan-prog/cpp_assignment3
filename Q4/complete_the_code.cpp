#include <iomanip>
#include <iostream>
class Money {
 long long paise;
public:
 Money(long long rupees=0,int p=0):paise(rupees*100+p){}
 Money operator+(const Money& b)const{return Money(0,static_cast<int>(paise+b.paise));}
 bool operator==(const Money& b)const{return paise==b.paise;}
 friend std::ostream& operator<<(std::ostream& os,const Money& m){
   return os<<"Rs "<<m.paise/100<<'.'<<std::setw(2)<<std::setfill('0')<<m.paise%100<<std::setfill(' ');
 }
};
int main(){Money a(120,75),b(79,25);Money c=a+b;
 std::cout<<c<<'\n'<<std::boolalpha<<(c==Money(200))<<'\n';}
