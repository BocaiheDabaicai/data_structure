#include<iostream>
#define N 10
typedef struct LString {
	char str[N+1];
	int length;
}LString;
typedef struct NString {
	char* ch;
	int length;
}NString;
int initNString(NString& str);
int strassign(NString& str, char* ch);
int strlength(NString str, int& x);
int EqualNString(NString str1, NString str2);
int Concat(NString& str, NString str1, NString str2);
int SubString(NString& str, NString str1, int pos, int len);
int ClearNString(NString& str);
int index(NString str, NString substr);
int getnext(NString substr, int next[]);//KMP needed
int KMP(NString str, NString substr, int next[]);
int ToString(NString str);
int main() {
	//char a[] = "abc1234abc";
	//char b[] = "ppoopp";
	//NString are,are1,are2;
	//initNString(are);
	//initNString(are1);
	//initNString(are2);
	//strassign(are1, a);
	////SubString(are2, are1, 1, 4);
	//strassign(are2, b);
	//Concat(are, are1, are2);
	//ToString(are);
	//---------------------------------Matching'algorithm-------------------------
	char test1[] = "0aabbaababaab";
	char test2[] = "0ababaa";
	int next[N],i;
	NString q1, q2;
	initNString(q1);
	initNString(q2);
	strassign(q1, test1);
	strassign(q2, test2);
	ToString(q1);
	ToString(q2);
	index(q1, q2);
	getnext(q2, next);
	i = KMP(q1, q2, next);
	printf("%d\n", i);
	//---------------------------------part two------------------------
	/*char test2[] = "0ababaa";
	int next[N];
	NString q2;
	initNString(q2);
	strassign(q2, test2);
	getnext(q2, next);*/
	return 1;
}
int initNString(NString& str)
{
	str.ch = NULL;
	str.length = 0;
	return 1;
}
int strassign(NString& str, char* ch)
{
	if (str.ch != NULL) //if(str.ch)
		free(str.ch);
	int len = 0;
	char* c = ch;
	while (*c != NULL) {
		++len;
		++c;
	}
	if (len == 0) {
		str.ch = NULL;
		str.length = 0;
		return 1;
	}
	else {
		str.ch = (char*)malloc(sizeof(char) * (len + 1));
		if (str.ch == NULL)
			return 0;
		else {
			c = ch;
			for (int i = 0; i <= len; ++i,++c)
				str.ch[i] = *c;
			str.length = len;
			return 1;
		}
	}
	return 1;
}
int strlength(NString str, int& x)
{
	x = str.length;
	return 1;
}
int EqualNString(NString str1, NString str2)
{
	for (int i = 0; i < str1.length && i < str2.length; ++i)
		if (str1.ch[i] != str2.ch[i])
			return str1.ch[i] - str2.ch[i];
	return str1.length - str2.length;
}
int Concat(NString& str, NString str1, NString str2)
{
	if (str.ch) {
		free(str.ch);
		str.ch = NULL;
	}
	str.ch = (char*)malloc(sizeof(char) * (str1.length + str2.length + 1));
	if (str.ch == NULL)
		return 0;
	char* p, * q;
	p = str1.ch;
	q = str2.ch;
	int i, j;
	for (i = 0; i < str1.length; ++i,++p)
		str.ch[i] = *p;
	for (j = str1.length; j < str1.length + str2.length + 1; ++j, ++q)
		str.ch[j] = *q;
	str.length = str1.length + str2.length;
	return 1;
}
int SubString(NString& str, NString str1, int pos, int len)
{
	if (str1.ch == NULL||pos<0||pos>=str1.length||len>str1.length-pos)
		return -1;
	if (str.ch) {
		free(str.ch);
		str.ch = NULL;
	}
	if (len == 0) {
		str.ch = NULL;
		str.length = 0;
		return 1;
	}
	str.ch = (char*)malloc(sizeof(char) * (len + 1));
	int i,j;
	for (i = 0, j = pos; i < len ; ++i, ++j)
		str.ch[i] = str1.ch[j];
	str.ch[i] = '\0';
	str.length = len;
	return 1;
}
int ClearNString(NString& str)
{
	if (str.ch) {
		free(str.ch);
		str.ch=NULL;
	}
	str.length = 0;
	return 1;
}
int index(NString str, NString substr)
{
	int i = 0, j = 0, k = i;
	while (i < str.length && j < substr.length) {
		if (str.ch[i] == substr.ch[j]) {
			i++;
			j++;
		}
		else {
			i = ++k;
			j = 0;
		}
	}
	//printf("j's length is: %d\nsubstr's length is %d", j,substr.length);
	if (j == substr.length)
		return k;
	else
		return -1;
}
int getnext(NString substr, int next[])	//there keeps special,and thus storing relevant datas starts at the first position.
{	//existing bug.
	int i = 1, j = 0;
	next[1] = 0;
	while (i < substr.length)
		if (j == 0 || substr.ch[i] == substr.ch[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	for (int a = 1; a < substr.length; a++)
		printf("%d ", next[a]);
	printf("\n");
	return 1;
}
int KMP(NString str, NString substr, int next[])
{
	int i = 1, j = 1;
	while (i < str.length && j < substr.length)
		if (j == 0 || str.ch[i] == substr.ch[j]) {
			i++;
			j++;
		}
		else
			j = next[j];
	printf("tested data is: %d\n", j);
	if (j >= substr.length)
		return i - substr.length + 1;	//Matching'start
	else
		return -1;
}
int ToString(NString str)
{
	int i;
	/*for (i = 0; i < str.length; ++i)
		printf("%c", str.ch[i]);*/
	printf("%s", str.ch);
	printf("\n");
	return 1;
}//轻描淡写地几句话写出一个运算规律
