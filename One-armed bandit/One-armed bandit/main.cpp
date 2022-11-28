#include <iostream>
#include <queue>
#include <string>
#include <random>
#include <cstdlib>
#include <conio.h>
using namespace std;

constexpr auto delim = "\n\n\n\n\n\t\t\t\t\t";

size_t getRandomNumber() {
	random_device rd;
	mt19937 random(rd());
	uniform_int_distribution<mt19937::result_type> number(5, 100);
	return number(random);
}

queue<string> make_random_queue() {
	vector<string> il{
	"CHERRY",
	"APPLE",
	"MELON",
	"SEVEN",
	"ZERO",
	"RAPSBERRY",
	"GUN",
	"LEMON",
	"ORANGE",
	"BAR",
	"CAKE",
	"BANANA",
	"FROG"
	};
	queue<string> qs;
	for (const auto& e : il) qs.push(e);
	return qs;
}

int main() {

	queue<string> q1(make_random_queue());
	queue<string> q2(make_random_queue());
	queue<string> q3(make_random_queue());

	size_t n{ 0 };

	cout << delim << "Let's begin......." << endl;
	cout << delim << "Press ENTER......." << endl;
	_getch();

	n = getRandomNumber();
	for (size_t j{ 0 }; j < n; ++j) {
		q1.push(q1.front());
		q1.pop();
	}

	n = getRandomNumber();
	for (size_t j{ 0 }; j < n; ++j) {
		q2.push(q2.front());
		q2.pop();
	}

	n = getRandomNumber();
	for (size_t j{ 0 }; j < n; ++j) {
		q3.push(q3.front());
		q3.pop();
	}

	system("cls");
	cout << delim << q1.front() << "\t" << q2.front() << "\t" << q3.front() << endl;

	if (q1.front() == q2.front() &&
		q2.front() == q3.front())
		cout << delim << "JACK POT" << endl;
	else if (	q1.front() == q2.front() ||
				q1.front() == q3.front() ||
				q2.front() == q3.front()	)
		cout << delim << "You were very close to catch JACK POT!!!" << endl;
	else
		cout << delim << "Maybe lucky will be on your side next time(((" << endl;

	cout << "\n\n\n\n\n\n\n";

	return 0;
}