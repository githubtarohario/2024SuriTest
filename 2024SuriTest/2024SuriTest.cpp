// テスト対策数理後期.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include"directxmath.h"
using namespace std;
//x,y
struct Vector2 {
	float x;
	float y;
};
//x,y,z
struct Vector3 {
	float x;
	float y;
	float z;
};


void re1() {
	Vector2 a = { 2,2 };
	Vector2 b = { 1,-2 };
	Vector2 c = {
					   a.x + b.x,
					   a.y + b.y
	};
	//2*aを計算a=(2.2)
	Vector2 d = {
						 2 * a.x
						,2 * a.y
	};
	//-3bを計算b=(1,-2)
	Vector2 e = { -3 * b.x,-3 * b.y };
	cout << "(1)2*a=" << "(" << d.x << "," << d.y << ")" << endl;
	//e=(-3,+6)
	cout << "(2)-3*b=" << "(" << e.x << "," << e.y << ")" << endl;
	cout << "(3)a+b=(" << c.x << "," << c.y << ")";
}

using namespace std;
int main()
{
	Vector2 a = { 1,3 };
	Vector2 b = { -2,1 };
	Vector2 c = { 3,-5 };
	float len;
	//(1)aのベクトルの大きさは√１０＝３．１６２
	len = sqrtf(a.x * a.x + a.y * a.y);//三平方の定理
	cout << "aベクトルの大きさ" << len << endl;
	//cの大きさ 5.831=√(3)*(3)+5*5=√34=5.831
	len = sqrtf(c.x * c.x + c.y * c.y);
	cout << "cベクトルの大きさ" << len << endl;
	//a+bを計算して大きさを求める
	Vector2 ab = { a.x + b.x,a.y + b.y };//a+b
	cout << "a+b=" << "(" << ab.x << "," << ab.y << ")" << endl;
	//a+b=(-1,4)
	len = sqrtf(ab.x * ab.x + ab.y * ab.y);//√17=4.123
	cout << "a+bの大きさ=" << len << endl;
	//a=(1,3) の平行な単位ベクトル（正規化）
	a = { 1,3 };
	//aの大きさを求める（三平方の定理）
	len = sqrtf(a.x * a.x + a.y * a.y);
	cout << "aベクトルの大きさ=" << len << endl;
	//aベクトルの成分をすべて大きさで割る(0.316,0.949)→正規化
	cout << "単位ベクトル(正規化）は(" << a.x / len << "," << a.y / len << ")" << endl;
	//Kyoto
	//(1)内積
	//(2)ふたつのベクトルの角度
	//(3)外積
	Vector2 d = { 1,2 };//d.x=1 d.y=2
	Vector2 e = { 4, 2 };
	float dot;//内積の値
	dot = d.x * e.x + d.y * e.y;//内積の公式
	cout << "dot（内積)=" << dot << endl;
	float len1 = sqrtf(d.x * d.x + d.y * d.y);//dの大きさ Test
	float len2 = sqrtf(e.x * e.x + e.y * e.y);//eの大きさ Test
	cout << "dの大きさ" << len1 << endl;
	cout << "eの大きさ" << len2 << endl;
	//d,eを正規化する(d,eを大きさ１にする）
	d = { d.x / len1,d.y / len1 };//Test
	e = { e.x / len2,e.y / len2 };//Test
	float angle;
	//公式
	//　　角度＝acosf(２つのベクトルの内積）//ただし２つのベクトルは正規化されている
	angle = acosf(d.x * e.x + d.y * e.y);//Test角度を求める公式angleは弧度法
	//弧度法から角度に戻す
	angle = DirectX::XMConvertToDegrees(angle);//Test
	cout << "angle=" << angle << endl;
	//外積（２つのベクトルの法線を求める
	Vector3 f = { 1 ,2,3 };
	Vector3 g = { 3,0, 5 };
	Vector3 gaiseki = {};//初期化
	gaiseki.x = f.y * g.z - f.z * g.y;//Test
	gaiseki.y = f.z * g.x - f.x * g.z;//Test
	gaiseki.z = f.x * g.y - f.y * g.x;//Test
	//(20,4,-6)
	cout << "外積 =(" << gaiseki.x << "," << gaiseki.y << "," << gaiseki.z << ")" << endl;

}
