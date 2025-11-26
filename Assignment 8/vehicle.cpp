#include<iostream>
using namespace std;

class Vehicle{
    public:
    virtual void gear_change()=0;
    virtual void speed_up()=0;
    virtual void apply_brakes()=0;
    virtual void display()=0;
};

class Bike : public Vehicle{
    int speed;
    int gear;
    public:
    Bike(){
        speed=0;
        gear=1;
    }
    void gear_change(){
        gear++;
        if(gear>5){
            gear=5;
        }
    }
    void speed_up(){
        speed+=10;
    }
    void apply_brakes(){
        speed-=10;
        gear--;
    }
    void display(){
        cout<<"Bike speed: "<<speed<<" Gear: "<<gear<<endl;
    }
};

class Bicycle : public Vehicle{
    int speed;
    int gear;
    public:
    Bicycle(){
        speed=0;
        gear=1;
    }
    void gear_change(){
        gear++;
        if(gear>5){
            gear=5;
        }
    }
    void speed_up(){
        speed+=4;
    }
    void apply_brakes(){
        speed-=4;
        gear--;
    }
    void display(){
        cout<<"Bicycle speed: "<<speed<<" Gear: "<<gear<<endl;
    }
};

class Car : public Vehicle{
    int speed;
    int gear;
    public:
    Car(){
        speed=0;
        gear=1;
    }
    void gear_change(){
        gear++;
        if(gear>5){
            gear=5;
        }
    }
    void speed_up(){
        speed+=20;
    }
    void apply_brakes(){
        speed-=20;
        gear--;
    }
    void display(){
        cout<<"Car speed: "<<speed<<" Gear: "<<gear<<endl;
    }
};

int main(){
    int ch;
    while(true){
    cout<<"Choose Vehicle:\n1.Bike\n2.Bicycle\n3.Car\n";
    cin>>ch;
    Vehicle *v;
    switch(ch){
        case 1:
            v=new Bike();
            v->gear_change();
            v->speed_up();
            v->display();
            v->apply_brakes();
            v->display();
            break;
        case 2:
            v=new Bicycle();
            v->gear_change();
            v->speed_up();
            v->display();
            v->apply_brakes();
            v->display();
            break;
        case 3:
            v=new Car();
            v->gear_change();
            v->speed_up();
            v->display();
            v->apply_brakes();
            v->display();
            break;
        default:
            cout<<"Invalid choice"<<endl;
            return 0;
    }
    }
    return 0;
}