#include "ThreadDemoMainWidget.h"
#include "ThreadDemo01Widget.h"
#include "ThreadDemo02Widget.h"

ThreadDemoMainWidget::ThreadDemoMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

ThreadDemoMainWidget::~ThreadDemoMainWidget()
{
	if (nullptr != bottomWidgetLayout)
	{
		delete bottomWidgetLayout;
		bottomWidgetLayout = nullptr;
	}

}

void ThreadDemoMainWidget::init()
{
	initMember();
}

void ThreadDemoMainWidget::initMember()
{
	demoWidgets.clear();

	bottomWidgetLayout = new QVBoxLayout;
	bottomWidgetLayout->setSpacing(10);
	bottomWidgetLayout->setContentsMargins(0, 0, 0, 0);
	bottomWidgetLayout->setObjectName(QStringLiteral("bottomWidgetLayout"));
	ui.bottomWidget->setLayout(bottomWidgetLayout);

	ThreadDemo01Widget * threadDemo01Widget = new ThreadDemo01Widget;
	threadDemo01Widget->setObjectName("threadDemo01Widget");
	demoWidgets.append(threadDemo01Widget);
	
	ThreadDemo02Widget * threadDemo02Widget = new ThreadDemo02Widget;
	threadDemo02Widget->setObjectName("threadDemo02Widget");
	demoWidgets.append(threadDemo02Widget);

	for (int i = 0; i < demoWidgets.count(); i++)
	{
		QWidget * widget = demoWidgets.at(i);
		widget->setVisible(false);

		bottomWidgetLayout->addWidget(demoWidgets.at(i));
		bottomWidgetLayout->setStretch(i, 1);
		
		ui.comboBox->addItem(widget->objectName());
	}


}

void ThreadDemoMainWidget::comboBoxCurrentIndexChanged()
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
