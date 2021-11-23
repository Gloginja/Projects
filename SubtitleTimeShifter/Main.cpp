#include <iostream>
#include "List.h"

using namespace std;

int main() {

	//List<int>Lista();
	List<int>* Test = new List<int>();
	Test->append(7);
	Test->append(13);
	Test->append(21);

	cout << Test->getCount() << endl;
	cout << Test->pop() << endl;
	cout << Test->pop() << endl;
	cout << Test->getCount() << endl;
	cout << Test->pop() << endl;
	cout << Test->pop() << endl;
	Test->append(22);
	cout << Test->getCount() << endl;
	cout << Test->pop() << endl;
	cout << Test->getCount() << endl;


	return 0;
}