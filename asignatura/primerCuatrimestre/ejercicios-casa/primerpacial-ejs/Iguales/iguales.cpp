#include <iostream>
using namespace std;

bool iguales(double list1[], double list2[], int cuantos1, int cuantos2){
 if(cuantos1 != cuantos2){
  cout << "Las listas no son iguales." << endl;
  return false;
 }
 
 for(int i = 0; i < cuantos1; i++){
  if(list1[i] != list2[i]){
   cout << "Las listas no son iguales." << endl;
   return false;
  }
 }
 cout << "Las listas son iguales." << endl;
 return true;
}

int main(){

 double list1 [] = {1,2,3,4,5};
 double list2[] = {1,2,3,4,5.5};

 if(iguales(list1,list2, 5, 5) == false){
  cout << "Todo funciona ok";
 }else{
  cout << "Me cago en tus muelas";
 }
 return 0;
}
