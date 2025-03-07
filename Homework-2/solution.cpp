//**********************************************************
//********************* TAHSÝN OCAKTAN *********************
//*********************   040200549    *********************
//**********************************************************
#include <iostream>
using namespace std;

bool flag = true; //flag for average value calculation

class Plant{ //abstract base class
protected:
    string name;
    int megawatts;
public:
    int year;
    Plant(string, int, int); //constructor
    virtual void plot() = 0; 


};

Plant::Plant (string name, int year, int megawatts): name(name),  year(year), megawatts(megawatts){ } //plant constructor function



class Coal: public Plant{ //derived class from Plant 
private:
    float carbon;
public:
    Coal(string, int, int, float);
    void plot();
};

Coal::Coal(string name, int year, int megawatts, float carbon): carbon(carbon), Plant(name, year, megawatts) {} //Coal constructor function

void Coal::plot() { //coal print function
    static float calculate_carbon = 0; //carbon sum variable 
    static int calls_number = 0; // Each time the print function is called to calculate the total obejct, its value increases by one.

    cout << name << "\t" << megawatts << "\t";
    
    for (int i = 0; i < megawatts/10; ++i) { //histogram printing
        cout << char(254) ;
    }

    calculate_carbon = calculate_carbon + carbon; //calculate carbon value
    calls_number = calls_number + 1; // increses by one 

    if (flag == 0) //check if objects are finished for average carbon rate calculation
    {
        cout << "\n\nAverage Carbon Rate : " << float (calculate_carbon)/float (calls_number);
        flag =1;
    }

    cout << endl;
}


class Hydro:public Plant{ //derived class from Plant
private:
    int height;
public:
    Hydro(string, int, int, int);
    void plot();
};

Hydro::Hydro(string name, int year, int megawatts, int height): height(height), Plant(name, year, megawatts) {} //Hydro constructor function

void Hydro::plot() {
    static int cal_height = 0;  //height sum variable 
    static int number_of_calls = 0; // Each time the print function is called to calculate the total obejct, its value increases by one.

    cout << name << "\t" << megawatts << "\t";
    for (int i = 0; i < megawatts/100; ++i) { //histogram printing
        cout << char(177) ;
    }
    cal_height = cal_height + height; //calculate carbon value
    number_of_calls = number_of_calls + 1; // increses by one 

    if (flag == 0) //check if objects are finished for average dam height calculation
    {
        cout << "\n\nAverage Dam Height : " << float (cal_height)/float (number_of_calls) ;
        flag =1;
    }

    cout << "\n" << endl;
    
}


int main() {

    Plant *power[13]; //8 coal object + 5 hydro object --> polymorphic array

	// add the object to the array
    power[0] = new Coal("Beihetan", 2024, 450, 6.21);
    power[1] = new Coal("Xiangji  ", 2022, 51, 5.37);
    power[2] = new Coal("Jaisalmer", 2023, 210, 5.32);
    power[3] = new Coal("Nyabarongo", 2024, 365, 5.51);
    power[4] = new Coal("Walney   ", 2023, 660, 4.00);
    power[5] = new Coal("Gateway   ",2023,405,5.18);
    power[6] = new Coal("Vindhyachal", 2023,520,5.92);
    power[7] = new Coal("Taichung", 2024,70,6.13);
    power[8] = new Hydro("Yeongheung", 2023, 1800, 173);
    power[9] = new Hydro("Kashiwazaki", 2022, 1330, 210);
    power[10] = new Hydro("Coulee    ", 2023, 1209, 135);
    power[11] = new Hydro("Hongyanhe", 2024, 702, 195);
    power[12] = new Hydro("Polaniec", 2022, 672,63);


    cout << "\nHISTOGRAM FOR ELECTRIC POWER PLANTS (MEGAWATTS): \n" << endl;
    cout << "COAL ELECTRIC PLANTS:" <<endl;
    
    for (int i = 0; i < 8; ++i) { //plot coal electric plants
        if (i==7) //If i = 7, my coal objects are finished
        {
            flag = 0; //flag for average value calculation
        }
        power[i]->plot();
    }

    cout << "\n\nHYDRO ELECTRIC PLANTS:\n" <<endl;
    
    for (int i = 8; i < 13 ; ++i) { //plot hydro electric plants
        if (i==12)
        {
            flag = 0; //flag for average value calculation
        }
        power[i]->plot();
    }



    int diz[3]={0,0,0,}; //array for How many are there from which year?

    cout << "\nHISTOGRAM FOR YEAR DISTRIBUTION" <<endl;
    
    for (int i = 0; i < 13 ; ++i) { //count the How many are there from which year?
    
        switch (power[i]->year){
        	
            case 2022: //for 2022
                diz[0]= diz[0]+1;
                break;

            case 2023://for 2023
                diz[1]= diz[1]+1;
                break;

            case 2024://for 2024
                diz[2]= diz[2]+1;
                break;
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << "YEAR 202"<<i+2<<" (" << diz[i] << ") \t";
        for (int j = 0; j <diz[i] ; ++j) {
            cout << char(219);
        }
        cout << "\n"<<endl;
    }

    return 0;
}

