#include <iostream>
using namespace std;

template <typename T>

class clsCalculator {
    public:

    static T add(T a, T b){
        return a + b;
    }

    static T subtract(T a, T b){
        return a - b;
    }

    static T divide(T a, T b){
        return a / b;
    }

    static T multipluy(T a, T b){
        return a * b;
    }
};

int main(){
    cout << clsCalculator<int>::add(100, 200) << endl;
    cout << clsCalculator<int>::subtract(90, 60) << endl;
    cout << clsCalculator<double>::divide(50, 3) << endl;
    cout << clsCalculator<char>::multipluy(15,15) << endl;
    
    return 0;
}