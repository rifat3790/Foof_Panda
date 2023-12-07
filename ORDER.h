#include<iostream>
#include<fstream>
using namespace std;

class Order{
    public:
        string username;
        string address;
        string storeName;
        string foodName;
        string storeApproved;
        string riderAccepted;
        string delivered;
        int amount;
        int price;
        Order *next;
        Order *front;
        Order *rear;

        Order(string us, string ad, string sn, string fn, string sta, string ra, string del, int am, int pr){
            username = us;
            address = ad;
            storeName = sn;
            foodName = fn;
            storeApproved = sta;
            riderAccepted = ra;
            delivered = del;
            amount = am;
            price = pr;
            next = NULL;
            front = NULL;
            rear = NULL;
        }
};

class OrderTemplate{
    Order *head;

    public:
        void newOrder(string us, string ad, string sn, string fn, string sta, string ra, string del, int am, int pr, int file){
            Order *newOrders = new Order(us, ad, sn, fn, sta, ra, del, am, pr);
            if(head==NULL){
                head = newOrders;
                if(file==0){
                ofstream fout;
                    fout.open("order.txt", ios::out | ios::app);
                    fout << head->username << endl;
                    fout << head->address << endl;
                    fout << head->storeName << endl;
                    fout << head->foodName << endl;
                    fout << head->storeApproved << endl;
                    fout << head->riderAccepted << endl;
                    fout << head->delivered << endl;
                    fout << head->amount << endl;
                    fout << head->price << endl;
                    fout.close();
                }
                return;
            }
            Order *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newOrders;
            if(file==0){
                ofstream fout;
                    fout.open("order.txt", ios::out | ios::app);
                    fout << temp->next->username << endl;
                    fout << temp->next->address << endl;
                    fout << temp->next->storeName << endl;
                    fout << temp->next->foodName << endl;
                    fout << temp->next->storeApproved << endl;
                    fout << temp->next->riderAccepted << endl;
                    fout << temp->next->delivered << endl;
                    fout << temp->next->amount << endl;
                    fout << temp->next->price << endl;
                    fout.close();
                }
        }

