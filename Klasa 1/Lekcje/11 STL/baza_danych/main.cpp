#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, money, pesel;
    map<int, int> users;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> pesel >> money;
        if(money < 0){
            if (users.find(pesel) != users.end()) {
                if (users[pesel] + money >= 0) {
                    users[pesel] += money;
                    cout << users[pesel] << "\n";
                } 
                else {
                    cout << "NIE\n";
                }
            } 
            else {
                cout << "NIE\n";
            }
        } 
        else {
            if (users.find(pesel) == users.end()) {
                users[pesel] = money;
            } 
            else {
                users[pesel] += money;
            }
            cout << users[pesel] << "\n";
        }
    }
}