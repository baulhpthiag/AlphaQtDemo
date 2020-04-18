#pragma once

#include <QObject>
#include <QMetaObject>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class TreeWidgetHelper : public QObject
{
	Q_OBJECT

public:
	TreeWidgetHelper(QObject *parent);
	~TreeWidgetHelper();

	template<class T>
	static void loadData(T& t,QTreeWidget* treeWidget);


	static void bindData(QObject* obj,QTreeWidgetItem * treeWidgetItem, QTreeWidget* treeWidget);
};

template<class T>
static void TreeWidgetHelper::loadData(T& t, QTreeWidget* treeWidget)
{
	if (nullptr == treeWidget)
	{
		return;
	}
	treeWidget->setColumnCount(2);
	treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
	treeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列

	QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(treeWidget);
	QObject *obj = (QObject*)(&t);
	
	bindData(obj, treeWidgetItem, treeWidget);



}
