#include<iostream>
#include<fstream>
using namespace std;

class Voucher{
public:
    string voucherCode;
    string voucherName;
    int amount;
    int maxOff;
    int minCost;
    Voucher *next;
    Voucher(string vc, string vn, int am, int max, int min){
        voucherCode = vc;
        voucherName = vn;
        amount = am;
        maxOff = max;
        minCost = min;
        next = NULL;
    }

};

class VoucherTemplate{
    Voucher *head;
    public:
        void createVoucher(string name, string code, int am, int max, int min, int file){
            Voucher *newVoucher = new Voucher(code, name, am, max, min);
            if(head==NULL){
                head = newVoucher;
                if(file==0){
                    ofstream fout;
                    fout.open("voucher.txt", ios::out | ios::app);
                    fout << head->voucherCode << endl;
                    fout << head->voucherName << endl;
                    fout << head->amount << endl;
                    fout << head->maxOff << endl;
                    fout << head->minCost << endl;
                    fout.close();
                }
                return;
            }
            Voucher *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newVoucher;
            if(file==0){
                    ofstream fout;
                    fout.open("voucher.txt", ios::out | ios::app);
                    fout << temp->next->voucherCode << endl;
                    fout << temp->next->voucherName << endl;
                    fout << temp->next->amount << endl;
                    fout << temp->next->maxOff << endl;
                    fout << temp->next->minCost << endl;
                    fout.close();
                }
        }

        void showAllVouchers(){
            Voucher *temp = head;
            int i =1;
            cout << "\t\t No \t|\t Voucher \t\t|\t Code \t\t|\t Amount" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                
                
                    cout << "\t\t " << i << " \t\t "<<temp->voucherName<< " \t\t " << temp->voucherCode << " \t\t\t " << temp->amount  << endl;
                
                temp=temp->next;
                i++;
            }
        }
        
        int voucherCounter(){
            Voucher *temp = head;
            int c=1;
            while(temp!=NULL){
                temp = temp->next;
                c++;
            }

            return c;
        }

        void deleteLastVoucher(){
            Voucher *temp = head;

            if(temp!=NULL && temp->next!=NULL){
                while(temp->next->next!=NULL){
                    temp = temp->next;
                }
                temp->next = NULL;
            cout << "Successfully Deleted" << endl;

            }else if(temp->next==NULL){
                if(temp!=NULL){
                    head = temp->next;
                }
            }

            int last = voucherCounter();
            string code, name, amo, maxo, minc;
            int amou, maxof, minco;
            ifstream read;
            ofstream write;
            write.open("temp.txt", ios::out | ios::app);
            read.open("voucher.txt");
            int co = 1;
            if(!read.fail()){
                while(co<last){
                    getline(read, code);
                    getline(read, name);
                    getline(read, amo);
                    getline(read, maxo);
                    getline(read, minc);

                    amou = stoi(amo);
                    maxof = stoi(maxo);
                    minco = stoi(minc);

                    write << code << endl;
                    write << name << endl;
                    write << amou << endl;
                    write << maxof << endl;
                    write << minco << endl;
                    co++;
                }

            }
            read.close();
            write.close();
            remove("voucher.txt");
            rename("temp.txt", "voucher.txt");

        }

        int returnVoucherAmount(string voucher){
            Voucher *temp = head;

            while(temp->voucherCode!=voucher){
                temp = temp->next;
            }
            int v = temp->amount;
            return v;
        }

        int returnVoucherMin(string voucher){

            Voucher *temp = head;
            while(temp->voucherCode!=voucher){
                temp = temp->next;
            }

            int v = temp->minCost;
            return v;
        }
};

class Location{
    public:
        string address;
        Location *next;
        Location(string ad){
            address = ad;
            next = NULL;
        }
};

class LocationTemplate{
    Location *head;
    public:
        void addLocation(string ad, int file){
            Location *newLocation = new Location(ad);
            if(head==NULL){
                head = newLocation;
                if(file==0){
                    ofstream fout;
                    fout.open("location.txt", ios::out | ios::app);
                    fout << head->address << endl;
                    fout.close();
                }
                return;
            }
            Location *temp = head;
            while(temp->next!=NULL) temp = temp->next;
            temp->next = newLocation;

            if(file==0){
                ofstream fout;
                fout.open("location.txt", ios::out | ios::app);
                fout << temp->next->address << endl;
                fout.close();
            }
        }

        int returnLocationStat(string ad){
            Location *temp = head;
            int flag = 0;
            while(temp!=NULL){
                if(temp->address==ad) flag=1;
                temp=temp->next;
            }

            if(flag==0) return -1;
            else return 1;
        }

        void showAllLocation(){
            Location *temp = head;
            int i = 1;
            cout << "\t\t------------------------------------------------" << endl;
            while(temp!=NULL){
                cout << "\t\t\t" << i << "." << temp->address << endl;
                temp = temp->next;
                i++;
            }
            cout << "\t\t------------------------------------------------" << endl;
        }

        void editLocation(int pos, string loc){
            Location *temp = head;
            int c=1;
            while(temp!=NULL){
                if(c==pos) break;
                temp = temp->next;
                c++;
            }
            temp->address = loc;
            string newLoc = temp->address;
            string loca;
            ifstream read;
            ofstream write;
            write.open("temp.txt", ios::out | ios::app);
            read.open("location.txt");
            int co = 1;
            if(!read.fail()){
                while(getline(read, loca)){
                    if(co==pos){
                        write << newLoc << endl;
                    }
                    else{
                        write << loca << endl;
                    }
                    co++;
                }
            
            }
            read.close();
            write.close();
            remove("location.txt");
            rename("temp.txt", "location.txt");

        }

        void deleteLocation(){
            Location *temp = head;
            if(temp!=NULL && temp->next!=NULL){
                while(temp->next->next!=NULL){
                    temp = temp->next;
                }
                temp->next = NULL;
            cout << "Successfully Deleted" << endl;

            }else if(temp->next==NULL){
                if(temp!=NULL){
                    head = temp->next;
                }
            }
        }

        int locationVerify(string loc){
            Location *temp = head;
            int flag = 0;
            while(temp!=NULL){
                if(temp->address==loc) flag=1;
                temp = temp->next;

            }

            return flag;
        }
            
};