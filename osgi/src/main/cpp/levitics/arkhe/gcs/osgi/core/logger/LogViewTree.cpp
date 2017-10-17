#include <levitics/arkhe/gcs/osgi/core/logger/LogViewTree.hpp>

LogViewTree::LogViewTree(QWidget *parent)
: QTreeWidget(parent)
{

}

LogViewTree::~LogViewTree(void)
{

}

void LogViewTree::onItemClicked(QTreeWidgetItem *item, int)
{
    if (item == this->runtime)
    {
        emit runtimeClicked();
    }
    else if (item == this->file)
    {
        ;
    }
    else
    {
        emit fileClicked(item->text(0));
    }
}

