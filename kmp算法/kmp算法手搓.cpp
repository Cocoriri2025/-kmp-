#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void computePM(char* str, int len, int* pi) {
	pi[0] = 0;
	int k = 0;
	int i = 1;
	while (i < len) {
		if (str[i] == str[k]) {
			pi[i++] = ++k;
		}
		else {
			if (k > 0)
				k = pi[k - 1];
			else {
				pi[i++] = k;
			}
		}
	}
}

int computeKMP(char* T, char* S, int* pi,int* num) {
	int T_len = strlen(T);
	int S_len = strlen(S);
	int j = 0;
	int i = 0;
	int count = 0;
	while (i < T_len) {
		if (T[i] == S[j]) {
			j++;
			i++;
		}
		else {
			if (j > 0)
				j = pi[j - 1];
			else {
				i++;
			}
		}
		if (j == S_len) {
			num[count++] = i - j + 1;
			j = pi[j - 1];
		}
	}
	return count;
}

int main() {
	char str[1000000];
	char arr[1000000];
	scanf("%s", arr);
	scanf("%s", str);
	int count = 0;
	int len = strlen(str);
	int len_2=strlen(arr);
	int* num=(int*)malloc(sizeof(int)*len_2);
	int* pi=(int*)malloc(sizeof(int)*len);
	computePM(str, len, pi);
	int n=computeKMP(arr, str, pi, num);
	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", pi[i]);
	}
	return 0;
}