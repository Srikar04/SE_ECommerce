/**
 * Filename: report.h
 * Author: Srikar
 * Date Created: 12-01-2024
 * Last Modified: 12-01-2024
 *
 * Description:
 * This is the header file for the report module.
 * It contains all its function declarations and structure definitions
 */
#ifndef REPORT_H
#define REPORT_H

void writeReport(const char* name, const char* paymentType, double totalBillPaid);
void readReport();
void readReportByAmount();
void readReportByName();

#endif