/*	main.cpp used for testing bst.h and bst.cpp
	J DeWolfe Oct 23, 2019
	This BST holds two separate data objects	*/

#include <string>
#include <ctime>
#include "dualDataBST.cpp"

using namespace std;

//PROTOTYPES
template <typename T1, typename T2>
void display(BST<T1, T2> &bst, T1 val, T1 rem, T1 nev); //Params: val(id), rem(oved), nev(er existed)
void testStringIntTree();
void testDoubleTimeTree();

//CALL ALL TESTS FROM MAIN
int main()
{
	testStringIntTree();
	testDoubleTimeTree();
	system("PAUSE");
}

//TEST #1
void testStringIntTree()
{
	cout << "TESTING THE BST WITH STRINGS & INTS" << endl;
	BST<string, int> stringIntTree;
	string words[12] = { "Bravo", "India", "Charlie", "Golf", "Hotel", "Delta", "Echo", "Alpha", "Foxtrot", "Juliett", "Lima", "Lima" };
	for (int i = 0; i < 12; i++)
	{
		stringIntTree.insert(words[i], i); //Insert() should reject second "Lima" entry 
		//Secondary data = pre-insertion index
	}
	stringIntTree.remove("Bravo");
	display(stringIntTree, (string)"Charlie", (string)"Bravo", (string)"Quebec");
}

//TEST #2
void testDoubleTimeTree()
{
	cout << "TESTING THE BST WITH DOUBLES & TIME" << endl;
	BST<double, time_t> doubleTimeTree;
	double numbers[11] = { 88.8, 66.8, 77.7, 33.3, 11.1, 22.2, 44.4, 55.5, 99.9, 0.0, 0.0 };
	for (int i = 0; i < 11; i++)
	{
		time_t now = time(NULL);
		doubleTimeTree.insert(numbers[i], now); //Insert() should reject second "0.0" entry
		//Secondary data = insertion time in milliseconds
	}
	doubleTimeTree.remove(22.2);
	display(doubleTimeTree, (double)44.4, (double)22.2, (double)500);
}

//DISPLAY TEST RESULTS ...
template <typename T1, typename T2>
void display(BST<T1, T2> &bst, T1 val, T1 rem, T1 nev)
{
	cout << endl << "Traverse (forward): ";
	bst.traverse(); //Reverse order = false
	cout << endl << "Traverse (reverse): ";
	bst.traverse(true); //Reverse order = true

	cout << endl << "Leaf Count: " << (int)bst.leafCount();
	cout << endl << "Height of Tree: " << (int)bst.getHeight() << endl;

	cout << endl << val << " was " << (bst.find(val) ? "Found" : "Not Found");
	cout << endl << rem << " was " << (bst.find(rem) ? "Found" : "Not Found");
	cout << endl << nev << " was " << (bst.find(nev) ? "Found" : "Not Found");
	cout << endl;

	//SECONDARY DATA
	T2 valData = bst.getSecondaryData(val);
	cout << endl << "Secondary data for " << val;
	if (valData) cout << " is " << valData;
	else cout << " wasn't found." << endl;

	T2 remData = bst.getSecondaryData(rem);
	cout << endl << "Secondary data for " << rem;
	if (remData) cout << " is " << remData;
	else cout << " wasn't found." << endl;
	//Secondary data for rem won't be found

	cout << endl << "------------------------------" << endl;


}