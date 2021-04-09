#pragma once
#include <iostream>
#include <string>
using namespace std;

class Data {
private:
	struct Key {
		string catalogName;
		string fileName;
	};

	string spec;

	struct DateOfCreation {
		int day, month, year;
	};

	int size;

	Key KeyObj;
	DateOfCreation DayObj;

public:

	Data() {
		KeyObj.catalogName = " ";
		KeyObj.fileName = " ";

		spec = " ";

		DayObj.day = 0;
		DayObj.month = 0;
		DayObj.year = 0;

		size = 0;
	}

	Data(string CatalogName, string FileName, string spec, int Day, int Month, int Year, int Size) : spec(spec), size(Size) {
		KeyObj.catalogName = CatalogName;
		KeyObj.fileName = FileName;

		DayObj.day = Day;
		DayObj.month = Month;
		DayObj.year = Year;
	};

	string getKey() {
		return KeyObj.catalogName + KeyObj.fileName;
	}
	string getCatalogName() {
		return KeyObj.catalogName;
	}
	string getFileName() {
		return KeyObj.fileName;
	}

	string getSpec() {
		return spec;
	}

	int getDay() {
		return DayObj.day;
	}
	int getMonth() {
		return DayObj.month;
	}
	int getYear() {
		return DayObj.year;
	}

	int getSize() {
		return size;
	}

	bool operator == (Data data) {
		if (KeyObj.catalogName == data.KeyObj.catalogName && KeyObj.fileName == data.KeyObj.fileName && spec == data.spec
			&& DayObj.day == data.DayObj.day && DayObj.month == data.DayObj.month && DayObj.year == data.DayObj.year
			&& size == data.size)
			return true;
		else
			return false;
	}
	bool operator != (Data data) {
		if ((KeyObj.catalogName != data.KeyObj.catalogName && KeyObj.fileName != data.KeyObj.fileName && spec != data.spec
			&& DayObj.day != data.DayObj.day && DayObj.month != data.DayObj.month && DayObj.year != data.DayObj.year
			&& size != data.size))
			return true;
		else
			return false;
	}

	friend istream& operator >> (istream& input, Data& data) {
		input >> data.KeyObj.catalogName >> data.KeyObj.fileName >> data.spec
			>> data.DayObj.day >> data.DayObj.month >> data.DayObj.year >> data.size;

		return input;
	};

	friend ostream& operator << (ostream& output, const Data& data) {
		output << data.KeyObj.catalogName << " " << data.KeyObj.fileName << " " << data.spec << " "
			<< data.DayObj.day << " " << data.DayObj.month << " " << data.DayObj.year << " " << " " << data.size;

		return output;
	};
};