#include<bits/stdc++.h>
using namespace std;
const double interest_rate = 0.001;
class user
{
    public:
        user(string,string,long double,char,int,int);
        void read_file();
        void establish_account();
        void overwrite_file();
        bool new_account(string);
        string account;
        string password;
        double balance;
        char ban;
        int false_times;
        int unrecord_times;
};
user::user(string a="none",string b="none",long double c=0,char d='N',int e=0,int f=0)
{
    account=a;
    password=b;
    balance=c;
    ban=d;
    false_times=e;
    unrecord_times=f;
}

vector<user> database;//declare
user index;

void user::read_file()
{
    ifstream fin("data.txt");
    string account_str;
    string password_str;
    long double balance_dou;
    char ban_ch;
    int false_times_int;
    if(!fin)
    {
        cout<<"error"<<endl;
    }
    while(fin>>account_str)
    {
        index.account=account_str;
        fin>>password_str;
        index.password=password_str;
        fin>>balance_dou;
        index.balance=balance_dou;
        fin>>ban_ch;
        index.ban=ban_ch;
        database.push_back(index);
    }
    fin.close();
}
void user::establish_account()
{
    ofstream fout("data.txt",ios::app|ios::out);
    string yes_or_no;//declare to 97
    string establish_account;
    string establish_password;
    system("cls");
    cout<<"您輸入的帳號並不存在"<<endl;
    cout<<"是否要建立新帳號？"<<endl << endl;
    cout<<"是  輸入yes / 否  任意輸入"<<endl << endl;
    cin>>yes_or_no;
    system("cls");
    if(new_account(yes_or_no))
    {
        cout<<"請輸入帳號名稱："<<endl;
        cin>>establish_account;
        fout<<endl<<establish_account<<' ';
        cout<<"請輸入密碼："<<endl;
        cin>>establish_password;
        fout<<establish_password<<' ';
        fout<<'0'<<' ';
        fout<<'N';
        cout<<"帳號創建完成"<<endl;
        fout.close();
        system("cls");
    }
    else
    {
        system("cls");
        exit;
    }
}

void user::overwrite_file()
{
    int database_size=database.size();
    ofstream fout("data.txt");
    for(int i=0;i<database_size;i++)
    {
        fout<<database[i].account<<' ';
        fout<<database[i].password<<' ';
        fout<<database[i].balance<<' ';
        fout<<database[i].ban<<endl;
    }
    fout.close();
}

bool user::new_account(string a)
{
    if(a=="yes")
    {
        return 1;
    }
    else
        return 0;
}

class menu
{
    private:
    bool the_first_time = true;
    public:
    int selection;
    void what_to_do();
    void redirection(int,int);
    void show_balance(int);
    void show_unrecord_times(int);
    void show_interest(int);
    void diposit(int);
    void withdraw(int);
    void plus_interest(int);
    void log_out(int);
    void up();
    void under();
};

string temp;
void menu::what_to_do()
{
    cout << "/---------------------------------------------------------\\"<< endl << endl;
    cout << "                     歡迎     " << temp << endl << endl;
	cout << "      查看帳戶餘額   請按  1 / 查看未登摺次數 請按  2" << endl;
    cout << "      顯示本階段利息 請按  3 / 存款           請按  4" << endl;
    cout << "      提款           請按  5 / 將利息加入本金 請按  6" << endl;
    cout << "      登出           請按  0" << endl << endl;
    cout << "\\---------------------------------------------------------/"<< endl ;
}

void menu::up(){
    cout << "/---------------------------------------------------------\\"<< endl << endl << endl;
}
void menu::under(){
    cout << endl << endl << endl;
    cout << "\\---------------------------------------------------------/"<< endl ;
}

void menu::redirection(int sel, int user_id)
{
	if(sel==1)
	{
		show_balance(user_id);
	}
	else if(sel==2)
	{
		show_unrecord_times(user_id);
	}
	else if(sel==3)
	{
		show_interest(user_id);
	}
	else if(sel==4)
	{
		diposit(user_id);
	}
	else if(sel==5)
	{
		withdraw(user_id);
	}
	else if(sel==6)
	{
		plus_interest(user_id);
	}
}

void menu::show_balance(int user_id)
{
    up();
	cout << "      餘額：" << setprecision(30)<<database[user_id].balance << endl << endl;
}

