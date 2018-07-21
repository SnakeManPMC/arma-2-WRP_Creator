#include <QtWidgets>
#include "widget.h"
#include "ui_widget.h"
#include <qdatetime.h>

// snake
#include "wrp.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::WidgetClass)
{
	ui->setupUi(this);

	// create WRP data
	connect( ui->CreateWRP, SIGNAL( clicked() ), this, SLOT( CreateWRP() ) );

	// read xyz
	connect( ui->ReadXYZ, SIGNAL( clicked() ), this, SLOT( ReadXYZ() ) );

	// read random objects list
	connect( ui->ReadObjects, SIGNAL( clicked() ), this, SLOT( ReadObjects() ) );

	// create random objects
	//connect( ui->RandomObjects, SIGNAL( clicked() ), this, SLOT( CreateRandomObjects() ) );

	// save WRP file
	connect( ui->SaveWRP, SIGNAL( clicked() ), this, SLOT( SaveWRP() ) );

	// load texture bmp file
	connect( ui->TextureBMP, SIGNAL( clicked() ), this, SLOT( TextureBMP() ) );

	// import objects
	connect( ui->ImportObjects, SIGNAL( clicked() ), this, SLOT( ImportObjects() ) );
}

Widget::~Widget()
{
	delete ui;
}

void Widget::CreateWRP()
{
	// create elevations
	int x = 0, z = 0, gridsize = 0;

	QString str;
	str = ui->MapGridSize->text();
	bool ok;
	gridsize = str.toInt(&ok, 10);

	// create empty elevations
	for (int zx = 0; zx < gridsize * gridsize; zx++)
	{
		/*
		this was by default WrpTool accepted -50, however I assume we
		can do what ever we want here?
		*/
		wrp[x][z].Elevation = -300;

		x++;
		if (x == gridsize)
		{
			z++; x = 0;
		}
		if (z == gridsize)
		{
			z = 0;
		}
	}
	ui->textEdit_Status->append("Created elevations!");

	// create textures IDs
	x = 0;
	z = 0;

	for (int tx = 0; tx < gridsize * gridsize; tx++)
	{
		wrp[x][z].TexIndex = 0;

		x++;
		if (x == gridsize)
		{
			z++;
			x = 0;
		}
		if (z == gridsize)
		{
			z = 0;
		}
	}
	ui->textEdit_Status->append("Created texture indexes!");

	// textures 32 char length and total of 512
	//for (int ix = 0; ix < 512; ix++)
	//{
	//}

	ui->textEdit_Status->append("Created WRP!");
	ui->textEdit_Status->append( "Map Grid Size: " + QString::number(gridsize) );
	ui->textEdit_Status->append( "Map Cell Size: " + ui->MapCellSize->text() );
}

void Widget::ReadXYZ()
{
	QString fileName;

	fileName = QFileDialog::getOpenFileName(
		this,
		"Choose a XYZ file to open",
		QString::null,
		QString::null);

	if (fileName.isEmpty())
	return;
	else
	{
		QFile file(fileName);

		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::information(this, tr("Unable to open file"),
			file.errorString());
			return;
		}

		ui->textEdit_Status->append("Opened " + fileName + " file!");

		QTextStream in(&file);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			QStringList list;
			list = line.split(" ");

			QString str;
			str = list[0];
			bool ok;
			short xx = str.toInt(&ok, 10);
			str = list[1];
			short yy = str.toInt(&ok, 10);
			str = list[2];
			short zz = str.toInt(&ok, 10);

			// save the data to our struct!
			wrp[xx][yy].Elevation = zz;

			//ui->textEdit_Status->append("x: " + QString::number(xx) + " z: " + QString::number(yy) + " elevation: " + QString::number(zz));
		}

		// were done, close the file.
		file.close();
	}

	ui->textEdit_Status->append("Read XYZ file!");
}

void Widget::ReadObjects()
{
	ui->textEdit_Status->append("Reading random objects...");

	QString fileName;

	fileName = QFileDialog::getOpenFileName(
		this,
		"Choose a TXT file to open",
		QString::null,
		QString::null);

	if (fileName.isEmpty())
	return;
	else
	{
		QFile file(fileName);

		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::information(this, tr("Unable to open file"),
			file.errorString());
			return;
		}

		ui->textEdit_Status->append("Opened " + fileName + " file!");

		QTextStream in(&file);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			RandomObjectList.push_back(line);
			ui->textEdit_ReadObjects->append(line);
		}

		// were done, close the file.
		file.close();
	}
}


