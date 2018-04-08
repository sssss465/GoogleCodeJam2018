//
// Created by Andrew Huang on 4/7/18.
//

#include <iostream>
using namespace std;
#define int unsigned long long

int ogg[100000];
int sortd[100000];
int n, t;

int out;

bool troublesort(){
    bool done = false;
    while (!done){
        done = true;
        for (int i = 0; i < n-2; i++){
            if (sortd[i] > sortd[i+2]){
                done = false;
                swap(sortd[i], sortd[i+2]);
            }
        }
    }
    return true;
}
signed main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >>n;
        for (int j = 0; j < n; j++){
            int p;
            cin >> p;
            ogg[j] = p;
            sortd[j] = p;
        }
        troublesort();
        int smol = sortd[0];
        long dx = -1;
        for (long i = 1; i < n; i++){
            if (smol > sortd[i]){
                dx = i-1;
                break;
            } else {
                smol = sortd[i];
            }
        }
        if(dx == -1){
            cout << "Case #" << i+1 << ": OK"<< "\n";
        } else {
            cout << "Case #" << i+1 << ": " <<dx << "\n";
        }

    }
}