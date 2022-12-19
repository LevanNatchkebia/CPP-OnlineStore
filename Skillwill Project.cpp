#include <iostream>

using namespace std;

class AbstractProduct {
    protected:
    
    string ProductName;
    int ProductPrice;
    
    public:
    static int ProductCount;
    
    AbstractProduct(string ProductName, int ProductPrice) {
        this->ProductName = ProductName;
        this->ProductPrice = ProductPrice;
        ProductCount++;
    }
    
    string getProductName() {
        return ProductName;
    }
    
    void setProductName (string ProductName) {
        this->ProductName = ProductName;
    }
    
    int getProductPrice() {
        return ProductPrice;
    }
    
    void setProductPrice(int ProductPrice) {
        this->ProductPrice = ProductPrice;
    }
    
    void clean () {
        
        cout<<ProductName<<" is cleaning"<<endl;
    }
    
    void recieveSignal() {
        
        cout<<ProductName<<" is recieving signal"<<endl;
    }
    
    virtual void startClean() = 0;
    
    void connectToPhone (){
        
        cout<<ProductName<<" is connecting to Phone"<<endl;
    }
};
int AbstractProduct::ProductCount = 0;

class VacuumCleaner: public AbstractProduct {
    public:
        VacuumCleaner(string ProductName,int ProductPrice): AbstractProduct(ProductName, ProductPrice) {}
        
        void startClean(){
            
            cout<<"Press start on Vacuum Cleaner"<<endl;
        }
        
        void startClean(string startMode) {
            cout<<startMode<<" mode is on"<<endl;
        }
};

class AirPurifier: public AbstractProduct {
    public:
        AirPurifier(string ProductName, int ProductPrice): AbstractProduct(ProductName, ProductPrice) {}
        
        void startClean(){
            cout<<"Press start on Air Purifier"<<endl;
        }
        
        void startClean(string startMode) {
            cout<<startMode<<" mode is on"<<endl;
        }
};

class OnlineStore {
    private: 
        string Name;
        
    public:
        static int SoldProductCount;
        
        OnlineStore (string Name) {
            this->Name = Name;
        }
        
        string getName () {
            return Name;
        }
        
        void setName (string Name) {
            this->Name = Name;
        }
    
        void SellProduct() {
            cout<<"Online Store sold product to client"<<endl;
            SoldProductCount++;
        }
        
        void SellProduct(VacuumCleaner cleaner){
            cout<<"Online store sold "<<cleaner.getProductName()<<" to customer for "<<cleaner.getProductPrice()<<"USD"<<endl;
            SoldProductCount++;
        }
        
        void SellProduct(AirPurifier cleaner) {
            cout<<"Onine store sold "<<cleaner.getProductName()<<" to customer for "<<cleaner.getProductPrice()<<"USD"<<endl;
            SoldProductCount++;
        }
};

int OnlineStore::SoldProductCount = 0;

int main()
{
    VacuumCleaner xiaomi ("Xiaomi", 500);
    AirPurifier philips ("Philips", 300);
    
    OnlineStore techstore ("Tech Store");
    
    // techstore.SellProduct();
    // cout<<OnlineStore::SoldProductCount<<endl;
    // techstore.SellProduct(xiaomi);
    // cout<<OnlineStore::SoldProductCount<<endl;
    // techstore.SellProduct(philips);
    // cout<<OnlineStore::SoldProductCount<<endl;
    
    // xiaomi.startClean();
    // xiaomi.startClean("cleaning");
    

    // philips.clean();
    // xiaomi.recieveSignal();
    // xiaomi.connectToPhone();
    
    return 0;
}
