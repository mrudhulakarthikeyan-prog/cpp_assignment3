#include <iostream>
#include <memory>
#include <vector>
class Event {
    int rows, cols, booked;
    char** seats;
public:
    Event(int r,int c) : rows(r<0?0:r), cols(c<0?0:c), booked(0), seats(nullptr) {
        if(rows>0 && cols>0) {
            seats=new char*[rows];
            int made=0;
            try {
                for(;made<rows;++made) {
                    seats[made]=new char[cols];
                    for(int j=0;j<cols;++j) seats[made][j]='O';
                }
            } catch(...) {
                while(made>0) delete[] seats[--made];
                delete[] seats; seats=nullptr; throw;
            }
        }
        std::cout<<"Event constructed: "<<rows<<"x"<<cols<<'\n';
    }
    bool book(int r,int c) {
        if(!seats||r<0||r>=rows||c<0||c>=cols||seats[r][c]=='X') return false;
        seats[r][c]='X'; ++booked; return true;
    }
    bool cancel(int r,int c) {
        if(!seats||r<0||r>=rows||c<0||c>=cols||seats[r][c]=='O') return false;
        seats[r][c]='O'; --booked; return true;
    }
    ~Event() {
        for(int i=0;i<rows && seats;++i) delete[] seats[i];
        delete[] seats;
        std::cout<<"Event closed; booked seats remaining: "<<booked<<'\n';
    }
};
int main() {
    std::cout<<"Q3 - DYNAMIC CONSTRUCTORS AND DESTRUCTORS\n";
    Event stackEvent(3,4); stackEvent.book(0,0); stackEvent.book(1,2); stackEvent.cancel(0,0);
    { Event blockEvent(2,2); blockEvent.book(1,1); }
    Event* heapEvent=new Event(2,3); heapEvent->book(0,1); delete heapEvent;
    Event zeroRows(0,5);
    for(auto [r,c] : {std::pair<int,int>{10,20},{100,200},{1000,2000}})
        std::cout<<"Approx seat storage "<<r<<"x"<<c<<": "<<(r*c)<<" bytes\n";
}
