#include <bits/stdc++.h>
using namespace std;
#define str string
#define ll long long
#define fl float
#define db double

class Student{
    public:
        str name;
        str id;
        db toan, ly, hoa;
        db tbc;
    
    void nhap(){
        cout << "Nhap ho va ten: ";
        getline(cin, name);
        cout << "Nhap ma so sinh vien: ";
        cin >> id;
        cout << "Nhap diem toan: ";
        cin >> toan;
        cout << "Nhap diem ly: ";
        cin >> ly;
        cout << "Nhap diem hoa: ";
        cin >> hoa;
    }


    db tinh(){
        tbc = (toan + ly + hoa) / 3;
        return tbc;
    }
    
    str xep_loai(){
        fl a = tinh();
        str hoc_luc;
        if(a >= 8){
            hoc_luc = "Gioi";
        }else if(a < 8 && a >= 7){
            hoc_luc = "Kha";
        }else if(a < 7 && a >= 6){
            hoc_luc = "Trung binh";
        }else{
            hoc_luc = "Yeu";
        }
        return hoc_luc;
    }
    
    void in(){
        cout << name << " " << id << " " << tbc << " " << xep_loai() << endl;
    }    
    
};

int main(){
    vector<Student> dssv;
    Student sv;
    int choice;
    do{
        cout << "---------- MENU ----------\n";
        cout << "1. Hien thi xep loai\n";
        cout << "2. Hien thi sinh vien co DTB cao nhat\n";
        cout << "3. Hien thi sinh vien co DTB thap nhat\n";
        cout << "4. Hien thi sinh vien xep loai yeu\n";
        cout << "5. Hien thi sinh vien xep loai gioi\n";
        cout << "6. Tim sinh vien theo ten\n";
        cout << "7. Tim sinh vien theo ma so sinh vien\n";
        cout << "8. In danh sach sinh vien\n";
        cout << "0. Exit\n";
        cout << "Moi ban nhap lua chon: ";
        cin >> choice;
        if(choice == 1){
            cin.ignore();
            sv.nhap();
            sv.tinh();
            sv.xep_loai();
            sv.in();
            dssv.push_back(sv);
        }else if(choice == 2){
            Student tmp;
            for(auto i:dssv){
                if(i.tbc > tmp.tbc){
                    tmp = i;
                }
            }
            tmp.in();
        }else if(choice == 3){
            Student tam;
            for(auto i:dssv){
                if(i.tbc < tam.tbc){
                    tam = i;
                }
            }
            tam.in();
        }else if(choice == 4){
            for(auto i:dssv){
                if(i.xep_loai() == "Yeu"){
                    i.in();
                }
            }
        }else if(choice == 5){
            for(auto i:dssv){
                if(i.xep_loai() == "Gioi"){
                    i.in();
                }
            }
        }else if(choice == 6){
            cin.ignore();
            bool tim = false;
            str s;
            cout << "Nhap ten can tim: ";
            getline(cin, s);
            for(auto i:dssv){
                if(i.name == s){
                    tim = true;
                    i.in();
                }
            }
            if(tim == false){
                cout << "Khong ton tai!!!";
            }
        }else if(choice == 7){
            cin.ignore();
            bool tim = false;
            str s;
            cout << "Nhap ma so sinh vien can tim: ";
            cin >> s;
            for(auto i:dssv){
                if(i.id == s){
                    tim = true;
                    i.in();
                }
            }
            if(tim == false){
                cout << "Khong ton tai!!!";
            }
        }else if(choice == 8){
            for(auto i:dssv){
                i.in();
                cout << endl;
            }
        }else{
            cout << "Tam biet!!\n";
        }
    }while(choice != 0);
}
