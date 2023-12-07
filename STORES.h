#include<iostream>
#include<fstream>
using namespace std;


class Stores{
    public: 
        string ownerName;
        string storeName;
        string password;
        int balance;
        string address;
        int isApproved;
        Stores *next;

        Stores(string oName, string sName, string pass, string ad, int bal, int isap){
            ownerName = oName;
            storeName = sName;
            password = pass;
            balance = bal;
            address = ad;
            isApproved = isap;
            next = NULL;
        }
};

class StoresTemplate{
    Stores *head;
    public:

    void storeRegisterLinked(string sName, string pass, string ad, string name, int bal, int isap, int file){
    Stores *newStore = new Stores(name, sName, pass, ad, bal, isap);

    if(head==NULL){
        head = newStore;
        if(file==0){
            ofstream fout;
            fout.open("store.txt", ios::out | ios::app);
            fout << head->ownerName << endl;
            fout << head->storeName << endl;
            fout << head->password << endl;
            fout << head->balance << endl;
            fout << head->address << endl;
            fout << head->isApproved << endl;
            fout.close();
        }
        return;
    }

    Stores *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newStore;
        if(file==0){
            ofstream fout;
                fout.open("store.txt", ios::out | ios::app);
                fout << temp->next->ownerName << endl;
                fout << temp->next->storeName << endl;
                fout << temp->next->password << endl;
                fout << temp->next->balance << endl;
                fout << temp->next->address << endl;
                fout << temp->next->isApproved << endl;
                fout.close();
        }
    }
    
    void showStores(){
        Stores *temp = head;
        int i = 1;
        while(temp!=NULL){
            if(i<10) cout << "\t\t\t\t   [" << i <<"] " <<  temp->storeName<<endl;
            else cout << "\t\t\t\t  [" << i <<"] " <<  temp->storeName<<endl;
            i++;
            temp=temp->next;
        }
    }

