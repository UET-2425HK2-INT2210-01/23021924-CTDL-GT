#include <iostream>
using namespace std;

int gcb(int a, int b){
    while (a != b){
        if (a>b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}
    
int main(){
    int M, N;
    cin >> M >> N;
    cout << gcb(M,N);
}