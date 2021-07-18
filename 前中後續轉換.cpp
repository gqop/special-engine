#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

bool is_operator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int get_priority(char c)
{
    if (c== '*'||c=='/')
        return 2;
    else if (c =='-'||c=='+')
        return 1;
    return 0;
}
string infix_to_postfix(string infix)
{
    string postfix;
    stack<char> index;
    for(int i=0;i<infix.length();i++)
    {
        if(isalpha(infix[i]) || isdigit(infix[i]))
        {
            postfix+=infix[i];
        }
        else if(infix[i]=='(')
        {
            index.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while((index.top()!='(')&&(!index.empty()))
            {
                char temp=index.top();
                postfix+=temp;
                index.pop();
            }
            if(index.top()=='(')
            {
                index.pop();
            }
        }
        else if(is_operator(infix[i]))
        {
            if(index.empty())
            {
                index.push(infix[i]);
            }
            else
            {
                if(get_priority(infix[i])>get_priority(index.top()))
                {
                    index.push(infix[i]);
                }
                else
                {
                    while((!index.empty())&&(get_priority(infix[i])<=get_priority(index.top())))
                    {
                        char temp=index.top();
                        postfix+=temp;
                        index.pop();
                    }
                    index.push(infix[i]);
                }
            }
        }
    }
    while(!index.empty())
    {
        postfix+=index.top();
        index.pop();
    }
    return postfix;
}

string postfix_to_prefix(string postfix,int& num)
{
    string str="";
    if(num==0)
    {
        reverse(postfix.begin(),postfix.end());
    }
    if(isdigit(postfix[num])||isalpha(postfix[num]))
    {
        str+=postfix[num];
        return str;
    }
    else
    {
        string num1,num2;
        char now=postfix[num];
        num++;
        num1=postfix_to_prefix(postfix,num);
        num++;
        num2=postfix_to_prefix(postfix,num);
        return now+num2+num1;
    }
}

string prefix_to_infix(string prefix,int& num)
{
    string str="";
    if(isdigit(prefix[num])||isalpha(prefix[num]))
    {
        str+=prefix[num];
        return str;
    }
    else
    {
        string num1,num2;
        char now=prefix[num];
        num++;
        num1=prefix_to_infix(prefix,num);
        num++;
        num2=prefix_to_infix(prefix,num);
        return "("+num1+now+num2+")";
    }
}

string postfix_to_infix(string postfix,int& num)
{
    string str="";
    if(num==0)
    {
        reverse(postfix.begin(),postfix.end());
    }
    if(isdigit(postfix[num])||isalpha(postfix[num]))
    {
        str+=postfix[num];
        return str;
    }
    else
    {
        string num1,num2;
        char now=postfix[num];
        num++;
        num1=postfix_to_infix(postfix,num);
        num++;
        num2=postfix_to_infix(postfix,num);
        return "("+num2+now+num1+")";
    }
}

string pretopre(string a)
{
    if(isdigit(a[0]))
    {
        string tmp="";
        tmp=tmp+a[0];
        return tmp;
    }
    else
    {
        string left=pretopre(a.substr(1,a.size()-1));
        string right=pretopre(a.substr(left.size()+1));
        return a[0]+left+right;
    }
}
double compute(string str)//傳入前序
{
    if(isdigit(str[0]))
    {
        return str[0]-48;
    }
    else 
    {
        char compute_d=str[0];
        string left=pretopre(str.substr(1,str.size()-1));
        string right=pretopre(str.substr(left.size()+1));
        if(compute_d=='+')
        {
            return compute(left)+compute(right);
        }
        else if(compute_d=='-')
        {
            return compute(left)-compute(right);
        }
        else if(compute_d=='/')
        {
            return compute(left)/compute(right);
        }
        else if(compute_d=='*')
        {
           return compute(left)*compute(right);
        }    
    }
}

void list(){
    system("cls");
    cout<<"1. prefix to infix and postfix."<<endl;
    cout<<"2. infix to prefix and postfix."<<endl;
    cout<<"3. postfix to prefix and infix."<<endl;
    cout<<"4. exit."<<endl;
}

int main()
{
    int which;
    int _count=0;
    string prefix;
    string infix;
    string postfix;
    list();
    while(cin>>which)
    {
        system("cls");
        if(which==1)
        {
            cout<<"prefix to infix and postfix"<<endl;
            _count=0;
            cin>>prefix;
            infix=prefix_to_infix(prefix,_count);
            infix = infix.substr(1, infix.length()-2);
            cout<<"Infix is: "<<infix<<endl;
            cout<<"Postfix is: "<<infix_to_postfix(infix)<<endl;
            cout << "The value is: " << compute(prefix) <<endl;
        }
        else if(which==2)
        {
            cout<<"infix to prefix and postfix"<<endl;
            _count=0;
            cin>>infix;
            postfix=infix_to_postfix(infix);
            string temp = postfix_to_prefix(postfix,_count);
            cout<<"Prefix is: "<<temp<<endl;
            cout<<"Postfix is: "<<postfix<<endl;
            cout << "The value is: " << compute(temp) <<endl;
        }
        else if(which==3)
        {
            cout<<"postfix to prefix and infix"<<endl;
            _count=0;
            cin>>postfix;
            infix=postfix_to_infix(postfix,_count);
            infix = infix.substr(1, infix.length()-2);
            _count=0;
            string temp = postfix_to_prefix(postfix,_count);
            cout<<"Prefix is: "<<temp<<endl;
            cout<<"Infix is: "<<infix<<endl;
            cout << "Value: " << compute(temp) << endl;
        }
        else if(which==4)
        {
            system("cls");
            break;
        }
        system("pause");
        cout<<"returning to menu";
        for(int i = 0; i< 3; i++){
            _sleep(500);
            cout<<'.';
        }
        list();
    }
}
//*/+785+4-93 prefix
//(((7+8)/5)*(4+(9-3))) infix
//78+5/493-+* postfix