        void displayMyOrder(string username){
            Order *temp = head;
            if(temp==NULL) return;
            cout << "\t\t Name \t|\t Amount \t|\t Price \t\t|\t Status" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->username==username){
                    cout << "\t\t " << temp->foodName << " \t\t "<<temp->amount<< " \t\t " << temp->price << " \t\t\t " << temp->delivered << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                }
                temp=temp->next;
            }
        }
        
        void displayStoreOrder(string storeName){
            Order *temp = head;
            if(temp==NULL) return;
            cout << "\t\t Name \t|\t Amount \t|\t Price \t\t|\t Status" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->storeName==storeName && temp->delivered == "pending"){
                    cout << "\t\t " << temp->foodName << " \t\t "<<temp->amount<< " \t\t " << temp->price << " \t\t\t " << temp->delivered << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                }
                temp=temp->next;
            }
        }
        
        void displayStoreAllOrder(string storeName){
            Order *temp = head;
            if(temp==NULL) return;
            cout << "\t\t Name \t|\t Amount \t|\t Price \t\t|\t Status" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->storeName==storeName){
                    cout << "\t\t " << temp->foodName << " \t\t "<<temp->amount<< " \t\t " << temp->price << " \t\t\t " << temp->delivered << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                }
                temp=temp->next;
            }
        }

        void confirmOrderByStore(int pos, string store, string status){
            Order *temp = head;
            if(temp==NULL) return;
            int c=1, cc=1;

            

            while(temp!=NULL){
                if(c==pos && temp->storeName==store && temp->delivered==status) break;
                if(temp->storeName==store && temp->delivered=="pending"){
                    c++;
                }
                cc++;
                temp = temp->next;
            }

            temp->delivered = "preparing";
            cout << "\t\t\t\t\t--Order Updated--" << endl;

            string uname, adres, sname, fname, sap, rap, deliv, am, pri;
            int a, p;
            ifstream read;
            ofstream write;
            write.open("temp.txt", ios::out | ios::app);
            read.open("order.txt");
            int co = 1;
            Order *res = head;
            if(!read.fail()){
                while(getline(read, uname)){
                    if(co==cc){
                            getline(read, adres);
                            getline(read, sname);
                            getline(read, fname);
                            getline(read, sap);
                            getline(read, rap);
                            getline(read, deliv);
                            getline(read, am);
                            getline(read, pri);
                            a = stoi(am);
                            p = stoi(pri);
                            deliv = "preparing";

                            write << uname << endl;
                            write << adres << endl;
                            write << sname << endl;
                            write << fname << endl;
                            write << sap << endl;
                            write << rap << endl;
                            write << deliv << endl;
                            write << a << endl;
                            write << p << endl;
                       
                            
                    }else{
                            getline(read, adres);
                            getline(read, sname);
                            getline(read, fname);
                            getline(read, sap);
                            getline(read, rap);
                            getline(read, deliv);
                            getline(read, am);
                            getline(read, pri);
                            a = stoi(am);
                            p = stoi(pri);

                            write << uname << endl;
                            write << adres << endl;
                            write << sname << endl;
                            write << fname << endl;
                            write << sap << endl;
                            write << rap << endl;
                            write << deliv << endl;
                            write << a << endl;
                            write << p << endl;
                    }
                    co++;
                    res=res->next;
                }
            }
            else{
                cout << "file not opened";
            }
            read.close();
            write.close();
            remove("order.txt");
            rename("temp.txt", "order.txt");
            }

        string riderFound(){
            Order *temp = head;
            string rider;
            if(temp==NULL) return "no";

            while(temp->next!=NULL){
                temp=temp->next;
            }

            rider = temp->next->riderAccepted;
            return rider;
        }

        void riderPendingOrder(string rider){
            Order *temp = head;
            if(temp==NULL) return;
            cout << "\t\t Name \t|\t Amount \t|\t Price \t\t|\t Address" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->riderAccepted==rider && temp->delivered=="preparing"){
                    cout << "\t\t " << temp->foodName << " \t\t "<<temp->amount<< " \t\t " << temp->price << " \t\t\t " << temp->address << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                }
                temp=temp->next;
            }
        }

        void riderPickedOrder(string rider){
            Order *temp = head;
            if(temp==NULL) return;
            cout << "\t\t Name \t|\t Amount \t|\t Price \t\t|\t Address" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->riderAccepted==rider && temp->delivered=="picked"){
                    cout << "\t\t " << temp->foodName << " \t\t "<<temp->amount<< " \t\t " << temp->price << " \t\t\t " << temp->address << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                }
                temp=temp->next;
            }
        }

        void confirmOrderByRider(int pos, string rider){
            Order *temp = head;
            if(temp==NULL) return;
            int c=1, cc=1;

            

            while(temp!=NULL){
                if(c==pos && temp->riderAccepted==rider && temp->delivered=="preparing") break;
                if(temp->riderAccepted==rider && temp->delivered=="preparing"){
                    c++;
                }
                cc++;
                temp = temp->next;
            }

            temp->delivered = "picked";
            cout << "\t\t\t\t\t--Order Updated--" << endl;

            string uname, adres, sname, fname, sap, rap, deliv, am, pri;
            int a, p;
            ifstream read;
            ofstream write;
            write.open("temp.txt", ios::out | ios::app);
            read.open("order.txt");
            int co = 1;
            Order *res = head;
            if(!read.fail()){
                while(getline(read, uname)){
                    if(co==cc){
                            getline(read, adres);
                            getline(read, sname);
                            getline(read, fname);
                            getline(read, sap);
                            getline(read, rap);
                            getline(read, deliv);
                            getline(read, am);
                            getline(read, pri);
                            a = stoi(am);
                            p = stoi(pri);
                            deliv = "picked";

                            write << uname << endl;
                            write << adres << endl;
                            write << sname << endl;
                            write << fname << endl;
                            write << sap << endl;
                            write << rap << endl;
                            write << deliv << endl;
                            write << a << endl;
                            write << p << endl;
                       
                            
                    }else{
                            getline(read, adres);
                            getline(read, sname);
                            getline(read, fname);
                            getline(read, sap);
                            getline(read, rap);
                            getline(read, deliv);
                            getline(read, am);
                            getline(read, pri);
                            a = stoi(am);
                            p = stoi(pri);

                            write << uname << endl;
                            write << adres << endl;
                            write << sname << endl;
                            write << fname << endl;
                            write << sap << endl;
                            write << rap << endl;
                            write << deliv << endl;
                            write << a << endl;
                            write << p << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("order.txt");
            rename("temp.txt", "order.txt");
            
            }

        void deliverOrderByRider(int pos, string rider){
            Order *temp = head;
            if(temp==NULL) return;
            int c=1, cc=1;

            

            while(temp!=NULL){
                if(c==pos && temp->riderAccepted==rider && temp->delivered=="picked") break;
                if(temp->riderAccepted==rider && temp->delivered=="picked"){
                    c++;
                }
                cc++;
                temp = temp->next;
            }

            temp->delivered = "delivered";
            cout << "\t\t\t\t\t--Order Updated--" << endl;

            string uname, adres, sname, fname, sap, rap, deliv, am, pri;
            int a, p;
            ifstream read;
            ofstream write;
            write.open("temp.txt", ios::out | ios::app);
            read.open("order.txt");
            int co = 1;
            Order *res = head;
            if(!read.fail()){
                while(getline(read, uname)){
                    if(co==cc){
                            getline(read, adres);
                            getline(read, sname);
                            getline(read, fname);
                            getline(read, sap);
                            getline(read, rap);
                            getline(read, deliv);
                            getline(read, am);
                            getline(read, pri);
                            a = stoi(am);
                            p = stoi(pri);
                            deliv = "delivered";

                            write << uname << endl;
                            write << adres << endl;
                            write << sname << endl;
                            write << fname << endl;
                            write << sap << endl;
                            write << rap << endl;
                            write << deliv << endl;
                            write << a << endl;
                            write << p << endl;
                       
                            
                    }else{
                            getline(read, adres);
                            getline(read, sname);
                            getline(read, fname);
                            getline(read, sap);
                            getline(read, rap);
                            getline(read, deliv);
                            getline(read, am);
                            getline(read, pri);
                            a = stoi(am);
                            p = stoi(pri);

                            write << uname << endl;
                            write << adres << endl;
                            write << sname << endl;
                            write << fname << endl;
                            write << sap << endl;
                            write << rap << endl;
                            write << deliv << endl;
                            write << a << endl;
                            write << p << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("order.txt");
            rename("temp.txt", "order.txt");
            
        }

        void showDonatedFood(){
            Order *temp = head;
            cout << "\t\t Name \t|\t Amount \t|\t Price \t\t|\t Donor" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->address=="donate"){
                    cout << "\t\t " << temp->foodName << " \t\t "<<temp->amount<< " \t\t " << temp->price << " \t\t\t " << temp->username << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                }
                temp=temp->next;
            }
        }
        
};