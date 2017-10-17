#include <QFile>
#include <levitics/arkhe/gcs/osgi/core/logger/LogViewList.hpp>
#include <levitics/arkhe/gcs/osgi/core/logger/LogModel.hpp>
LogViewList::LogViewList(QWidget *parent)
    : QListView(parent)
{
    this->m_model = new LogModel(this);

    this->m_proxy = new QSortFilterProxyModel(this);
    this->m_proxy->setFilterKeyColumn(0);

    this->setModel(this->m_proxy);

    this->setAlternatingRowColors(true);
    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setFrameShape(QFrame::NoFrame);
    this->setRuntime();
}

LogViewList::~LogViewList(void)
{
    qDeleteAll(this->m_models);
}

void LogViewList::setAutoScroll(bool autoScroll)
{
    if(autoScroll)
    {
        connect(this->m_model, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SLOT(scrollToBottom()));
    }
    else
    {
        disconnect(this->m_model, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SLOT(scrollToBottom()));
    }
}

void
LogViewList::setRuntime(void)
{
//    Logger::instance().attachModel(this->model);

//    this->m_proxy->setSourceModel(this->model);
}

void
LogViewList::setFile(const QString& path)
{
    if (this->m_models.contains(path))
    {
        this->m_models.remove(path);
    }

    QFile file(path);

    if(!file.open(QFile::ReadOnly))
    {
        //qDebug() << "Unable to read file" << path;
    }

    QString contents = file.readAll();

    file.close();

    QStringListModel *model = new QStringListModel(contents.split("\n"));

    this->m_proxy->setSourceModel(this->m_model);

//    this->m_models.insert(path, this->m_model);

    // QFileSystemWatcher *watcher = new QFileSystemWatcher(QStringList() << path, this);

    // connect(watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(setFile(const QString&)));
}

void
LogViewList::setFilter(const QRegExp& expression)
{
    this->m_proxy->setFilterRegExp(expression);
}

