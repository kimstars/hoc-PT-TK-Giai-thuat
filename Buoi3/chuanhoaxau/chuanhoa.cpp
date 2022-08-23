
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void XoaDau_Cuoi(string &s)
{

    while (s[0] == 32)
    {
        strcpy(&s[0], &s[1]);
    }


    while (s[s.length() -1] == 32)
    {
        strcpy(&s[s.length()-1], "");
    }
   
}

void LowerAll(string &s){
    for(int i = 0 ;i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
}

void XoaTrong(string &s)
{
    int i = 1;
    int n = s.length();
    while (i < n)
    {
        while ((s[i+1] == ' ')  &&(s[i] == ' ') )
            strcpy(&s[i], &s[i+1]);
        i++;
    }
}


void Xoa_Trc_DB(string &s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if ((s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == ':') && (s[i - 1] == ' '))
        {
            strcpy(&s[i-1], &s[i]);
        }
    }
}

void Them_Sau_DB(string &s){
    string b;
    int n = s.length();
    for(int i = 0 ;i < n ; i++) {
         if ((s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == ':') && (s[i + 1] != ' '))
        {
            strcpy(&b[0], &s[i+1]);
            s[i+1] = 32;
            strcpy(&s[i+2], &b[0]);
        }
    }
}


void Viet_hoa_dau(string &s){
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.length()-1; i++){
        if(s[i] == '.'){
            s[i+2] = toupper(s[i+2]);
        }
    }
}


int main()
{
    string str;
    fflush(stdin);
    getline(cin, str);

    // chuan hoa
    XoaDau_Cuoi(str);
    XoaTrong(str);
    Xoa_Trc_DB(str);
    LowerAll(str);
    Them_Sau_DB(str);
    Viet_hoa_dau(str);


    //
    cout << str;
}