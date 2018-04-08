#include <iostream>
using namespace std;

pair<int, int> cities[500];

int q, b, qq, city;
int main() {
    cin >>q;
    int l,r;
    for (int i =0; i < q; i++){
        cin >>b;
        for (int j = 0; j < b; j++){
            cin>>l>>r;
            cities[j] = make_pair(l,r);
        }
        cin >> qq;
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < qq; j++){
            cin >> city;
            int count = 0;

            for (int j = 0; j < b; j++){
                if (cities[j].first <= city && cities[j].second >= city){
                    count++;
                }
            }
            cout << count << " ";
        }
        cout << "\n";
    }

    return 0;
}
