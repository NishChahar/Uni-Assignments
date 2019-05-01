#include<iostream>
#include<cmath>

using namespace std;

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

void input_function(int f[],int d)
{
    for(int i=0; i<=d; i++)
    {
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

void newton(int f[], float x0, int d, float epsilon = 0.001)
{
    float x1;
    float fct=calculate_f(f,x0,d);
    float fdt=calculate_fd(f,x0,d);
    cout<<"\nfct and fdt = "<<fct<<" "<<fdt;
    x1 = x0 - (fct/fdt);
    cout<<"\n x1 ="<<x1;

    if((abs(x1-x0))<epsilon)
        cout<<"\nRoot Found :"<<x1;
    else
        newton(f,x1,d);
}

int main()
{
    int f[10], a, b, deg;
    cout<<"\n Enter you function in the form mentioned below";
    cout<<"\n If your function is 4x^3 + 3x^2 - x - 10 = 0, put only the coefficient in increasing degree of x (i.e. like -10  -1  3  4)";
    cout<<"\n Enter the highest degree of your polynomial function ";
    cin>>deg;
    input_function(f, deg);
    cout<<"\n Enter the interval for finding the root";
    cin>>a>>b;
    cout<<"\nUsing Bisection Method...";
    newton(f,a,deg);
    return 0;
}