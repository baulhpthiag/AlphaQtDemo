#include "MainWidget.h"
#include "SwitchControl.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	SwitchControl *pSwitchControl = new SwitchControl(this);
	pSwitchControl->move(100, 100);

	SwitchControl *pGreenSwitchControl = new SwitchControl(this);
	pGreenSwitchControl->move(100, 150);

	SwitchControl *pDisabledSwitchControl = new SwitchControl(this);
	pDisabledSwitchControl->move(100, 200);


	// 设置状态、样式
	pGreenSwitchControl->setToggle(true);
	pGreenSwitchControl->setCheckedColor(QColor(0, 160, 230));
	pDisabledSwitchControl->setDisabled(true);
	pDisabledSwitchControl->setToggle(true);

	// 连接信号槽
	connect(pSwitchControl, SIGNAL(toggled(bool)), this, SLOT(onToggled(bool)));

}

void MainWidget::onToggled(bool bChecked)
{
	qDebug() << "State : " << bChecked;
}
