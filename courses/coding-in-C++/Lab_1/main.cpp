#include "report_util.hpp"

int main() {
    std::string studentName;
    std::uint_fast8_t homework;
    std::uint_fast8_t midterm;
    std::uint_fast8_t finalExam;

    float finalGrade;
    std::string letterGrade;
    std::string status;

    readStudentData(studentName, homework, midterm, finalExam);
    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade, status);
    printReport(studentName, homework, midterm, finalExam, finalGrade, letterGrade, status);
    return 0;
}
