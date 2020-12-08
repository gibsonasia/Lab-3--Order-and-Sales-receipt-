 // Asia Gibson 
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>


class Order {

  public: 
    explicit Order(std::string cust){
      change_customer(cust);
    }

    Order(){}

    //define print_receipt
    void print_receipt() const{
      
      for (int i = 0; i < 30; i++){
        std::cout << "=";
      }
      std::cout << "\n";
        
        std::cout << "Order for " << customer_name << "\n" ;
        std::cout << "Sold by rep id: " << sales_id << "\n";
        std::cout << "Number of items: " << number_items << "\n";

        for(double item : items ){
          std::cout << std::setfill (' ');
          std::cout << std::setw(10) << "$" << std::setw(6) << item << "\n"; ;
        }
        std::cout << std::setfill (' ');
        std::cout << std::right << std::setw(17) << "-------" << "\n"; 
        std::cout << std::setfill (' ');
        std::cout << " Total " << std::setw(3) << "$" << std::setw(6) << order_total << "\n" ;

      for (int i = 0; i < 30; i++){
        std::cout << "=";
      }
        std::cout << "\n\n";

    }

    void change_customer(std::string newname){
      customer_name = newname;
    }

    double get_order_total() const{
      return order_total;
    }

    void set_salesid(int sid){
      sales_id = sid;
    }

    void add_item(double newitem){
      if (newitem > 0){
        items.push_back(newitem);
        number_items++;
        order_total += newitem;
      }
    }

  private: 
    int number_items{0};
    double order_total{0.0};
    int sales_id{0};
    std::string customer_name{};
    std::vector<double> items;


}; 
