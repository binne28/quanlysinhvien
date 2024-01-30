#include <bits/stdc++.h>
using namespace std;
#define str string
#define fl float
#define db double
#define ll long long

class QuanLy
{
    public:
        str name;
        str id;
        db toan, ly, hoa;
        fl tb;

    QuanLy(){
        toan = 0;
        ly = 0;
        hoa = 0;
    }

    void nhap(){
        cout << "Nhap ten sinh vien: ";
        getline(cin, name);
        cout << "Nhap MSSV: ";
        cin >> id;
        cout << "Nhap diem toan: ";
        cin >> toan;
        cout << "Nhap diem ly: ";
        cin >> ly;
        cout << "Nhap diem hoa: ";
        cin >> hoa;
    }

    db tinh(){
        tb = (toan + ly + hoa) / 3;
        return tb;
    }

    str xep_loai(){
        fl a = tinh();
        str hocluc;
        if(a >= 9){
            hocluc = "Xuat sac";
        }else if(a >= 8 && a < 9){
            hocluc = "Gioi";
        }else if(a >= 7 && a < 8){
            hocluc = "Kha";
        }else if(a >= 6 && a < 7){
            hocluc = "Trung binh kha";
        }else if(a >= 5 && a < 6){
            hocluc = "Trung binh";
        }else{
            hocluc = "Yeu";
        }
        return hocluc;
    }

    void xuat(){
        cout << name << " " << id << " " << " " << tb << " " << xep_loai() << endl;
    }
};



int main(){
    vector<QuanLy> dssv;
    QuanLy sv;
    int choice;
    do{
        cout << "---------- MENU ----------\n";
        cout << "1. Hien thi xep loai sinh vien\n";
        cout << "2. Hien thi diem TBC cao nhat\n";
        cout << "3. Hien thi sinh vien yeu\n";
        cout << "4. Tim sinh vien theo ten\n";
        cout << "5. Tim sinh vien theo ma\n";
        cout << "6. Xoa sinh vien\n";
        cout << "7. Hien thi danh sach sinh vien\n";
        cout << "0. Exit\n";
        cout << "Moi ban nhap lua chon: ";
        cin >> choice;
        if(choice == 1){
            cin.ignore();
            sv.nhap();
            sv.xep_loai();
            sv.xuat();
            dssv.push_back(sv);
        }else if(choice == 2){
            QuanLy tmp;
                for(auto i:dssv){
                    if(i.tb > tmp.tb){
                        tmp = i;
                    }
                }
                tmp.xuat();
        }else if(choice == 3){
                bool tim = false;
                for(auto i:dssv){
                    if(i.xep_loai() == "Yeu"){
                        tim = true;
                        i.xuat();
                    }
                }
                if(tim == false){
                    cout << "Khong co sinh vien nao dat loai yeu\n";
                }
        }else if(choice == 4){
            cin.ignore();
            str s;
            cout << "Nhap ten sinh vien can tim: ";
            getline(cin, s);
            bool tim = false;
            for(auto i:dssv){
                if(i.name == s){
                    tim = true;
                    i.xuat();
                }
            }
            if(tim == false){
                cout << "Khong ton tai!!!";
            }
        }else if(choice == 5){
            str s1;
            cout << "Nhap ma sinh vien can tim: ";
            cin >> s1;
            bool tim = false;
            for(auto i:dssv){
                if(i.id == s1){
                    tim = true;
                    i.xuat();
                }
            }
            if(tim == false){
                cout << "Khong ton tai!!!";
            }
        }else if(choice == 6){
            str s;
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> s;
            for(auto i = dssv.begin(); i != dssv.end(); i++){
                if(i->id == s){
                    dssv.erase(i);
                    cout << "Da xoa sinh vien";
                    break;
                }
            }
        }else if(choice == 7){
            cout << "------- Danh sach sinh vien -------\n";
            for(auto i:dssv){
                i.xuat();
                cout << endl;
            }
        }else{
            cout << "Tam biet!\n";
        }
    }while(choice != 0);
}
