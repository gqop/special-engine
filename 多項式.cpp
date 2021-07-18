#include<bits/stdc++.h>
using namespace std;
class poly
{
    public:
    vector<double> poly_data;
    void operator+(poly&);
    void operator-(poly&);
    void operator*(poly&);
};


void poly::operator+(poly& a)
{
    if(this->poly_data.size()<a.poly_data.size())
    {
        while(this->poly_data.size()<a.poly_data.size())
        {
            this->poly_data.push_back(0);
        }
    }
    for(int i=0; i<=a.poly_data.size()-1; i++)
    {
        if(a.poly_data[i]!=0)
        {
            this->poly_data[i]+=a.poly_data[i];
        }
    }
}

void poly::operator-(poly& a)
{
    if(this->poly_data.size()<a.poly_data.size())
    {
        while(this->poly_data.size()<a.poly_data.size())
        {
            this->poly_data.push_back(0);
        }
    }
    for(int i=0; i<a.poly_data.size(); i++)
    {
        if(a.poly_data[i]!=0)
        {
            this->poly_data[i]-=a.poly_data[i];
        }
    }
}

void poly::operator*(poly& a)
{
    vector<double> temp;
    int tempsize=this->poly_data.size();
    while(temp.size()<a.poly_data.size()+tempsize+1)
    {
        temp.push_back(0);
        this->poly_data.push_back(0);
    }
    for(int i=0; i<a.poly_data.size(); i++)
    {
        if(a.poly_data[i]!=0)
        {
            for(int r=0; r<this->poly_data.size(); r++)
            {
                if(this->poly_data[r]!=0)
                {
                    temp[i+r+1]+=a.poly_data[i]*this->poly_data[r];
                }
            }
        }
    }
    for(int i=0; i<temp.size(); i++)
    {
        this->poly_data[i]=temp[i];
    }
}

void set_poly(poly& a)
{
    double coe;
    int pow;
    while(cin>>coe)
    {
        cin>>pow;
        if(coe==-1&&pow==-1)
        {
            break;
        }
        else
        {
            if(pow+1>a.poly_data.size())
            {
                while(pow+1>a.poly_data.size())
                {
                    a.poly_data.push_back(0);
                }
            }
            a.poly_data[pow]+=coe;
        }
    }
}

void operate(poly& a)
{
    poly temp;
    set_poly(temp);
    bool f=0;
    for(int i=temp.poly_data.size()-1; i>=0; i--)
    {
        if(temp.poly_data[i]!=0)
        {
            if(f==1)
            {
                if(temp.poly_data[i]>0)
                    cout<<"+";
            }
            cout<<temp.poly_data[i]<<"x^"<<i;
            f=1;
        }
    }
    char op;
    cout<<endl;
    cout<<"enter which operate"<<endl;
    cin>>op;
    if(op=='+')
    {
        a+temp;
    }
    if(op=='-')
    {
        a-temp;
    }
    if(op=='*')
    {
        a*temp;
    }
}

void pre_and_continue(poly& a)
{
    system("cls");
    bool f=0;
    cout<<"the ans is:";
    for(int i=a.poly_data.size()-1; i>=0; i--)
    {
        if(a.poly_data[i]!=0)
        {
            if(f==1)
            {
                if(a.poly_data[i]>0)
                    cout<<"+";
            }
            cout<<a.poly_data[i]<<"x^"<<i;
            f=1;
        }
    }
    cout<<endl;
    cout<<"to continue please enter 1"<<endl;
    int r;
    cin>>r;
    if(r==1)
    {
        cout<<endl;
        cout<<"enter polynomial that will operate with the previous one(coefficient and  power ,enter -1 -1 to stop enter EX: 2 3 5 6 -1 -1=> 2X^3 + 5X^6)"<<endl;
        operate(a);
        pre_and_continue(a);
    }
}

int main()
{
    cout<<"enter your first polynomial(coefficient and  power ,enter -1 -1 to stop enter EX: 2 3 5 6 -1 -1=> 2X^3 + 5X^6)"<<endl;
    poly initial;
    set_poly(initial);
    bool f=0;
    for(int i=initial.poly_data.size()-1; i>=0; i--)
    {
        if(initial.poly_data[i]!=0)
        {
            if(f==1)
            {
                if(initial.poly_data[i]>0)
                    cout<<"+";
            }
            cout<<initial.poly_data[i]<<"x^"<<i;
            f=1;
        }
    }
    cout<<endl;
    cout<<"enter your second polynomial(coefficient and  power ,enter -1 -1 to stop enter EX: 2 3 5 6 -1 -1=> 2X^3 + 5X^6)"<<endl;
    operate(initial);
    pre_and_continue(initial);
    system("pause");
}
