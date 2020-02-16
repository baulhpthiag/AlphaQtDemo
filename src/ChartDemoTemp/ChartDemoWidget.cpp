#include "ChartDemoWidget.h"

ChartDemoWidget::ChartDemoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

void ChartDemoWidget::init()
{
	demoWidgets.clear();

	bottomWidgetLayout = new QVBoxLayout();
	ui.bottomWidget->setLayout(bottomWidgetLayout);
	bottomWidgetLayout->setSpacing(10);
	bottomWidgetLayout->setContentsMargins(0, 0, 0, 0);
	bottomWidgetLayout->setObjectName(QStringLiteral("bottomWidgetLayout"));

	chartDemo01Widget = new ChartDemo01Widget;
	bottomWidgetLayout->addWidget(chartDemo01Widget);
	bottomWidgetLayout->setStretch(0, 1);
	chartDemo01Widget->setVisible(false);
	ui.comboBox->addItem("ChartDemo01");
	demoWidgets.append(chartDemo01Widget);

	chartDemo02Widget = new ChartDemo02Widget;
	bottomWidgetLayout->addWidget(chartDemo02Widget);
	bottomWidgetLayout->setStretch(1, 1);
	chartDemo02Widget->setVisible(false);
	ui.comboBox->addItem("ChartDemo02");
	demoWidgets.append(chartDemo02Widget);

	comboBoxCurrentIndexChanged();
}

void ChartDemoWidget::comboBoxCurrentIndexChanged()
{
	int currentIndex = ui.comboBox->currentIndex();

	for (int i =0;i<demoWidgets.count();i++)
	{
		if (i==currentIndex)
		{
			demoWidgets.at(i)->setVisible(true);
		}
		else
		{
			demoWidgets.at(i)->setVisible(false);
		}
	}

}
