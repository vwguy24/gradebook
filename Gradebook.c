#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LENGTH 10
FILE *ifp;
int assigns, stus;
double final_grades[5];
int grades[20][20];
char students[5][NAME_LENGTH];
void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus], char students[stus][NAME_LENGTH]);
void printGrades(int assigns, int stus, int grades[assigns][stus], FILE *ofp);
void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH]);
void printStudents(int stus, char students[stus][NAME_LENGTH], FILE *ofp);
void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[stus]);
void printFinalLetterGrades(int stus, double final_grades[], FILE *ofp);
void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[stus], FILE *ofp);

int main(int argc, char *argv[])
{
    FILE *ofp = fopen("output.txt", "w");
    getGrades(ifp, assigns, stus, grades, students);
    printStudents(stus, students, ofp);
    printGrades(assigns, stus, grades, ofp);
    calcGrades(assigns, stus, grades, &final_grades);
    printFinalLetterGrades(stus, final_grades, ofp);
    printPercentageGrades(stus, students, &final_grades, ofp);
    fclose(ifp);
    fclose(ofp);

	return 0;
}

void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus], char students[stus][NAME_LENGTH])
{
    printf("What file should I open?");
    char file[30];
    char name[10];
    scanf("%s", file);
    ifp = fopen(file, "r");
    fscanf(ifp, "%d ", &assigns);
    fscanf(ifp, "%d ", &stus);
    for (int i = 0; i < stus; i++){
        fscanf(ifp, "%s", name);
        strcpy(students[i], name);
    }
    for(int i = 0; i < stus; i++){
        for(int j = 0; j < assigns; j++){
            fscanf(ifp, "%d ", &grades[j][i]);
        }
    }
}

void printGrades(int assigns, int stus, int grades[assigns][stus], FILE *ofp)
{
    for(int i = 0; i < assigns; i++){
        for(int j = 0; j < stus; j++){
            fprintf(ofp, "%-20d", grades[i][j]);
        }
        fprintf(ofp, "\n");
    }
}

void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH])
{

}

void printStudents(int stus, char students[stus][NAME_LENGTH], FILE *ofp)
{
    for(int i = 0; i < stus; i++){
        fprintf(ofp, "%20s", students[i]);
    }
    fprintf(ofp, "\n");
}

void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[stus])
{
    for(int i = 0; i < stus; i++){
        int total = 0;
        for(int j = 0; j < assigns; j++){
            total = total + grades[j][i];
        }
        final_grades[i] = total / assigns;
    }
}

void printFinalLetterGrades(int stus, double final_grades[stus], FILE *ofp)
{
    for(int i = 0; i < stus; i++){
        char letter;
        if(final_grades[i] >= 90){
            letter = 'A';
        }
        else if(final_grades[i] >=80){
            letter = 'B';
        }
        else if(final_grades[i] >= 70){
            letter = 'C';
        }
        else if(final_grades[i] >= 60){
            letter = 'D';
        }
        else{
            letter = 'F';
        }
        fprintf(ofp, "%20c", letter);
    }
}

void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[], FILE *ofp)
{
    for(int i = 0; i < stus; i++){
        fprintf(ofp, "%s: %f\n", students[i], final_grades[i]);
    }
}
