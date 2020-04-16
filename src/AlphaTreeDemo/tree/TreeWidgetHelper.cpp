#include "TreeWidgetHelper.h"
#include <QMetaProperty>
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>

#include "BoolConfigNode.h"
#include "DoubleConfigNode.h"
#include "DoubleEnumConfigNode.h"

#include "IntConfigNode.h"
#include "IntEnumConfigNode.h"
#include "StringConfigNode.h"
#include "StringEnumConfigNode.h"

TreeWidgetHelper::TreeWidgetHelper(QObject *parent)
	: QObject(parent)
{
}

TreeWidgetHelper::~TreeWidgetHelper()
{
}

void TreeWidgetHelper::bindData(QObject* obj, QTreeWidgetItem * treeWidgetItem, QTreeWidget* treeWidget)
{
	if (nullptr == treeWidgetItem || nullptr == obj)
	{
		return;
	}
	const QMetaObject * metaObj = obj->metaObject();
	int count = metaObj->propertyCount();
	int offset = metaObj->propertyOffset();


	for (int i = offset; i < count; i++)
	{
		QMetaProperty metaProperty = metaObj->property(i);
		const char *pStrKey = metaProperty.name();
		QString strKey = QString::fromUtf8(pStrKey);

		QVariant var = obj->property(pStrKey);
		const char * pStrTypeName = var.typeName();
		QString strTypeName = QString::fromUtf8(pStrTypeName);


		if ("int" == strTypeName)
		{
			QTreeWidgetItem *tempItem = new QTreeWidgetItem(treeWidgetItem);
			tempItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			tempItem->setText(0, strKey);
			tempItem->setText(1, var.toString());
		}
		else if ("double" == strTypeName)
		{
			QTreeWidgetItem *tempItem = new QTreeWidgetItem(treeWidgetItem);
			tempItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			tempItem->setText(0, strKey);
			tempItem->setText(1, var.toString());
		}
		else if ("bool" == strTypeName)
		{
			QTreeWidgetItem *tempItem = new QTreeWidgetItem(treeWidgetItem);
			tempItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			tempItem->setText(0, strKey);
			tempItem->setText(1, var.toString());
		}
		else if ("QString" == strTypeName)
		{
			QTreeWidgetItem *tempItem = new QTreeWidgetItem(treeWidgetItem);
			tempItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			tempItem->setText(0, strKey);
			tempItem->setText(1, var.toString());
		}
		//自定义结构
		else if ("BoolConfigNode*" == strTypeName)
		{
			BoolConfigNode* tempConfigNode = var.value<BoolConfigNode*>();
			qDebug() << "tree";
			qDebug() << tempConfigNode;
			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QComboBox *tempComboBox = new QComboBox();
			tempComboBox->setObjectName("test");
			tempComboBox->addItem("false");
			tempComboBox->addItem("true");
			tempComboBox->setCurrentIndex(tempConfigNode->_nodeValue ? 1 : 0);

			//信号
			void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
			connect(tempComboBox, signal_currentIndexChanged, tempConfigNode, &BoolConfigNode::nodeValueChanged);

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempComboBox);

		}
		else if ("DoubleConfigNode*" == strTypeName)
		{
			DoubleConfigNode* tempConfigNode = var.value<DoubleConfigNode*>();
			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);
			QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			tempLineEdit->setText(QString::number(tempConfigNode->_nodeValue));
			//信号

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempLineEdit);
		}
		else if ("DoubleEnumConfigNode*" == strTypeName)
		{
			DoubleEnumConfigNode* tempConfigNode = var.value<DoubleEnumConfigNode*>();
			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QComboBox *tempComboBox = new QComboBox(treeWidget);
			if (tempConfigNode->_valueEnum.count() > 0)
			{
				for (int j = 0; j < tempConfigNode->_valueEnum.count(); j++)
				{
					tempComboBox->addItem(QString::number(tempConfigNode->_valueEnum[j]));
				}

				tempComboBox->setCurrentIndex(tempConfigNode->_enumIndex);
			}

			void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
			connect(tempComboBox, signal_currentIndexChanged, tempConfigNode, &DoubleEnumConfigNode::nodeValueIndexChanged);

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempComboBox);
		}
		else if ("IntConfigNode*" == strTypeName)
		{
			IntConfigNode* tempConfigNode = var.value<IntConfigNode*>();
			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			tempLineEdit->setText(QString::number(tempConfigNode->_nodeValue));
			//信号

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempLineEdit);
		}
		else if ("IntEnumConfigNode*" == strTypeName)
		{
			IntEnumConfigNode* tempConfigNode = var.value<IntEnumConfigNode*>();
			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QComboBox *tempComboBox = new QComboBox(treeWidget);
			if (tempConfigNode->_valueEnum.count() > 0)
			{
				for (int j = 0; j < tempConfigNode->_valueEnum.count(); j++)
				{
					tempComboBox->addItem(QString::number(tempConfigNode->_valueEnum[j]));
				}

				tempComboBox->setCurrentIndex(tempConfigNode->_enumIndex);
			}
			void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
			connect(tempComboBox, signal_currentIndexChanged, tempConfigNode, &IntEnumConfigNode::nodeValueIndexChanged);

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempComboBox);

		}
		else if ("StringConfigNode*" == strTypeName)
		{
			StringConfigNode* tempConfigNode = var.value<StringConfigNode*>();
			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			tempLineEdit->setText(tempConfigNode->_nodeValue);
			//信号

			//信号
			connect(tempLineEdit, &QLineEdit::textChanged, tempConfigNode, &StringConfigNode::nodeValueChanged);

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempLineEdit);

		}
		else if ("StringEnumConfigNode*" == strTypeName)
		{
			StringEnumConfigNode* tempConfigNode = var.value<StringEnumConfigNode*>();
			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QComboBox *tempComboBox = new QComboBox(treeWidget);
			if (tempConfigNode->_valueEnum.count() > 0)
			{
				for (int j = 0; j < tempConfigNode->_valueEnum.count(); j++)
				{
					tempComboBox->addItem(tempConfigNode->_valueEnum[j]);
				}

				tempComboBox->setCurrentIndex(tempConfigNode->_enumIndex);
			}
			//信号
			void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
			connect(tempComboBox, signal_currentIndexChanged, tempConfigNode, &StringEnumConfigNode::nodeValueIndexChanged);
			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempComboBox);

		}

		else if (strTypeName.contains("QList"))
		{
			if ("QList<QString>" == strTypeName)
			{
				QList<QString> list = var.value<QList<QString>>();
				QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
				tempTreeWidgetItem->setText(0, strKey);
				for (int j = 0; j < list.count(); j++)
				{
					QTreeWidgetItem *childItem = new QTreeWidgetItem(tempTreeWidgetItem);
					childItem->setText(0, strKey + QString::number(j));
					childItem->setText(1, list[j]);
					childItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
				}

			}
			else if ("QList<int>" == strTypeName)
			{
				QList<int> list = var.value<QList<int>>();
				QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
				tempTreeWidgetItem->setText(0, strKey);
				for (int j = 0; j < list.count(); j++)
				{
					QTreeWidgetItem *childItem = new QTreeWidgetItem(tempTreeWidgetItem);
					childItem->setText(0, strKey + QString::number(j));
					childItem->setText(1, QString::number(list[j]));
					childItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
				}
			}
			else if ("QList<double>" == strTypeName)
			{
				QList<double> list = var.value<QList<double>>();
				QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
				tempTreeWidgetItem->setText(0, strKey);
				for (int j = 0; j < list.count(); j++)
				{
					QTreeWidgetItem *childItem = new QTreeWidgetItem(tempTreeWidgetItem);
					childItem->setText(0, strKey + QString::number(j));
					childItem->setText(1, QString::number(list[j]));
					childItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
				}
			}
			else if ("QList<bool>" == strTypeName)
			{
				QList<bool> list = var.value<QList<bool>>();
				QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
				tempTreeWidgetItem->setText(0, strKey);
				for (int j = 0; j < list.count(); j++)
				{
					QTreeWidgetItem *childItem = new QTreeWidgetItem(tempTreeWidgetItem);
					QString b = list[j] ? "true" : "false";
					childItem->setText(0, strKey + QString::number(j));
					childItem->setText(1, b);
					childItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
				}
			}
			////自定义类型
			//else if ("QList<BoolConfigNode*>" == strTypeName)
			//{
			//	QList<BoolConfigNode*> list = var.value<QList<BoolConfigNode*>>();

			//	QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			//	tempTreeWidgetItem->setText(0, strKey);

			//	for (int j = 0; j < list.count(); j++)
			//	{
			//		BoolConfigNode* tempConfigNode = list[j];

			//		QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
			//		childTempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			//		QComboBox *tempComboBox = new QComboBox(treeWidget);
			//		tempComboBox->addItem("false");
			//		tempComboBox->addItem("true");
			//		tempComboBox->setCurrentIndex(tempConfigNode->_nodeValue ? 1 : 0);
			//		//信号

			//		treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);

			//	}

			//}
			//else if ("QList<DoubleConfigNode*>" == strTypeName)
			//{
			//	QList<DoubleConfigNode*> list = var.value<QList<DoubleConfigNode*>>();
			//	QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			//	tempTreeWidgetItem->setText(0, strKey);

			//	for (int i = 0; i < list.count(); i++)
			//	{
			//		DoubleConfigNode* tempConfigNode = list[i];
			//		QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
			//		childTempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);
			//		QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			//		tempLineEdit->setText(QString::number(tempConfigNode->_nodeValue));
			//		//信号

			//		treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			//	}

			//}
			//else if ("QList<DoubleEnumConfigNode*>" == strTypeName)
			//{
			//	QList<DoubleEnumConfigNode*> list = var.value<QList<DoubleEnumConfigNode*>>();
			//	QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			//	tempTreeWidgetItem->setText(0, strKey);

			//	for (int i = 0; i < list.count(); i++)
			//	{
			//		DoubleEnumConfigNode* tempConfigNode = list[i];
			//		QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
			//		childTempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			//		QComboBox *tempComboBox = new QComboBox(treeWidget);
			//		if (tempConfigNode->_valueEnum.count() > 0)
			//		{
			//			for (int j = 0; j < tempConfigNode->_valueEnum.count(); j++)
			//			{
			//				tempComboBox->addItem(QString::number(tempConfigNode->_valueEnum[j]));
			//			}

			//			tempComboBox->setCurrentIndex(tempConfigNode->_enumIndex);
			//		}
			//		//信号

			//		treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);

			//	}
			//}
			//else if ("QList<IntConfigNode*>" == strTypeName)
			//{
			//	QList<IntConfigNode*> list = var.value<QList<IntConfigNode*>>();
			//	QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			//	tempTreeWidgetItem->setText(0, strKey);

			//	for (int i = 0; i < list.count(); i++)
			//	{
			//		IntConfigNode* tempConfigNode = list[i];
			//		QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
			//		childTempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			//		QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			//		tempLineEdit->setText(QString::number(tempConfigNode->_nodeValue));
			//		//信号

			//		treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			//	}
			//}
			//else if ("QList<IntEnumConfigNode*>" == strTypeName)
			//{
			//	QList<IntEnumConfigNode*> list = var.value<QList<IntEnumConfigNode*>>();
			//	QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			//	tempTreeWidgetItem->setText(0, strKey);
			//	for (int i = 0; i < list.count(); i++)
			//	{
			//		IntEnumConfigNode* tempConfigNode = list[i];
			//		QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
			//		childTempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			//		QComboBox *tempComboBox = new QComboBox(treeWidget);
			//		if (tempConfigNode->_valueEnum.count() > 0)
			//		{
			//			for (int j = 0; j < tempConfigNode->_valueEnum.count(); j++)
			//			{
			//				tempComboBox->addItem(QString::number(tempConfigNode->_valueEnum[j]));
			//			}

			//			tempComboBox->setCurrentIndex(tempConfigNode->_enumIndex);
			//		}
			//		//信号

			//		treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);

			//	}
			//}
			//else if ("QList<StringConfigNode*>" == strTypeName)
			//{
			//	QList<StringConfigNode*> list = var.value<QList<StringConfigNode*>>();
			//	QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			//	tempTreeWidgetItem->setText(0, strKey);

			//	for (int i = 0; i < list.count(); i++)
			//	{
			//		StringConfigNode* tempConfigNode = list[i];
			//		QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
			//		childTempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			//		QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			//		tempLineEdit->setText(tempConfigNode->_nodeValue);
			//		//信号

			//		treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			//	}
			//}
			//else if ("QList<StringEnumConfigNode*>" == strTypeName)
			//{
			//	QList<StringEnumConfigNode*> list = var.value<QList<StringEnumConfigNode*>>();
			//	QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			//	tempTreeWidgetItem->setText(0, strKey);
			//	for (int i = 0; i < list.count(); i++)
			//	{
			//		StringEnumConfigNode* tempConfigNode = list[i];
			//		QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
			//		childTempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			//		QComboBox *tempComboBox = new QComboBox(treeWidget);
			//		if (tempConfigNode->_valueEnum.count() > 0)
			//		{
			//			for (int j = 0; j < tempConfigNode->_valueEnum.count(); j++)
			//			{
			//				tempComboBox->addItem(tempConfigNode->_valueEnum[j]);
			//			}

			//			tempComboBox->setCurrentIndex(tempConfigNode->_enumIndex);
			//		}
			//		//信号

			//		treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);
			//	}
			//}
			else
			{
				qDebug() << "TreeWidgetHelper objToJsonObj unknown type " + strTypeName;

				/*QJsonArray jsonArray;
				QSequentialIterable it = val.value<QSequentialIterable>();
				for (const QVariant &v : it)
				{
				QJsonObject childJsonObj;
				QObject *childObject = qvariant_cast<QObject*>(v);
				objToJsonObj(&childJsonObj, childObject);
				jsonArray.append(childJsonObj);
				}
				jsonObj->insert(qstringKey, jsonArray);*/

			}
		}
		else if (strTypeName.contains("*"))
		{
			qDebug() << "TreeWidgetHelper objToJsonObj unknown type " + strTypeName;

			/*QJsonObject tempJsonObj;
			QString upperFirst = qstringKey.mid(0).at(0).toUpper() + qstringKey.mid(1);
			QString methodName = "get" + upperFirst;
			const QByteArray text = methodName.toLocal8Bit();

			QObject * returnValue;
			QMetaObject::invokeMethod(obj, text.data(), Qt::DirectConnection, Q_RETURN_ARG(QObject*, returnValue));

			objToJsonObj(&tempJsonObj, returnValue);
			jsonObj->insert(qstringKey, QJsonValue::fromVariant(tempJsonObj));*/
		}
		else
		{
			qDebug() << "TreeWidgetHelper objToJsonObj unknown type " + strTypeName;
		}




	}


}
