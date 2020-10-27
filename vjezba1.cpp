#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char ime[20];
	char prezime[20];
	int bodovi;


}Student; 

int brojredaka(char *imeFilea){
	char m[50];
	int n=0; 
	FILE *fp = NULL;
	fp = fopen(imeFilea, "r");

	while( !feof(fp)){
		if(fgets(m, 50, fp))
			n++;
	
	
	} 

	fclose(fp); 
	return n; 

}

int citaj(char *imeFilea, int n, Student *stud){
	int i;
	FILE *fp = fopen(imeFilea, "r");

	for(i=0; i<n; i++){
		fscanf(fp, "%s %s %d", stud[i].ime, stud[i].prezime, &stud[i].bodovi);
	
	}
	fclose(fp); 

	
}

int ispisi(int n, Student *stud, int max){
	int i; 
	for ( i=0; i<n; i++){
		printf("%s %s %d r=%.2f posto\n", stud[i].ime, stud[i].prezime, stud[i].bodovi, stud[i].bodovi / (float)max * 100);
	
	}

	
}

int main(){
	int max; 
	int n; 
	Student *niz = NULL; 

	printf("Unesi max broj bodova");
	scanf("%d", &max); 
	n = brojredaka("Studenti.txt");
	niz = (Student*)malloc(n * sizeof(Student));

	printf("Broj studenata je: %d\n", n);

	citaj("Studenti.txt",n, niz);
	
	ispisi(n, niz, max);

	




return 0; 
}