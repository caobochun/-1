#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
using namespace std;


struct student {
	int num;
	string name;
	int as;
	int bs;
	int cs;
	double sum;
	int rank;
	double pingfang;
};
struct tempeorary {
	int len, sum, pingfang, biaozhuncha, ave,allsum;

}tmp;
student stu[10];
int choose;

void login() {

	ifstream input("data.txt", ifstream::in);
	input >> tmp.len;

	for (int i = 0; i < 6; i++)
	{
		input >> stu[i].num; cout << stu[i].num;
		input >> stu[i].name;
		input >> stu[i].as;
		input >> stu[i].bs;
		input >> stu[i].cs;
		tmp.sum = (stu[i].as * 2.0 + stu[i].bs * 2.0 + stu[i].cs * 6.0) / 10;
		stu[i].sum = tmp.sum;

	}
	input.close();
	for (int i = 0; i < 6; i++)
	{
		cout << stu[i].num;
		cout << stu[i].name;
		cout << stu[i].as;
		cout << stu[i].bs;
		cout << stu[i].cs;
		cout << stu[i].sum;
	

	}
}
void exchange(int x, int y) {
	student t;
	t = stu[x]; stu[x] = stu[y]; stu[y] = t;
}
void Sort() {
	for (int i = 1; i < 6; i++) {
		if (stu[i - 1].sum > stu[i].sum)
			for (int o = i; o != 0; o--) {
				if (stu[o - 1].sum < stu[o].sum)
					break;
				exchange(o - 1, o);
			}
	}
}

void seek() {
	int num;
	cout << "请输入学号：" << endl;
	cin >> num;
	for (int i = 0; i < 6; i++)
	{
		if (stu[i].num == num) {
			cout << "平时成绩为:" << stu[i].as << "实验成绩为:" << stu[i].bs << "期末成绩为:" << stu[i].cs << endl;
			break;
		}
	}
}
void analysis(){
	tmp.ave = tmp.sum / tmp.len;
	for (int i = 0; i < 6; i++)
	{
		stu[i].pingfang = pow((stu[i].sum - tmp.ave),2);
		tmp.allsum = stu[i].pingfang + tmp.allsum;
	}
	tmp.biaozhuncha = sqrt(tmp.allsum / tmp.len);
	cout << "平均数为" << tmp.ave << "标准差为" << tmp.biaozhuncha << endl;
}

int main() {
	login();
	cout << "please type the order 1is put in order 2 is seeking 3 is analysis  "<<endl;
	cin >> choose;
	switch (choose) {
	case 1: Sort();
	case 2:seek();
	case 3:analysis();
		return 0;
	}
}