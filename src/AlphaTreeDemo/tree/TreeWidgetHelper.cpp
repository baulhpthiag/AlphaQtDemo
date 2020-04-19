#include "TreeWidgetHelper.h"
#include <QMetaProperty>
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>
#include <QMetaObject>

#include "BoolConfigNode.h"
#include "IntConfigNode.h"
#include "IntEnumConfigNode.h"
#include "DoubleConfigNode.h"
#include "DoubleEnumConfigNode.h"
#include "StringConfigNode.h"
#include "StringEnumConfigNode.h"

#include "BoolListConfigNode.h"
#include "IntListConfigNode.h"
#include "IntEnumListConfigNode.h"
#include "DoubleListConfigNode.h"
#include "DoubleEnumListConfigNode.h"
#include "StringListConfigNode.h"
#include "StringEnumListConfigNode.h"

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

		QString up = strKey.at(0).toUpper();
		QString tempMethod = "get" + up + strKey.mid(1) + "P";
		QByteArray byteArray = tempMethod.toLatin1();
		char * cp = byteArray.data();

		if ("bool" == strTypeName)
		{
			QTreeWidgetItem *tempItem = new QTreeWidgetItem(treeWidgetItem);
			tempItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			tempItem->setText(0, strKey);
			tempItem->setText(1, var.toString());
		}
		else if ("int" == strTypeName)
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
		else if ("QString" == strTypeName)
		{
			QTreeWidgetItem *tempItem = new QTreeWidgetItem(treeWidgetItem);
			tempItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			tempItem->setText(0, strKey);
			tempItem->setText(1, var.toString());
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
		else if ("QList<QString>" == strTypeName)
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
		//自定义结构
		else if ("BoolConfigNode" == strTypeName)
		{
			
			BoolConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(BoolConfigNode*, tempConfigNode));

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
		else if ("IntConfigNode" == strTypeName)
		{
			IntConfigNode* tempConfigNode = nullptr;
		
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(IntConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			tempLineEdit->setText(QString::number(tempConfigNode->_nodeValue));
			//信号

			connect(tempLineEdit, &QLineEdit::textChanged, tempConfigNode, &IntConfigNode::nodeValueChanged);

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempLineEdit);
		}
		else if ("IntEnumConfigNode" == strTypeName)
		{
			IntEnumConfigNode* tempConfigNode =nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(IntEnumConfigNode*, tempConfigNode));

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
		else if ("DoubleConfigNode" == strTypeName)
		{
			DoubleConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(DoubleConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);
			QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			tempLineEdit->setText(QString::number(tempConfigNode->_nodeValue));
			//信号

			connect(tempLineEdit, &QLineEdit::textChanged, tempConfigNode, &DoubleConfigNode::nodeValueChanged);

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempLineEdit);
		}
		else if ("DoubleEnumConfigNode" == strTypeName)
		{
			DoubleEnumConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(DoubleEnumConfigNode*, tempConfigNode));

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
		else if ("StringConfigNode" == strTypeName)
		{
			StringConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(StringConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
			tempLineEdit->setText(tempConfigNode->_nodeValue);
			//信号
			connect(tempLineEdit, &QLineEdit::textChanged, tempConfigNode, &StringConfigNode::nodeValueChanged);

			treeWidget->setItemWidget(tempTreeWidgetItem, 1, tempLineEdit);

		}
		else if ("StringEnumConfigNode" == strTypeName)
		{
			StringEnumConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(StringEnumConfigNode*, tempConfigNode));

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
		else if ("QList<BoolConfigNode>" == strTypeName)
		{
			QList<BoolConfigNode>* list = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(QList<BoolConfigNode>*, list));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, strKey);

			for (int j = 0; j < list->count(); j++)
			{
				BoolConfigNode tempConfigNode = list->at(j);

				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, tempConfigNode._nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				tempComboBox->addItem("false");
				tempComboBox->addItem("true");
				tempComboBox->setCurrentIndex(tempConfigNode._nodeValue ? 1 : 0);
				//信号

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);

			}

		}
		else if ("QList<IntConfigNode>" == strTypeName)
		{
			QList<IntConfigNode>* list = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(QList<IntConfigNode>*, list));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, strKey);

			for (int j = 0; j < list->count(); j++)
			{
				IntConfigNode tempConfigNode = list->at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, tempConfigNode._nodeShowName);

				QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
				tempLineEdit->setText(QString::number(tempConfigNode._nodeValue));
				//信号

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			}
		}
		else if ("QList<IntEnumConfigNode>" == strTypeName)
		{
			QList<IntEnumConfigNode>* list = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(QList<IntEnumConfigNode>*, list));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, strKey);
			for (int j = 0; j < list->count(); j++)
			{
				IntEnumConfigNode tempConfigNode = list->at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, tempConfigNode._nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				if (tempConfigNode._valueEnum.count() > 0)
				{
					for (int k = 0; k < tempConfigNode._valueEnum.count(); k++)
					{
						tempComboBox->addItem(QString::number(tempConfigNode._valueEnum[k]));
					}

					tempComboBox->setCurrentIndex(tempConfigNode._enumIndex);
				}
				//信号

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);

			}
		}
		else if ("QList<DoubleConfigNode>" == strTypeName)
		{
			QList<DoubleConfigNode>* list =nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(QList<DoubleConfigNode>*, list));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, strKey);

			for (int j = 0; j< list->count(); j++)
			{
				DoubleConfigNode tempConfigNode = list->at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, tempConfigNode._nodeShowName);
				QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
				tempLineEdit->setText(QString::number(tempConfigNode._nodeValue));
				//信号

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			}

		}
		else if ("QList<DoubleEnumConfigNode>" == strTypeName)
		{
			QList<DoubleEnumConfigNode>* list = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(QList<DoubleEnumConfigNode>*, list));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, strKey);

			for (int j = 0; j < list->count(); j++)
			{
				DoubleEnumConfigNode tempConfigNode = list->at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, tempConfigNode._nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				if (tempConfigNode._valueEnum.count() > 0)
				{
					for (int k = 0; k < tempConfigNode._valueEnum.count(); k++)
					{
						tempComboBox->addItem(QString::number(tempConfigNode._valueEnum[k]));
					}

					tempComboBox->setCurrentIndex(tempConfigNode._enumIndex);
				}
				//信号
				void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
				connect(tempComboBox, signal_currentIndexChanged, &tempConfigNode, &DoubleEnumConfigNode::nodeValueIndexChanged);
				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);

			}
		}
		else if ("QList<StringConfigNode>" == strTypeName)
		{
			QList<StringConfigNode>* list = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(QList<StringConfigNode>*, list));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, strKey);

			for (int j = 0; j < list->count(); j++)
			{
				StringConfigNode tempConfigNode = list->at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, tempConfigNode._nodeShowName);

				QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
				tempLineEdit->setText(tempConfigNode._nodeValue);
				//信号

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			}
		}
		else if ("QList<StringEnumConfigNode>" == strTypeName)
		{
			QList<StringEnumConfigNode>* list = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(QList<StringEnumConfigNode>*, list));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, strKey);
			for (int j = 0; j < list->count(); j++)
			{
				StringEnumConfigNode tempConfigNode = list->at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, tempConfigNode._nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				if (tempConfigNode._valueEnum.count() > 0)
				{
					for (int k = 0; k < tempConfigNode._valueEnum.count(); k++)
					{
						tempComboBox->addItem(tempConfigNode._valueEnum[k]);
					}

					tempComboBox->setCurrentIndex(tempConfigNode._enumIndex);
				}
				//信号

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);
			}
		}

		else if ("BoolListConfigNode" == strTypeName)
		{

			BoolListConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(BoolListConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QList<BoolConfigNode*> list =tempConfigNode->getNodeListP();

			for (int j = 0;j<list.count();j++)
			{
				BoolConfigNode* childTempConfigNode = list.at(j);

				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, childTempConfigNode->_nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				tempComboBox->addItem("false");
				tempComboBox->addItem("true");
				tempComboBox->setCurrentIndex(childTempConfigNode->_nodeValue ? 1 : 0);
				//信号

				void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
				//connect(tempComboBox, signal_currentIndexChanged, childTempConfigNode, &BoolConfigNode::nodeValueChanged);
				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);
			}


		}
		else if ("IntListConfigNode" == strTypeName)
		{

			IntListConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(IntListConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QList<IntConfigNode*> list = tempConfigNode->getNodeListP();

			for (int j = 0; j < list.count(); j++)
			{
				IntConfigNode* childTempConfigNode = list.at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, childTempConfigNode->_nodeShowName);

				QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
				tempLineEdit->setText(QString::number(childTempConfigNode->_nodeValue));
				//信号
				//connect(tempLineEdit, &QLineEdit::textChanged, childTempConfigNode, &IntConfigNode::nodeValueChanged);


				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			}


		}
		else if ("IntEnumListConfigNode" == strTypeName)
		{

			IntEnumListConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(IntEnumListConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QList<IntEnumConfigNode*> list = tempConfigNode->getNodeListP();

			for (int j = 0; j < list.count(); j++)
			{
				IntEnumConfigNode* childTempConfigNode = list.at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, childTempConfigNode->_nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				if (childTempConfigNode->_valueEnum.count() > 0)
				{
					for (int k = 0; k < childTempConfigNode->_valueEnum.count(); k++)
					{
						tempComboBox->addItem(QString::number(childTempConfigNode->_valueEnum[k]));
					}

					tempComboBox->setCurrentIndex(childTempConfigNode->_enumIndex);
				}
				//信号

				void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
				//connect(tempComboBox, signal_currentIndexChanged, childTempConfigNode, &IntEnumConfigNode::nodeValueIndexChanged);

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);
			}


		}
		else if ("DoubleListConfigNode" == strTypeName)
		{

			DoubleListConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(DoubleListConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QList<DoubleConfigNode*> list = tempConfigNode->getNodeListP();

			for (int j = 0; j < list.count(); j++)
			{
				DoubleConfigNode* childTempConfigNode = list.at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, childTempConfigNode->_nodeShowName);
				QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
				tempLineEdit->setText(QString::number(childTempConfigNode->_nodeValue));
				//信号
				//connect(tempLineEdit, &QLineEdit::textChanged, childTempConfigNode, &DoubleConfigNode::nodeValueChanged);

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			}


		}
		else if ("DoubleEnumListConfigNode" == strTypeName)
		{

			DoubleEnumListConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(DoubleEnumListConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QList<DoubleEnumConfigNode*> list = tempConfigNode->getNodeListP();

			for (int j = 0; j < list.count(); j++)
			{
				DoubleEnumConfigNode* childTempConfigNode = list.at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, childTempConfigNode->_nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				if (childTempConfigNode->_valueEnum.count() > 0)
				{
					for (int k = 0; k < childTempConfigNode->_valueEnum.count(); k++)
					{
						tempComboBox->addItem(QString::number(childTempConfigNode->_valueEnum[k]));
					}

					tempComboBox->setCurrentIndex(childTempConfigNode->_enumIndex);
				}
				//信号
				void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
				//connect(tempComboBox, signal_currentIndexChanged, childTempConfigNode, &DoubleEnumConfigNode::nodeValueIndexChanged);

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);
			}


		}
		else if ("StringListConfigNode" == strTypeName)
		{

			StringListConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(StringListConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QList<StringConfigNode*> list = tempConfigNode->getNodeListP();

			for (int j = 0; j < list.count(); j++)
			{
				StringConfigNode* childTempConfigNode = list.at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, childTempConfigNode->_nodeShowName);

				QLineEdit * tempLineEdit = new QLineEdit(treeWidget);
				tempLineEdit->setText(childTempConfigNode->_nodeValue);
				//信号
				//connect(tempLineEdit, &QLineEdit::textChanged, childTempConfigNode, &StringConfigNode::nodeValueChanged);

				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempLineEdit);
			}


		}
		else if ("StringEnumListConfigNode" == strTypeName)
		{

			StringEnumListConfigNode* tempConfigNode = nullptr;
			QMetaObject::invokeMethod(obj, cp, Q_RETURN_ARG(StringEnumListConfigNode*, tempConfigNode));

			QTreeWidgetItem *tempTreeWidgetItem = new QTreeWidgetItem(treeWidgetItem);
			tempTreeWidgetItem->setText(0, tempConfigNode->_nodeShowName);

			QList<StringEnumConfigNode*> list = tempConfigNode->getNodeListP();

			for (int j = 0; j < list.count(); j++)
			{
				StringEnumConfigNode* childTempConfigNode = list.at(j);
				QTreeWidgetItem *childTempTreeWidgetItem = new QTreeWidgetItem(tempTreeWidgetItem);
				childTempTreeWidgetItem->setText(0, childTempConfigNode->_nodeShowName);

				QComboBox *tempComboBox = new QComboBox(treeWidget);
				if (childTempConfigNode->_valueEnum.count() > 0)
				{
					for (int k = 0; k < childTempConfigNode->_valueEnum.count(); k++)
					{
						tempComboBox->addItem(childTempConfigNode->_valueEnum[k]);
					}

					tempComboBox->setCurrentIndex(childTempConfigNode->_enumIndex);
				}
				//信号
				void (QComboBox::*signal_currentIndexChanged)(int) = &QComboBox::currentIndexChanged;
				//connect(tempComboBox, signal_currentIndexChanged, childTempConfigNode, &StringEnumConfigNode::nodeValueIndexChanged);
				treeWidget->setItemWidget(childTempTreeWidgetItem, 1, tempComboBox);
			}


		}

		else if (strTypeName.contains("QList"))
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
