#include "GenList.h"
int main()
{
	cout << "定义表1" << endl;
	GenList<int> gl1;
	gl1.Show(); cout << endl <<endl;

	cout << "插入表1：1,2,3,4" << endl;
	gl1.Insert(1); gl1.Insert(2); gl1.Insert(3); gl1.Insert(4);
	gl1.Show(); cout << endl <<endl;

	cout << "定义表2" << endl;
	GenList<int> gl2;
	gl2.Show(); cout << endl <<endl;

	cout << "插入表2：5,6" << endl;
	gl2.Insert(5); gl2.Insert(6);
	gl2.Show(); cout << endl <<endl;

	cout << "将表1插入表2" << endl;
	gl2.Insert(gl1);
	gl2.Show(); cout << endl << endl;

	cout << "定义表3" << endl;
	GenList<int> gl3;
	gl3.Show(); cout << endl << endl;

	cout << "将表2插入表3" << endl;
	gl3.Insert(gl2);
	gl3.Show(); cout << endl << endl;

	cout << "插入表3：7,8,9" << endl;
	gl3.Insert(7); gl3.Insert(8); gl3.Insert(9);
	gl3.Show(); cout << endl << endl;

	cout << "表3的深度：" << gl3.GetDepth() << endl;
	cout << "表3的长度：" << gl3.GetLength() << endl;
	cout << endl;
	return 0;
}