#include <iostream>
using namespace std;

int sumatorio(int num){

 int res = 0;

 for(int i = 1; i <= num; i++){
  return res += num;
 }
 
 return res;
}

int main(){
 if(sumatorio(10) == 10 && sumatorio(30) == 30){
  cout << "Todo funciona como debe.";
 }else{
  cout << "Algo va mal";
 }
}