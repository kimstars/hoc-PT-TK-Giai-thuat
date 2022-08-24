#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const string numstr[] = {
    "khong ", "mot ", "hai ", "ba ", "bon ", "nam ", "sau ", "bay ", "tam ", "chin "};


int c[10];
long n;


void so_to_mang() // chuyển số nguyên sang mảng
{
    int i;
    for (i = 1; i <= 7; i++)
        c[i] = 0;
    i = 7;
    while (n != 0)
    {
        c[i] = n % 10;
        n = n / 10;
        i--;
    }
}


void printMang(){
    for(int i = 1; i <= 7; i++){
        cout << c[i] << " ";
    }
}

void NhapDL(){
    do{
        cout << "Nhap N : ";
        cin >> n;
        if(n < 0 || n > 9999999){
            cout << "Nhap lai N (0,9999999)" << endl;
        }
    }while(n < 0 || n > 9999999);
}

void LayVT(int vt){
  
    if(vt == 7) return ;
    switch(vt){
        case 1 : 
            cout << "trieu "; break;
        case 2 : 
            if( !((c[vt+2] == 0) && (c[vt+1] == 0) && (c[vt] == 0)) )
                cout << "tram "; break;

        case 3 : case 6 :
            if(c[vt] != 0)
                cout << "muoi ";
            else{
                if(c[vt+1]!= 0)
                    cout << "le ";
            }
            break;

        case 4 : 
            if(!((c[vt] == 0) && (c[vt - 1] == 0) && (c[vt-2] == 0))) // 0005000
                cout << "nghin "; break;

        case 5 : 
            if(!((c[vt+2] == 0) && (c[vt+1] == 0) && c[vt] == 0))
                cout << "tram "; break;
        
    }
}

void DocSo(long n){
    so_to_mang();
    // truong hop co mot so 0
    int vtd = 8;
    for(int i = 1; i <= 7; i++){
        if(c[i] != 0){
            vtd = i;
            break;
        }
    }
    if(vtd == 8) {
        cout << "khong "; return;
    }

    for (int i = vtd; i <= 7; i++){
        switch(c[i]){
            case 1: case 2: case 3: case 4: case 6: case 7: case 8: case 9:
                cout << numstr[c[i]]; LayVT(i); break;

            case 5:
                if(i == 6){
                    if(c[i - 1] == 0) cout << "nam "; // giua 
                    else cout << "lam "; // cuoi
                    LayVT(i);

                }else{
                    if(i == 4){
                        if(c[i-1] == 0){
                            cout << "nam ";
                        }else{
                            cout << "lam ";
                        }
                    }else{
                        cout << numstr[c[i]]; 
                    }
                    LayVT(i);
                }
                break;

            case 0:
                if (((i == 5) || (i == 2)) && ((c[i + 2] != 0) || ((c[i + 1] != 0))))
                    cout << numstr[c[i]];
                    LayVT(i);
                break;

        }
    }


}




int main()
{
    NhapDL();
    DocSo(n);
    cout << endl;

}