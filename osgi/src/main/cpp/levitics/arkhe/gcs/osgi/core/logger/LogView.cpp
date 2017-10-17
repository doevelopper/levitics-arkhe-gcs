#include <levitics/arkhe/gcs/osgi/core/logger/private/LogViewPrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/logger/LogView.hpp>
#include<QVBoxLayout>
#include<QHBoxLayout>
LogView::LogView(QWidget *parent) 
: QWidget(parent)
, d(new LogViewPrivate)
{
    d->bar = new LogViewBar(this);
    d->tree = new LogViewTree(this);
	d->tree->setMaximumWidth(200);
    d->list = new LogViewList(this);

    d->autoScroll = new QCheckBox("Auto scroll", this);
    d->autoScroll->setTristate(false);

    QVBoxLayout *list_view_layout = new QVBoxLayout;
    list_view_layout->addWidget(d->autoScroll);
    list_view_layout->addWidget(d->list);

    QHBoxLayout *h_layout = new QHBoxLayout;
    h_layout->setContentsMargins(0, 0, 0, 0);
    h_layout->setSpacing(0);
    h_layout->addWidget(d->tree);
    h_layout->addLayout(list_view_layout);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(d->bar);
    layout->addLayout(h_layout);

     connect(d->tree, SIGNAL(runtimeClicked()), d->list, SLOT(setRuntime()));
     connect(d->tree, SIGNAL(fileClicked(const QString&)), d->list, SLOT(setFile(const QString&)));

     connect(d->autoScroll, SIGNAL(stateChanged(int)), this, SLOT(autoScrollChecked(int)));
     connect(d->list, SIGNAL(clicked(const QModelIndex&)), this, SLOT(disableAutoScroll()));
     connect(d->bar, SIGNAL(displayTrace(bool)), this, SLOT(displayTrace(bool)));
     connect(d->bar, SIGNAL(displayDebug(bool)), this, SLOT(displayDebug(bool)));
     connect(d->bar, SIGNAL(displayInfo(bool)),  this, SLOT(displayInfo(bool)));
     connect(d->bar, SIGNAL(displayWarn(bool)),  this, SLOT(displayWarn(bool)));
     connect(d->bar, SIGNAL(displayError(bool)), this, SLOT(displayError(bool)));
     connect(d->bar, SIGNAL(displayFatal(bool)), this, SLOT(displayFatal(bool)));

    d->autoScroll->setChecked(true);
}


LogView::~LogView(void)
{
    delete d;
    d = NULL;
}

void LogView::autoScrollChecked(int state)
{
    if(state == Qt::Unchecked)
	{
        this->disableAutoScroll();
	}
    else
	{
        this->enableAutoScroll();
	}
}

void LogView::disableAutoScroll(void)
{
    d->list->setAutoScroll(false);
    d->autoScroll->setChecked(false);
}

void LogView::enableAutoScroll(void)
{
    d->list->setAutoScroll(true);
    d->autoScroll->setChecked(true);
}

void LogView::displayTrace(bool display)
{
    if(!display)
	{
        d->exclude << "TRACE";
	}
    else
	{
        d->exclude.removeAll("TRACE");
	}

    d->list->setFilter(d->expression());
}

void LogView::displayDebug(bool display)
{
    if(!display)
        d->exclude << "DEBUG";
    else
        d->exclude.removeAll("DEBUG");

    d->list->setFilter(d->expression());
}

void LogView::displayInfo(bool display)
{
    if(!display)
        d->exclude << "INFO";
    else
        d->exclude.removeAll("INFO");

    d->list->setFilter(d->expression());
}

void LogView::displayWarn(bool display)
{
    if(!display)
        d->exclude << "WARN";
    else
        d->exclude.removeAll("WARN");

    d->list->setFilter(d->expression());
}

void LogView::displayError(bool display)
{
    if(!display)
        d->exclude << "ERROR";
    else
        d->exclude.removeAll("ERROR");

    d->list->setFilter(d->expression());
}

void LogView::displayFatal(bool display)
{
    if(!display)
        d->exclude << "FATAL";
    else
        d->exclude.removeAll("FATAL");

    d->list->setFilter(d->expression());
}
