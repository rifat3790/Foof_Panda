#include<iostream>
#include<fstream>
using namespace std;

class Rider{
public:
    int riderId;
    string riderName;
    string riderAddress;
    string riderPassword;
    string rideBy;
    string riderApproved;
    int riderBalance;
    int riderOrderComplete;
    Rider *next;
    Rider(int id, string name, string address, string pass, string ride,string app, int bal, int order){
        riderId = id;
        riderName = name;
        riderAddress = address;
        riderPassword = pass;
        rideBy = ride;
        riderApproved = app;
        riderBalance = bal;
        riderOrderComplete = order;
        next = NULL;
    }
};

class RiderTemplate{
    Rider *head;
    public:

    void riderRegistration(int id, string name, string ad, string pass, string ride, string approve, int bal, int order, int file){
        Rider *newRider = new Rider(id, name, ad, pass, ride, approve, bal, order);

        if(head == NULL){
            head = newRider;
            if(file==0){
                ofstream rider;
                rider.open("rider.txt", ios::out | ios::app);
                rider << head->riderId << endl;
                rider << head->riderName << endl;
                rider << head->riderAddress << endl;
                rider << head->riderPassword << endl;
                rider << head->rideBy << endl;
                rider << head->riderApproved << endl;
                rider << head->riderBalance << endl;
                rider << head->riderOrderComplete << endl;
                rider.close();
            }
            return;
        }
        Rider *temp = head;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = newRider;

        if(file==0){
            ofstream rider;
            rider.open("rider.txt", ios::out | ios::app);
            rider << temp->next->riderId << endl;
            rider << temp->next->riderName << endl;
            rider << temp->next->riderAddress << endl;
            rider << temp->next->riderPassword << endl;
            rider << temp->next->rideBy << endl;
            rider << temp->next->riderApproved << endl;
            rider << temp->next->riderBalance << endl;
            rider << temp->next->riderOrderComplete << endl;
            rider.close();
        }
    }

    int riderLogin(string rider, string pass){
        Rider *temp = head;
        int c=0;
        while(temp!=NULL){
            if(temp->riderName==rider && temp->riderPassword==pass){
                c=1;
                break;
            }
            temp=temp->next;
        }
        return c;
    }

    int riderIdPasser(){
        Rider *temp = head;
        int c=0;
        if(temp==NULL) return -1;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        return c;
    }

    string riderFounder(int id){
        Rider *temp = head;
        string f;
        while(temp!=NULL){
            if(temp->riderId==id){
                return temp->riderName;
            }
            temp=temp->next;
        }
        return f;
        
    }

