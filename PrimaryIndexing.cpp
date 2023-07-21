#include <iostream>
#include <fstream>
#include <algorithm>
#include<string>
#include<string.h>
#include <map>

using namespace std;

class student{
    public:
    map<string, int>ind_map;
    string name, usn, branch, x;
    int ch;

    bool srch(string usn){
        auto it = ind_map.find((usn));
        return it!=ind_map.end();
    }

    void displayrec(string x){
        replace(x.begin(), x.end(), '|', '\t');
        cout<<x<<endl;
    }

    void displaydata(){
        cout<<"\033[32mData file\033[m"<<endl;
        cout<<"Name\tUSN\tBranch"<<endl;
        fstream f("data.txt", ios::in);
        while(getline(f,x)){
            if(x.find('$') == string::npos){
                displayrec(x);
            }
        }f.close();
    }

    void addrec(string name, string usn, string branch){
        fstream f("data.txt", ios::app);
        x = name+"|"+usn+"|"+branch;
        f<<x;
        f.seekg(0-x.length(), ios::cur);
        ind_map[(usn)] = f.tellg();
        f<<endl;
        f.close();
    }

    void primary(){
        cout<<"\033[32mPrimary index file\033[m"<<endl;
        fstream f("primary.txt", ios::out);
        for(auto i: ind_map){
            f<<i.first<<"|"<<i.second<<endl;
            cout<<i.first<<"|"<<i.second<<endl;
        }
        f.close();
    }

    void remove(string usn){
        fstream f("data.txt", ios::in|ios::out);
        f.seekp(ind_map[(usn)]);
        f.put('$');
        f.close();
        ind_map.erase((usn));
    }
};

int main(){
    student s;
    fstream f("data.txt", ios::out);f.close();
    cout<<"1.Add\n2.Search\n3.Display\n4.Remove\nElse.exit\n";
    while(1){
        cout<<"\033[32m\nChoice: \033[m";
        cin>>s.ch;
        switch(s.ch){
            case 1:{
                cout<<"\033[31mName, USN, Branch: \033[m";
                cin>>s.name>>s.usn>>s.branch;
                if(s.srch(s.usn)){
                    cout<<"Duplicates not allowed!"<<endl;break;
                }
                s.addrec(s.name, s.usn, s.branch);break;
            }
            case 2:{
                cout<<"USN to search: ";
                cin>>s.usn;
                if(s.srch(s.usn)){
                    cout<<"Name\tUSN\tBranch"<<endl;
                    fstream f("data.txt", ios::in);
                    f.seekg(s.ind_map[(s.usn)]);
                    f>>s.x;
                    s.displayrec(s.x);
                }else{
                    cout<<"Record matching this USN not present"<<endl;
                }break;
            }case 3:{
                s.displaydata();
                cout<<endl;
                s.primary();break;
            }case 4:{
                cout<<"USN to delete: ";
                cin>>s.usn;
                if(s.srch(s.usn)){
                    cout<<"Contents are: "<<endl;
                    fstream f("data.txt", ios::in);
                    f.seekg(s.ind_map[(s.usn)]);
                    f>>s.x;
                    s.displayrec(s.x);
                    s.remove(s.usn);
                    cout<<"Successfully deleted!"<<endl;
                    break;
                }cout<<"Record matching this USN not present"<<endl;
                break;
            }
            default:
                exit(0);
        }
    }
}