#include <iostream>
using namespace std;

int fact(int num){
    
    int res = 1;
    
    if(num < 1){
        cout << "Syntax Error";
    }else{
        for(int i = 1; i <= num; i++){
            res = res *i;
        }
    }
    return res;
}

int main(){
    if (fact(1) == 1 && fact(4) == 24){
        cout << fact(1) << endl;
        cout << fact(4) << endl;
        cout << "Todo funciona correctamente";
    }else{
        cout << "Algo no funciona.";
    }
}