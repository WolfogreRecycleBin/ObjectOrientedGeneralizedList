#include "GenList.h"
int main()
{
	cout << "�����1" << endl;
	GenList<int> gl1;
	gl1.Show(); cout << endl <<endl;

	cout << "�����1��1,2,3,4" << endl;
	gl1.Insert(1); gl1.Insert(2); gl1.Insert(3); gl1.Insert(4);
	gl1.Show(); cout << endl <<endl;

	cout << "�����2" << endl;
	GenList<int> gl2;
	gl2.Show(); cout << endl <<endl;

	cout << "�����2��5,6" << endl;
	gl2.Insert(5); gl2.Insert(6);
	gl2.Show(); cout << endl <<endl;

	cout << "����1�����2" << endl;
	gl2.Insert(gl1);
	gl2.Show(); cout << endl << endl;

	cout << "�����3" << endl;
	GenList<int> gl3;
	gl3.Show(); cout << endl << endl;

	cout << "����2�����3" << endl;
	gl3.Insert(gl2);
	gl3.Show(); cout << endl << endl;

	cout << "�����3��7,8,9" << endl;
	gl3.Insert(7); gl3.Insert(8); gl3.Insert(9);
	gl3.Show(); cout << endl << endl;

	cout << "��3����ȣ�" << gl3.GetDepth() << endl;
	cout << "��3�ĳ��ȣ�" << gl3.GetLength() << endl;
	cout << endl;
	return 0;
}