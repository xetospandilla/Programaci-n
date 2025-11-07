#include <iostream>
using namespace std;

int res = 0;

double siguiente(int a){
    return res = a +1;
}

int main(){

    if(siguiente(1)==2){
        cout << "Las prueba salió perfectamente.";
    } else {
        cout << "Algo va mal.";
    }

    return 0;
}