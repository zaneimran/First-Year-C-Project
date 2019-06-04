#include <stdio.h>

int DivisorOfThree(int a, int b, int c)
{
	int max, i;
	int GCD = 0;

	if(a>b && a>c){
		max = a;
	}
	else if(b>a && b>c){
		max = b;
	}
	else{
		max = c;
	}

	printf("%d", max);
	
	if(a<=0 || b<=0 || c<=0){
		GCD = -1;
	}

	for(i=0;i<max; i++){
		if ((a%i) == 0 && (b%i)==0 && (c%i) == 0){
			GCD = i;
		}
		else{
			GCD = 0;
		}
	}

	return GCD; 	
}

int main(void){
    printf("GCD = %d\n", DivisorOfThree(1288, 759, 1173));      
    printf("GCD = %d\n", DivisorOfThree(760, 1960, 2720));      
    printf("GCD = %d\n", DivisorOfThree(100, 0, 1000000));

    return 0;
}