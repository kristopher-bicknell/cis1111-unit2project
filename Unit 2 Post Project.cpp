//Kris Bicknell
//February 21, 2024
//The Store Shipping Info 9000
//Provides shipping information on an order, featuring name and address collection and a randomly-generated discount on every sale

#include <iostream>
#include <string>
#include <iomanip>
#include <random>

using namespace std;

int paintCanNum,paintBrushNum,paintRollerNum,discount;
string fullName,shippingAddress;
double distFromStore,distCost,weightCost,subtotal,total;
const double shippingPerMile=0.45,shippingPerLb=2.65,lbToOz=16.0,paintCanWeight=192.0,paintBrushWeight=0.4,paintRollerWeight=32;
random_device myEngine;
uniform_int_distribution<int> randomInt(1,10);

int main()
{
    //display store name, prices, etc
    cout<<"Welcome to The Store!\nWe currently are running a random sale on every purchase. You may receive up to 10% off your order!\n";
    cout<<"What we sell: \n";
    cout<<fixed<<setprecision(2);
    cout<<setw(30)<<left<<"Paint cans:"<<right<<paintCanWeight<<" oz"<<endl;
    cout<<setw(30)<<left<<"Paint brushes:"<<right<<paintBrushWeight<<" oz"<<endl;
    cout<<setw(30)<<left<<"Paint rollers:"<<right<<paintRollerWeight<<" oz"<<endl;
    
    //user inputs
    cout<<"\nHow many paint cans would you like to buy? ";
    cin>>paintCanNum;
    cout<<"\nHow many paint brushes would you like to buy? ";
    cin>>paintBrushNum;
    cout<<"\nHow many paint rollers would you like to buy? ";
    cin>>paintRollerNum;
    
    //collect name and shippingAddress
    cout<<"\n-------------------SHIPPING INFO-----------------\n";
    cout<<"\nWhat is your full first and last name? ";
    cin.ignore(1);
    getline(cin,fullName);
    cout<<"\nWhat is your shipping address? ";
    cin.ignore(1);
    getline(cin,shippingAddress);
    cout<<"\nHow many miles is this address from the store? ";
    cin>>distFromStore;
    
    //Bill
    cout<<"\n\n------------------BILL------------------\n";
    cout<<setw(30)<<left<<"Shipping to:"<<right<<fullName<<endl;
    cout<<setw(30)<<left<<"Shipping address:"<<right<<shippingAddress<<endl<<endl;
    //math
    distCost=distFromStore*shippingPerMile;
    cout<<setw(30)<<left<<"Distance cost:"<<right<<"$"<<distCost<<endl;
    weightCost=shippingPerLb*ceil((((paintCanNum*paintCanWeight)+(paintBrushNum*paintBrushWeight)+(paintRollerNum*paintRollerWeight))/lbToOz));
    cout<<setw(30)<<left<<"Weight cost (lbs):"<<right<<"$"<<weightCost<<endl;
    subtotal=weightCost+distCost;
    cout<<setw(30)<<left<<"Subtotal:"<<right<<"$"<<subtotal<<endl;
    double discount=randomInt(myEngine);
    cout<<setw(30)<<left<<"Percent off:"<<right<<discount<<"%"<<endl;
    discount=(discount/100)*subtotal;
    cout<<setw(30)<<left<<"Discount:"<<right<<"$"<<discount<<endl;
    total=subtotal-discount;
    cout<<setw(30)<<left<<"Total shipping cost:"<<right<<"$"<<total<<endl;
    
    return 0;
}
