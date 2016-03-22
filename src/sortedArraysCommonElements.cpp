/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare2(char* date1, char* date2){
	int day1 = ((int)(date1[0] - '0') * 10) + ((int)(date1[1] - '0'));
	int mon1 = ((int)(date1[3] - '0') * 10) + ((int)(date1[4] - '0'));
	int year1 = ((int)(date1[6] - '0') * 1000) + ((int)(date1[7] - '0') * 100) + ((int)(date1[8] - '0') * 10) + (int)(date1[9] - '0');
	int day2 = ((int)(date2[0] - '0') * 10) + ((int)(date2[1] - '0'));
	int mon2 = ((int)(date2[3] - '0') * 10) + ((int)(date2[4] - '0'));
	int year2 = ((int)(date2[6] - '0') * 1000) + ((int)(date2[7] - '0') * 100) + ((int)(date2[8] - '0') * 10) + (int)(date2[9] - '0');
	if (year1 > year2){
		return -1;
	}
	else{
		if (year1 == year2){
			if (mon1 > mon2){
				return -1;
			}
			else{
				if (mon1 == mon2){
					if (day1 > day2){
						return -1;
					}
					else{
						if (day1 == day2){
							return 0;
						}
						else{
							return 1;
						}
					}
				}
				else{
					return 1;
				}
			}
		}
		else{
			return 1;
		}
	}
}
void copy1(char* str1, char* str2, int len){
	int i = 0;
	while (str2[i] != '\0'){
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j, res,k=0;
	struct transaction *result;
	if (ALen >= BLen){
		result = (struct transaction*)malloc(ALen*sizeof(struct transaction));
	}
	else{
		result = (struct transaction*)malloc(BLen*sizeof(struct transaction));
	}
	if ((A == NULL) || (B == NULL)){
		return NULL;
	}
	else{
		for (i = 0; i < ALen; i++){
			for (j = 0; j < BLen; j++){
				res = compare2(A[i].date, B[j].date);
				if (res == 0){
					result[k].amount = A[i].amount;
					copy1(result[k].date, A[i].date,11);
					copy1(result[k].description, A[i].description,20);
					k++;
				}
			}
		}
	}
	if (k == 0){
		return NULL;
	}
	else{
		return result;
	}
}