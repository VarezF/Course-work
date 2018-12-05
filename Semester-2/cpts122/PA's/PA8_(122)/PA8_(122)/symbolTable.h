#pragma once

class tableEntry {
public:
	tableEntry();
private:
	int mSymbol;	//integer containing the ASCII representation of a variable, a line number or a constant
	char mType;	//characters indicating the symbol’s type: 'C' for constant, 'L' for line number and 'V' for variable.
	int mlocation; //contains the Simpletron memory location(00 to 99) to which the symbol refers
};

class symbolTable {	//array of tableEntry objects representing each symbol in the program.
public:
	symbolTable();
private:
	tableEntry *mSymbols;
};

typedef struct flags {
	int flags[100] = {-1};
}Flags;
