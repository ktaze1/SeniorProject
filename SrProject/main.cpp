#include "mainwindow.h"
#include <QNetworkConfigurationManager>
#include <QSettings>
#include <QNetworkSession>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QNetworkConfigurationManager manager;
	if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
		// Get saved network configuration
		QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
		settings.beginGroup(QLatin1String("QtNetwork"));
		const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
		settings.endGroup();

		// If the saved network configuration is not currently discovered use the system default
		QNetworkConfiguration config = manager.configurationFromIdentifier(id);
		if ((config.state() & QNetworkConfiguration::Discovered) !=
			QNetworkConfiguration::Discovered) {
			config = manager.defaultConfiguration();
		}

		QNetworkSession *networkSession = new QNetworkSession(config, &a);
		networkSession->open();
		networkSession->waitForOpened();

		if (networkSession->isOpen()) {
			// Save the used configuration
			QNetworkConfiguration config = networkSession->configuration();
			QString id;
			if (config.type() == QNetworkConfiguration::UserChoice) {
				id = networkSession->sessionProperty(
						QLatin1String("UserChoiceConfiguration")).toString();
			} else {
				id = config.identifier();
			}

			QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
			settings.beginGroup(QLatin1String("QtNetwork"));
			settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
			settings.endGroup();
		}
	}
	MainWindow w;
	w.setWindowTitle("Code Editor");
	w.show();

	return a.exec();
}
