/* check unclosed brackets */
/* 2026-10-11 */

#include <stdio.h>

#define MAXL 100

int main(void)
{
	int br[MAXL]={0};
	int brn[MAXL]={0};
	int brc[MAXL]={0};
	/*
	 * br[i]=1	(
	 * br[i]=2	[
	 * br[i]=3	{
	 */
	int p=0;
	int line=1;
	int col=0;

	int test=0;
	/*
	 * 0	in test
	 * 1	in double quote
	 * 2	in quote
	 * 3	in //comment
	 * 4	in / * comment
	 */
	int bsl=0;
	/* backslash */

	int c;
	int lc=0;
	/* last c */
	while ((c=getchar())!=EOF) {
		++col;
		if (c=='\t') {
			col=(1+col/8)*8;
		} else if (c=='\n') {
			++line;
			col=0;
		}
		if (test==0) {
			switch (c) {
			case '(':
				br[p]=1;
				brn[p]=line;
				brc[p]=col;
				++p;
				break;
			case '[':
				br[p]=2;
				brn[p]=line;
				brc[p]=col;
				++p;
				break;
			case '{':
				br[p]=3;
				brn[p]=line;
				brc[p]=col;
				++p;
				break;
			case ')':
				--p;
				if (p<0) {
					printf("Overmatched bracket at line %d, column %d.\n",line,col);
					break;
				}
				if (br[p]==1)
					br[p]=0;
				else
					printf("Unmatched bracket at line %d, column %d.\n",line,col);
				break;
			case ']':
				--p;
				if (p<0) {
					printf("Overmatched brackets at line %d, column %d.\n",line,col);
					break;
				}
				if (br[p]==2)
					br[p]=0;
				else
					printf("Unmatched brackets at line %d, column %d.\n",line,col);
				break;
			case '}':
				--p;
				if (p<0) {
					printf("Overmatched brackets at line %d, column %d.\n",line,col);
					break;
				}
				if (br[p]==3)
					br[p]=0;
				else
					printf("Unmatched brackets at line %d, column %d.\n",line,col);
				break;
			case '\"':
				test=1;
				break;
			case '\'':
				test=2;
				break;
			case '/':
				if (lc=='/')
					test=3;
				break;
			case '*':
				if (lc=='/')
					test=4;
				break;
			}
		} else if (test==1) {
			if (bsl==1)
				bsl=0;
			else if (c=='\\')
				bsl=1;
			else if (c=='\"')
				test=bsl=0;
		} else if (test==2) {
			if (bsl==1)
				bsl=0;
			else if (c=='\\')
				bsl=1;
			else if (c=='\'')
				test=bsl=0;
		} else if (test==3) {
			if (c=='\n')
				test=0;
		} else if (test==4) {
			if (c=='/'&&lc=='*')
				test=0;
		}
		lc=c;
	}
	for (; p>0; --p) {
		printf("unclosed bracket at line %d, column %d.\n",brn[p],brc[p]);
	}
	printf("Check completed!\n");
	return 0;
}
