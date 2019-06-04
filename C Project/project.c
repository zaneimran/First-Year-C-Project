/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY:  << place your name and ID number here >> */

#include "project.h"

#define MAX_ARRAY_SIZE 1000
/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */


void chooseDirection(int startRow, int endRow, int startCol, int endCol, int *hor, int *vert) {

	if (startRow < endRow) { //Down
		if (startCol < endCol) { // Right
			*hor = 1;
			*vert = 1;
		}
		else if (startCol > endCol) { //Left
			*hor = -1;
			*vert = 1;
		}
		else if (startCol == endCol) { // Down
			*hor = 0;
			*vert = 1;
		}
	}
	else if (startRow > endRow) { // Up
		if (startCol < endCol) { // Right
			*hor = 1;
			*vert = -1;
		}
		else if (startCol > endCol) { //Left
			*hor = -1;
			*vert = -1;
		}
		else if (startCol == endCol) { // Up
			*hor = 0;
			*vert = -1;
		}
	}
}


/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/* Your comment goes here*/
int DivisorOfThree(int a, int b, int c)
{
	int max, i;
	int GCD = 0;

	if(a>b && a>c){
		max = a;
	}
	else if(b>a && b>c){
		max = b;
	}
	else{
		max = c;
	}
	
	if(a<=0 || b<=0 || c<=0){
		return -1;
	}

	for(i=1;i<max; i++){
		if (a%i == 0 && b%i==0 && c%i == 0){
			GCD = i;
		}
	}

	return GCD; 	
}

/* Your comment goes here*/
double AverageSheep(int *counts)
{
	double sum = 0.0;
	double i = 0.0;
	double average = 0.0;
	int pos = 0;
	
	while (counts[pos] != 9999) {
		if (counts[pos] != -1) {
			sum = counts[pos] + sum;
			i++;
			pos++;
		}
		else {
			pos++;
		}
	}
	average = sum / i;
	return average;
}

/* Your comment goes here*/
void Emphasise(char* word)
{
	int i, j, size;
	int start;
	int end = 0;
	int k = 0;
	int first = 0;
	char character;
	size = strlen(word);

	// Cycle through every single element in array
	for (i = 0; i < size; i++) {
		if (word[i] == '_' && first == 0) {
			start = i;
			first = 1;
		}
		if (word[i] == '_' && first == 1) {
			end = i;
		}
	}
	for (j = start+1; j < end; j++) {
		if ('a'<=word[j] && word[j]<'z') {
			character = word[j];
			character = character - ('a'-'A');
			word[j] = character;
		}
		else {
			word[j] = word[j];
		}
	}

	for (i = end; i < size; i++) {
		word[i] = word[i+1];
	}

	for (i = start; i < size; i++) {
		word[i] = word[i + 1];
	}

}

/* Your comment goes here*/
int PrimeFactors(int n, int *factors)
{
	int i = 2;
	int pos = 0;

	while (n != 1) {
		if (n%i == 0) {
			while (n%i == 0) {
				factors[pos] = i;
				n = n / i;
				pos++;
			}
		}
		i++;
	}
	
	return pos;
}

/* Your comment goes here*/
void ConnectTwo(int maze[10][10])
{
	int i, j;
	int startC, startR;
	int init, step;
	int hor = 0;
	int vert = 0;
	int startRow, startCol, endRow, endCol;
	// Get start and end positions
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (maze[i][j] == 1) {
				startRow = i;
				startCol = j;
			}
			if (maze[i][j] == 2) {
				endRow = i;
				endCol = j;
			}
		}
	}

	chooseDirection(startRow, endRow, startCol, endCol, &hor, &vert);

	i = startRow;
	j = startCol;

	while (i != endRow && j != endCol) { //Diagonal 

		if (i != startRow && j != startCol) {
			maze[i][j] = 3;
		}
		i = i + vert;
		j = j + hor;
	}

	if ((startRow != endRow) && (startCol != endCol)) {
		startC = j;
		startR = i;
	}
	else {
		startC = startCol;
		startR = startRow;
	}

	if ((startR == endRow) && (startC < endCol)) { // Horizontal Right
		for (i = startC+1; i < endCol; i++) {
			maze[startR][i] = 3;
		}
	}
	else if ((startR == endRow) && (startC > endCol)) { // Horizontal Left
		for (i = startC-1; i > endCol; i--) {
			maze[startR][i] = 3;
		}
	}
	else if ((startC == endCol) && (startR < endRow)) { // Vertical Down
		for (i = startR; i < endRow; i++) {
			maze[i][startC] = 3;
		}
	}
	else if ((startC == endCol) && (startR > endRow)) { // Vertical Up
		for (i = startR; i > endRow; i--) {
			maze[i][startC] = 3;
		}
	}
	
		
	/*
	printf("\n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
	*/
	//maze[0][0] = 99999;
}

