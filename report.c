/**
 * Filename: report.c
 * Author: Srikar
 * Date Created: 12-01-2024
 * Last Modified: 12-01-2024
 *
 * Description:
 * This is the file containing the report related functions such as 
 * writing to report, reading from report with custom conditions and so on.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void writeReport(const char* name, const char* paymentType, double totalBillPaid) {
    char* filename = "report.csv";
    FILE* file = fopen(filename, "a"); // Open the file in append mode

    if (file != NULL) {
        fprintf(file, "%s,%s,%.2f\n", name, paymentType, totalBillPaid);
        fclose(file);
        printf("Data written to report.csv successfully.\n");
    } else {
        printf("Failed to open report.csv for writing.\n");
    }
}

void readReport(){
    char* filename = "report.csv";
    FILE* file = fopen(filename, "r"); // Open the file in read mode

    char line[100];
    printf("Name\tPayment Type\tTotal Bill Paid\n");
    while(fgets(line, sizeof(line), file)){
        if(strlen(line) == 0){
            printf("Report is empty.\n");
            break;
        }
        char* token = strtok(line, ",");
        while(token != NULL){
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(file);
}

void readReportByName(char* name){
    char* filename = "report.csv";
    FILE* file = fopen(filename, "r"); // Open the file in read mode

    char line[100];
    printf("Name\tPayment Type\tTotal Bill Paid\n");
    while(fgets(line, sizeof(line), file)){
        if(strlen(line) == 0){
            printf("Report is empty.\n");
            break;
        }
        char* token = strtok(line, ",");
        if(strcmp(token,name) == 0){
            while(token != NULL){
                printf("%s\t", token);
                token = strtok(NULL, ",");
            }
        }
        printf("\n");
    }
    fclose(file);
}

void readReportByAmount(double amount){
     char* filename = "report.csv";
    FILE* file = fopen(filename, "r"); // Open the file in read mode

    char line[100];
    printf("Name\tPayment Type\tTotal Bill Paid\n");
    while(fgets(line, sizeof(line), file)){
        if(strlen(line) == 0){
            printf("Report is empty.\n");
            break;
        }
        char* line_copy = strdup(line);
        char* token;
        int count = 0;
        while((token = strtok(count == 0 ? line : NULL,",")) !=NULL && ++count < 3);
        double num = atoi(token);
        if(num >= amount){
            char* token1 = strtok(line_copy,","); // Tokenize the copy of the line
            while(token1 != NULL){
                printf("%s\t", token1);
                token1 = strtok(NULL, ",");
            }
            printf("\n");
        }
    }
    fclose(file);
}