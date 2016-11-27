#include <iostream> 

 using namespace std;

 class String
 {
	 	int size;
	 	char *string;
	 public:
		 	String(const char* secondstring);
		 	void EditString(const char* secondstring);
		 	char* displayString();
		 	int SizeString();
		 	void pasteString();
		 	void AddToString(const char* addString);
		void AddSymbol(const char symbol, int position);
		 	void DisplayInASCII();
		 	char* BigRegister();
			char* SmallRegister();
		 	~String();
		 };

 String::String(const char* secondstring)
 {
	 	size = strlen(secondstring) + 1;
	 	string = new char[size];
	 	strcpy_s(string, size, secondstring);
	 }

 void String::EditString(const char* secondstring)
 {
	 	size = strlen(secondstring) + 1;
	 	string = new char[size];
	 	strcpy_s(string, size, secondstring);
	 }

 inline char* String::displayString()
 {
	 	return string;
	 }

 inline int String::SizeString()
 {
 	return strlen(string);
	 }

void String::pasteString()
 {
	 	char* bufString = new char[size];
	 	strcpy_s(bufString, size, string);
	 	delete[] string;
	 	string = new char[size];
	 	strcpy_s(string, size, bufString);
	 	delete[] bufString;
	 }

 void String::AddToString(const char* addString)
 {
	 	size += strlen(addString);
		pasteString();
	 	strcat_s(string, size, addString);
	 }

 void String::AddSymbol(const char symbol, int position)
 {
	 	if (position >= size) {
		 		cout << "This position is out of size of the string" << endl;
	 		return;
	
	}

		 	size += 1;
	pasteString();
	
			for (int i = size - 1; i >= 0; --i) {
		 		if (i == position) {
		 			string[i] = symbol;
		 			break;
		
		}
			swap(string[i], string[i - 1]);
	
	}
	 }


 void String::DisplayInASCII()
 {
	for (int i = 0; i < size - 1; ++i) {
				cout << string[i] << " " << (int)string[i] << endl;
		
	}
	 }


char* String::BigRegister()
 {
	 	for (int i = 0; i < size; ++i) {
		 		if (string[i] >= 97 && string[i] <= 122) {
			 			string[i] = string[i] - 32;
		
		}
		
	}
	return string;
 }


 char* String::SmallRegister()
 {
	 	for (int i = 0; i < size; ++i) {
			if (string[i] >= 65 && string[i] <= 90) {
			 			string[i] = string[i] + 32;
			
		}
		
	}
		return string;
	 }

 String::~String()
 {
		delete[] string;
 }

 void main()
 {
	String str("LightMyFire");
	cout << "\n1:   Tasc:    \t \t \t";
	cout << str.displayString() << endl;
	cout << "\n2:   Tasc:    \t \t \t";
 	str.EditString("LightMyFire");
	cout << str.displayString() << endl;
	cout << "\n3:  The length of a string: \t";
	cout << str.SizeString() << endl;
	cout << "\n4:  Add string to first one : \t";
	cout << str.displayString() << endl;
 	cout << "\n5:  Union of Strings:  \t \t";
	str.AddToString("ToBurnItDown!");
 	cout << str.displayString() << endl;
	cout << "\n6:  Insert symbol in define position in string:  \t ";
	str.AddSymbol(':)', 11);
 	cout << str.displayString() << endl;
	cout << "\n7:  String on ASCII:  \t " << endl;
	str.DisplayInASCII();
	cout << "\n8:  Our string in large register:  \t";
	cout << str.BigRegister() << endl;
	cout << "\n9:  Our string in small register:  \t";
	cout << str.SmallRegister() << endl;
	 }
