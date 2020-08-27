#include <iostream>
#include "PaperStack.h"

int main() {
	PaperStack myPapers;

	myPapers.addPaper(10);
	myPapers.showPaperStack();
	myPapers.gradePaper('A');
	myPapers.gradePaper('B');
	myPapers.gradePaper('C');
	myPapers.gradePaper('D');
	myPapers.gradePaper('F');
	myPapers.gradePaper('A');
	myPapers.gradePaper('B');
	myPapers.gradePaper('C');
	myPapers.gradePaper('D');
	myPapers.gradePaper('F');

	std::cout << "\n";

	myPapers.showPaperStack();

	std::cin.ignore();
	return 0;
}