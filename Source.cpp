#include "Set.h"
#include <set>
using namespace std;


int main() {
    Set<int> intSet;
    Set<string> stringSet;
    while (true) {
        int type = 0;
        cout << "1. int" << endl;
        cout << "2. string" << endl;
        cout << "Choice type: ";
        cin >> type;
        if (type != 1 && type != 2) {
            cout << "Incorrect choice, try again.\n";
        }
        else {
            bool t = true;
            while (t) {
                cout << "\n1. Add element" << endl;
                cout << "2. Remove element" << endl;
                cout << "3. Find element" << endl;
                cout << "4. Input elements in set" << endl;
                cout << "5. Output set" << endl;
                cout << "6. Enter new set, associate and output" << endl;
                cout << "7. Enter new set, intersect and output" << endl;
                cout << "8. Enter new set and check for subset" << endl;
                cout << "0. Back to choosing" << endl;
                int ch = 0;
                cin >> ch;
                switch (ch) {
                case 1:
                    if (type == 1) {
                        cout << "Enter element: ";
                        int a = 0;
                        cin >> a;
                        intSet.add(a);
                    }
                    else {
                        cout << "Enter element: ";
                        string a = "";
                        cin >> a;
                        stringSet.add(a);
                    }
                    break;
                case 2:
                    if (type == 1) {
                        cout << "Enter element: ";
                        int a = 0;
                        cin >> a;
                        intSet.remove(a);
                    }
                    else {
                        cout << "Enter element: ";
                        string a = "";
                        cin >> a;
                        stringSet.remove(a);
                    }
                    break;
                case 3:
                    if (type == 1) {
                        cout << "Enter element: ";
                        int a = 0;
                        cin >> a;
                        if (intSet.find(a))
                            cout << "Element was found!\n";
                        else
                            cout << "Element wasn't found!\n";
                    }
                    else {
                        cout << "Enter element: ";
                        string a = "";
                        cin >> a;
                        if (stringSet.find(a))
                            cout << "Element was found!\n";
                        else
                            cout << "Element wasn't found!\n";
                    }
                    break;
                case 4:
                    cout << "Enter number of elements: ";
                    if (type == 1)
                        cin >> intSet;
                    else
                        cin >> stringSet;
                    break;
                case 5:
                    if (type == 1)
                        cout << intSet;
                    else
                        cout << stringSet;
                    break; 
                case 6:
                    cout << "Enter number of elements: ";
                    if (type == 1) {
                        Set<int> temp, res;
                        cin >> temp;
                        res.association(intSet, temp);
                        cout << res;
                    } else {
                        Set<string> temp, res;
                        cin >> temp;
                        res.association(stringSet, temp);
                        cout << res;
                    }
                    break;
                case 7:
                    cout << "Enter number of elements: ";
                    if (type == 1) {
                        Set<int> temp, res;
                        cin >> temp;
                        res.intersection(intSet, temp);
                        cout << res;
                    }
                    else {
                        Set<string> temp, res;
                        cin >> temp;
                        res.intersection(stringSet, temp);
                        cout << res;
                    }
                    break;
                case 8:
                    cout << "Enter number of elements: ";
                    if (type == 1) {
                        Set<int> res;
                        cin >> res;
                        if (res.is_subset(intSet))
                            cout << "New set is subset!\n";
                        else 
                            cout << "New set isn't subset!\n";
                    }
                    else {
                        Set<string> res;
                        cin >> res;
                        if (res.is_subset(stringSet))
                            cout << "New set is subset!\n";
                        else
                            cout << "New set isn't subset!\n";
                    }
                    break;
                case 0:
                    t = false;
                    break;
                default:
                    cout << "Incorrect choice, try again.\n";
                }
            }
        }
    }
    return 0;
}