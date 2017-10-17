#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEWTREE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEWTREE_HPP

#include <QTreeWidget>

class LogViewTree : public QTreeWidget
{
    Q_OBJECT
public:
    LogViewTree(QWidget *parent = Q_NULLPTR);
    ~LogViewTree();

signals:
    void runtimeClicked(void);
    void fileClicked(const QString& path);

protected slots:
    void onItemClicked(QTreeWidgetItem *, int);

private:
    QTreeWidgetItem *runtime;
    QTreeWidgetItem *file;
};

#endif

