#include <iostream>
using namespace std;

template <typename T> 


T GetMax(T a, T b){
    return (a > b);
} 

int main(){
    int maxInt = GetMax(9, 8);
    float maxfloat = GetMax(19.8, 19.6);
    char maxChar = GetMax('a', 'n');

    cout << maxInt << endl;
    cout << maxfloat << endl;
    cout << maxChar << endl;
 
    return 0;
}