#include <levitics/arkhe/gcs/osgi/core/logger/LogViewBar.hpp>

#include <QPushButton>
#include <QHBoxLayout>

LogViewBar::LogViewBar(QWidget *parent)
    : QFrame(parent)
{
    QPushButton *b_trace = new QPushButton("Trace", this);
    QPushButton *b_debug = new QPushButton("Debug", this);
    QPushButton *b_info  = new QPushButton("Info", this);
    QPushButton *b_warn  = new QPushButton("Warn", this);
    QPushButton *b_error = new QPushButton("Error", this);
    QPushButton *b_fatal = new QPushButton("Fatal", this);

    b_trace->setCheckable(true);
    b_debug->setCheckable(true);
    b_info->setCheckable(true);
    b_warn->setCheckable(true);
    b_error->setCheckable(true);
    b_fatal->setCheckable(true);

    b_trace->setChecked(true);
    b_debug->setChecked(true);
    b_info->setChecked(true);
    b_warn->setChecked(true);
    b_error->setChecked(true);
    b_fatal->setChecked(true);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(b_trace);
    layout->addWidget(b_debug);
    layout->addWidget(b_info);
    layout->addWidget(b_warn);
    layout->addWidget(b_error);
    layout->addWidget(b_fatal);

    connect(b_trace, SIGNAL(clicked(bool)), this, SIGNAL(displayTrace(bool)));
    connect(b_debug, SIGNAL(clicked(bool)), this, SIGNAL(displayDebug(bool)));
    connect(b_info,  SIGNAL(clicked(bool)), this, SIGNAL(displayInfo(bool)));
    connect(b_warn,  SIGNAL(clicked(bool)), this, SIGNAL(displayWarn(bool)));
    connect(b_error, SIGNAL(clicked(bool)), this, SIGNAL(displayError(bool)));
    connect(b_fatal, SIGNAL(clicked(bool)), this, SIGNAL(displayFatal(bool)));
}

LogViewBar::~LogViewBar()
{

}
