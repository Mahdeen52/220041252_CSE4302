#include <iostream>
using namespace std;

class Medicine {
    char tradeName[1000];
    char genericName[1000];
    double unitPrice,discountPrice,discountPercent;

public:
  
   public:
    void assignName(char name[], char genName[]) {
        
        int i = 0;
        while (name[i] != '\0' && i < 999) {
            tradeName[i] = name[i];
            i++;
        }
        tradeName[i] = '\0';  

        int j = 0;
        while (genName[j] != '\0' && j < 999) {
            genericName[j] = genName[j];
            j++;
        }
        genericName[j] = '\0';  
    }

    
    void assignPrice(double price) {
        if (price >= 0) {
            unitPrice = price;
        } else {
            unitPrice = 0.0;
        }
    }

    
    void setDiscountPercent(double percent) {
        if (percent >= 0 && percent <= 30) {
            discountPercent = percent;
        } else {
            discountPercent = 5.0;  
        }
    }

    
    double getSellingPrice(int nos) {
         discountPrice = unitPrice - (unitPrice * (discountPercent / 100));
        return discountPrice * nos;
    }

  
    void display() {
        cout<<"IUT MEDICAL CENTER"<<endl;
         cout<<"CHECKOUT:"<<endl<<endl;
        
cout << "MRP of " << tradeName << " (" << genericName << ") is BDT " 
<< unitPrice << ". Current discount " << discountPercent << "%." << endl;
        
cout << "Selling price BDT " << getSellingPrice(5) << "." << endl;
        
        
}
    
};

int main() {

    Medicine medi;
    char trade[] = "Napa Extra";
    char generic[] = "StrongParacetamol";
    
    medi.assignName(trade, generic);
    medi.assignPrice(100.00);
    medi.setDiscountPercent(10.0);
    medi.getSellingPrice(5);
    medi.display();

    return 0;
}