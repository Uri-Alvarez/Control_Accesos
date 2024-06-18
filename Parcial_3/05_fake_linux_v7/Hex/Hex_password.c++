#include<iostream>
using namespace std;

int main()
{
	string nokey = "MVZMX-";
    string key = "PVHA8-3YNHU-76AD8-YGGY5-NPWTH";
    string strInput;

    cout << "Ingresa password_: ";
    cin >> strInput;

    if (strInput == key)
    {
        cout << "Completed!" << endl;
    }
    else
    {
        cout << "Failed" << endl;
    }

    return 0;
}