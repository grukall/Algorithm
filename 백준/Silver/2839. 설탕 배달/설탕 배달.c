#include <stdio.h>
int main(void) {
	int n;
	int a,b;
	int temp;
	scanf("%d", &n);
	a = n / 5;
	temp = n % 5;
	while(1)
	if (temp % 3 == 0){
		b = temp / 3;
		break;
	}
	else if (a == 0) {
		printf("-1");
		return 0;
	}
	else {
		temp += 5;
		a--;
	}
	printf("%d", a + b);
	return 0;
}