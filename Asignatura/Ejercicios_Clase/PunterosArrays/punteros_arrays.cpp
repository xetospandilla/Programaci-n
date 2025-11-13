#include <iostream>
using namespace std;

//----Variables----

void porValor(int x)       {x+=1;};
void porReferencia(int &x) {x +=1;};
void porPuntero(int *x)    {*x +=1;};

//----Arrays-----

void arrayClasico(int arr[], int size){
 for(int i = 0; i < size; i++){
  arr[i] *=2;
 }
}

void arrayPorPuntero(int *arr, int size){
 for(int i = 0; i < size; i++){
  arr[i] *=2;
 }
}

void arrayReferencia(int (&arr)[5]){
 for(int i = 0; i < 5; i++){
  arr[i] *=2;
 }
}

int main(){
 int a = 5;
 int nums[] = {1,2,3,4,5};
 

 //Falta modificar las funciones, para que impriman enpantalla lo que deberían.
 cout << "------------------------------------------" << endl;
porValor(a);
porReferencia(a);
porPuntero(a);
 cout << "------------------------------------------" << endl;
 arrayClasico(nums, a);
 arrayPorPuntero(nums, a);
 arrayReferencia((&nums)[a]);
 cout << "------------------------------------------" << endl;

 return 0;
}