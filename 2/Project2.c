#include<stdio.h>
#include<stdlib.h>

int r, c, status;   //Row, column and status variables.
int i, j;           //Loop variables.
double x, y;     //Interval variables.

void getDimensions() {
		
		do { 
		printf("Enter the row dimension(max: 100): ");
		status=scanf("%d", &r);
		if(status<1) {
		fflush(stdin);
		continue;
	}
	}while(r<1||r>100||status!=1);
	
	do { 
		printf("Enter the column dimension(max: 100): ");
		status=scanf("%d", &c);
		if(status<1) {
		fflush(stdin);
		continue;
	}
	}while(c<1||c>100||status!=1);
	
	
}

void getInterval() {
		
		printf("\n**Enter the interval that you want to clean;\n\nInterval: X < Numbers_Will_Be_Cleaned < Y;\n");
	do { 
		printf("*Clean between(Smallest number in the interval( X )): ");
		status=scanf("%lf", &x);
		if(status<1) {
		fflush(stdin);
		continue;
	}
	}while(status!=1);
	
	do { 
		printf("*Clean between(Greatest number in the interval( Y )): ");
		status=scanf("%lf", &y);
		if(status<1) {
		fflush(stdin);
		continue;
	}
	}while(status!=1);
}

void readFile() {
	
	double matrix[100][100];
	
	FILE *fp=fopen("matrix.txt","r");
	
	if(fp==NULL) printf("Error: File not found.");
	
	else {
		//Get the matrix size entered.
		
		status=fscanf(fp, "%d %d", &r, &c);
		if(status<2) printf("===============ERROR: WRONG MATRIX ARRANGEMENT.===============\nThe format should be like this to read from the file;\n=====\n2 2         //Row and column sizes entered.\n\n1.0 2.0     //\n3.0 4.0     //Elements of matrix.\n=====\n");
		
		//Fill the matrix.
			
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				status=fscanf(fp, "%lf", &matrix[i][j]);
				if(status<1) {
					printf("===============ERROR: WRONG MATRIX ARRANGEMENT.===============\nThe format should be like this to read from the file;\n=====\n2 2         //Row and column sizes entered.\n\n1.0 2.0     //\n3.0 4.0     //Elements of matrix.\n=====\n");
				}
		}
		j=0;
	}
	}
	
	//Display the matrix.
	
	printf("\nDetected matrix sizes: [%d][%d]\n\n-----Filled Matrix-----\n", r, c);
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			printf("%.2f  ", matrix[i][j]);
		}
		printf("\n");
		j=0;
	}	
	
	fclose(fp);
	
    //Calculate column and row sum vectors by using dynamic memory allocation.
	
	double *colSum=(double *)malloc(sizeof(double)*c);
	double *rowSum=(double *)malloc(sizeof(double)*r);
	double sum=0;
	
	//Calculate column sum vector.
	
	for(j=0;j<c;j++) {
		for(i=0;i<r;i++) {
			sum=sum+matrix[i][j];
		}
		colSum[j]=sum;
		sum=0;
		i=0;
	}
	
	//Calculate row sum vector.
	
	sum=0;
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			sum=sum+matrix[i][j];
		}
		rowSum[i]=sum;
		sum=0;
		j=0;
	}
	
	//Display column and row sum vectors.
	
	printf("\n-----Column Sum Vector-----\n");
	for(i=0;i<c;i++) {
		printf("%.2f  ", colSum[i]);
	}
	
	printf("\n\n-----Row Sum Vector-----\n");
	for(j=0;j<r;j++) {
		printf("%.2f\n", rowSum[j]);
	}
	
	//Get the interval that will be cleaned.
	
	getInterval();
	
	//Clean the matrix data inside the interval.
	
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			if(matrix[i][j]>x&&matrix[i][j]<y) matrix[i][j]=0;
		}
		j=0;
	}
	
	//Display the matrix.
	
	printf("\n-----Filled Matrix-----\n");
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			printf("%.2f  ", matrix[i][j]);
		}
		printf("\n");
		j=0;
	}	
	}

int main() {
	int mode;
		
	//Selecting the mode.
	
	do {
	printf("Press 1 to read \"matrix.txt\" or 2 to create a new matrix: ");
	status=scanf("%d", &mode);
	if(status<1) {
		fflush(stdin);
		continue;
	}
}while(mode>2||mode<0||status!=1);
	
	//If the reading mode is chosen.
	
	if(mode==1) readFile();
	
	//If the creating mode is chosen.
	
	else {
	
	//Create a 100x100 static matrix.
	
	double matrix[100][100];
	
	//Get the matrix dimensions that will be created.
	
	getDimensions();
	
	//Fill the matrix.
	
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			do { 
				printf("Enter [%d][%d]: ", i+1, j+1);
				status=scanf("%lf", &matrix[i][j]);
				if(status<1) {
				fflush(stdin);
				continue;
				}
			}while(status!=1);
			}
		j=0;
	}
	
	//Display the matrix.
	
	printf("\n-----Filled Matrix-----\n");
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			printf("%.2f  ", matrix[i][j]);
		}
		printf("\n");
		j=0;
	}	
	
	//Calculate column and row sum vectors by using dynamic memory allocation.
	
	double *colSum=(double *)malloc(sizeof(double)*c);
	double *rowSum=(double *)malloc(sizeof(double)*r);
	double sum=0;
	
	//Calculate column sum vector.
	
	for(j=0;j<c;j++) {
		for(i=0;i<r;i++) {
			sum=sum+matrix[i][j];
		}
		colSum[j]=sum;
		sum=0;
		i=0;
	}
	
	//Calculate row sum vector.
	
	sum=0;
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			sum=sum+matrix[i][j];
		}
		rowSum[i]=sum;
		sum=0;
		j=0;
	}
	
	//Display column and row sum vectors.
	
	printf("\n-----Column Sum Vector-----\n");
	for(i=0;i<c;i++) {
		printf("%.2f  ", colSum[i]);
	}
	
	printf("\n\n-----Row Sum Vector-----\n");
	for(j=0;j<r;j++) {
		printf("%.2f\n", rowSum[j]);
	}
	
	//Get the interval that will be cleaned.
	
	getInterval();
	
	//Clean the matrix data inside the interval.
	
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			if(matrix[i][j]>x&&matrix[i][j]<y) matrix[i][j]=0;
		}
		j=0;
	}
	
	//Display the matrix.
	
	printf("\n-----Filled Matrix-----\n");
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			printf("%.2f  ", matrix[i][j]);
		}
		printf("\n");
		j=0;
	}	
}

	system("PAUSE");
	return 0;
}
