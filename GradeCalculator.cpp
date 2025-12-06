#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>

void calculateGrade(double average);
int main(){
    bool replay = true; //replay control
    while(replay){
    char replayInput; //replay input
    std::string scoresInput; //scores string input
    std::string vectorSizeInput; //vector size string input
    int vectorSize; //size of vectors
    std::string subjectName; //subject name input
    std::vector <std::string> subjects; //vector to hold subject names
    std::vector <double> scores; //vector to hold scores
    bool vectorRunning = true; //vector size input control
    double total = 0.0;
    double average = 0.0;
    std::cout << "Welcome to the Grade Calculator!" << std::endl;
    std::cout << "How many subjects do you have?: ";
    while(vectorRunning){
    std::cin >> vectorSizeInput;
    try {
        vectorSize = std::stoi(vectorSizeInput);
        if (vectorSize <= 0) {
            throw std::out_of_range("Number of subjects must be positive.");
        }
        vectorRunning = false;
    } catch (const std::invalid_argument&) {
        std::cout << "Invalid input. Please enter a numeric value." << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "Invalid number of subjects. Please enter a positive integer." << std::endl;
    }
    }
    for(int i = 0; i < vectorSize; i++){
        std::cout << "Enter the name of subject " << (i + 1) << ": ";
        std::getline(std::cin >> std::ws, subjectName);
        subjects.push_back(subjectName);
    }    
    std::cout << "Please enter the scores for the following subjects:" << std::endl;
    for(int i = 0; i < vectorSize; i++){
        bool running = true;
        std::cout << subjects[i] << ": ";
        while(running){
        std::cin >> scoresInput;
        try {
            double score = std::stod(scoresInput);
            if (score < 0 || score > 100) {
                throw std::out_of_range("Score must be between 0 and 100.");
            }
            scores.push_back(score);
            total += scores[i];
            running = false;
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a numeric value." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Invalid score. Please enter a score between 0 and 100." << std::endl;
        }
        }
    }
    average = total / vectorSize;
    std::cout << "Total Score: " << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << "Average Score: " << std::fixed << std::setprecision(2) << average << std::endl;
    calculateGrade(average);
    std::cout << "Would you like to calculate again? (Y/N): ";
    std::cin >> replayInput;
    if(replayInput == 'N' || replayInput == 'n'){
        replay = false;
    } else if(replayInput == 'Y' || replayInput == 'y'){
        replay = true;
    } else{
        std::cout << "Invalid input. Exiting the program." << std::endl;
        replay = false;
    }
    std::cout << "Thank you for using the Grade Calculator!" << std::endl;
    }
    return 0;
}
void calculateGrade(double average) {
    char grade;
    if (average >= 90) {
        grade = 'A';
    } else if (average >= 80) {
        grade = 'B';
    } else if (average >= 60) {
        grade = 'C';
    } else if (average >= 40) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    std::cout << "Your Grade: " << grade << std::endl;
}