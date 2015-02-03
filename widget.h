#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QtWidgets>

namespace Ui
{
	class WidgetClass;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	~Widget();

public slots:
	void CreateWRP();
	void ReadXYZ();
	void ReadObjects();
	void SaveWRP();
	void TextureBMP();
	void ImportObjects();

private:
	Ui::WidgetClass *ui;
	QVector<QString> RandomObjectList;
};

#endif // WIDGET_H