    void showRidersNotApproved(){
        Rider *temp = head;

        int i=1;
            cout << "\t\t No \t|\t Name \t\t|\t Address \t\t|\t Status" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                if(temp->riderApproved=="no"){
                   cout << "\t\t " << i << " \t\t "<<temp->riderName<< " \t\t " << temp->riderAddress << " \t\t\t " << "Not Approved" << endl;
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                    i++;
                }
                temp=temp->next;
            }
    }

    void approveRider(){
        Rider *temp = head;
        int c = 0, cc=1;

        while(temp!=NULL){ 
            if(temp->riderApproved == "no"){
                break;
            }
            cc++;
            temp = temp->next;
        }
        temp->riderApproved = "yes";
        string newIsap = temp->riderApproved;

        string rId, rName, rAdd, rPass, rBy, rApp, rBal, rOrC;
        int id, bal, order;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("rider.txt");
        int co = 1;
        Rider *res = head;

        if(!read.fail()){
                while(getline(read, rId)){
                    if(co==cc){
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << newIsap << endl;
                            write << bal << endl;
                            write << order << endl;
                       
                            
                    }else{
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << bal << endl;
                            write << order << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("rider.txt");
            rename("temp.txt", "rider.txt");
            cout << endl<< "\t\t\t-----Rider Approved------"<<endl;
    }

    string returnApprovalStatus(string rider){
        Rider *temp = head;
        while(temp->riderName!=rider) temp=temp->next;

        string status = temp->riderApproved;
        return status;
    }

    void showAllRiders(){
        Rider *temp = head;

        int i=1;
            cout << "\t\t No \t|\t Name \t\t|\t Balance \t\t|\t Orders" << endl;
            cout << "\t\t-------------------------------------------------------------------------" << endl;
            while(temp!=NULL){
                
               
                    cout << "\t\t " << i << " \t\t "<<temp->riderName<< " \t\t " << temp->riderBalance << " \t\t\t " << temp->riderOrderComplete << endl;
                
                    cout << "\t\t-------------------------------------------------------------------------" << endl;
                    i++;
                
                temp=temp->next;
            }
    }

    void orderUpdate(string rider){
        Rider *temp = head;
        int c = 0, cc=1;

        while(temp->riderName!=rider){ 
            
            cc++;
            temp = temp->next;
        }
        temp->riderOrderComplete += 1;
        int newOrder = temp->riderOrderComplete;

        string rId, rName, rAdd, rPass, rBy, rApp, rBal, rOrC;
        int id, bal, order;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("rider.txt");
        int co = 1;
        Rider *res = head;

        if(!read.fail()){
                while(getline(read, rId)){
                    if(co==cc){
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << bal << endl;
                            write << newOrder << endl;
                       
                            
                    }else{
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << bal << endl;
                            write << order << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("rider.txt");
            rename("temp.txt", "rider.txt");
    }

    void myAccount(string rider){
        Rider *temp = head;
        while(temp!=NULL){
            if(temp->riderName==rider){
                cout << endl;
                
                cout << "\t\t\t--------------------------------" << endl;
                cout << "\t\t\t Name: " << temp->riderName << endl;
                cout << "\t\t\t Balance: " << temp->riderBalance << endl;
                cout << "\t\t\t Orders: " << temp->riderOrderComplete  << endl;
            }
            temp=temp->next;
        }
    }

    void balanceUpdate(string rider, int money){
        Rider *temp = head;
        int c = 1;
        while(temp->riderName!=rider){
            temp = temp->next;
            c++;
        }
        temp->riderBalance += money;
        int newBalance = temp->riderBalance;

        string rId, rName, rAdd, rPass, rBy, rApp, rBal, rOrC;
        int id, bal, order;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("rider.txt");
        int co = 1;
        Rider *res = head;

        if(!read.fail()){
                while(getline(read, rId)){
                    if(co==c){
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << newBalance << endl;
                            write << order << endl;
                       
                            
                    }else{
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << bal << endl;
                            write << order << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("rider.txt");
            rename("temp.txt", "rider.txt");

            

    }

    void changePassword(string rider, string newP){
        Rider *temp = head;
        int c = 1;

        while(temp->riderName!=rider){
            temp = temp->next;
            c++;
        }

        temp->riderPassword = newP;
        string newpass = temp->riderPassword;

        string rId, rName, rAdd, rPass, rBy, rApp, rBal, rOrC;
        int id, bal, order;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("rider.txt");
        int co = 1;
        Rider *res = head;

        if(!read.fail()){
                while(getline(read, rId)){
                    if(co==c){
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << newpass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << bal << endl;
                            write << order << endl;
                       
                            
                    }else{
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << bal << endl;
                            write << order << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("rider.txt");
            rename("temp.txt", "rider.txt");
            cout << "\t\t\t\t ----Password Changed----" << endl;

    }

    int returnBalance(string rider){
        Rider *temp = head;
        while(temp->riderName!=rider) temp = temp->next;

        int b = temp->riderBalance;
        return b;
    }

    void withdraw(string rider, int money){
        Rider *temp = head;
        int c = 1;

        while(temp->riderName!=rider){
            temp = temp->next;
            c++;
        }
        temp->riderBalance -= money;
        int newBal = temp->riderBalance;

        string rId, rName, rAdd, rPass, rBy, rApp, rBal, rOrC;
        int id, bal, order;

        ifstream read;
        ofstream write;
        write.open("temp.txt", ios::out | ios::app);
        read.open("rider.txt");
        int co = 1;
        Rider *res = head;

        if(!read.fail()){
                while(getline(read, rId)){
                    if(co==c){
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << newBal << endl;
                            write << order << endl;
                       
                            
                    }else{
                            getline(read, rName);
                            getline(read, rAdd);
                            getline(read, rPass);
                            getline(read, rBy);
                            getline(read, rApp);
                            getline(read, rBal);
                            getline(read, rOrC);
                            
                            id = stoi(rId);
                            bal = stoi(rBal);
                            order = stoi(rOrC);

                            write << id << endl;
                            write << rName << endl;
                            write << rAdd << endl;
                            write << rPass << endl;
                            write << rBy << endl;
                            write << rApp << endl;
                            write << bal << endl;
                            write << order << endl;
                    }
                    co++;
                    res=res->next;
                }
            }

            read.close();
            write.close();
            remove("rider.txt");
            rename("temp.txt", "rider.txt");
            cout << "\t\t\t\t ----Withdraw Successfull----" << endl;
    }
};

