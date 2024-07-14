#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){
    int a , b;
    
    cout<<"Enter the value of num 1 ";
    cin>>a;
    cout<<"\nEnter the value of num 2 ";
    cin>>b;
    system("cls");
    Sleep(50);
    cout<<"the value of a is "<<a<<" and the value of b is "<<b;
    cout<<"\n"<<a<<" + "<<b<<" = "<<a+b;
    getch();
    return 0;
}