#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
int main()
{
	char sir[256]="I went to the library yesterday";
	char mat[255][256];
	int i=0, j, n;
	//scanf("%s",sir);
	char* p;
	p = strtok(sir, " .");
	while (p!=NULL)
	{
		strcpy(mat[i++], p);
		p = strtok(NULL, " .");
	}
	n = i-1;
	for(i=0;i<n;i++)
		for (j = i + 1; j <= n; j++)
			if ((strlen(mat[j]) > strlen(mat[i])) || (strlen(mat[j]) == strlen(mat[i]) && strcmp(mat[j], mat[i]) < 0))
			{
				char aux[256];
				strcpy(aux, mat[i]);
				strcpy(mat[i], mat[j]);
				strcpy(mat[j], aux);
			}
	for(i=0;i<=n;i++)
		printf("%s \n",mat[i]);
	return 0;
}