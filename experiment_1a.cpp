#include<iostream>
using namespace std;

class Shape{
    private:
       double height,length,radius,breadth;
       int base;
       double arearec,areatri,areacircle;
    public:
       void set_length(double l){
        length=l;
       }
       void set_breadth(double b){
        breadth=b;
       }
       
       void set_height(double h){
        height=h;
       }
       void set_base(double a){
        base=a;
       }
       void set_radius(double r){
        radius=r;
       }

       double get_length(){
        return length;
       }
       double get_breadth(){
        return breadth;
       }
       double get_height(){
        return height;
       }
       int get_base(){
        return base;
       }
       double get_radius(){
        return radius;
       }

       void area(double l,double b){
        arearec= l*b;
       }
       void area(double r, long pi=3.14){
        areacircle= pi*r*r;
       }
       void area(int a, double h){
        areatri =0.5*a*h;
       }

       double get_area_rectangle(){
        return arearec;
       }
       double get_area_circle(){
        return areacircle;
       }
       double get_area_triangle(){
        return areatri;
       }
};

int main(){
    Shape obj;
    obj.set_base(2);
    obj.set_height(2.5);
    obj.set_length(1.5);
    obj.set_breadth(2.0);
    obj.set_radius(2.5);

    double l,b;
    l=obj.get_length();
    b=obj.get_breadth();
    obj.area(l,b);

    double r=obj.get_radius();
    obj.area(r);

    int base=obj.get_base();
    double h=obj.get_height();
    obj.area(base,h);

    cout<<"\nArea of Rectangle of OBJ1: "<<obj.get_area_rectangle();
    cout<<"\nArea of circle of OBJ1: "<<obj.get_area_circle();
    cout<<"\nArea of triangle of OBJ1: "<<obj.get_area_triangle();

    return 0;

}
