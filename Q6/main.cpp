#include <chrono>
#include <cstring>
#include <iostream>
#include <string>
class Text {
    char* data;
    static int copies;
public:
    explicit Text(const char* s="") {
        std::size_t n=std::strlen(s); data=new char[n+1]; std::memcpy(data,s,n+1);
    }
    Text(const Text& o) {
        ++copies; std::size_t n=std::strlen(o.data);
        data=new char[n+1]; std::memcpy(data,o.data,n+1);
    }
    Text& operator=(const Text& o) {
        if(this!=&o){char* fresh=new char[std::strlen(o.data)+1];
            std::strcpy(fresh,o.data);delete[] data;data=fresh;}
        return *this;
    }
    ~Text(){delete[] data;}
    Text operator+(const Text& b)const{
        std::size_t n=std::strlen(data),m=std::strlen(b.data);
        char* tmp=new char[n+m+1];std::strcpy(tmp,data);std::strcat(tmp,b.data);
        Text result(tmp);delete[] tmp;return result;
    }
    bool operator==(const Text& b)const{return std::strcmp(data,b.data)==0;}
    bool operator!=(const Text& b)const{return !(*this==b);}
    friend std::ostream& operator<<(std::ostream& o,const Text& t){return o<<t.data;}
    static int copyCount(){return copies;}
};
int Text::copies=0;
int main(){
    std::cout<<"Q6 - TEXT CLASS / OPERATOR RULES\n";
    Text a("Hello "),b("C++"),c("");Text joined=a+b;
    std::cout<<joined<<"\nEmpty text=["<<c<<"]\n";
    Text longText("This is a longer message used to verify dynamic allocation and copying.");
    Text copy=longText;copy=copy;
    std::cout<<"Long copy: "<<copy<<"\nEqual: "<<std::boolalpha<<(copy==longText)
             <<" not-equal: "<<(a!=b)<<"\nCopy constructor count: "<<Text::copyCount()<<'\n';
    std::string x="";auto s=std::chrono::steady_clock::now();
    for(int i=0;i<100000;++i)x+="x";
    auto e=std::chrono::steady_clock::now();
    std::cout<<"std::string 100000 appends us: "
             <<std::chrono::duration_cast<std::chrono::microseconds>(e-s).count()
             <<" length "<<x.size()<<'\n';
}
