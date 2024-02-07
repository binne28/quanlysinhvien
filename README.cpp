#include <bits/stdc++.h>
using namespace std;
#define str string
#define db double
#define fl float
#define ll long long

class Book{
    private:
        str name, id, tac_gia, the_loai, namxuatban;
        ll soluong;
    public:
    //set: thiet lap de truy xuat vao private
    //get: lay du lieu tu set
        void setname(){
            this->name = name;
        }
        str getname(){
            return name;
        }

        void setid(){
            this->id = id;
        }

        str getid(){
            return id;
        }

        void settacgia(){
            this->tac_gia = tac_gia;
        }

        str gettacgia(){
            return the_loai;
        }

        void settheloai(){
            this->the_loai = the_loai;
        }

        str gettheloai(){
            return the_loai;
        }
        
        void setsoluong(){
            this->soluong = soluong;
        }

        ll getsoluong(){
            return soluong;
        }
        
        void setnamxuatban(){
            this->namxuatban = namxuatban;
        }
        
        str getnamxuatban(){
            return namxuatban;
        }

        void input(){
            cout << "Nhap ma sach: ";
            cin >> this->id;
            cin.ignore();
            cout << "Nhap ten sach: ";
            getline(cin, this->name);
            cout << "Nhap tac gia cua sach: ";
            getline(cin, this->tac_gia);
            cout << "Nhap the loai: ";
            getline(cin, this->the_loai);
            cout << "Nhap nam xuat ban: ";
            cin >> this->namxuatban;
            cout << "Nhap so luong sach: ";
            cin >> this->soluong;
        }


        void output(){
            cout << "Ma sach: " << this->id << endl;
            cout << "Ten sach: " << this-> name << endl;
            cout << "Tac gia: " << this->tac_gia <<endl;
            cout << "Nam xuat ban: " << this->namxuatban << endl;
            cout << "So luong: " << this->soluong << endl;
        }
};


class Library{
    private:

    public: 
};

int main(){
    vector <Book> sach;
    Book b;
    int choice;
    do{
        cout << "------------ MENU ------------\n";
        cout << "1. Them sach vao thu vien\n";
        cout << "2. Tim kiem sach trong thu vien\n";
        cout << "3. Hien thi thong tin sach\n";
        cout << "4. Xoa sach khoi thu vien bang ma sach\n";
        cout << "5. Tim kiem thong tin sach bang ma sach\n";
        cout << "6. Xoa sach khoi thu vien bang ten sach\n";
        cout << "0. Exit\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        system("cls");
        if(choice == 1){
            b.input();
            sach.push_back(b);
        }else if(choice == 2){
            cin.ignore();
            bool tim = false;
            str a;
            cout << "Nhap ten sach ban muon tim kiem: ";
            getline(cin, a);
            for(auto i = sach.begin(); i != sach.end(); i++){
                if(i->getname() == a){
                    tim = true;
                    i->output();
                }
            }
            if(tim == false){
                cout << "Khong tim thay sach co ten nhu vay!!!\n";
            }
        }else if(choice == 3){ 
            if(sach.empty()){
                cout << "Khong co sach nao trong thu vien\n";
            }else{
                for(auto i:sach){
                    i.output();
                    cout << endl;
                }
            }
        }else if(choice == 4){
            str ma;
            cout << "Nhap ma sach ban muon xoa: ";
            cin >> ma;
            bool tim = false;
            for(auto i = sach.begin(); i != sach.end(); i++){
                if(i->getid() == ma){
                    tim = true;
                    i= sach.erase(i);
                    cout << "Da xoa khoi thu vien!!!\n";
                    break;
                }
            }
            if(tim == false){
                cout << "Khong tim thay ma sach nao nhu vay!\n";
            }
        }else if(choice == 5) //5. Tim kiem thong tin sach bang ma sach
        {
            bool check = false;
            str id1;
            cout << "Nhap ma sach ban muon tim kiem: ";
            cin >> id1;
            for(auto i = sach.begin(); i != sach.end(); i++){
                if(i->getid() == id1){
                    check = true;
                    i->output();
                }
            }
            if(check == false){
                cout << "Khong tim thay ma sach nao nhu vay!!!\n";
            }
        }else if(choice == 6)// xoa sach theo ten
        {
            str name1;
            cout << "Nhap ten sach ban muon xoa: ";
            getline(cin, name1);
            bool check = false;
            for(auto i = sach.begin(); i != sach.end(); i++){
                if(i->getname() == name1){
                    check = true;
                    i = sach.erase(i);
                    cout << "Da xoa khoi thu vien!!!\n";
                    break;
                }
            }
            if(check == false){
                cout << "Khong tim thay ten sach nao nhu vay ca!!\n";
            }
        }
        else{
            cout << "Xin chao va hen gap laii!!!!\n Tam biet!!!";
        }
    }while(choice != 0);
}
