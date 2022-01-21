#include<stdio.h>
#include<string.h>

#define SIZE1 855
#define SIZE2 710

int main() {
	
	FILE* ffollowers, * ffollowing,*notF;
	char follower[SIZE1][30], following[SIZE2][30];
	int control[SIZE2] = { 0 };
	int i=0,j=0,k=0,b=0;

	ffollowers = fopen("followers.txt", "r");
	ffollowing= fopen("following.txt", "r");
	notF = fopen("notfollowing.txt", "w");

	if (ffollowers == NULL || ffollowing == NULL || notF == NULL) {
		printf("files couldnt be opened");
		return 1;
	}

	while (!feof(ffollowers)) {
		while (i < SIZE1) {
			fscanf(ffollowers, "%s",follower[i] );
			i++;
		}
	}
	i = 0;
	while (!feof(ffollowing)) {
		while (i < SIZE2) {
			fscanf(ffollowing,"%s",following[i] );
			i++;
		}
	}
	fclose(ffollowers);
	fclose(ffollowing);
	ffollowers = fopen("followers.txt", "r");
	ffollowing = fopen("following.txt", "r");

	for (j = 0;j < SIZE2;j++) {
		for (k = 0;k < SIZE1;k++) {
			if (strcmp(following[j], follower[k]) == 0){
				control[j]++;
				b++;
			}
		}
		if (control[j] == 0) {
			fprintf(notF, "\n%s\n", following[j]);
		}
	}
	
	fclose(ffollowers);
	fclose(ffollowing);
	fclose(notF);
	
	return 0;
}