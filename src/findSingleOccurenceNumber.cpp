/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdlib.h>

int findSingleOccurenceNumber(int *A, int len) {
	int result = -1,count=0;
	if (A == NULL){
		return result;
	}
	else{
		for (int i = 0; i < len; i++){
			count = 0;
			for (int j = 0; j < len; j++){
				if (A[i] == A[j]){
					count++;
				}
			}
			if (count == 1){
				result = A[i];
				return result;
				break;
			}
		}
	}
}