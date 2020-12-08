// Asia Gibson 
#include <limits>
#include "Order.h"
using namespace std;

// print receipt for all orders 
void close_shop(const vector<Order>& orders){
  for (Order ord : orders){
    ord.print_receipt();
  }
}

int main() {
  
  vector<Order> sales;
  int numOrders{0}, items{0}, salesid{};
  double price{0.0};
  string customer{};

  cout << "Enter number of orders: ";
  //protect against bad input 
  cin >> numOrders;
  while(cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter number of orders: ";
    cin >> numOrders;
  }
  
  while (numOrders-- > 0){
    cin.ignore(); 

    cout << "\n\nEnter customer name: ";
    getline(cin, customer);
    Order neworder{customer}; // create a new order 

    cout << "\nEnter number of items sold: ";
    cin >> items;
  
    while (items-- > 0){
      cout << "Enter item price: ";
      cin >> price;
      neworder.add_item(price);
    }

    cout << "Enter sales rep ID: ";
    cin >> salesid;
    neworder.set_salesid(salesid);

    sales.push_back(neworder); // add order to sales vector
  }

  close_shop(sales);
  
}
