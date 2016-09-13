#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controlpanel.h"
#include "item.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void NewGame();

	void DrawChessAtPoint(QPainter& painter,QPoint& pt);

	void DrawBKRects();
	void DrawFixedRects();
	void DrawCurItem();

	void SetSpeed(int n);

	bool HitSide();
	bool HitBottom();
	bool HitTop();
	void AddToFixedRects();

	void DeleteFullRows();
protected:
	void paintEvent(QPaintEvent *);
	void timerEvent(QTimerEvent*);
	void resizeEvent(QResizeEvent *);

	void keyPressEvent(QKeyEvent *);

public slots:
	void Btn1Clicked();
	void Btn2Clicked();

private:
    Ui::MainWindow *ui;

	ControlPanel* m_ControlPanel;

	QVector<QPoint> m_BolderItems;
	//QVector<QPoint> m_FixedItems;
	//QVector<QPoint> m_CurItem;		//��ǰ�Item
	//QVector<QPoint> m_NextItem;
	Item m_FixedItems;
	Item m_CurItem;
	Item m_NextItem;

	int m_nTimerId;
	int m_nSpeed;

	int m_nScore;
	int m_nLevel;
	//int m_nLevelScore;
};

#endif // MAINWINDOW_H
