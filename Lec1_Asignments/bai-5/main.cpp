#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int a[5];
    for (int i=0; i<5; i++){
        cin >> a[i];
    }
    int max=a[0], min=a[0];
    int sum=0;
    for (int i=1; i<5; i++){
        if (a[i] < min) {
            min = a[i];
        } else if(a[i] > max){
            max = a[i];
        }
    }
    sum = max + min;
     cout << sum;
}