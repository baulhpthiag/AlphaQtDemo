#include "CustomWindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QFile>

CustomWindow::CustomWindow(QWidget *parent)
    : QWidget(parent)
{
	// FramelessWindowHint�������ô���ȥ���߿�;
	// WindowMinimizeButtonHint ���������ڴ�����С��ʱ��������������ڿ�����ʾ��ԭ����;
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	// ���ô��ڱ���͸��;
	// ��ʼ��������;
	setAttribute(Qt::WA_TranslucentBackground);
	initTitleBar();
}

CustomWindow::~CustomWindow()
{

}

void CustomWindow::initTitleBar()
{
    m_titleBar = new CustomTitleBar(this);
	m_titleBar->move(0, 0);
	
	connect(m_titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
	connect(m_titleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
	connect(m_titleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

}

void CustomWindow::paintEvent(QPaintEvent* event)
{
	// 	Q_UNUSED(event);
	// 	QStyleOption opt;
	// 	opt.init(this);
	// 	QPainter painter(this);
	// 	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

	//���ñ���ɫ;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillPath(pathBack, QBrush(QColor(215, 221, 228)));

	return QWidget::paintEvent(event);
}

void CustomWindow::loadStyleSheet(const QString &sheetName)
{
	QFile file(":/Resources/" + sheetName + ".css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
}

void CustomWindow::onButtonMinClicked()
{
	if (Qt::Tool == (windowFlags() & Qt::Tool))
	{
		hide();    //������Qt::Tool �������showMinimized()�򴰿ھ������ˣ�����
	}
	else
	{
		showMinimized();
	}
}

void CustomWindow::onButtonRestoreClicked()
{
	QPoint windowPos;
	QSize windowSize;
	m_titleBar->getRestoreInfo(windowPos, windowSize);
	this->setGeometry(QRect(windowPos, windowSize));
}

void CustomWindow::onButtonMaxClicked()
{
	m_titleBar->saveRestoreInfo(this->pos(), QSize(this->width(), this->height()));
	QRect desktopRect = QApplication::desktop()->availableGeometry();
	QRect FactRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3, desktopRect.width() + 6, desktopRect.height() + 6);
	setGeometry(FactRect);
}

void CustomWindow::onButtonCloseClicked()
{
	close();
}