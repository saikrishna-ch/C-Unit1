//
//  E01_Functions.cpp
//  Unit1_exercise1_understanding_functions
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E01_FunctionsSpec.cpp file.
 
 */


//
// Note:
//  Think of all the edge cases.
//
// returns the mid-point of
// given 2 points on X-axis
//
int midPoint(int x1, int x2) {
	int mid = x1 + (x2 - x1) / 2;
    return mid;
}

//
// sum of most significant digits of non-negative integers.
//
int sumOfMSDs(int num1, int num2) {
	//int sum = num1 + num2;
	if (num1 < 10 &&num2 <10) {
		return num1+num2;
	}
	else if (num1 >= 10 && num2 < 10) {
		while (num1 >= 10) {
			num1 = num1 / 10;
		}
		return num1 + num2;
	}
	else if (num2 >= 10 && num1 < 10) {
		while (num2 >= 10) {
			num2 = num2 / 10;
		}
		return num1 + num2;
	}
	else {
		while (num2 >= 10) {
			num2 = num2 / 10;
		}
		while (num1 >= 10) {
			num1 = num1 / 10;
		}
		return num1 + num2;
	}

	
}

//
// sum of two 100 digit positive numbers
//
void sumOf100DigitNumbers(int num1[100], int num2[100], int sum[101]) {
	int carry = 0;
	for (int i = 99; i >=0; i--) {
		if (num1[i] + num2[i] +carry < 10) {
			sum[i+1] = num1[i] + num2[i]+carry;
			carry = 0;
		}
		else {
			sum[i + 1] = (num1[i] + num2[i] +carry) % 10;
			carry = (num1[i]+num2[i]+carry)/ 10;

		}
		sum[0] = carry;
	}
}

//
// product of two 100 digit positive numbers
//
void productOf100DigitNumbers(int num1[100], int num2[100], int prod[200]) {
	int i, j =99, carry = 0, start = 0,k ,end = 199, swift = 199, count = 0, carry2 = 0;
	int sum[100][200];
	for (int row = 0; row< 100; row++) {
		for (int col = 0; col < 200; col++) {
			sum[row][col] = 0;
		}
	}
	for (j = 99; j >= 0; j--) {
		end = swift;
		for (i = 99; i >= 0; i--) {
			if ((num1[i] * num2[j]) + carry < 10) {
				sum[start][end] = num1[i] * num2[j] + carry;
				carry = 0;
				end--;
			}
			else {
				sum[start][end] = (num1[i] * num2[j] + carry) % 10;
				carry = (num1[i] * num2[j] + carry) / 10;
				end--;
			}

		}
		sum[start][end] = carry;
		carry = 0;
		start++;
		swift--;
	}
	for (k = 199; k >= 0; k--) {
		count = 0;
		for (int l = 0; l <= 99; l++) {
			count = count + sum[l][k];

		}
		if (count + carry2 < 10) {
			prod[k] = count + carry2;
			carry2 = 0;
		}
		else {
			prod[k] = (count + carry2) % 10;
			carry2 = (count + carry2) / 10;

		}
		
	}
	prod[k] = carry2;
}
