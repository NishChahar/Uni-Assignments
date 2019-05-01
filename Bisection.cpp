#include<iostream>
#include<cmath>

using namespace std;

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

void bisection(int f[], float a, float b, int d, int n=1, float epsilon = 0.000001, int MAX = 100)
{
    while(n<MAX)
    {
        float c = (a+b)/2.0;
         //cout<<"\nValue of a,b and c "<<a<<" "<<b<<" "<<c;
         //float fct=;
        if(calculate_f(f,c,d)==0 || ((b-a)/2.0)<epsilon)                
            {cout<<"\n Root found at "<<c;
            break;}
        else 
        {
            //cout<<"\nIn else";
            n++; //cout<<"\n n="<<n;
            //float fa = calculate_f(f,a,d);
            if((calculate_f(f,a,d)*calculate_f(f,c,d))>0)
             a=c; //cout<<"\n a and c "<<a<<" "<<c;}
            else
             b=c; //cout<<"\n b and c "<<b<<" "<<c;}
        }
    }
    cout<<"\nError..."; 
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
    bisection(f,a,b,deg);
    return 0;
}