void Widget::SaveWRP()
{
	int x = 0, z = 0, gridsize = 0;
	QTime timmy(0, 0, 0);
	qsrand(timmy.secsTo(QTime::currentTime()));

	QString str;
	str = ui->MapGridSize->text();
	bool ok;
	gridsize = str.toInt(&ok, 10);

	str = ui->MapCellSize->text();
	int CellSize = str.toInt(&ok, 10);

	QString fileName;

	fileName = QFileDialog::getSaveFileName(
		this,
		"Save WRP file",
		QString::null,
		QString::null);

	QFile file(fileName);

	if (!file.open(QIODevice::WriteOnly))
	{
		QMessageBox::information(this, tr("Unable to open file for saving"),
		file.errorString());
		return;
	}
	// signature
	file.write("4WVR", 4);
	ui->textEdit_Status->append("Created " + fileName);
	ui->textEdit_Status->append("Signature: 4WVR");

	// grid size
	file.write((char*)&gridsize, sizeof(qint32));
	file.write((char*)&gridsize, sizeof(qint32));

	ui->textEdit_Status->append("Map Grid Size: " + QString::number(gridsize));

	// write elevations...
	for (int zx = 0; zx < gridsize * gridsize; zx++)
	{
		file.write((char*)&wrp[x][z].Elevation, sizeof(wrp[x][z].Elevation));

		x++;
		if (x == gridsize)
		{
			z++; x = 0;
		}
		if (z == gridsize)
		{
			z = 0;
		}
	}
	ui->textEdit_Status->append("Elevations done!");

	// write textures IDs
	x = 0;
	z = 0;

	for (int tx = 0; tx < gridsize * gridsize; tx++)
	{
		file.write((char*)&wrp[x][z].TexIndex, sizeof(wrp[x][z].TexIndex));

		x++;
		if (x == gridsize)
		{
			z++;
			x = 0;
		}
		if (z == gridsize)
		{
			z = 0;
		}
	}
	ui->textEdit_Status->append("Texture indexes done!");

	// textures 32 char length and total of 512
	// first texture is always the placeholder not used thingy.
	file.write("data\\more_anim.01.pac", 32);
	for (int ix = 1; ix < 512; ix++)
	{
		file.write("", 32);
	}
	ui->textEdit_Status->append("Texture names done!");

	// rotate the newly created object randomly.
	double pi = 3.1415926535;
	float Scale = 1;
	float stuff;

	QString str1;
	str1 = ui->MapLimit->text();
	int numOfObjects = str1.toInt(&ok, 10);
	int i = 0;
	int dObjIndex = 0;

	while (i < numOfObjects)
	{
		// rotation floats
		float YRotation = (qrand() % 360);

		stuff = (float)cos(YRotation/180*pi)*Scale;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = 0;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = (float)-sin(YRotation/180*pi)*Scale;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = 0;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = Scale;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = 0;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = (float)sin(YRotation/180*pi)*Scale;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = 0;
		file.write((char *)&stuff, sizeof (stuff));

		stuff = (float)cos(YRotation/180*pi)*Scale;
		file.write((char *)&stuff, sizeof (stuff));

		// x, y, z
		float dDirX = 1 + (float) (gridsize * CellSize * qrand() / (RAND_MAX + 1.0));
		float dDirZ = 1 + (float) (gridsize * CellSize * qrand() / (RAND_MAX + 1.0));
		float dDirY = 0;

		file.write((char *)&dDirX, sizeof (dDirX));
		file.write((char *)&dDirY, sizeof (dDirY));
		file.write((char *)&dDirZ, sizeof (dDirZ));

		// object index
		dObjIndex++;
		file.write((char *)&dObjIndex, sizeof (dObjIndex));

		// object name
		// add the 3d objects randomly
		int idx = qrand() % RandomObjectList.size();

		QString p3dname;
		p3dname.resize(76);
		p3dname = RandomObjectList[idx];

		// this doesnt work, writes garbage?
		file.write((char*)&p3dname, sizeof(p3dname));

		i++;
	}

	// close the saved wrp.
	file.close();
	ui->textEdit_Status->append("All done, file closed, WRP saved!");
}

void Widget::TextureBMP()
{
	QMessageBox::information(this, tr("Not implemented"), "This feature is not implemented yet, sorry.");
	ui->textEdit_Status->append("Texture BMP loading not implemented yet.");
}

void Widget::ImportObjects()
{
	QMessageBox::information(this, tr("Not implemented"), "This feature is not implemented yet, sorry.");
	ui->textEdit_Status->append("Import objects not implemented yet.");
}
