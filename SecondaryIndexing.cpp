#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

class Student {
public:
    string name, usn, branch, x;
    int ch;
    vector<string> names;
    map<string, int> ind_map;

    void addEntry(string name, string usn, string branch) {
        x = name + "|" + usn + "|" + branch;
        names.push_back(name);
        fstream f("data.txt", ios::app);
        f << x;
        f.seekg(0 - x.length(), ios::cur);
        ind_map[usn] = f.tellg();
        f << endl;
        f.close();
    }

    void displayRec(string x) {
        replace(x.begin(), x.end(), '|', '\t');
        cout << x << endl;
    }

    void displayData() {
        cout << "\n\033[34mData File\033[m" << endl;
        cout << "Name\tUSN\tBranch" << endl;
        fstream f("data.txt", ios::in);
        while (getline(f, x)) {
            if (x.find('$') == string::npos) {
                displayRec(x);
            }
        }
        f.close();
        cout << endl;
    }

    bool search(string usn) {
        auto it = ind_map.find(usn);
        return (it != ind_map.end());
    }

    void displayMatchRec(string name) {
        fstream f("data.txt", ios::in);
        while (getline(f, x)) {
            if (x.find(name) != string::npos) {
                displayRec(x);
            }
        }
        f.close();
    }

    string getName(string rec) {
        return rec.substr(0, rec.find('|'));
    }

    void primary() {
        fstream f("primary.txt", ios::out);
        cout << "\033[34mPrimary file\033[m" << endl;
        for (auto i : ind_map) {
            f << i.first << "|" << i.second << endl;
            cout << i.first << "|" << i.second << endl;
        }
        f.close();
        cout << endl;
    }

    void secondary() {
        fstream f("secondary.txt", ios::out);
        fstream ff("data.txt", ios::in);
        cout << "\033[34mSecondary file\033[m" << endl;
        for (auto i : ind_map) {
            ff.seekg(i.second);
            ff >> x;
            f << getName(x) << "|" << i.first << endl;
            cout << getName(x) << "|" << i.first << endl;
        }
        f.close();
        ff.close();
        cout << endl;
    }

    void remove(string name, string usn) {
        fstream f("data.txt", ios::in | ios::out);
        f.seekg(ind_map[usn]);
        f.put('$');
        f.close();
        ind_map.erase(usn);
        auto it = find(names.begin(), names.end(), name);
        names.erase(it);
    }
};

int main() {
    Student s;
    fstream f("data.txt", ios::out);
    f.close();
    cout << "\033[34m1.Add\n2.Search\n3.Display\n4.Delete\nElse.Exit\n\033[m";
    while (1) {
        cout << "\033[31m\nChoice: \033[m";
        cin >> s.ch;
        switch (s.ch) {
            case 1: {
                cout << "Name, USN, Branch: ";
                cin >> s.name >> s.usn >> s.branch;
                if (s.search(s.usn)) {
                    cout << "Duplicate!" << endl;
                    break;
                }
                s.addEntry(s.name, s.usn, s.branch);
                break;
            }
            case 2: {
                cout << "Name to search: ";
                cin >> s.name;
                if (count(s.names.begin(), s.names.end(), s.name) == 0) {
                    cout << "Not present!" << endl;
                } else if (count(s.names.begin(), s.names.end(), s.name) == 1) {
                    cout<<"Details are: "<<endl;
                    s.displayMatchRec(s.name);
                } else {
                    cout << "Duplicates are present, enter USN to search: ";
                    cin >> s.usn;
                    cout<<"Details are: "<<endl;
                    s.displayMatchRec(s.usn);
                }
                break;
            }
            case 3: {
                s.displayData();
                s.primary();
                s.secondary();
                break;
            }
            case 4: {
                cout << "Name to remove: ";
                cin >> s.name;
                if (count(s.names.begin(), s.names.end(), s.name) == 0) {
                    cout << "Not present to delete!" << endl;
                    break;
                }
                s.displayMatchRec(s.name);
                cout << "Enter USN to delete: ";
                cin >> s.usn;
                s.remove(s.name, s.usn);
                cout<<"Succecfully deleted!"<<endl;
                break;
            }
            default:
                exit(0);
        }
    }
    return 0;
}
