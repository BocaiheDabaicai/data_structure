#include<stdio.h>
int main() {
	int year, month, day, result=0;
	int montharray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("Please insert correct year¡¢month¡¢day,\nthe programe will export an anwser about data.\n");
	scanf_s("%d %d %d", &year, &month, &day);
	if (year >= 1900 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
		for (int i = 0; i < month-1; i++)
			result += montharray[i];
		result += day;
		if (year % 4 == 0 && month >= 2)
			result += 1;
		printf("Today is %d day of this year", result);
	}
	else
		printf("Your importing datas have some expression mistakes!\n");
	return 1;
}