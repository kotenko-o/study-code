#include <string>
#include <iostream>
#include <limits>
#include <cstdint>
#include <iomanip>

constexpr int MIN_GRADE = 0;
constexpr int MAX_GRADE = 100;

constexpr float MIN_A = 90.0;
constexpr float MIN_B = 80.0;
constexpr float MIN_C = 70.0;
constexpr float MIN_D = 60.0;
constexpr float MIN_E = 50.0;

constexpr float W_HOMEWORK = 0.40;
constexpr float W_MIDTERM = 0.25;
constexpr float W_FINALEXAM = 0.35;

/**
 * @brief Hilfsfunktion, um die Noten zu ablesen und falsche EIngaben zu bearbeiten
 * @param[out]      grade       grade, die abgekesen werden soll
 */
void readScore(std::uint_fast8_t &grade) {
    int readValue;
    while (true) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!(std::cin >> readValue)) {
            std::cout << "Es muss eine Ganzzahl sein. Versuchen Sie nochmals: ";
            continue;
        }
        if (readValue > MAX_GRADE || readValue < MIN_GRADE) {
            std::cout << "Von Ihnen eingegebene Note liegt ausser bereich [0, 100]. Versuchen Sie nochmals: ";
            continue;
        }
        break;
    }
    grade = static_cast<uint_fast8_t>(readValue);
}

/**
 * @brief Die funktion dient dem Ablesen der Studienleistungen
 * @param[out]      name        String, containig a student Name
 * @param[out]      homework    homework grade
 * @param[out]      midterm     midterm grade
 * @param[out]      final_exam  final exam grade
 */
void readStudentData(std::string &name, std::uint_fast8_t &homework, std::uint_fast8_t &midterm, std::uint_fast8_t &finalExam) {
    std::cout << "Geben Sie Ihre Namen ein: ";
    std::cin >> name;
    std::cout << "Geben Sie Ihre Homework-Note ein [0, 100]: ";
    readScore(homework);
    std::cout << "Geben Sie Ihre Midterm-Note ein [0, 100]: ";
    readScore(midterm);
    std::cout << "Geben Sie Ihre Final-Exam-Note ein [0, 100]: ";
    readScore(finalExam);
}

/**
 * @brief Hilfsfunktion, um die Buchstabe-Note sowie Status zu bekommen
 * @param[in]       grade       die zu bewertende Note
 * @param[out]      letter      Variable mit der Buchstabe
 * @param[out]      status      Variable mit dem Status
 */
void getLetter(float &grade, std::string &letter, std::string &status) {
    if (grade >= MIN_A) {
        letter = "A";
        status = "Pass";
        return;
    }
    if (grade >= MIN_B) {
        letter = "B";
        status = "Pass";
        return;
    }
    if (grade >= MIN_C) {
        letter = "C";
        status = "Pass";
        return;
    }
    if (grade >= MIN_D) {
        letter = "D";
        status = "Conditional pass";
        return;
    } 
    if (grade >= MIN_E) {
        letter = "E";
        status = "Conditional pass";
        return;
    }
    letter = "F";
    status = "Fail";
    return;
}

/**
 * @brief Rechnet die finale Note aus
 * @param[in]       homework    Homework note
 * @param[in]       midterm     Midterm note
 * @param[in]       finalExam   finalExam note
 * @param[out]      finalGrade  Final Grade
 * @param[out]      letterGrade Grade as Letter
 * @param[out]      status      Status nicht/bestanden
 */
void calculateGrade(const std::uint_fast8_t &homework, const std::uint_fast8_t &midterm, const std::uint_fast8_t &finalExam, float &finalGrade, std::string &letterGrade, std::string &status) {
    if (W_HOMEWORK + W_MIDTERM + W_FINALEXAM != 1.0) {
        std::cout << "[WARNING] Weighst are not set correctly." << std::endl;
    }
    finalGrade = homework * W_HOMEWORK + midterm * W_MIDTERM + finalExam * W_FINALEXAM;
    getLetter(finalGrade, letterGrade, status);
}

/**
 * @brief Fuktion um ein Notenbericht zu ausgeben
 * @param[in]   name        Name des Studenten
 * @param[in]   homework    Homework-Note
 * @param[in]   midterm     Midterm-Note
 * @param[in]   finalExam   Final Exam Note
 * @param[in]   fianlGrade  Finale Note
 * @param[in]   letter      Note als Buchstabe
 * @param[in]   status      Status
 */
void printReport(std::string &name, std::uint_fast8_t &homework, std::uint_fast8_t &midterm, std::uint_fast8_t &finalexam,
                float &finalGrade, std::string &letter, std::string &status) {
    std::cout << "-------------------------------------\nStudent Report\n-------------------------------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "\nScores\n-------------------------------------" << std::endl;
    std::cout << std::fixed;
    std::cout << std::left << std::setw(15) << "Homework" << ": " << std::setprecision(2) << static_cast<float>(homework) <<std::endl;
    std::cout << std::left << std::setw(15) << "Midterm" << ": " << std::setprecision(2) << static_cast<float>(midterm) <<std::endl;
    std::cout << std::left << std::setw(15) << "Final Exam" << ": " << std::setprecision(2) << static_cast<float>(finalexam) << "\n" <<std::endl;
    std::cout << std::left << std::setw(15) << "Final Grade" << ": " << std::setprecision(2) << finalGrade << std::endl;
    std::cout << std::left << std::setw(15) << "Letter Grade" << ": " << letter <<std::endl;
    std::cout << std::left << std::setw(15) << "Status" << ": " << status << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

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