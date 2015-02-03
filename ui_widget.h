/********************************************************************************
** Form generated from reading ui file 'widget.ui'
**
** Created: Sun Oct 18 23:03:06 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetClass
{
public:
    QPushButton *CreateWRP;
    QLineEdit *MapGridSize;
    QLabel *Label_MapGrid;
    QLabel *Label_MapCell;
    QLineEdit *MapCellSize;
    QPushButton *ReadXYZ;
    QPushButton *ReadObjects;
    QTextEdit *textEdit_ReadObjects;
    QPushButton *SaveWRP;
    QLineEdit *MapLimit;
    QLabel *Label_CellLimit;
    QLineEdit *CellLimit;
    QLabel *Label_MapLimit;
    QLabel *Label_HeightLimit;
    QLineEdit *HeightLimit;
    QPushButton *RandomObjects;
    QLineEdit *Offset;
    QLabel *Label_Factor;
    QLineEdit *Factor;
    QLabel *Label_Offset;
    QLabel *label_Status;
    QLabel *label_Objects;
    QPushButton *TextureBMP;
    QPushButton *ImportObjects;
    QTextEdit *textEdit_Status;

    void setupUi(QWidget *WidgetClass)
    {
        if (WidgetClass->objectName().isEmpty())
            WidgetClass->setObjectName(QString::fromUtf8("WidgetClass"));
        WidgetClass->resize(527, 514);
        CreateWRP = new QPushButton(WidgetClass);
        CreateWRP->setObjectName(QString::fromUtf8("CreateWRP"));
        CreateWRP->setGeometry(QRect(140, 30, 75, 24));
        MapGridSize = new QLineEdit(WidgetClass);
        MapGridSize->setObjectName(QString::fromUtf8("MapGridSize"));
        MapGridSize->setGeometry(QRect(80, 20, 41, 21));
        Label_MapGrid = new QLabel(WidgetClass);
        Label_MapGrid->setObjectName(QString::fromUtf8("Label_MapGrid"));
        Label_MapGrid->setGeometry(QRect(10, 20, 71, 16));
        Label_MapCell = new QLabel(WidgetClass);
        Label_MapCell->setObjectName(QString::fromUtf8("Label_MapCell"));
        Label_MapCell->setGeometry(QRect(10, 50, 71, 16));
        MapCellSize = new QLineEdit(WidgetClass);
        MapCellSize->setObjectName(QString::fromUtf8("MapCellSize"));
        MapCellSize->setGeometry(QRect(80, 50, 41, 21));
        ReadXYZ = new QPushButton(WidgetClass);
        ReadXYZ->setObjectName(QString::fromUtf8("ReadXYZ"));
        ReadXYZ->setGeometry(QRect(140, 100, 75, 24));
        ReadObjects = new QPushButton(WidgetClass);
        ReadObjects->setObjectName(QString::fromUtf8("ReadObjects"));
        ReadObjects->setGeometry(QRect(40, 180, 75, 24));
        textEdit_ReadObjects = new QTextEdit(WidgetClass);
        textEdit_ReadObjects->setObjectName(QString::fromUtf8("textEdit_ReadObjects"));
        textEdit_ReadObjects->setGeometry(QRect(10, 220, 271, 221));
        SaveWRP = new QPushButton(WidgetClass);
        SaveWRP->setObjectName(QString::fromUtf8("SaveWRP"));
        SaveWRP->setGeometry(QRect(30, 460, 75, 24));
        MapLimit = new QLineEdit(WidgetClass);
        MapLimit->setObjectName(QString::fromUtf8("MapLimit"));
        MapLimit->setGeometry(QRect(360, 220, 41, 21));
        Label_CellLimit = new QLabel(WidgetClass);
        Label_CellLimit->setObjectName(QString::fromUtf8("Label_CellLimit"));
        Label_CellLimit->setGeometry(QRect(290, 250, 51, 16));
        CellLimit = new QLineEdit(WidgetClass);
        CellLimit->setObjectName(QString::fromUtf8("CellLimit"));
        CellLimit->setGeometry(QRect(360, 250, 41, 21));
        Label_MapLimit = new QLabel(WidgetClass);
        Label_MapLimit->setObjectName(QString::fromUtf8("Label_MapLimit"));
        Label_MapLimit->setGeometry(QRect(290, 220, 51, 20));
        Label_HeightLimit = new QLabel(WidgetClass);
        Label_HeightLimit->setObjectName(QString::fromUtf8("Label_HeightLimit"));
        Label_HeightLimit->setGeometry(QRect(290, 280, 61, 16));
        HeightLimit = new QLineEdit(WidgetClass);
        HeightLimit->setObjectName(QString::fromUtf8("HeightLimit"));
        HeightLimit->setGeometry(QRect(360, 280, 41, 21));
        RandomObjects = new QPushButton(WidgetClass);
        RandomObjects->setObjectName(QString::fromUtf8("RandomObjects"));
        RandomObjects->setGeometry(QRect(420, 210, 91, 24));
        Offset = new QLineEdit(WidgetClass);
        Offset->setObjectName(QString::fromUtf8("Offset"));
        Offset->setGeometry(QRect(80, 120, 41, 21));
        Label_Factor = new QLabel(WidgetClass);
        Label_Factor->setObjectName(QString::fromUtf8("Label_Factor"));
        Label_Factor->setGeometry(QRect(10, 90, 71, 16));
        Factor = new QLineEdit(WidgetClass);
        Factor->setObjectName(QString::fromUtf8("Factor"));
        Factor->setGeometry(QRect(80, 90, 41, 21));
        Label_Offset = new QLabel(WidgetClass);
        Label_Offset->setObjectName(QString::fromUtf8("Label_Offset"));
        Label_Offset->setGeometry(QRect(10, 120, 71, 16));
        label_Status = new QLabel(WidgetClass);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setGeometry(QRect(20, 490, 46, 20));
        label_Objects = new QLabel(WidgetClass);
        label_Objects->setObjectName(QString::fromUtf8("label_Objects"));
        label_Objects->setGeometry(QRect(300, 490, 46, 21));
        TextureBMP = new QPushButton(WidgetClass);
        TextureBMP->setObjectName(QString::fromUtf8("TextureBMP"));
        TextureBMP->setGeometry(QRect(270, 150, 75, 24));
        ImportObjects = new QPushButton(WidgetClass);
        ImportObjects->setObjectName(QString::fromUtf8("ImportObjects"));
        ImportObjects->setGeometry(QRect(370, 150, 91, 24));
        textEdit_Status = new QTextEdit(WidgetClass);
        textEdit_Status->setObjectName(QString::fromUtf8("textEdit_Status"));
        textEdit_Status->setGeometry(QRect(293, 313, 221, 171));

        retranslateUi(WidgetClass);

        QMetaObject::connectSlotsByName(WidgetClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetClass)
    {
        WidgetClass->setWindowTitle(QApplication::translate("WidgetClass", "WRP Creator", 0));
        CreateWRP->setText(QApplication::translate("WidgetClass", "Create WRP", 0));
        MapGridSize->setText(QApplication::translate("WidgetClass", "32", 0));
        Label_MapGrid->setText(QApplication::translate("WidgetClass", "Map Grid size", 0));
        Label_MapCell->setText(QApplication::translate("WidgetClass", "Map Cell size", 0));
        MapCellSize->setText(QApplication::translate("WidgetClass", "50", 0));
        ReadXYZ->setText(QApplication::translate("WidgetClass", "Read XYZ", 0));
        ReadObjects->setText(QApplication::translate("WidgetClass", "Read objects", 0));
        SaveWRP->setText(QApplication::translate("WidgetClass", "Save WRP", 0));
        MapLimit->setText(QApplication::translate("WidgetClass", "1000", 0));
        Label_CellLimit->setText(QApplication::translate("WidgetClass", "Cell Limit", 0));
        CellLimit->setText(QApplication::translate("WidgetClass", "50", 0));
        Label_MapLimit->setText(QApplication::translate("WidgetClass", "Map Limit", 0));
        Label_HeightLimit->setText(QApplication::translate("WidgetClass", "Height Limit", 0));
        HeightLimit->setText(QApplication::translate("WidgetClass", "6", 0));
        RandomObjects->setText(QApplication::translate("WidgetClass", "Random Objects", 0));
        Offset->setText(QApplication::translate("WidgetClass", "0", 0));
        Label_Factor->setText(QApplication::translate("WidgetClass", "Factor", 0));
        Factor->setText(QApplication::translate("WidgetClass", "22", 0));
        Label_Offset->setText(QApplication::translate("WidgetClass", "Offset", 0));
        label_Status->setText(QApplication::translate("WidgetClass", "Status:", 0));
        label_Objects->setText(QApplication::translate("WidgetClass", "Objects:", 0));
        TextureBMP->setText(QApplication::translate("WidgetClass", "Texture BMP", 0));
        ImportObjects->setText(QApplication::translate("WidgetClass", "Import Objects", 0));
        Q_UNUSED(WidgetClass);
    } // retranslateUi

};

namespace Ui {
    class WidgetClass: public Ui_WidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
