#include "LambdaDemoTempWidget.h"
#include <QDebug>

LambdaDemoTempWidget::LambdaDemoTempWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void LambdaDemoTempWidget::test01ButtonClicked()
{
	/*

	lambda格式
	[capture](parameters) mutable ->return-type{ statement }
	1.[capture]：捕捉列表。捕捉列表总是出现在Lambda函数的开始处。实际上，[]是Lambda引出符。编译器根据该引出符判断接下来的代码是否是Lambda函数。
	捕捉列表能够捕捉上下文中的变量以供Lambda函数使用;
	2.(parameters)：参数列表。与普通函数的参数列表一致。如果不需要参数传递，则可以连同括号“()”一起省略;
	3.mutable：mutable修饰符。默认情况下，Lambda函数总是一个const函数，mutable可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）;
	4.->return-type：返回类型。用追踪返回类型形式声明函数的返回类型。我们可以在不需要返回值的时候也可以连同符号”->”一起省略。
	此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导;
	5.{statement}：函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量。
	与普通函数最大的区别是，除了可以使用参数以外，Lambda函数还可以通过捕获列表访问一些上下文中的数据。具体地，捕捉列表描述了上下文中哪些数据可以被Lambda使用，
	以及使用方式（以值传递的方式或引用传递的方式）。语法上，在“[]”包括起来的是捕捉列表，捕捉列表由多个捕捉项组成，并以逗号分隔。捕捉列表有以下几种形式：
	0.[]表示没有使用任何参数
	1.[var]表示值传递方式捕捉变量var；
	2.[=]表示值传递方式捕捉所有父作用域的变量（包括this）；
	3.[&var]表示引用传递捕捉变量var；
	4.[&]表示引用传递方式捕捉所有父作用域的变量（包括this）；
	5.[this]表示值传递方式捕捉当前的this指针。
	上面提到了一个父作用域，也就是包含Lambda函数的语句块，说通俗点就是包含Lambda的“{}”代码块。上面的捕捉列表还可以进行组合，例如：
	1.[=, &a, &b]表示以引用传递的方式捕捉变量a和b，以值传递方式捕捉其它所有变量;
	2.[&, a, this]表示以值传递的方式捕捉变量a和this，引用传递方式捕捉其它所有变量。
	不过值得注意的是，捕捉列表不允许变量重复传递。下面一些例子就是典型的重复，会导致编译时期的错误。例如：
	3.[=, a]这里已经以值传递方式捕捉了所有变量，但是重复捕捉a了，会报错的;
	4.[&, &this]这里&已经以引用传递方式捕捉了所有变量，再捕捉this也是一种重复。
	
	*/


	int a = 1;
	int b = 2;

	auto func = [=](int c) {
		qDebug() << "a:" << a;
		qDebug() << "b:" << b;
		qDebug() << "c:" << c;
	};
	func(3);


	QObject::connect(this, &LambdaDemoTempWidget::testSignal,this, [=]() {qDebug() << "lambda 表达式"; });

}
