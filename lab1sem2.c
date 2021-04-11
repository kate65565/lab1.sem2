float modulus (float x) { 
	if (x >= 0)
	return x;
	else return x*(-1);
}
float factorial(int n) 
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
float myPow(float x, int n) 
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
	float x[] = {1,2,3,4,5}; 
    float z[]={0.841667,0.907936,0.145313,-0.756027,-0.960922}; 
	float y[] = {0,0,0,0,0}; 
	int i, n,j=0;
	e = 0.1; 

	for (j=0;j<=4;j++){
		t = x[j];
		i = 0;
		while(modulus(t) > e){
			t = (myPow(-1,i)*myPow(x[j],2*i+1))/factorial(2*i+1); 
			y[j] = y[j] + t; 
			i++;
		}
	}
	
	for(i = 0; i<=4;i++){
		if (modulus(y[i] - z[i]) > 0.001)
			return -1; // error
	}
	return 0; // success 
} 

