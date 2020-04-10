#include "mainwindow.h"
#include "customshadow.h"
#include "shadow.h"
#include <QPainter>
#include <QLinearGradient>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, m_paintHeight(1)
{
	ui.setupUi(this);

	m_customWindow = new CustomShadow(this);
	resize(m_customWindow->size() + QSize(20, 20));
	m_customWindow->hide();
	m_customWindow->move(10, 10);

	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	QPropertyAnimation *animation = new QPropertyAnimation(this, "paintheight");
	connect(animation, &QPropertyAnimation::finished, [this](){
		m_customWindow->show();
	});
	animation->setDuration(200);
	animation->setEasingCurve(QEasingCurve::InQuad);
	animation->setStartValue(1);
	animation->setEndValue(m_customWindow->height());
	animation->start(QAbstractAnimation::DeleteWhenStopped);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.setRenderHints(QPainter::Antialiasing, true);
	QImage image = m_customWindow->grab().toImage();

	int pWidth = image.width();
	int pHeight = image.height();

	p.drawImage(10, 10, image, 0, 0, pWidth, m_paintHeight);
	__super::paintEvent(event);
}