void menu::show_unrecord_times(int user_id)
{
    up();
	cout << "      未登摺次數：" << database[user_id].unrecord_times << endl << endl;
}

void menu::show_interest(int user_id)
{
    up();
	cout << "      目前利息：" << setprecision(30)<< database[user_id].balance*interest_rate << endl;
}

void menu::diposit(int user_id)
{
    system("cls");
	double diposit_num;
    up();
	cout << "      請輸入要存入之金額：" << endl << endl;
    under();
	cin>>diposit_num;
    cin.clear();
    system("cls");
    up();
	if(diposit_num<=0){
		cout << endl << "      無法存入。" << endl;
    }
    else if(diposit_num > 1000000000){
        cout << "      你應該是那麼多錢吧，請別開玩笑了" << endl;
    }
	else
	{
		database[user_id].balance+=diposit_num;
		cout << "      存入完成。" << endl;
		cout << "      目前餘額：" << setprecision(30)<<database[user_id].balance<< endl << endl;
	}
	database[user_id].unrecord_times++;
}

void menu::withdraw(int user_id)
{
	double withdraw_num;
    up();
	cout << "      請輸入要領出之金額：" << endl << endl;
	cout << "      ";
    under();
	cin>>withdraw_num;
    system("cls");
	if(withdraw_num > 1000000000){
		up();
        cout << "      機器沒那麼多鈔票，請至銀行櫃台提領" << endl;
	}

	else if(withdraw_num>database[user_id].balance){
        up();
		cout << "      餘額不足"<<endl;
    }

	else
	{
        up();
		database[user_id].balance-=withdraw_num;
		cout << "      請取鈔" << withdraw_num << endl;
        _sleep(3/2*1000);
		cout << "      餘額：" << setprecision(30)<<database[user_id].balance << endl;
	}

	database[user_id].unrecord_times++;
}

void menu::plus_interest(int user_id)
{
    if(the_first_time){
        up();
        database[user_id].balance+=database[user_id].balance*interest_rate;
        cout<<"      已加入利息"<< database[user_id].balance*interest_rate <<endl;
        cout << "      餘額：" << setprecision(30)<<database[user_id].balance << endl;
        database[user_id].unrecord_times++;
        the_first_time = false;
    }
    else{
        up();
        cout << "      您已經加入過利息了"<<endl;
    }
}

int main()
{
    _front://348
    index.read_file();
    string enter_account;
    string enter_password;
    int database_size=database.size();//declare
    system("cls");
    _login://311
    cout<<"請輸入帳號：";
    cin>>enter_account;
    cin.clear();
    for(int i=0;i<database_size;i++)
    {
        if(enter_account==database[i].account)
        {
            _back://342
            temp = enter_account;
            if(database[i].ban=='Y')
            {
            	cout<<"此帳戶已遭鎖定"<<endl;
            	index.overwrite_file();
                return 0;
            }
            cout<<"請輸入密碼：";
            cin>>enter_password;
            cin.clear();
            if(enter_password==database[i].password)
            {
				system("CLS");
				int selection;
				menu menu_index;
				_back_to_menu://323
				menu_index.what_to_do();
				cin>>selection;
				system("CLS");
				if(selection==0)
				{
					index.overwrite_file();
					goto _login;//go to 280
				}
				else
				{
					menu_index.redirection(selection,i);
					cout << "      是否回到主選單？" << endl;
                    cout << "      是  輸入yes / 否  任意輸入"<< endl;
                    menu_index.under();
					string YN;
					cin>>YN;
					if(YN=="yes"){
                        system("CLS");
						goto _back_to_menu;//go to 304
                    }
					else{
						index.overwrite_file();
                        system("CLS");
                        cout << endl <<"感謝您的惠顧  歡迎再次光臨";
                        _sleep(4*1000);
                        system("CLS");
						break;
                    }
				}
            }
            else if(enter_password!=database[i].password)
            {
                database[i].false_times+=1;
                if(database[i].false_times==3)
                {
                    database[i].ban='Y';
                }
                goto _back;//go to 288
            }
        }
        else if((i==database_size-1)&&(enter_account!=database[i].account))
        {
            index.establish_account();
            goto _front;//go to 274
        }
    }
}

