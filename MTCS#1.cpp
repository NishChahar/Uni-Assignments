//Program implementing Bisection, Newton Raphson and Secant Methods which are used to find roots in Numerical Analysis.
//This program only works for polynoimial functions.

#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

void input_function(int f[],int d)    //function for taking the input
{
    for(int i=0; i<=d; i++)
    {
        cout<<"Enter the coefficient of "<<i<<" degree of x ";
        cin>>f[i];
    }
}

float calculate_f(int f[], float x, int d)
{
    float fc=0;
    for(int i=0;i<=d;i++)
    {
        fc += f[i]*pow(x,i); 
    }
    return fc;
}

float calculate_fd(int f[], float x, int d)
{
    int g[10];
    float fcd=0;
    for(int i=1;i<=d;i++)
    {
        g[i-1]=f[i]*i;
    }
    for(int i=0;i<=d-1;i++)
    {
        fcd += g[i]*pow(x,i);
    }
    return fcd;
}

void bisection(int f[], float a, float b, int d, int n=1, float epsilon = 0.000001, int MAX = 100)
{
    while(n<MAX)
    {
        float c = (a+b)/2.0;
        if(calculate_f(f,c,d)==0 || ((b-a)/2.0)<epsilon)                
            {cout<<"\nRoot Found :"<<c;
             break;}
        else 
        {
            n++; 
            if((calculate_f(f,a,d)*calculate_f(f,c,d))>0)
             a=c;
            else
             b=c;
        }
    }
}
void secant(int f[], float x0, float x1, int d, float epsilon = 0.001)
{
    float x2;
    x2 = x1 - (calculate_f(f,x1,d)*((x1-x0)/(calculate_f(f,x1,d)-calculate_f(f,x0,d))));
    if((abs(x2-x1))<epsilon)
        cout<<"\nRoot Found :"<<x2;
    else
        secant(f,x1,x2,d);             
} 

void newton(int f[], float x0, int d, float epsilon = 0.001)
{
    float x1;
    x1 = x0 - (calculate_f(f,x0,d)/calculate_fd(f,x0,d));
    if((abs(x1-x0))<epsilon)
        cout<<"Root Found :"<<x1<<endl;
    else
        newton(f,x1,d);
}

int main()
{
    int f[10], a, b, x0, deg;
    cout<<"\nEnter you function in the form mentioned below";
    cout<<"\nIf your function is 4x^3 + 3x^2 - x - 10 = 0, put only the coefficient in increasing degree of x (i.e. like -10  -1  3  4)";
    cout<<"\nEnter the highest degree of your polynomial function ";
    cin>>deg;
    input_function(f, deg);
    cout<<"\nEnter the interval for finding the root";
    cout<<"\nEnter the lower limit of the interval ";
    cin>>a;
    cout<<"Ente the upper limit of the interval ";
    cin>>b;
    cout<<"\n\n\nUsing Bisection Method...";
    bisection(f,a,b,deg);
    cout<<"\n\n\nUsing Secant Method...";
    secant(f,a,b,deg);
    cout<<"\n\n\nUsing Newton Method...";
    cout<<"\nEnter the starting point x0 ";
    cin>>x0;
    newton(f,x0,deg);
    return 0;
}


