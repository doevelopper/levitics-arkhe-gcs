#include <arkhe/core/SplashScreen.hpp>
#include <QProgressBar>
#include <QPainter>
// #include <QStyleOptionProgressBarV2>

SplashScreen::SplashScreen(QWidget *parent, Qt::WindowFlags f) 
: QSplashScreen(parent)
, m_percentage_done(0)
, m_alignment(0)

{
    m_width = 480;
    m_height = 380;

	float fontFactor = 1.0;
    int paddingLeftCol2 = 230;
	int paddingTopCol2 = 376;
	
    QString titleText = QString(QApplication::applicationName()).replace(QString("-testnet"), QString(""), Qt::CaseSensitive); // cut of testnet, place it as single object further down
    QString versionText = "QString";//("Version %1 ").arg(QString::fromStdString(FormatFullVersion()));
    QString copyrightText1 = QChar(0xA9)+QString(" 2015-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The GCS  developers"));
    QString copyrightText2 = QChar(0xA9)+QString(" 2016-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The GCS developers"));
	QString copyrightText3 = QChar(0xA9)+QString(" 2017-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The ARKHE GCS  developers"));

    QString font = "Monospace";
	QFont   oFont = QFont(font, 9*fontFactor, QFont::Bold);
	oFont.setStyleHint(QFont::TypeWriter);

	
	
	QPixmap pixmap = QPixmap(":/images/splashscreen.png");
	QPainter pixmapPaint(&pixmap);
	pixmapPaint.setPen(QColor(70,70,70));
	
    pixmapPaint.setFont(QFont(font, 9*fontFactor));
    pixmapPaint.drawText(paddingLeftCol2,paddingTopCol2+26,versionText);
	pixmapPaint.setPen(QPen(Qt::white));
    // pixmapPaint.setFont(QFont(oFont, 9*fontFactor));
	////pixmapPaint.setFont(QFont("Arial", 12, QFont::Black));
    // pixmapPaint.drawText(paddingLeftCol2,paddingTopCol2+0,copyrightText1);
    // pixmapPaint.drawText(paddingLeftCol2,paddingTopCol2+13,copyrightText2);
	// pixmapPaint.drawText(paddingLeftCol2,paddingTopCol2+line3,copyrightText3)
	// pixmapPaint.end();
	
    // this->setPixmap(pixmapPaint);
    // this->setCursor(Qt::BusyCursor);

    // QFont font;
    // font.setPointSize(10);
    // font.setBold(false);
    // this->setFont(font);
}

SplashScreen::SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f)
: QSplashScreen(pixmap, f)
{
	QSplashScreen::setPixmap(pixmap);
}

SplashScreen::~SplashScreen()
{
	delete m_progressBar;
}

void SplashScreen::setProgress(int value)
{
    m_percentage_done = value;
    if (m_percentage_done > 100)
        m_percentage_done = 100;
    if (m_percentage_done < 0)
        m_percentage_done = 0;
    update();
	// progress = value;
	// repaint();
	// QCoreApplication::instance()->processEvents();
    m_progressBar->setValue(value);
}

void SplashScreen::splashFinish(QWidget *mainWin)
{
	
}

void SplashScreen::setMessageRect(QRect rect, int alignement)
{
    this->m_rect = rect;
    this->m_alignment = alignement;
};

// void SplashScreen::showMessage(const QString &message, int alignment, const QColor &color)
// {
	
// }
	
void SplashScreen::splashSVG(const int splashWidth,const int splashHeight)
{
	// QCoreApplication::instance()->processEvents();
	static const QString filename(":/res/images/UAV Forge Logo 2015.svg");
	
	QSvgRenderer svg(filename);//Construct and load the SVG image
	QSize SplashSize = svg.viewBox().size();//Calculate the scaled size within a bounded size
	SplashSize.scale(splashWidth, splashHeight, Qt::KeepAspectRatio);
	QPixmap pixmap(SplashSize);
	pixmap.fill(Qt::white);
	QPainter painter(&pixmap);
	svg.render(&painter, pixmap.rect());
	// QSplashScreen splash(pixmap);
	// splash.show();
	
	 // splash.finish(&mainWindow);

}

void SplashScreen::progressBar()
{
	m_progressBar = new QProgressBar(this);
	m_progressBar->setGeometry(1,this->height()-23,this->width()-2,23);
	m_progressBar->setRange(0, 100);
	m_progressBar->setValue(0);
	m_progressBar->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	// m_progressBar->setTextVisible(false);
	m_progressBar->setStyleSheet("QProgressBar{border: 2px solid rgb(216,216,218); border-radius: 4px; text-align:center; background:rgb(50, 50, 50);}"
                                "QProgressBar::chunk {background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a); border-radius: 3px;}");
	connect(m_progressBar, & QProgressBar::valueChanged, [this]() {repaint();});
	
	// mLabel = new QLabel(this);
    // mLabel->setGeometry(1,this->height()-23,this->width()-2,23);
    // mLabel->setStyleSheet("color:rgb(235,235,235)");
	// mLabel->setAlignment(Qt::AlignCenter);
}
	

void SplashScreen::setLabelTest(QString str)
{
    // mLabel->setText(str);
	// repaint();
	QCoreApplication::instance()->processEvents();
}
	
void SplashScreen::drawContents(QPainter *painter)
{
    QPixmap textPix = QSplashScreen::pixmap();
    painter->setPen(this->m_color);
    painter->drawText(this->m_rect, this->m_alignment, this->m_message);
	
    // QSplashScreen::drawContents(painter);

    // QRect textRect( 15.0, m_height-40, 100, 30);

    // QString versionText = "QString";//("version ").append(GUIHelpers::getBornAgainVersionString());
    // style()->drawItemText(painter, textRect, 0, this->palette(), true, versionText);

    // QString loadingText("loading . ");
    // for(size_t i=0; i<size_t(m_percentage_done/20); ++i) 
	// {
        // loadingText.append(". ");
    // }

    // QRect loadingRect( 380.0, m_height-40, 100, 30);
    // style()->drawItemText(painter, loadingRect, 0, this->palette(), true, loadingText);

}

void SplashScreen::showStatusMessage(const QString &message, const QColor &color)
{
    this->m_message = message;
    this->m_color = color;
    this->showMessage(this->m_message, this->m_alignment, this->m_color);
};


void SplashScreen::paintEvent(QPaintEvent *event)
{
	
}

void SplashScreen::closeEvent(QCloseEvent *event)
{
	
}