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

	QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(treeWidget);
	QObject *obj = (QObject*)(&t);
	
	bindData(obj, treeWidgetItem, treeWidget);



}
