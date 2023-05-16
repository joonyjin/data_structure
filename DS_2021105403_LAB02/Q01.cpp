#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Number of Parameters = " << argc << endl;
	for (int i = 0; i < argc; i++) {
		cout << i << "-th argument = " << argv[i] << endl;
	}


	ifstream input_file(argv[1]);
	ofstream output_file(argv[2]);
	string name = argv[3];

	char ch;
	while (input_file.get(ch)) {
		if (ch == '\n') {
			if (name == "Mac") output_file << '\r';
			else if (name == "Linux" || name == "Windows") output_file << '\n';
		}
		else output_file << ch;
	}

	input_file.close();
	output_file.close();


}