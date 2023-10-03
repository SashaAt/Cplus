#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct trail {
	string begin;
	string end;
	string num;
	trail* next;
};

void creat(int kolvo, trail* p) {
	string InputBegin, InputEnd;
	string InputNum;
	for (int i = 0; i < kolvo; i++) {
		cout << "���������� �������:\n 1) �������� ���������� ������\n 2) �������� ��������� ������\n 3) ����� �������\n";
		cin >> InputBegin >> InputEnd >> InputNum;
		p->begin = InputBegin;
		p->end = InputEnd;
		p->num = InputNum;
		p->next = new trail;
		p = p->next;
	}
	p->next = nullptr;
}

void add(trail* p, int kolvo) {
	trail* input;
	input = new trail;
	cout << "���������� �������:\n 1) �������� ���������� ������\n 2) �������� ��������� ������\n 3) ����� �������\n";
	cin >> input->begin >> input->end >> input->num;
	for (int i = 0; i < kolvo - 1; ++i) {
		p = p->next;
	}
	p->next = input;
	input->next = nullptr;
}

void redact(trail* p, int position) {
	for (int i = 0; i < position; i++)
		p = p->next;
	cout << "���������� �������:\n 1) �������� ���������� ������\n 2) �������� ��������� ������\n 3) ����� �������� \n";
	string InputBegin, InputEnd;
	string InputNum;
	cin >> InputBegin >> InputEnd >> InputNum;
	p->begin = InputBegin;
	p->end = InputEnd;
	p->num = InputNum;
}

trail* del(trail* p, int position) {
	trail* tmp = p;
	if (position != 0) {
		for (int i = 0; i < position - 1; i++)
			p = p->next;						// ���������� �������� ����� ���������
		trail* p_del = p->next;					// ��������� �� ��������� ������
		trail* p_next = p_del->next;			// ��������� ������ ����� ����������
		p->next = p_next;
	}
	else {
		tmp = p->next;
		delete p;
	}
	return tmp;
}

void look(trail* p, int position) {
	for (int i = 0; i < position; i++)
		p = p->next;
	cout << "�������� ���������� ������: " << p->begin << endl << "�������� ��������� ������: " << p->end << endl << "����� ��������: " << p->num << endl;
}

trail* paste(trail* p, int position) {
	trail* input;
	input = new trail;
	cout << "���������� �������:\n 1) �������� ���������� ������\n 2) �������� ��������� ������\n 3) ����� ��������\n";
	cin >> input->begin >> input->end >> input->num;
	if (position != 0) {
		for (int i = 0; i < position - 1; i++) {		// ���������� �������� ����� �����������
			p = p->next;
		}
		input->next = p->next;
		p->next = input;
	}
	else {
		input->next = p;
		p = input;
	}
	return p;
}

/*
void paste_ops(marsh* p, int position) {
	marsh input;
	cout << "���������� �������:\n 1) �������� ���������� ������\n 2) �������� ��������� ������\n 3) ����� ��������\n";
	cin >> input.begin >> input.end >> input.num;
	for (int i = 0; i < position - 1; i++) {		// ���������� �������� ����� �����������
		p = p->next;
	}
	input.next = p->next;
	p->next = &input;
}
*/

void look_all(trail* p, int kolvo) {
	for (int i = 0; i < kolvo; i++) {
		cout << "�������� ���������� ������: " << p->begin << endl << "�������� ��������� ������: " << p->end << endl << "����� ��������: " << p->num << endl;
		cout << "------------------" << endl;
		p = p->next;
	}
}

trail* del_all(trail* p, int kolvo) {
	trail* tmp_p;
	for (int i = 0; i < kolvo; i++) {
		tmp_p = p->next;
		delete p;
		p = tmp_p;
	}
	p = new trail;
	return p;
}

void serch_by_begin(trail* p, int kolvo, string key) {
	for (int i = 0; i < kolvo; i++) {
		if (p->begin == key) {
			cout << p->begin << "\t" << p->end << "\t" << p->num << endl;
		}
		p = p->next;
	}
}

void serch_by_end(trail* p, int kolvo, string key) {
	for (int i = 0; i < kolvo; i++) {
		if (p->end == key) {
			cout << p->begin << "\t" << p->end << "\t" << p->num << endl;
		}
		p = p->next;
	}
}

void serch_by_num(trail* p, int kolvo, string key) {
	for (int i = 0; i < kolvo; i++) {
		if (p->num == key) {
			cout << p->begin << "\t" << p->end << "\t" << p->num << endl;
		}
		p = p->next;
	}
}

void record(trail* p, int kolvo) {
	string file_name;
	ofstream fout;
	cout << "������� ���� �������� ������������� ����� ����, ���� ������ ������� �����, �������� ������:" << endl;
	cin >> file_name;
	fout.open(file_name);
	if (!fout.is_open()) {
		cout << "������ �������� �����";
	}
	else {
		for (int i = 0; i < kolvo; ++i) {
			fout << p->begin << '\t' << p->end << '\t' << p->num << endl;
			p = p->next;
		}
	}
	fout.close();
}

