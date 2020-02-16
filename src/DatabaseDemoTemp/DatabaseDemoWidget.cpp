#include "DatabaseDemoWidget.h"

DatabaseDemoWidget::DatabaseDemoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

void DatabaseDemoWidget::init()
{
	
	bottomWidgetLayout = new QVBoxLayout();
	ui.bottomWidget->setLayout(bottomWidgetLayout);
	bottomWidgetLayout->setSpacing(10);
	bottomWidgetLayout->setContentsMargins(0, 0, 0, 0);
	bottomWidgetLayout->setObjectName(QStringLiteral("bottomWidgetLayout"));
	//bottomWidgetLayout->setContentsMargins(0, 0, 0, 0);

	databaseDemo01Widget = new DatabaseDemo01Widget;
	bottomWidgetLayout->addWidget(databaseDemo01Widget);
	bottomWidgetLayout->setStretch(0, 1);
	databaseDemo01Widget->setVisible(true);

	databaseDemo02Widget = new DatabaseDemo02Widget;
	bottomWidgetLayout->addWidget(databaseDemo02Widget);
	bottomWidgetLayout->setStretch(1, 1);
	databaseDemo02Widget->setVisible(false);

	ui.comboBox->addItem("DatabaseDemo01");
	ui.comboBox->addItem("DatabaseDemo02");
}

void DatabaseDemoWidget::comboBoxCurrentIndexChanged()
{
	if (ui.comboBox->currentIndex() == 0)
	{
		databaseDemo01Widget->setVisible(true);
		databaseDemo02Widget->setVisible(false);
	}
	else
	{
		databaseDemo01Widget->setVisible(false);
		databaseDemo02Widget->setVisible(true);
	}

}
