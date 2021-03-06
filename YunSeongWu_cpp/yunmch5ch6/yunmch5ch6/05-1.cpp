#include <iostream>
#include <cstring>
using namespace std;
namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };
}

class NameCard
{
private:
	char * name;
	char * company;
	char * phone;
	int level;
	char * levelprint(int level)
	{
		char * level_name;
		switch (level)
		{
		case COMP_POS::CLERK:
			level_name = "사원";
			break;
		case COMP_POS::SENIOR:
			level_name = "주임";
			break;
		case COMP_POS::ASSIST:
			level_name = "대리";
			break;
		case COMP_POS::MANAGER:
			level_name = "과장";
			break;
		}
		return level_name;
	}
public:
	NameCard(char*name, char*company, char*phone, int level)
		:level(level)
	{
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);

	}
	~NameCard()
	{
		delete[] name;
		delete[] company;
		delete[] phone;
	}
	NameCard(const NameCard &copy)
		:level(copy.level)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: " << levelprint(level) << endl << endl;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}