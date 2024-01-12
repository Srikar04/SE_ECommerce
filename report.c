#include <stdio.h>

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
