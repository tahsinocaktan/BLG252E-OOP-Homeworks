#include <iostream>
#include <iomanip>
using namespace std;

//************************ OOP Homework 1 ************************ 
//************************ Tahsin OCAKTAN ************************ 
//************************   040200549    ************************ 

const int N = 5; // size of list_of_ordered_product array
static int total = 0; // Variable returned by calculate_total_debt() function
static int sum = 0; // variable for calculation in calculate_total_debt() function

class Customer; // First declaration  for using friend class 


class Product { // product class for products according to UML class diagram in homework.pdf
    friend class Customer;
    private:
        string name;
        float price;

    public:
        Product(){}; // empty default constructor's  
        Product(string, float); // parameter constructor funciton 
//        Product* get(Product&); //print value for debug 
//        void prints(); //print value for debug 


};

Product::Product(string n, float p) {
    this->name=n;  //initialize variable
    this->price=p; //initialize variable
}


//Product* Product::get(Product &p) {	//print value for debugging
//    return &p;
//}

//void Product::prints() {	//print value for debugging
//    cout << "Name = " << name << " price = " << price << endl;
//}

class Customer{ // customer class for customers according to UML class diagram in homework.pdf
    private:
        string customer_name; // customer name
        float credit_card_limit; // customer's credit card limit
        Product list_of_ordered_product[N]; // list of customers' purchases
        int count_of_ordered_product = 0; // number of materials purchased

    public:
        Customer(string, float); // parameter constructor funciton 
        void operator+(Product&); // Controlling whether customers can make purchases based on their credit card limits
        float calculate_total_debt(); // total prices of purchased products
        void print(); // print function
};

Customer::Customer(string cname, float cclimit = 1000) {
    this->customer_name = cname; //initialize variable
    this->credit_card_limit = cclimit; //initialize variable
}

float Customer::calculate_total_debt() {

    sum = sum + list_of_ordered_product[count_of_ordered_product-1].price;

    return sum;
}

void Customer::operator+(Product &p) {
	
    count_of_ordered_product++; //increase the number of products by 1
    
    if (count_of_ordered_product<6) { // Since the maximum number of products that can be purchased is 5, controlling the number of products
    
        if (credit_card_limit - total >= p.price) { // Checking whether the card limit is sufficient
        
            list_of_ordered_product[count_of_ordered_product - 1] = p; // shopping cart containing purchasable items
            
            cout << "Add product : " << list_of_ordered_product[count_of_ordered_product - 1].name << " " << list_of_ordered_product[count_of_ordered_product - 1].price << endl;
            cout << "Product is added to customer successfully" << endl << endl;
            total = calculate_total_debt(); // returning value for calculation of debt
            //cout << "toplam = " << total << endl; // for debuging
        }
        else {// If the card limit is not enough, the following code will be executed
        
            count_of_ordered_product--; //decrease the number of products by 1 (Since we increased by one above)
            
            if (count_of_ordered_product == 0) // array index cannot be less than 0
            {
                count_of_ordered_product = 1;
            }
            
            else {
                count_of_ordered_product++;
            }
            // adjusting shopping cart and printing of products that cannot be purchased
            list_of_ordered_product[count_of_ordered_product - 1] = p;
            cout << "Add product : " << list_of_ordered_product[count_of_ordered_product - 1].name << " " << list_of_ordered_product[count_of_ordered_product - 1].price << endl;
            cout << "Total debt exceed the credit card limit" << endl;
            cout << "Product add operation is not done" << endl << endl;
            count_of_ordered_product--;
        }
    }
    else
    { // if the number of products is 6 or more, the following code will be executed
        count_of_ordered_product--;
        cout << "Add product : " << p.name << " " << p.price << endl;
        cout << "Count of ordered products exceeded the maximum number" << endl;
        cout << "Product add operation is not done" << endl << endl;
    }
}

void Customer::print() {
    cout << "Customer Name             : " << customer_name << endl;
    cout << "Credit Card Limit         : " << credit_card_limit << endl;
    cout << "Count of ordered products : " << count_of_ordered_product << endl;
    cout << "List of Ordered Products  : " << endl;

    for (int i = 0; i < count_of_ordered_product; ++i) {
        cout << i+1 << ". Name : " << list_of_ordered_product[i].name << setw(30)<< setw(30- (list_of_ordered_product[i].name).length()) << "  Price : " << list_of_ordered_product[i].price << endl;
    }
    cout << "TOTAL DEBT = " << total << endl << endl; 
    total = 0; // Since shopping is over, total values are reset to zero.
    sum = 0; // Since shopping is over, total values are reset to zero.
    cout << "*****************************************************************" << endl << endl;

}


int main() {
	
    cout << "PROGRAM STARTED" << endl << endl;

	//Objects of the product class are defined as arrays
    Product product_list[12] = {Product("Panasonic Phone",800),
                                Product("Toshiba Battery",300),
                                Product("Kenwood DVD",400),
                                Product("Canon Battery",500),
                                Product("Nikon Accessory",600),
                                Product("Yamaha Subwoofer",200),
                                Product("Whirlpool Charger",90),
                                Product("Logitech Remote",20),
                                Product("LG Dryer ",100),
                                Product("Linksys Router",60),
                                Product("Nintendo Portable",150),
                                Product("Mitsubishi Stand",50)};

	//Objects of the customer class are defined as arrays
    Customer customer_list[3] = {Customer("JOHN FISHER",2000),
                                 Customer("RONALD CRAIG"),
                                 Customer("THOMAS AUSTIN",750)};
                                 
	// For first customers' purchases
    customer_list[0].operator+(product_list[0]);
    customer_list[0].operator+(product_list[1]);
    customer_list[0].operator+(product_list[2]);
    customer_list[0].print();

	//For second customers' purchases
    customer_list[1].operator+(product_list[3]);
    customer_list[1].operator+(product_list[4]);
    customer_list[1].operator+(product_list[5]);
    customer_list[1].print();

	//For third customers' purchases
    customer_list[2].operator+(product_list[6]);
    customer_list[2].operator+(product_list[7]);
    customer_list[2].operator+(product_list[8]);
    customer_list[2].operator+(product_list[9]);
    customer_list[2].operator+(product_list[10]);
    customer_list[2].operator+(product_list[11]);
    customer_list[2].print();

    cout << "PROGRAM FINISHED" << endl << endl;

/* // for debugging 
    Product *a;
    for (int i = 0; i < 11; ++i) {
        a = product_list->get(product_list[i]);
        a->prints();

    }*/



    return 0;
}

