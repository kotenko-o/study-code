#ifndef REPORT_UTIL_HPP
#define REPORT_UTIL_HPP

#include <string>
#include <cstdint>

/**
 * @brief Hilfsfunktion, um die Noten zu ablesen und falsche EIngaben zu bearbeiten
 * @param[out]      grade       grade, die abgekesen werden soll
 */
void readScore(std::uint_fast8_t &grade);

/**
 * @brief Die funktion dient dem Ablesen der Studienleistungen
 * @param[out]      name        String, containig a student Name
 * @param[out]      homework    homework grade
 * @param[out]      midterm     midterm grade
 * @param[out]      final_exam  final exam grade
 */
void readStudentData(std::string &name, std::uint_fast8_t &homework, std::uint_fast8_t &midterm, std::uint_fast8_t &finalExam);

/**
 * @brief Hilfsfunktion, um die Buchstabe-Note sowie Status zu bekommen
 * @param[in]       grade       die zu bewertende Note
 * @param[out]      letter      Variable mit der Buchstabe
 * @param[out]      status      Variable mit dem Status
 */
void getLetter(float &grade, std::string &letter, std::string &status);

/**
 * @brief Rechnet die finale Note aus
 * @param[in]       homework    Homework note
 * @param[in]       midterm     Midterm note
 * @param[in]       finalExam   finalExam note
 * @param[out]      finalGrade  Final Grade
 * @param[out]      letterGrade Grade as Letter
 * @param[out]      status      Status nicht/bestanden
 */
void calculateGrade(const std::uint_fast8_t &homework, const std::uint_fast8_t &midterm, const std::uint_fast8_t &finalExam, float &finalGrade, std::string &letterGrade, std::string &status);

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
                float &finalGrade, std::string &letter, std::string &status);

#endif