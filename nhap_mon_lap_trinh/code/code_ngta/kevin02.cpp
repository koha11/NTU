#include<stdio.h>
#include<math.h>
#include<string.h>

void binaryToDecimal();
int convertBinaryToDecimal(long bin, int count, int i);

int countDigits(int num);

void multiplicationTable();

void reverseNumber();

void decimalToBinary();

int main(){
	int chosen, integer_num;
	printf("Please choose any modal here by press keys: \n");
	printf("1. Convert binary number to decimal\n");
	printf("2. Convert decimal number to binary\n");
	printf("3. Multiplication Table Up to 9\n");
	printf("4. Count Number of Digits in an Integer. Ex: 678 -> 3\n");
	printf("5. Reverse an Integer. Ex: 1234 -> 4321\n");
	printf("Choose: ");
	scanf("%d", &chosen);
	
	switch(chosen){
		case 1:
			binaryToDecimal();
			break;
		case 2:
			decimalToBinary();
			break;
		case 3:
			multiplicationTable();
			break;
		case 4:
			printf("Your integer: ");
			scanf("%d", &integer_num);
			printf("Your number of digits: %d", countDigits(integer_num));
			break;
		case 5:
				printf("Your integer: ");
				reverseNumber();
				break;
		default:
			printf("Plese re-run the program!");
	}
	
}

void binaryToDecimal(){
	long bin;
	int i, decimal = 0;
	
	printf("Your binary: ");
	scanf("%ld", &bin);
	
	int count = countDigits(bin);
	
	for(i = 0; i < count; i++)
	{
		if(convertBinaryToDecimal(bin,count,i) == 1)
			decimal += (int)pow(2,i);
	}
	
	printf("%ld --> %d\n", bin, decimal);
	
	//1111/1000 --> 111/100 --> 11/10 --> 1	
}

int convertBinaryToDecimal(long bin, int count, int i){
	int j;
	count--;
	
	while(count != i)
	{
		bin = bin % (int)pow(10,count);
		count--;
	}
	
	if(i != 0)
		bin = bin / (int)pow(10,i);

	return bin;	
}

int countDigits(int num){
	int soDu, count = 0;
	while(soDu != num){
		count++;
		soDu = num % (int)pow(10,count);
	}
	
	return count;
}

void multiplicationTable(){
	int mt[10][10], i ,j;
	
	mt[0][0] = 0;
	
	for(i = 1; i < 10; i++)
		mt[i][0] = i;
	for(j = 1; j < 10; j++)
		mt[0][j] = j;
	
	for(i = 1; i < 10; i++)
		for(j = 1; j < 10; j++)
			mt[i][j] = i*j;
	
	for(i = 0; i < 10; i++)
	{
		printf("\n");
		if(i == 1)
			printf("\n");
		for(j = 0; j < 10; j++)
		{
			printf("%5d", mt[i][j]);
			if(j == 0)
				printf(" ");
		}			
	}			
}

void reverseNumber(){
	char num[30];
	int i;
	scanf("%s", &num);
	
	printf("%s --> ", num);
	for(i = strlen(num); i >= 0; i--)
		printf("%c", num[i]);
}

void decimalToBinary(){
	int digit, j, i = 0, num, k = 0;
	int isBitOne[50];
	printf("Your integer: ");
	scanf("%d", &num);
	while(pow(2,i) < num){
		i++;
	}
	digit = i;
	
	for(i = i-1 ;i >= 0; i--)
	{
		if(num - pow(2,i) >= 0)
		{
			num = num - pow(2,i);
			isBitOne[k] = i;
			k++;
		}
		if(num == 0)
			break;
		//15 - 8 = 7 - 4 = 3 - 2 = 1 - 1 = 0
	}
	
	for(i = digit-1;  i >= 0; i--)
		for(j = 0; j < k; j++)
			if(i == isBitOne[j])
			{
				printf("1");
				break;
			}
			else if(j == k-1) 
				printf("0");
}



