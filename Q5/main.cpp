#include <chrono>
#include <iostream>
#include <string>
#include <vector>
class Time {
    int seconds;
public:
    Time(int h=0,int m=0,int s=0):seconds(h*3600+m*60+s){}
    Time& operator++(){++seconds;return *this;}
    Time operator++(int){Time old=*this;++seconds;return old;}
    bool operator==(const Time& b)const{return seconds==b.seconds;}
    bool operator<(const Time& b)const{return seconds<b.seconds;}
    friend std::ostream& operator<<(std::ostream& o,const Time& t){
        int h=t.seconds/3600, m=(t.seconds/60)%60, s=t.seconds%60;
        return o<<h<<':'<<m<<':'<<s;
    }
};
class Playlist {
    std::vector<std::string> tracks;
public:
    Playlist(std::initializer_list<std::string> x):tracks(x){}
    std::string& operator[](int i){
        if(i<0||i>=static_cast<int>(tracks.size())) throw std::out_of_range("Playlist index out of range");
        return tracks[i];
    }
    const std::string& operator[](int i)const{
        if(i<0||i>=static_cast<int>(tracks.size())) throw std::out_of_range("Playlist index out of range");
        return tracks[i];
    }
    int size()const{return static_cast<int>(tracks.size());}
};
int main(){
    std::cout<<"Q5 - INCREMENT / COMPARISON / SUBSCRIPT\n";
    Time t(0,0,5); Time a=t++; Time b=++t;
    std::cout<<"postfix old="<<a<<" prefix new="<<b<<" current="<<t<<'\n';
    Time rollover(0,59,59); ++rollover; std::cout<<"After 59:59: "<<rollover<<'\n';
    std::cout<<"Comparison: "<<std::boolalpha<<(a<b)<<' '<<(a==b)<<'\n';
    Playlist p{"Track A","Track B","Track C"};
    std::cout<<"Playlist[1]: "<<p[1]<<'\n';
    for(int index:{-1,p.size()}){
        try{std::cout<<p[index]<<'\n';}
        catch(const std::out_of_range& e){std::cout<<"Caught: "<<e.what()<<'\n';}
    }
    volatile long long sum=0;
    auto start=std::chrono::steady_clock::now();
    for(int i=0;i<10000000;++i){Time x; ++x; sum+=1;}
    auto end=std::chrono::steady_clock::now();
    std::cout<<"10,000,000 prefix operations us: "
             <<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
             <<" checksum "<<sum<<'\n';
}
