#include "JsonDemoWidget.h"

JsonDemoWidget::JsonDemoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

void JsonDemoWidget::init()
{
	demoWidgets.clear();

	bottomWidgetLayout = new QVBoxLayout();
	ui.bottomWidget->setLayout(bottomWidgetLayout);
	bottomWidgetLayout->setSpacing(10);
	bottomWidgetLayout->setContentsMargins(0, 0, 0, 0);
	bottomWidgetLayout->setObjectName(QStringLiteral("bottomWidgetLayout"));

	jsonDemo01Widget = new JsonDemo01Widget;
	bottomWidgetLayout->addWidget(jsonDemo01Widget);
	bottomWidgetLayout->setStretch(0, 1);
	jsonDemo01Widget->setVisible(false);
	ui.comboBox->addItem("JsonDemo01");
	demoWidgets.append(jsonDemo01Widget);

	jsonDemo02Widget = new JsonDemo02Widget;
	bottomWidgetLayout->addWidget(jsonDemo02Widget);
	bottomWidgetLayout->setStretch(1, 1);
	jsonDemo02Widget->setVisible(false);
	ui.comboBox->addItem("JsonDemo02");
	demoWidgets.append(jsonDemo02Widget);

	jsonDemo03Widget = new JsonDemo03Widget;
	bottomWidgetLayout->addWidget(jsonDemo03Widget);
	bottomWidgetLayout->setStretch(2, 1);
	jsonDemo03Widget->setVisible(false);
	ui.comboBox->addItem("JsonDemo03");
	demoWidgets.append(jsonDemo03Widget);


	comboBoxCurrentIndexChanged();

}

void JsonDemoWidget::comboBoxCurrentIndexChanged()
{
	int currentIndex = ui.comboBox->currentIndex();

	for (int i = 0; i < demoWidgets.count(); i++)
	{
		if (i == currentIndex)
		{
			demoWidgets.at(i)->setVisible(true);
		}
		else
		{
			demoWidgets.at(i)->setVisible(false);
		}
	}
}
