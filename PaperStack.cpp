#include "PaperStack.h"
#include <iostream>

PaperStack::PaperStack() {
	this->top = NULL;
	this->bottom = NULL;
	totalPapers = 0;
	papersToGrade = 0;
}

void PaperStack::addPaper(int amountOfPaper) {
	for (int i = 0; i < amountOfPaper; i++) {
		if (this->bottom == NULL) {
			bottom = new Paper();

			this->top = bottom;
			this->top->below = bottom;

			totalPapers++;
			papersToGrade++;
		}

		else {
			Paper* temp = this->top;

			this->top->above = new Paper();
			this->top = top->above;
			this->top->below = temp;

			totalPapers++;
			papersToGrade++;

			temp = NULL;
			delete temp;
		}
	}
}

void PaperStack::showPaperStack() {
	Paper* temp = this->top;
	std::string graded;
	int count = 0;

	while (temp != this->bottom) {
		graded = (temp->isGraded()) ? "Yes" : "No";
		std::cout << "Paper: " << totalPapers - count++ << " \tGrade: " << temp->grade << "\n";
		temp = temp->below;
	}

	graded = (temp->isGraded()) ? "Yes" : "No";
	std::cout << "Paper: " << totalPapers - count++ << " \tGrade: " << temp->grade << "\n";

	temp = NULL;
	delete temp;
}

void PaperStack::gradePaper(char _grade) {
	if (papersToGrade == 0) {
		std::cout << "All papers have been graded.\n";

		return;
	}

	else if (this->top->isValidGrade(_grade)) {
		this->top->grade = _grade;

		papersToGrade--;

		Paper* temp = this->top->below;

		temp->above = NULL;
		this->top->above = this->bottom;
		this->bottom->below = this->top;
		this->bottom = this->top;
		this->top = temp;

		return;
	}

	else {
		std::cout << "Please enter a valid grade.\n";

		return;
	}
}

void PaperStack::tossPaper() {
	if (totalPapers == 0) {
		std::cout << "There are no papers in the stack.\n";

		return;
	}

	else {
		Paper* temp = this->top;

		this->top = this->top->below;

		delete temp;
	}
}

PaperStack::~PaperStack() {
	Paper* temp;

	while (this->top != NULL) {
		temp = this->bottom;
		this->bottom = this->bottom->above;

		delete temp;
	}
}