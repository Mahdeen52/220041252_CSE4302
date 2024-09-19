#include <iostream>
using namespace std;

class Counter{
    private: int count=0,inc_steps;
    public: void setIncrementStep (int n) {
            inc_steps=n;
    }
    
            
            int getCount() {
                return count;
            }
            
            void increment() {
                count+=inc_steps;
                
            }
            
            void resetCount() {
                count=0;
            }

};




int main() {
    Counter count;
    
    count.getCount();
    cout<<"Current count is:"<<count.getCount()<<endl;
    
    count.setIncrementStep (5);
    count.increment();
    
    cout<<"Current count is:"<<count.getCount()<<endl;
    
    count.setIncrementStep (10);
    count.increment ();
    
    cout<<"Current count is:"<<count.getCount()<<endl;
    
    count.resetCount();
    cout<<"Current count is:"<<count.getCount()<<endl;
    
    
    

    return 0;
}