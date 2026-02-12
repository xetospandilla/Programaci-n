#include <iostream>
using namespace std;

bool primo(int num){
 if(num == 2){
  cout << "El número 2 es primo." << endl;
  return true;
 }
 if (num < 2){
  cout << "El número " << num << "no es primo." << endl;
  return false;
 }
 if (num % 2 == 0){
  cout << "El número " << num << " no es primo." << endl;
  return false;
 }

 for(int i = 3; i < num; i++){
  if(num % i == 0){
   return false;
  }
 }
 return true;
}

int main(){
 if(primo(2) == true && primo(4) == false && primo(5) == true){
  cout << "Todo funciona correctamente." << endl;
  cout << "Las respuestas dieron: " << primo(2) << ", " << primo(4) << " y " << primo(5);
 }else{
  cout << "Algo va mal";
 }
}
