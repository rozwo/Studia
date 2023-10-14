// Napisz program testujący zdefiniowane przez ciebie manipulatory.
// Jednym z elementów testowania ma być procedura, która odczyta wszystkie
// linie danych zapamiętując je w kontenerze vector<>, następnie posortuje
// odczytane linie leksykograficznie i wypisze je wraz z pierwotnymi numerami
// linii (numer linii umieść na początku wiersza w nawiasach kwadratowych).

#include "manipulators.hpp"
using namespace std;

void printv(vector<string> v1, vector<string> v2) {
    int i = 0;
    cout << endl << "Wynik" << streams::colon << endl;  //pokazuje uzycie colon
    while(i != v1.size()) {
        int j = 0;
        while(v1[i] != v2[j])
        j++;        //pokazuje uzycie index i comma
        cout << streams::index(j+1,1) << v1[i] << streams::comma << endl;
        i++;
    }
}

int main() {
    // pokazuje ignore
    cout << "Napis ";
    string s;
    getline(cin >> streams::ignore(5), s);
    cout << s << endl;

    // pokazuje clearline
    string tekst;
    getline(cin >> streams::clearline, tekst);
    // cin >> streams::clearline >> tekst;
    cout << endl << tekst << endl;

    // pokazuje colon, index i comma
    cout << endl;
    string c;
    vector<string> v1,v2;
    cout << "Linie do sortowania " << endl;
    while (getline(cin, c)) {
        if(c == "") {
            break;
        }
        v1.push_back(c);
    }
    v2 = v1;
    sort(v1.begin(), v1.end(), [](const string& a, const string& b) {
        const string& str1 = a;
        const string& str2 = b;

        const int len = min(str1.length(), str2.length());

        for (int i = 0; i < len; i++) {
            char c1 = tolower(str1[i]);
            char c2 = tolower(str2[i]);
            if (c1 < c2) {
                return true;
            } else if (c1 > c2) {
                return false;
            }
        }
        return str1.length() < str2.length();
    });

    printv(v1,v2);

    return 0;
}