/* Your comment goes here*/
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex)
{
	int i;
	int j = 0;
	int loop = 1;
	int run = 0;
	int maxRun = 0;

	for (i = 0; i < numPrices; i++) {
		loop = 1;
		run = 0;
		j = i;
		while (loop==1) {
			if (prices[j] < prices[j+1]) {
				run++;
				if (run > maxRun) {
					maxRun = run;
					*bestRun = maxRun;
					*bestRunIndex = i;
				}
			}
			else {
				loop = 0;
			}
			j++;
		}
	}

}

/* Your comment goes here*/
void Compress(int *input, int *output)
{
	int val = 0;
	int pos = 0;
	int run = 1;
	int i = 0;

	while (input[pos] != -1) {
		
		val = input[pos];
		if (input[pos] == input[pos + 1]) {
			run++;
		}
		else {
			output[i] = run;
			output[i + 1] = val;
			run = 1;
			i = i + 2;
		}		
		pos++;
	}

	output[i] = -1;

//	output[0] = 99999 + input[0];
}

/* Your comment goes here*/
void AddOne(char *input, char *output)
{

	int length = strlen(input);
	int changePos;
	int a = 0;
	changePos = length - 1;

	input[changePos]++;


	while (input[changePos] == ':') {
		if (changePos == 0) {
			input[0] = '1';
			input[1] = '0';
			a = 1;
		}
		else {
			input[changePos] = '0';
			changePos--;
			input[changePos]++;
			if (input[0] == ':') {
				input[0] = '1';
				input[length] = '0';
				a = 1;
			}
		}
	}

	input[length + a] = '\0';

	strcpy(output, input);
}
	
	
	//input[0] = '1';
	//output[0] = '~';


/* Your comment goes here*/
void Histogram(char *result, int *values, int numValues)
{
	int i, j;
	int k;
	int max = values[0];
	int n;
	int size;
	char var;

	k = 0;

	for (i = 1; i < numValues; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}

	n = max;

	//printf("\n");
	int pos;
	pos = 0;

	for (i = 0; i < max + 2; i++) {
		for (j = 0; j < numValues + 2; j++) {
			if ((i == 0) || (i == (max + 1)) || (j == 0) || (j == (numValues + 1))) {
				result[k] = '*';
			}
			else {
				if (values[pos] > n) {
					result[k] = 'X';
					values[pos]--;
				}
				else {
					result[k] = ' ';
				}
				pos++;
			}
			k++;
		}

		pos = 0;
		result[k] = '\n';
		k++;
		n--;
	}

	result[k-1] = '\0';

	//printf("%s", result);

	//result[0] = (char)('~' + numValues + values[0]);
}

/* Your comment goes here*/
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus)
{
	int i, j;
	int count = 0;
	int pure = 0;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (map[i][j] == 9) {
				count++;
			}
			if (i != 0 && j != 0 && i != rows && j != cols){
				if (map[i-1][j] == 9 && map[i+1][j] == 9 && map[i][j-1] == 9 && map[i][j+1] == 9 && map[i+1][j + 1] == 9 && map[i-1][j - 1] == 9 && map[i-1][j + 1] == 9 && map[i+1][j - 1] == 9){
					pure++;
				}
			}
		}
	}
	results[0] = count;
	results[1] = pure;

	//results[0] = 99993 + rows + cols + map[0][0] + bonus;
}

