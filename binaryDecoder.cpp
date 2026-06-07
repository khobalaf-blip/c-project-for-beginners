#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cout << "masukkan kode biner : ";
    cin >> s;

    int arr[s.size()];
    for (int i = 0; i < s.size(); i ++){
        arr[i] = s[i] - '0';
    }

    int nilai = 0;
    int times = 1;

    for(int j = s.size() - 1; j >= 0; j--){
        nilai = arr[j] * times + nilai;
        times = times * 2;
    }

    cout << "Nilai : "<< nilai << endl;
    return 0;
}