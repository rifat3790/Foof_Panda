#include<iostream>
#include<fstream>
using namespace std;

class User{
    public:
        string phone;
        string username;
        string password;
        string address;
        int balance;
        int noOfOrder;
        User *next;
    public:
    User(string us, string pass, string ad, int bal, int nof){
        username = us;
        password = pass;
        address = ad;
        balance = bal;
        noOfOrder = nof;
        next = NULL;
    } 



};

class UserTemplate{
    User *head;
    public:
        void userRegister(string username, string password, string address, int bal, int nof, int file){
    User *newUser = new User(username, password, address, bal, nof);

    if(head==NULL){
        head = newUser;
        if(file==0){
            ofstream fout;
            fout.open("user.txt", ios::out | ios::app);
            fout << head->username << endl;
            fout << head->password << endl;
            fout << head->address << endl;
            fout << head->balance << endl;
            fout << head->noOfOrder << endl;
            fout.close();
        }
        return;
    }

    User *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newUser;
    if(file==0){
        ofstream fout;
        fout.open("user.txt", ios::out | ios::app);
        fout << temp->next->username << endl;
        fout << temp->next->password << endl;
        fout << temp->next->address << endl;
        fout << temp->next->balance << endl;
        fout << temp->next->noOfOrder << endl;
        fout.close();
    }
}
        void displayUser(){
        User *temp = head;
        while(temp!=NULL){
            cout << temp->username << endl;
            cout << temp->address << endl;
            temp = temp->next;
        }

    }

    int userLogin(string user, string pass){
        User *temp = head;
        int c=0;
        while(temp!=NULL){
            if(temp->username==user && temp->password==pass){
                c=1;
                break;
            }
            temp=temp->next;
        }
        return c;
    }

    void myAccount(string name){
        User *temp = head;
        while(temp!=NULL){
            if(temp->username==name){
                cout << endl;
                cout << "\t\t\t\t " << temp->username << endl;
                cout << "\t\t\t--------------------------------" << endl;
                cout << "\t\t\t Order Completed: " << temp->noOfOrder << endl;
                cout << "\t\t\t Balance: " << temp->balance << endl;
                cout << "\t\t\t Address: " << temp->address << endl;
            }
            temp=temp->next;
        }
    }

    int balance(string name){
        User *temp = head;
        while(temp!=NULL){
            if(temp->username==name){
                return temp->balance;
            }
            temp=temp->next;
        }
        return -1;
    }

    int duplicateUserCheck(string name){
        User *temp = head;
        while(temp!=NULL){
            if(temp->username==name) return 0;
            temp=temp->next;
        }
        return 1;
    }

    void depositMoney(string depUser, int money){
        User *temp = head;
        int c=1;

        while(temp->username!=depUser){
            temp=temp->next;
            c++;
        }

        temp->balance += money;
        int newBalance = temp->balance;

        string user, pass, add, bala, nofd;
        int balan, nofrd;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("user.txt");
        int co = 1;
        User *res = head;

        if(!read.fail()){
                while(getline(read, user)){
                    if(co==c){
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << newBalance << endl;
                            write << nofrd << endl;
                       
                            
                    }else{
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << balan << endl;
                            write << nofrd << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("user.txt");
            rename("temp.txt", "user.txt");
    }

    int updateMoney(string depUser, int cost){
        User *temp = head;
        int c=1;

        while(temp->username!=depUser){
            temp=temp->next;
            c++;
        }

        temp->balance -= cost;
        int newBalance = temp->balance;

        string user, pass, add, bala, nofd;
        int balan, nofrd;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("user.txt");
        int co = 1;
        User *res = head;

        if(!read.fail()){
                while(getline(read, user)){
                    if(co==c){
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << newBalance << endl;
                            write << nofrd << endl;
                       
                            
                    }else{
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << balan << endl;
                            write << nofrd << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("user.txt");
            rename("temp.txt", "user.txt");
            return newBalance;
    }

    int returnNoOfOrder(string user){
        User *temp = head;

        while(temp->username!=user){
            temp = temp->next;
        }

        int a = temp->noOfOrder;
        return a;
    }

    void updateNoOfOrder(string acUser){
        User *temp = head;
        int c = 1;

        while(temp->username!=acUser){
            temp = temp->next;
        }

        temp->noOfOrder += 1;
        int newNoOrder = temp->noOfOrder;

        string user, pass, add, bala, nofd;
        int balan, nofrd;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("user.txt");
        int co = 1;
        User *res = head;

        if(!read.fail()){
                while(getline(read, user)){
                    if(co==c){
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << balan << endl;
                            write << newNoOrder << endl;
                       
                            
                    }else{
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << balan << endl;
                            write << nofrd << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("user.txt");
            rename("temp.txt", "user.txt");

    }

    string addressFinder(string rider){
        User *temp = head;
        while(temp->username!=rider) temp = temp->next;

        string ad = temp->address;

        return ad;
    }

    void editAddress(string euser, string ad){
        User *temp = head;
        int c = 1;
        while(temp->username!=euser){
            temp = temp->next;
            c++;
        }
        temp->address = ad;
        string newAddress = temp->address;

        string user, pass, add, bala, nofd;
        int balan, nofrd;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("user.txt");
        int co = 1;
        User *res = head;

        if(!read.fail()){
                while(getline(read, user)){
                    if(co==c){
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << newAddress << endl;
                            write << balan << endl;
                            write << nofrd << endl;
                       
                            
                    }else{
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << balan << endl;
                            write << nofrd << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("user.txt");
            rename("temp.txt", "user.txt");

            cout << "\t\t\t ----Address Updated----" << endl;

    }

    void editPassword(string euser, string passw){
        User *temp = head;
        int c = 1;
        while(temp->username!=euser){
            temp = temp->next;
            c++;
        }
        temp->password = passw;
        string newAddress = temp->password;

        string user, pass, add, bala, nofd;
        int balan, nofrd;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("user.txt");
        int co = 1;
        User *res = head;

        if(!read.fail()){
                while(getline(read, user)){
                    if(co==c){
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << newAddress << endl;
                            write << add << endl;
                            write << balan << endl;
                            write << nofrd << endl;
                       
                            
                    }else{
                            getline(read, pass);
                            getline(read, add);
                            getline(read, bala);
                            getline(read, nofd);
                            
                            balan = stoi(bala);
                            nofrd = stoi(nofd);

                            write << user << endl;
                            write << pass << endl;
                            write << add << endl;
                            write << balan << endl;
                            write << nofrd << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("user.txt");
            rename("temp.txt", "user.txt");

            cout << "\t\t\t ----Password Updated----" << endl;
    }
};



