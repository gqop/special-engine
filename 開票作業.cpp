#include<bits/stdc++.h>
using namespace std;

int stoi(string a)
{
    stringstream string_to_int;
    int n;
    string_to_int<<a;
    string_to_int>>n;
    return n;
}
int main()
{
    string s1; //declare
    vector<string> name;
    ifstream fin("name.txt");
    if(!fin)
    {
        cout<<"warnning"<<endl;
    }
    while(fin>>s1)
    {
        name.push_back(s1);
    }
    fin.close();
    int ll=name.size(),region1[ll]={0},region2[ll]={0},region3[ll]={0},region4[ll]={0},region5[ll]={0}; //int
    for(int i=0;i<ll;i++)
    {
        for(int j=i+1;j<ll;j++)
        {
            if(name[i]>name[j])
            {
                swap(name[i],name[j]);
            }
        }
    }
    string s2; //declare
    vector<string> all;
    ifstream fin2("data.txt");
    if(!fin2)
    {
        cout<<"warnning"<<endl;
    }
    while(fin2>>s2)
    {
        all.push_back(s2);
    }
    fin2.close();
    int ll2=all.size(),all_sum=0,sum1=0,sum2=0,sum3=0,sum4=0,all_received=0,received1=0,received2=0,received3=0,received4=0; //declare
    string winner1,winner2,winner3,winner4,all_winner; //declare
    for(int i=0;i<ll2;i=i+3)
    {
        for(int j=0;j<ll;j++)
        {
            if(all[i]==name[j])
            {
                int num=stoi(all[i+1]);//declare
                if(num==1)
                {
                    region1[j]+=stoi(all[i+2]);
                }
                else if(num==2)
                {
                    region2[j]+=stoi(all[i+2]);
                }
                else if(num==3)
                {
                    region3[j]+=stoi(all[i+2]);
                }
                else if(num==4)
                {
                    region4[j]+=stoi(all[i+2]);
                }
            }
        }
    }
    cout<<"         ------------Election Results-------------          "<<endl;
    cout<<"Name       Region1   Region2   Region3   Region4       Total"<<endl;
    cout<<"---------  -------   -------   -------   -------   ---------"<<endl;
    for(int i=0;i<ll;i++)
    {
        region5[i]=region1[i]+region2[i]+region3[i]+region4[i];
        cout<<left<<setw(9)<<name[i]<<"  "<<right<<setw(7)<<region1[i]<<"   "<<setw(7)<<region2[i]<<"   "<<setw(7)<<region3[i]<<"   "<<setw(7)<<region4[i]<<"   "<<setw(9)<<region5[i]<<endl;
        sum1+=region1[i];
        sum2+=region2[i];
        sum3+=region3[i];
        sum4+=region4[i];
        all_sum+=region5[i];
        if(region1[i]>received1)
        {
            received1=region1[i];
            winner1=name[i];
        }
        if(region2[i]>received2)
        {
            received2=region2[i];
            winner2=name[i];
        }
        if(region3[i]>received3)
        {
            received3=region3[i];
            winner3=name[i];
        }
        if(region4[i]>received4)
        {
            received4=region4[i];
            winner4=name[i];
        }
        if(region5[i]>all_received)
        {
            all_received=region5[i];
            all_winner=name[i];
        }
    }
    cout<<endl<<endl;
    cout<<"Region 1 Winner: "<<winner1<<", Votes Received: "<<received1<<endl;
    cout<<"Region 2 Winner: "<<winner2<<", Votes Received: "<<received2<<endl;
    cout<<"Region 3 Winner: "<<winner3<<", Votes Received: "<<received3<<endl;
    cout<<"Region 4 Winner: "<<winner4<<", Votes Received: "<<received4<<endl;
    cout<<"Winner: "<<all_winner<<", Votes Received: "<<all_received<<endl<<endl;
    cout<<"Region 1 votes polled: "<<sum1<<endl;
    cout<<"Region 2 votes polled: "<<sum2<<endl;
    cout<<"Region 3 votes polled: "<<sum3<<endl;
    cout<<"Region 4 votes polled: "<<sum4<<endl;
    cout<<"Total votes polled: "<<all_sum<<endl;
}
