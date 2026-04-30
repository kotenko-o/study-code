#include <string>
#include <iostream>
#include <limits>

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
void readScore(int &grade) {
    if (!(std::cin >> grade)) {
        std::cout << "Es muss eine Ganzzahl sein. Versuchen Sie nochmals: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        readScore(grade);
        return;
    } else if (grade > MAX_GRADE || grade < MIN_GRADE) {
        std::cout << "Von Ihnen eingegebene Note liegt ausser bereich [0, 100]. Versuchen Sie nochmals: ";
        readScore(grade);
        return;
    }
}

/**
 * @brief Die funktion dient dem Ablesen der Studienleistungen
 * @param[out]      name        String, containig a student Name
 * @param[out]      homework    homework grade
 * @param[out]      midterm     midterm grade
 * @param[out]      final_exam  final exam grade
 */
void readStudentData(std::string &name, int &homework, int &midterm, int &finalExam) {
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
 * @brief Hilfsfunktion, um die Buchstabe-Note zu bekommen
 * @param[in]       grade       die zu bewertende Note
 * @return          string      Entsprechende Buchstabe
 */
std::string getLetter(float &grade) {
    if (grade >= MIN_A) {
        return "A";
    }
    if (grade >= MIN_B) {
        return "B";
    }
    if (grade >= MIN_C) {
        return "C";
    }
    if (grade >= MIN_D) {
        return "D";
    } 
    if (grade >= MIN_E) {
        return "E";
    }
    return "F";
}

/**
 * @brief Rechnet die finale Note aus
 * @param[in]       homework    Homework note
 * @param[in]       midterm     Midterm note
 * @param[in]       finalExam   finalExam note
 * @param[out]      finalGrade  Final Grade
 * @param[out]      letterGrade Grade as Letter
 */
void calculateGrade(int &homework, int &midterm, int &finalExam, int &finalGrade, std::string &letterGrade) {

}

int main() {
    std::string studentName;
    int homework;
    int midterm;
    int finalExam;

    float finalGrade;
    std::string letterGrade;

    readStudentData(studentName, homework, midterm, finalExam);
    return 0;
}