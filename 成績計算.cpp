#include<bits/stdc++.h>
using namespace std;

bool sorted=0;
class Grade
{
    public:
        Grade();
        void set_name(string);
        void set_quiz1(int);
        void set_quiz2(int);
        void set_midterm(int);
        void set_final_exam(int);
        void set_average();
        void set_grade_lv(double);
        void set_rank(int);
        string get_name();
        int get_quiz1();
        int get_quiz2();
        int get_midterm();
        int get_final_exam();
        double get_average();
        char get_grade_lv();
        int get_rank();
    private:
        string name;
        int quiz1;
        int quiz2;
        int midterm;
        int final_exam;
        double average;
        char grade_lv;
        int rank;
};

vector<Grade> database;

Grade::Grade()
{}

void Grade::set_name(string a){
    name=a;
}

void Grade::set_quiz1(int a){
    quiz1=a;
}

void Grade::set_quiz2(int a){
    quiz2=a;
}

void Grade::set_midterm(int a){
    midterm=a;
}

void Grade::set_final_exam(int a){
    final_exam=a;
}

void Grade::set_average(){
    double temp;
    temp=((quiz1+quiz2)/20.0*25)+(midterm/100.0*25)+(final_exam/100.0*50);
    average=temp;
}

void Grade::set_grade_lv(double a){
    a=average;
    if(a>=90)
        grade_lv='A';
    else if(a<90&&a>=80)
        grade_lv='B';
    else if(a<80&&a>=70)
        grade_lv='C';
    else if(a<70&&a>=60)
        grade_lv='D';
    else if(a<60)
        grade_lv='F';
}

void Grade::set_rank(int a){
    rank=a;
}

string Grade::get_name(){
    return name;
}

int Grade::get_quiz1(){
    return quiz1;
}

int Grade::get_quiz2(){
    return quiz2;
}

int Grade::get_midterm(){
    return midterm;
}

int Grade::get_final_exam(){
    return final_exam;
}

double Grade::get_average(){
    return average;
}

char Grade::get_grade_lv(){
    return grade_lv;
}

int Grade::get_rank(){
    return rank;
}

void set_Grade(){
    Grade get_push;
    fstream fin;
    fin.open("data.txt");
    string temp_str;
    int temp_int;
    while(fin>>temp_str){
        get_push.set_name(temp_str);
        fin>>temp_int;
        get_push.set_quiz1(temp_int);
        fin>>temp_int;
        get_push.set_quiz2(temp_int);
        fin>>temp_int;
        get_push.set_midterm(temp_int);
        fin>>temp_int;
        get_push.set_final_exam(temp_int);
        get_push.set_average();
        get_push.set_grade_lv(get_push.get_average());
        database.push_back(get_push);
    }
}

bool comp(Grade a,Grade b){
    return a.get_average()>b.get_average();
}

void insert_rank(){
    for(int i=0; i<database.size(); i++)
    {
        database[i].set_rank(i+1);
    }
}

void sort_by_aver(){
    sort(database.begin(),database.end(),comp);
}

void about_Grade(){
    cout<<left<<setw(7)<<"Name"<<setw(9)<<"Quiz 1"<<setw(9)<<"Quiz 2"<<setw(10)<<"Midterm"<<setw(13)<<"Final Exam"<<setw(18)<<"semester grade"<<setw(7)<<"GPA"<<setw(5)<<"rank"<<endl;
}

void prese_grade(){
    for(int i=0; i<database.size(); i++){
        cout<<setw(7)<<left<<database[i].get_name()<<setw(9)<<database[i].get_quiz1()<<setw(9)<<database[i].get_quiz2();
        cout<<setw(10)<<database[i].get_midterm()<<setw(13)<<database[i].get_final_exam()<<setw(18)<<database[i].get_average()<<setw(7)<<database[i].get_grade_lv()<<endl;
    }
}

void prese_grade2(){
    for(int i=0; i<database.size(); i++){
        cout<<setw(7)<<left<<database[i].get_name()<<setw(9)<<database[i].get_quiz1()<<setw(9)<<database[i].get_quiz2();
        cout<<setw(10)<<database[i].get_midterm()<<setw(13)<<database[i].get_final_exam()<<setw(18)<<database[i].get_average()<<setw(7)<<database[i].get_grade_lv()<<setw(5)<<database[i].get_rank()<<endl;
    }
}
bool comp2(Grade a, Grade b)
{
    return a.get_name()<b.get_name();
}

void sort_by_name(){
    sort(database.begin(),database.end(),comp2);
}

void check_x(bool a)
{
    int i;
    cout<<"enter which student u want to check"<<endl;
    cin>>i;
    i=i-1;
    if(i>database.size())
        cout<<"theres no that much students"<<endl;
    else
    {
        cout<<left<<setw(7)<<"Name"<<setw(9)<<"Quiz 1"<<setw(9)<<"Quiz 2"<<setw(10)<<"Midterm"<<setw(13)<<"Final Exam"<<setw(18)<<"semester grade"<<setw(7)<<"GPA"<<setw(5)<<"rank"<<endl;
        cout<<left<<setw(7)<<database[i].get_name()<<setw(9)<<database[i].get_quiz1()<<setw(9)<<database[i].get_quiz2();
        if(a==1)
        {
            cout<<left<<setw(10)<<database[i].get_midterm()<<setw(13)<<database[i].get_final_exam()<<setw(18)<<database[i].get_average()<<setw(7)<<database[i].get_grade_lv()<<setw(5)<<database[i].get_rank()<<endl;
        }
        else
        {
            cout<<left<<setw(10)<<database[i].get_midterm()<<setw(13)<<database[i].get_final_exam()<<setw(18)<<database[i].get_average()<<setw(7)<<database[i].get_grade_lv()<<endl;
        }
    }
}

void todolist(int todo)
{
    system("cls");
    if(todo==1)
        check_x(sorted);
    if(todo==2)
    {
        sorted=1;
        sort_by_aver();
        insert_rank();
        about_Grade();
        prese_grade2();
    }
    cout<<"to check numberX student please enter 1 then enter X"<<endl;
    cout<<"to sort by average and get rank plaese enter 2"<<endl;
    int rock;
    cin>>rock;
    todolist(rock);
}

int main(){
    set_Grade();
    sort_by_name();
    about_Grade();
    prese_grade();
    int todo;
    cout<<"to check numberX student please enter 1 then enter X"<<endl;
    cout<<"to sort by average and get rank plaese enter 2"<<endl;
    cin>>todo;
    todolist(todo);
}
