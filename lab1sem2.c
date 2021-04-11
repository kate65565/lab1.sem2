#include "stdio.h"
float modulus (float x) { //подсчет модуля
	if (x >= 0)
	return x;
	else return x*(-1);
}
float factorial(int n) //подсчет факториала
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
float myPow(float x, int n) //подсчет степени 
{
	int i;
	float q;
	q=x;
	if (n==0)
	return 1;
  	for (i=0; i<n-1;i++) {
  		x=x*q;
	  }
	  return x;	
}
int main(){
	float t,e = 0;
	float x[] = {1,2,3,4,5}; // набор тестовых значений х в рад
    float z[]={0.841667,0.907936,0.145313,-0.756027,-0.960922}; // набор ожидаемых результатов
	float y[] = {0,0,0,0,0}; // пустой массив для сохранения результатов
	int i, n,j=0;
	e = 0.2; //определение заданной точности

	for (j=0;j<=4;j++){ //перебор элементов массива
		t = x[j];
		i = 0;
		while(modulus(t) > e){
			t = (myPow(-1,i)*myPow(x[j],2*i+1))/factorial(2*i+1); //вычисление синуса по формуле
			y[j] = y[j] + t; 
			i++;
		}
	}
	
	for(i = 0; i<=4;i++){
		if (modulus(y[i] - z[i]) > 0.001)
			return -1; // код ошибки
	}
	return 0; //код успешного выполнения
} 

