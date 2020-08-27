#pragma once
#include <string.h>


class PaperStack {
private:
	struct Paper {
		char grade;
		char validGrades[5] = { 'A', 'B', 'C', 'D', 'F' };
		int studentID;
		Paper* above;
		Paper* below;

		Paper() { 
			grade = '\0'; 
			studentID = -1; 
			above = NULL;
			below = NULL;
		}

		Paper(char _grade, int _studentID) {
			this->grade = _grade;
			this->studentID = _studentID;
			above = NULL;
			below = NULL;
		}

		bool isGraded() {
			if (this->grade != '\0') {
				return true;
			}

			return false;
		}

		bool isValidGrade(char grade) {
			for (int i = 0; i < strlen(validGrades); i++) {
				if (grade == validGrades[i]) {
					return true;
				}
			}

			return false;
		}
	};

	Paper* top;
	Paper* bottom;
	int totalPapers;
	int papersToGrade;

public:
	PaperStack();
	void addPaper(int amountOfPaper);
	void showPaperStack();
	void gradePaper(char _grade);
	void tossPaper();
	~PaperStack();
};