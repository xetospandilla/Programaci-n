/*
-------------------------------------------------------------------------------------------------------
Bucle For-Each
-------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> nums;
    int num;

    cout << "Introduce varios números. Escribe 0 para salir." << endl;
    while(cin >> num && num != 0){
        nums.push_back(num);
    }

    cout << "Ha introducido los siguientes números: " << endl;
    
    for(int n:nums){
        cout << n;
    }
    cout << endl;

    return 0;
}
/*
-------------------------------------------------------------------------------------------------------
*/