void read(trail* p) {
	ifstream fin;
	string file_name;
	cout << "������� ��� ����� ��� ��������:" << endl;
	cin >> file_name;
	fin.open(file_name);
	if (!fin.is_open()) {
		cout << "������ �������� �����";
	}
	else {
		char ch;
		while (fin.get(ch)) {
			cout << ch;
		}
	}
	fin.close();
}

trail* sort(trail* p, int kolvo, string key) {		// ��������� �� num
	int i;
	trail* p1, * p2;
	for (int k = 0; k < 2; ++k) {
		i = 0;
		while (i < kolvo - 1) {
			trail* p_last;
			p1 = p;
			p_last = p1;
			for (int j = 0; j < i; ++j) {
				p_last = p1;
				p1 = p1->next;
			}
			p2 = p1->next;
			string check1, check2;
			if (key == "3") {
				check1 = p1->num;
				check2 = p2->num;
			}
			else if(key == "2"){
				check1 = p1->end;
				check2 = p2->end;
			}
			else if (key == "1") {
				check1 = p1->begin;
				check2 = p2->begin;
			}
			else {
				cout << "���� ������ �������" << endl;
				return p;
			}
			if (check1 > check2) {
				p1->next = p2->next;
				p2->next = p1;
				if (i == 0) {
					p = p2;
				}
				else {
					p_last->next = p2;
				}
				i = 0;
			}
			i++;
		}
	}
	return p;
}

int main() {
	setlocale(LC_ALL, "rus");
	char choise = ' ';
	trail* p_begin = new trail;		// ��������� �� ������ ������� ������
	int HowMuch = 0;				// ���-�� ��������� � ������
	while (choise != 'E') {
		cout << "������� ���� �� ������: \n1 - �������� ������.\n2 - ���������� �������� � ����� ������.\n3 - ������� �������� � ������������ ����� ������.\n4 - �������� ������������� �������� �� ������.\n5 - ����� �������� ������ �� ��������� �����.\n6 - ���������� ������.\n7 - �������� ��������.\n8 - �������������� ��������.\n9 � �������� ������.\nD - ������� ���� ������.\nW - �������� � ����.\nR - ��������� �� �����.\nE - ����� �� ���������.\n";
		cin >> choise;
		if (choise == '1')
		{
			cout << "������� ��������� ����� � ������?" << endl;
			cin >> HowMuch;
			if (HowMuch < 0) {
				while (HowMuch < 0) {
					cout << "��������� ������ ���� ������ ����. ������� �����" << endl;
					cin >> HowMuch;
				}
			}
			creat(HowMuch, p_begin);
		}
		else if (choise == '2') {
			add(p_begin, HowMuch);
			HowMuch++;
		}
		else if (choise == '3') {
			if (HowMuch > 0) {
				int position;
				cout << "�� ����� ����� �������� ����� ������� (������� ���������� � ����) ?" << endl;
				cin >> position;
				p_begin = paste(p_begin, position);
				HowMuch++;
			}
		}
		else if (choise == '4') {
			if (HowMuch > 0) {
				int position;
				cout << "������� � ����� �������� ������� (������� ���������� � ����) ?" << endl;
				cin >> position;
				p_begin = del(p_begin, position);
				HowMuch--;
			}
		}
		else if (choise == '5') {
			cout << "������� ����� ������, �� �������� ����� ������ (1 ��� 2 ��� 3): \n 1) �������� ���������� ������\n 2) �������� ��������� ������\n 3) ����� ��������\n";
			int check;
			cin >> check;
			cout << "������� ����" << endl;
			string key;
			cin >> key;
			if (check == 1) {
				serch_by_begin(p_begin, HowMuch, key);
			}
			else if (check == 2) {
				serch_by_end(p_begin, HowMuch, key);
			}
			else {
				serch_by_num(p_begin, HowMuch, key);
			}
		}
		else if (choise == '6') {
			cout << "������� �� ���� ���� �������������: 1) ��������� ����� 2) �������� ����� 3) ����� ��������" << endl;
			string key;
			cin >> key;
			p_begin = sort(p_begin, HowMuch, key);
		}
		else if (choise == '7') {
			if (HowMuch > 0) {
				cout << "������� � ����� �������� �� ������ ����������� (������� ���������� � ����) ?" << endl;
				int position;
				cin >> position;
				look(p_begin, position);
			}
		}
		else if (choise == '8') {
			if (HowMuch > 0) {
				cout << "������� � ����� �������� �� ������ �������� (������� ���������� � ����) ?" << endl;
				int position;
				cin >> position;
				redact(p_begin, position);
			}
		}
		else if (choise == '9') {
			if (HowMuch != 0)
				look_all(p_begin, HowMuch);
			else
				cout << "������ ����" << endl;
		}
		else if (choise == 'D') {
			p_begin = del_all(p_begin, HowMuch);
			HowMuch = 0;
		}
		else if (choise == 'W') {
			if (HowMuch != 0) {
				record(p_begin, HowMuch);
			}
		}
		else if (choise == 'R') {
			read(p_begin);
		}
	}
	return 0;
}