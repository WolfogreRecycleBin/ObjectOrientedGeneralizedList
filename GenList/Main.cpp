#include "GenList.h"
int main()
{
	GenList<int> gl;
	gl.Show(); cout << endl;
	cout << "depth:" << gl.GetDepth() << endl;
	gl.Insert(1);
	gl.Insert(2);
	gl.Insert(3);
	gl.Insert(4);
	gl.Show(); cout << endl;
	GenList<int> gl1;
	cout << "depth:" << gl1.GetDepth() << endl;
	gl1.Insert(gl);
	gl1.Insert(5);
	gl1.Insert(6);
	gl1.Show(); cout << endl;
	cout << "depth:" << gl1.GetDepth() << endl;
	cout << "lenth:" << gl1.GetLength() << endl;
	return 0;
}