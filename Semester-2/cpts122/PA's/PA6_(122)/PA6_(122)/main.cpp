#include "BST.h"

int main()
{
	BST<char, std::string> searchTree;
	std::cout << "_____________Morse Code List____________" << std::endl;
	
	//////////////////////////////////DeleteNode()-Extra Credit///////////////////////////////////////////////////////////////////////
	searchTree.print(searchTree.getmpRoot());
	std::cout << std::endl;

	searchTree.setmpRoot(searchTree.getmpRoot()->deleteNode('B'));
	searchTree.setmpRoot(searchTree.getmpRoot()->deleteNode('='));
	searchTree.setmpRoot(searchTree.getmpRoot()->deleteNode('Z'));
	searchTree.print(searchTree.getmpRoot());

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	system("pause");
	system("cls");
	std::cout << "Converting your file to morse code" << std::endl;	//splash screen notifying user of conversion
	Sleep(1000);
	system("cls");

	if (searchTree.convert() == false)	//splash screen notifying user of partially-successful conversion
	{
		std::cout << "Conversion completed" << std::endl <<
			"(Note: non-convertable characters were found within your file, lines are marked)" << std::endl;
	}
	else std::cout << "Conversion successfull" << std::endl;
	system("pause");
	system("cls");
}