    void showStoresNotApproved(){
        Stores *temp = head;

        int i=1;
            cout << "\t\t No \t|\t Owner \t\t|\t Store \t\t|\t Status" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->isApproved==0){
                   cout << "\t\t " << i << " \t\t "<<temp->ownerName<< " \t\t " << temp->storeName << " \t\t\t " << "Not Approved" << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                    i++;
                }
                temp=temp->next;
            }
    }

    void showAllStores(){
        Stores *temp = head;

        int i=1;
            cout << "\t\t No \t|\t Owner \t\t|\t Name \t\t|\t Status" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                
                if(temp->isApproved==0){
                    cout << "\t\t " << i << " \t\t "<<temp->ownerName<< " \t\t " << temp->storeName << " \t\t\t " << "Not Approved" << endl;
                }else if(temp->isApproved==1){
                    cout << "\t\t " << i << " \t\t "<<temp->ownerName<< " \t\t " << temp->storeName << " \t\t\t " << "Approved" << endl;
                }
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                    i++;
                
                temp=temp->next;
            }
    }

    void approveStore(int opt){
        Stores *temp = head;
        int c = 0, cc=1;

        while(temp!=NULL){ 
            if(temp->isApproved == 0){
                break;
            }
            cc++;
            temp = temp->next;
        }
        temp->isApproved = 1;
        int newIsap = temp->isApproved;

        string oname, sname, pas, ball, add, ip;
        int balancee, isAp;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("store.txt");
        int co = 1;
        Stores *res = head;

        if(!read.fail()){
                while(getline(read, oname)){
                    if(co==cc){
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << pas << endl;
                            write << balancee << endl;
                            write << add << endl;
                            write << newIsap << endl;
                       
                            
                    }else{
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << pas << endl;
                            write << balancee << endl;
                            write << add << endl;
                            write << isAp << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("store.txt");
            rename("temp.txt", "store.txt");
            cout << endl<< "\t\t\t-----Store Approved------"<<endl;
    }

    int returnApprovalStatus(string store){
        Stores *temp = head;
        while(temp->storeName!=store) temp=temp->next;

        int status = temp->isApproved;
        return status;
    }

    string searchStoreFood(int val){
        int c = 1;
        Stores *temp = head;

        if(temp==NULL) return "-1";
        while(c!=val){
            if(temp->next==NULL) return "-1";
            temp = temp->next;
            c++;
        }

        string found = temp->storeName;
        
        return found;
    }

    int storeLogin(string store, string pass){
        Stores *temp = head;

        if(temp==NULL) return 0;
        int c=0;
        while(temp!=NULL){
            if(temp->storeName==store && temp->password==pass){
                c = 1;
                break;
            }
            temp=temp->next;
        }
        return c;
    }

    void updateStoreBalance(string store, int bal){
        Stores *temp = head;
        int c = 1;

        while(temp->storeName!=store){
            temp = temp->next;
            c++;
        }

        temp->balance += bal;
        int b = temp->balance;

        string oname, sname, pas, ball, add, ip;
        int balancee, isAp;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("store.txt");
        int co = 1;
        Stores *res = head;

        if(!read.fail()){
                while(getline(read, oname)){
                    if(co==c){
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << pas << endl;
                            write << b << endl;
                            write << add << endl;
                            write << isAp << endl;
                       
                            
                    }else{
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << pas << endl;
                            write << balancee << endl;
                            write << add << endl;
                            write << isAp << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("store.txt");
            rename("temp.txt", "store.txt");
    }

    void myAccount(string name){
        Stores *temp = head;
        while(temp!=NULL){
            if(temp->storeName==name){
                cout << endl;
                cout << "\t\t\t\t " << temp->storeName << endl;
                cout << "\t\t\t--------------------------------" << endl;
                cout << "\t\t\t Owner: " << temp->ownerName << endl;
                if(temp->isApproved==0) cout << "\t\t\t Approval Status: Not Approved" << endl;
                else cout << "\t\t\t Approval Status: Approved" << endl;
                cout << "\t\t\t Balance: " << temp->balance << " TK" << endl;
                cout << "\t\t\t Address: " << temp->address << endl;
            }
            temp=temp->next;
        }
    }

    void changePassword(string store, string newP){
        Stores *temp = head;
        int c = 1;

        while(temp->storeName!=store){
            temp = temp->next;
            c++;
        }
        temp->password = newP;
        string newpass = temp->password;

        string oname, sname, pas, ball, add, ip;
        int balancee, isAp;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("store.txt");
        int co = 1;
        Stores *res = head;

        if(!read.fail()){
                while(getline(read, oname)){
                    if(co==c){
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << newpass << endl;
                            write << balancee << endl;
                            write << add << endl;
                            write << isAp << endl;
                       
                            
                    }else{
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << pas << endl;
                            write << balancee << endl;
                            write << add << endl;
                            write << isAp << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("store.txt");
            rename("temp.txt", "store.txt");
            cout << "\t\t\t-----Password Changed----" << endl;
    }

    int returnStoreBalance(string store){
        Stores *temp = head;
        while(temp->storeName!=store){
            temp = temp->next;
        }
        int b = temp->balance;
        return b;
    }

    void withdrawBalance(string store, int with){
        Stores *temp = head;
        int c = 1;
        while(temp->storeName!=store){
            temp = temp->next;
            c++;
        }

        temp->balance -= with;
        int newBalance = temp->balance;

        string oname, sname, pas, ball, add, ip;
        int balancee, isAp;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("store.txt");
        int co = 1;
        Stores *res = head;

        if(!read.fail()){
                while(getline(read, oname)){
                    if(co==c){
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << pas << endl;
                            write << newBalance << endl;
                            write << add << endl;
                            write << isAp << endl;
                       
                            
                    }else{
                            getline(read, sname);
                            getline(read, pas);
                            getline(read, ball);
                            getline(read, add);
                            getline(read, ip);
                            
                            balancee = stoi(ball);
                            isAp = stoi(ip);

                            write << oname << endl;
                            write << sname << endl;
                            write << pas << endl;
                            write << balancee << endl;
                            write << add << endl;
                            write << isAp << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("store.txt");
            rename("temp.txt", "store.txt");

            cout << "\t\t\t\tWithdrawal Successfull" << endl;
    }
};

class Foods{
    public:
        string storeName;
        string name;
        int price;
        int stock;
        Foods *next;
        
        Foods(string sName, string nam, int pr, int st){
            storeName = sName;
            name = nam;
            price = pr;
            stock = st;
            next = NULL;
        }
};

class FoodsTemplate{
    Foods *head;
    public:
        void addFood(string store, string food, int price, int stock, int file){
            Foods *newFood = new Foods(store, food, price, stock);
            if(head==NULL){
                head = newFood;
                if(file==0){
                    ofstream fout;
                    fout.open("food.txt", ios::out | ios::app);
                    fout << head->storeName << endl;
                    fout << head->name << endl;
                    fout << head->price << endl;
                    fout << head->stock << endl;
                    fout.close();
                }
                return;
            }
            Foods *temp = head;
            while(temp->next!=NULL) temp = temp->next;
            temp->next = newFood;
                 if(file==0){
                    ofstream fout;
                    fout.open("food.txt", ios::out | ios::app);
                    fout << temp->next->storeName << endl;
                    fout << temp->next->name << endl;
                    fout << temp->next->price << endl;
                    fout << temp->next->stock << endl;
                    fout.close();
                }
        }
        
        void displayFood(string store){
            Foods *temp = head;
            while(temp!=NULL){
                if(temp->storeName==store){
                    cout << "\t\t-------------------------------------------------" << endl;
                    
                }
                temp=temp->next;
            }
        }

        void displayFoodFromShop(string storeName){
            Foods *temp = head;
            int i=1;
            cout << "\t\t No \t|\t Name \t\t|\t Price \t\t|\t Stock" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->storeName==storeName){
                   cout << "\t\t " << i << " \t\t "<<temp->name<< " \t\t " << temp->price << " \t\t\t " << temp->stock << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                    i++;
                }
                temp=temp->next;
            }
        }

        string selectedFood(int val, string store){
            Foods *temp = head;
            int c=1;
            if(temp==NULL) return "-1";
            while(temp!=NULL){
                if(temp->storeName==store){
                    if(c==val) break;
                    c++;
                }
                    temp = temp->next;
                }

            string found = temp->name;
        
            return found;
        }

        int orderFoodPrice(int val, string store){
            Foods *temp = head;
            int c=1;
            if(temp==NULL) return -1;
            while(temp!=NULL){
                if(temp->storeName==store){
                    if(c==val) break;
                    c++;
                }
                    temp = temp->next;
                }

            int found = temp->price;
        
            return found;
        }

        int updateStock(string food, int a, string store){
            Foods *temp = head;
            int c = 1;
            while(1){
                if(temp->name==food && temp->storeName==store) break;
                temp = temp->next;
                c++;
            }
            temp->stock = temp->stock - a;
            int s = temp->stock;

        string sname, fname, pric, sto;
        int pr, st;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("food.txt");
        int co = 1;
        Foods *res = head;

        if(!read.fail()){
                while(getline(read, sname)){
                    if(co==c){
                            getline(read, fname);
                            getline(read, pric);
                            getline(read, sto);
                            
                            pr = stoi(pric);
                            st = stoi(sto);

                            write << sname << endl;
                            write << fname << endl;
                            write << pr << endl;
                            write << s << endl;
                       
                            
                    }else{
                            getline(read, fname);
                            getline(read, pric);
                            getline(read, sto);
                            
                            pr = stoi(pric);
                            st = stoi(sto);

                            write << sname << endl;
                            write << fname << endl;
                            write << pr << endl;
                            write << st << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("food.txt");
            rename("temp.txt", "food.txt");
        return s;

        }

        void editName(string food, string newName, string store){
            Foods *temp = head;
            int c = 1;
            while(1){
                if(temp->name==food && temp->storeName==store) break;
                temp = temp->next;
                c++;
            }
            temp->name = newName;

        string sname, fname, pric, sto;
        int pr, st;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("food.txt");
        int co = 1;
        Foods *res = head;

        if(!read.fail()){
                while(getline(read, sname)){
                    if(co==c){
                            getline(read, fname);
                            getline(read, pric);
                            getline(read, sto);
                            
                            pr = stoi(pric);
                            st = stoi(sto);

                            write << sname << endl;
                            write << newName << endl;
                            write << pr << endl;
                            write << st << endl;
                       
                            
                    }else{
                            getline(read, fname);
                            getline(read, pric);
                            getline(read, sto);
                            
                            pr = stoi(pric);
                            st = stoi(sto);

                            write << sname << endl;
                            write << fname << endl;
                            write << pr << endl;
                            write << st << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("food.txt");
            rename("temp.txt", "food.txt");
        }

        void editPrice(string food, int newPrice, string store){
            Foods *temp = head;
            int c = 1;
            while(1){
                if(temp->name==food && temp->storeName==store) break;
                temp = temp->next;
                c++;
            }
            temp->price = newPrice;

        string sname, fname, pric, sto;
        int pr, st;
        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("food.txt");
        int co = 1;
        Foods *res = head;

        if(!read.fail()){
                while(getline(read, sname)){
                    if(co==c){
                            getline(read, fname);
                            getline(read, pric);
                            getline(read, sto);
                            
                            pr = stoi(pric);
                            st = stoi(sto);

                            write << sname << endl;
                            write << fname << endl;
                            write << newPrice << endl;
                            write << st << endl;
                       
                            
                    }else{
                            getline(read, fname);
                            getline(read, pric);
                            getline(read, sto);
                            
                            pr = stoi(pric);
                            st = stoi(sto);

                            write << sname << endl;
                            write << fname << endl;
                            write << pr << endl;
                            write << st << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("food.txt");
            rename("temp.txt", "food.txt");
        }

        int foodCount(){
            Foods *temp = head;
            int c=0;

            while(temp!=NULL){
                c++;
                temp = temp->next;
            }

            return c;
        }

        int findIndexOfFood(string food, string store){
            Foods *temp = head;
            int c = 1;
            while(1){
                if(temp->name==food&&temp->storeName==store) break;

                c++;
                temp = temp->next;
            }
            return c;
        }

        void deleteHeadFood(){
            Foods *temp = head;
            if(temp!=NULL){
                head = temp->next;
                delete temp;
                cout << "\t\t\t----Food Deleted----" << endl;
            }
        }

        void deleteTailFood(){
            Foods *temp = head;
            // int last = foodCount();
            if(temp!=NULL && temp->next!=NULL){
            while(temp->next->next!=NULL) temp=temp->next;
            Foods *delNode = temp->next;
            temp->next = NULL;
            delete delNode;
            cout << "Successfully Deleted" << endl;
            }else if(temp->next==NULL){
                deleteHeadFood();
            }else{
                cout << "There is no value" << endl;
            }       
        }

        void deleteFood(int pos){
            Foods *temp = head;

            if(temp!=NULL && pos<=foodCount()){
            if(pos==1) deleteHeadFood();
            else if(pos == foodCount()) deleteTailFood();
            else{
                int i=1;
                while(i<pos-1){
                    temp=temp->next;
                    i++;
                }
                Foods *delNode = temp->next;
                temp->next = delNode->next;
                delete delNode;
                cout << "Successfully deleted" << endl;
        }
    }else cout << "Invalid Position" << endl;
        }
};