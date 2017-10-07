#ifndef ARKHE_CORE_SPLASHSCREEN_HPP
#define ARKHE_CORE_SPLASHSCREEN_HPP

#include <QSplashScreen>
#include <QPixmap>
#include <QtSvg>
#include <QPainter>

class QColor;
class QLabel;
class QProgressBar;

/*
QPixmap splashImage(":images/splash.png");
QPixmap splashMask(":images/splashmask.png");

customSplashScreen* splash = new customSplashScreen(splashImage);
splash->setMessageRect(QRect::QRect(7, 253, 415, 14), Qt::AlignCenter); // Setting the message position.

QFont splashFont;
splashFont.setFamily("Arial");
splashFont.setBold(true);
splashFont.setPixelSize(9);
splashFont.setStretch(125);

splash->setFont(splashFont);
splash->setMask(splashMask);
splash->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SplashScreen);
splash->show();

/ * To intercept mousclick to hide splash screen. Since the
splash screen is typically displayed before the event loop
has started running, it is necessary to periodically call. * /
app.processEvents();

splash->showStatusMessage(QObject::tr("Initializing…"));

/ * Some code here * /

app.processEvents();

splash->showStatusMessage(QObject::tr("Loading something…"));

*/

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(QWidget *parent = Q_NULLPTR ,Qt::WindowFlags f = Qt::WindowFlags() /*Qt::SplashScreen*/);
	SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f);
	virtual ~SplashScreen();
	
	void showStatusMessage(const QString &message, const QColor &color = Qt::black);
    void setMessageRect(QRect rect, int alignment = Qt::AlignLeft);
	
	void splashSVG(const int splashWidth = 600,const int splashHeight = 450);
	void progressBar();
	void setLabelTest(QString str);

public slots:
    void setProgress(int value);
	void splashFinish(QWidget *mainWin);
	// void showMessage(const QString &message, int alignment, const QColor &color);

protected:
    // void drawContents(QPainter *painter);
	virtual void drawContents(QPainter *painter);
    void paintEvent(QPaintEvent *event);
	void closeEvent(QCloseEvent *event);	
	
private:

    int m_width;
	int m_height;
    int m_percentage_done;
	int m_alignment;	
	QProgressBar * m_progressBar;
	QLabel *m_label;
    QPixmap pixmap;
    QString m_message;
    QColor m_color;
	QRect m_rect;

};

#endif
