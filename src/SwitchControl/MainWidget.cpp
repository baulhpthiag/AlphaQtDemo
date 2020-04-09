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


	// ����״̬����ʽ
	pGreenSwitchControl->setToggle(true);
	pGreenSwitchControl->setCheckedColor(QColor(0, 160, 230));
	pDisabledSwitchControl->setDisabled(true);
	pDisabledSwitchControl->setToggle(true);

	// �����źŲ�
	connect(pSwitchControl, SIGNAL(toggled(bool)), this, SLOT(onToggled(bool)));

}

void MainWidget::onToggled(bool bChecked)
{
	qDebug() << "State : " << bChecked;
}
