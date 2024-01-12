#ifndef REPORT_H
#define REPORT_H

void writeReport(const char* name, const char* paymentType, double totalBillPaid);
void readReport();
void readReportByAmount();
void readReportByName();

#endif