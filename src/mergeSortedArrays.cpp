/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
void copy(char*, char*,int);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare1(char* date1, char* date2){
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



void copy(char* str1, char* str2,int len){
	int i=0;
	while(str2[i]!='\0'){
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	struct transaction temp;
	int res, i = 0, j = 0;
	if ((A == NULL) || (B == NULL)){
		return NULL;
	}
	else{
		for (i = 0; i < ALen; i++){//copying A transactions into result
			result[i].amount = A[i].amount;
			copy(result[i].date, A[i].date, 11);
			copy(result[i].description, A[i].description, 20);
		}
		for (i = 0, j = ALen; i < BLen, j < ALen + BLen; i++, j++){//copying B transactions into result
			result[j].amount = B[i].amount;
			copy(result[j].date, B[i].date, 11);
			copy(result[j].description, B[i].description, 20);
		}
		for (int i = 0; i < ALen + BLen; i++){
			for (int j = i; j < ALen + BLen; j++){
				res = compare1(result[i].date, result[j].date);//comparing the two structures
				if (res == -1){
					//swap(result[i], result[j]);
					temp.amount = result[i].amount;
					copy(temp.date, result[i].date, 11);
					copy(temp.description, result[i].description, 20);
					result[i].amount = result[j].amount;
					copy(result[i].date, result[j].date, 11);
					copy(result[i].description, result[j].description, 20);
					result[j].amount = temp.amount;
					copy(result[j].date, temp.date, 11);
					copy(result[j].description, temp.description, 20);
				}
			}
		}
		return result;
	}
}
					