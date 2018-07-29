#include <iostream>
#include <iomanip>

using namespace std;

class GradeCalculator {
public:
	void input();
	bool testQuiz(double quizScore);
	bool testExam(double examScore);
	void calculateGrade();
	void findGrade();
	void output();
private:
	double quiz1, quiz2, midterm, finalExam, finalPercent;
	char grade;
};

int main()
{
	GradeCalculator student;

	student.input();
	student.calculateGrade();
	student.findGrade();
	student.output();

	cin.get();
	//cin.get(); // I added these two to make the executable pause before closing when I compile at home

	return 0;
}

void GradeCalculator::input()
{
	do
	{
		cout << endl << "Please enter the student's score for Quiz 1 (1-10):" << endl;
		cin >> quiz1;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (!testQuiz(quiz1));

	quiz1 = quiz1 * 10;

	do
	{
		cout << endl << "Please enter the student's score for Quiz 2 (1-10):" << endl;
		cin >> quiz2;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (!testQuiz(quiz2));

	quiz2 = quiz2 * 10;
	
	do
	{
		cout << endl << "Please enter the student's score for the midterm (1-100):" << endl;
		cin >> midterm;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (!testExam(midterm));

	do
	{
		cout << endl << "Please enter the student's score for the final (1-100):" << endl;
		cin >> finalExam;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (!testExam(finalExam));
}

bool GradeCalculator::testQuiz(double quizScore)
{
	bool tester = (quizScore >= 1) && (quizScore <= 10);

	if (!tester)
	{
		cout << endl << "ERROR: Invalid point value for the quiz (1-10)!" << endl;
	}

	return tester;
}

bool GradeCalculator::testExam(double examScore)
{
	bool tester = (examScore >= 1) && (examScore <= 100);

	if (!tester)
	{
		cout << endl << "ERROR: Invalid point value for the exam (1-100)!" << endl;
	}

	return tester;
}

void GradeCalculator::calculateGrade()
{
	finalPercent = (((quiz1 + quiz2) / 2) * 0.25) + (midterm * 0.25) + (finalExam * 0.5);
}

void GradeCalculator::findGrade()
{
	if (finalPercent < 60)
	{
		grade = 'F';
	}
	else if (finalPercent < 70)
	{
		grade = 'D';
	}
	else if (finalPercent < 80)
	{
		grade = 'C';
	}
	else if (finalPercent < 90)
	{
		grade = 'B';
	}
	else
	{
		grade = 'A';
	}
}

void GradeCalculator::output()
{
	cout << fixed << setprecision(2);
	cout << endl << "This student's score for Quiz 1 is: " << quiz1 << "%" << endl;
	cout << endl << "This student's score for Quiz 2 is: " << quiz2 << "%" << endl;
	cout << endl << "This student's score for the midterm is: " << midterm << "%" << endl;
	cout << endl << "This student's score for the final is: " << finalExam << "%" << endl;
	cout << endl << "This student's average score is " << (quiz1 + quiz2 + midterm + finalExam) / 4 << "%" << endl;

	if (grade == 'A' || grade == 'F')
	{
		cout << endl << "This student's final grade is " << finalPercent << "% which translates to an " << grade << "." << endl;
	}
	else
	{
		cout << endl << "This student's final weighted grade is " << finalPercent << "% which translates to a " << grade << "." << endl;
	}
}