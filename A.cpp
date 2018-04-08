#include <iostream>
#include <string>

using namespace std;
#define ull long long
int t;
ull d;
string c;

pair<ull, ull> damage(){
    ull damage = 0;
    ull charge = 1;
    for (int j = 0; j<c.length(); j++ ){
        if (c[j] == 'C'){
            charge = charge *2;
        } else {
            damage += charge;
        }
    }
    return make_pair(damage,charge);
}

int main(){
    cin >> t;
    for (int i =0; i < t; i++){
        cin >> d >> c;
        int swaps = 0;
        // find damage
        pair<ull, ull> dc = damage();
        ull ldamage = dc.first;
        ull charge = dc.second;
        //cout << "damage is " << ldamage << " charge is " << charge << endl;
        ull running = ldamage; // running damage
        ull grad = running; // make sure its decreasing
        if (ldamage > d){
            while (running-d > 0){ // if u can find the
                for (int j = c.length()-2; j>= 0; j--){// find score backwards
                   // cout << "entered for loop" << endl;
                    if (c[j] == 'C' && c[j+1] == 'S'){
                        swap(c[j], c[j+1]);
                        swaps ++;
                    }
                    if (c[j] == 'S'){
                        running -= charge;
                    } else {
                        charge /= 2;
                    }
                }
                pair<ull, ull> dc2 = damage();
                if (ldamage == dc2.first) {
                   // cout << "broke from no decrease" << endl;
                    break;
                }; // this means there has been no decrease form last time
                ldamage = dc2.first;
                charge = dc.second;
                running = ldamage;
                //if (ldamage <= d) break;
            } // else no swaps needed
        }

        //cout << c << endl;
        pair <ull, ull> out = damage();
        if (out.first <= d){
            cout << "Case #" << i+1 << ": " << swaps << "\n";
        } else {
            cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << "\n";
        }
        //cout << "\n\n";
    }
}

