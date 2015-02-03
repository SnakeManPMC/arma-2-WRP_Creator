#ifndef WRP_H
#define WRP_H

typedef struct
{
	short Elevation;
	short TexIndex;
} wrpformat[4096][4096];

static wrpformat wrp;

// array where to store our random objects
//QList<QString> RandomObjectList;

#endif // WRP_H
