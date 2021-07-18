#include<bits/stdc++.h>
using namespace std;
class mergeSort
{
    private:
        int data_size;
        vector<int> data;
        void sub_sort(int, int);
        void merge(int, int, int, int);
        void sub_display(int, int);
    public:
        mergeSort(int);
        void sort();
        void display();
};
mergeSort::mergeSort(int a=50)
{
    srand(time(NULL));
    data_size=a;
    while(a--)
    {
        int x=rand()%100;
        data.push_back(x);
    }
}



void mergeSort::sub_sort(int front, int end)
{
    if(front>=end)
        return;
    int mid = (end+front)/2;
    //=======================================
    cout<<"split"<<endl;                 
    for(int i=front; i<=end; i++)
    {
        cout<<this->data[i]<<' ';
    }
    cout<<endl;
    for(int i=front; i<=mid; i++)
    {
        cout<<this->data[i]<<' ';
    }
    cout<<endl;
    for(int i=front; i<mid; i++)
    {
        cout<<"   ";
    }
    for(int i=mid+1; i<=end; i++)
    {
        cout<<this->data[i]<<' ';
    }
    cout<<endl;
    //========================================
    sub_sort(front, mid);
    sub_sort(mid+1, end);
    merge(front, mid, mid+1, end);
}



void mergeSort::merge(int L_front, int  L_end, int R_front, int R_end)
{
    cout<<"merge"<<endl;
    vector<int> L_Sub(this->data.begin() + L_front, this->data.begin() + L_end+1);
    vector<int> R_Sub(this->data.begin() + R_front, this->data.begin() + R_end+1);
    //======================================
    for(int i=0; i<L_Sub.size(); i++)
    {
        cout<<L_Sub[i]<<' ';
    }
    cout<<endl;
    for(int i=0; i<L_Sub.size(); i++)
    {
        cout<<"   ";
    }
    for(int i=0; i<R_Sub.size(); i++)
    {
        cout<<R_Sub[i]<<' ';
    }
    cout<<endl;
    //======================================
    L_Sub.insert(L_Sub.end(), numeric_limits<int>::max());
    R_Sub.insert(R_Sub.end(), numeric_limits<int>::max());
    int L_index = 0, R_index = 0;
    for (int i = L_front; i <= R_end; i++) 
    {
        if (L_Sub[L_index] < R_Sub[R_index]) 
        {
            this->data[i] = L_Sub[L_index];
            L_index++;
        } 
        else 
        {
            this->data[i] = R_Sub[R_index];
            R_index++;
        }
    }
    //======================================
    for(int i=L_front; i<=R_end; i++)
    {
        cout<<this->data[i]<<' ';
    }
    //======================================
    cout<<endl;
}



void mergeSort::sort()
{
    sub_sort(0, data_size-1);
}



void mergeSort::display()
{
    for(int i=0; i<data_size; i++)
    {
        cout<<this->data[i]<<' ';
    }
    cout<<endl;
}



int main()
{
    int num;
    cin>>num;
    mergeSort a(num);
    cout<<"unsorted:  ";
    a.display();
    a.sort();
    cout<<"sorted:  ";
    a.display();
    system("pause");
}