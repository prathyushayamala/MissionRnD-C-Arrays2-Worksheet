/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare(char* transaction_date, char* date){
	int day1 = ((int)(transaction_date[0] - '0') * 10) + ((int)(transaction_date[1] - '0'));
	int mon1 = ((int)(transaction_date[3] - '0') * 10) + ((int)(transaction_date[4] - '0'));
	int year1 = ((int)(transaction_date[6] - '0') * 1000) + ((int)(transaction_date[7] - '0') * 100) + ((int)(transaction_date[8] - '0') * 10) + (int)(transaction_date[9] - '0');
	int day2 = ((int)(date[0] - '0') * 10) + ((int)(date[1] - '0'));
	int mon2 = ((int)(date[3] - '0') * 10) + ((int)(date[4] - '0'));
	int year2 = ((int)(date[6] - '0') * 1000) + ((int)(date[7] - '0') * 100) + ((int)(date[8] - '0') * 10) + (int)(date[9] - '0');
	if (year1 > year2){
		return 1;
	}
	else{
		if (year1 == year2){
			if (mon1 > mon2){
				return 1;
			}
			else{
				if (mon1 == mon2){
					if (day1 > day2){
						return 1;
					}
					else{
						return 0;
					}
				}
				else{
					return 0;
				}
			}
		}
		else{
			return 0;
		}
	}
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int count = 0,res;
	if (Arr == NULL){
		return NULL;
	}
	else{
		for (int i = 0; i < len; i++){
			res = compare(Arr[i].date, date);
			if (res == 1){
				count=len-i;
				break;
			}
		}
		return count;
	}
}
