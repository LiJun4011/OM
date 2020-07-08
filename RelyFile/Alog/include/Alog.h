#pragma once

#include "alog_global.h"
#include <QtCore\QCoreApplication>

class ALOG_EXPORT Alog :public QObject
{
	Q_OBJECT
public:
	Alog();
	~Alog();
	void initializeRootLogger();
	void shutdownRootLogger();
	void logStartup();
	void logShutdown();
	void setupRootLogger(const QString &introMessage);
	void shutDownRootLogger(const QString &extroMessage);

private:

};
