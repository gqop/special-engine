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
    cout<<"�z��J���b���ä��s�b"<<endl;
    cout<<"�O�_�n�إ߷s�b���H"<<endl << endl;
    cout<<"�O  ��Jyes / �_  ���N��J"<<endl << endl;
    cin>>yes_or_no;
    system("cls");
    if(new_account(yes_or_no))
    {
        cout<<"�п�J�b���W�١G"<<endl;
        cin>>establish_account;
        fout<<endl<<establish_account<<' ';
        cout<<"�п�J�K�X�G"<<endl;
        cin>>establish_password;
        fout<<establish_password<<' ';
        fout<<'0'<<' ';
        fout<<'N';
        cout<<"�b���Ыا���"<<endl;
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
    cout << "                     �w��     " << temp << endl << endl;
	cout << "      �d�ݱb��l�B   �Ы�  1 / �d�ݥ��n�P���� �Ы�  2" << endl;
    cout << "      ��ܥ����q�Q�� �Ы�  3 / �s��           �Ы�  4" << endl;
    cout << "      ����           �Ы�  5 / �N�Q���[�J���� �Ы�  6" << endl;
    cout << "      �n�X           �Ы�  0" << endl << endl;
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
	cout << "      �l�B�G" << setprecision(30)<<database[user_id].balance << endl << endl;
}

void menu::show_unrecord_times(int user_id)
{
    up();
	cout << "      ���n�P���ơG" << database[user_id].unrecord_times << endl << endl;
}

void menu::show_interest(int user_id)
{
    up();
	cout << "      �ثe�Q���G" << setprecision(30)<< database[user_id].balance*interest_rate << endl;
}

void menu::diposit(int user_id)
{
    system("cls");
	double diposit_num;
    up();
	cout << "      �п�J�n�s�J�����B�G" << endl << endl;
    under();
	cin>>diposit_num;
    cin.clear();
    system("cls");
    up();
	if(diposit_num<=0){
		cout << endl << "      �L�k�s�J�C" << endl;
    }
    else if(diposit_num > 1000000000){
        cout << "      �A���ӬO����h���a�A�ЧO�}�����F" << endl;
    }
	else
	{
		database[user_id].balance+=diposit_num;
		cout << "      �s�J�����C" << endl;
		cout << "      �ثe�l�B�G" << setprecision(30)<<database[user_id].balance<< endl << endl;
	}
	database[user_id].unrecord_times++;
}

void menu::withdraw(int user_id)
{
	double withdraw_num;
    up();
	cout << "      �п�J�n��X�����B�G" << endl << endl;
	cout << "      ";
    under();
	cin>>withdraw_num;
    system("cls");
	if(withdraw_num > 1000000000){
		up();
        cout << "      �����S����h�r���A�ЦܻȦ��d�x����" << endl;
	}

	else if(withdraw_num>database[user_id].balance){
        up();
		cout << "      �l�B����"<<endl;
    }

	else
	{
        up();
		database[user_id].balance-=withdraw_num;
		cout << "      �Ш��r" << withdraw_num << endl;
        _sleep(3/2*1000);
		cout << "      �l�B�G" << setprecision(30)<<database[user_id].balance << endl;
	}

	database[user_id].unrecord_times++;
}

void menu::plus_interest(int user_id)
{
    if(the_first_time){
        up();
        database[user_id].balance+=database[user_id].balance*interest_rate;
        cout<<"      �w�[�J�Q��"<< database[user_id].balance*interest_rate <<endl;
        cout << "      �l�B�G" << setprecision(30)<<database[user_id].balance << endl;
        database[user_id].unrecord_times++;
        the_first_time = false;
    }
    else{
        up();
        cout << "      �z�w�g�[�J�L�Q���F"<<endl;
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
    cout<<"�п�J�b���G";
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
            	cout<<"���b��w�D��w"<<endl;
            	index.overwrite_file();
                return 0;
            }
            cout<<"�п�J�K�X�G";
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
					cout << "      �O�_�^��D���H" << endl;
                    cout << "      �O  ��Jyes / �_  ���N��J"<< endl;
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
                        cout << endl <<"�P�±z���f�U  �w��A�����{";
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

