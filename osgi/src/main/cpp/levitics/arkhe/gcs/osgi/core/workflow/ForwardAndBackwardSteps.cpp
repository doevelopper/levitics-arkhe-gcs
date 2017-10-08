
#include <QDebug>
#include <iostream>

#include <levitics/arkhe/gcs/osgi/core/workflow/ForwardAndBackwardSteps.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStep.hpp>

log4cxx::LoggerPtr ForwardAndBackwardSteps::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.ForwardAndBackwardSteps"));

ForwardAndBackwardSteps::ForwardAndBackwardSteps()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ForwardAndBackwardSteps::~ForwardAndBackwardSteps()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QList<WorkflowStep *>
ForwardAndBackwardSteps::forwardSteps () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_forwardSteps );
}

void
ForwardAndBackwardSteps::setForwardSteps (const QList<WorkflowStep *> & forwardSteps)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_forwardSteps = forwardSteps;
}

QList<WorkflowStep *>
ForwardAndBackwardSteps::backwardSteps () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_backwardSteps );
}

void
ForwardAndBackwardSteps::setBackwardSteps (const QList<WorkflowStep *> & backwardSteps)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_backwardSteps = backwardSteps;
}

QList<QString>
ForwardAndBackwardSteps::forwardBranchIds () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_forwardBranchIds );
}

void
ForwardAndBackwardSteps::setForwardBranchIds (const QList<QString> & forwardBranchIds)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_forwardBranchIds = forwardBranchIds;
}

QList<QString>
ForwardAndBackwardSteps::backwardBranchIds () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_backwardBranchIds );
}

void
ForwardAndBackwardSteps::setBackwardBranchIds (const QList<QString> & backwardBranchIds)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_backwardBranchIds = backwardBranchIds;
}

QString
ForwardAndBackwardSteps::forwardBranchId (WorkflowStep * step)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    int index = this->forwardSteps().indexOf(step);

    if( index != -1 )
    {
        return ( this->forwardBranchIds().at(index) );
    }
    else
    {
        return ( QString() );
    }
}

QString
ForwardAndBackwardSteps::backwardBranchId (WorkflowStep * step)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    int index = this->backwardSteps().indexOf(step);

    if( index != -1 )
    {
        return ( this->backwardBranchIds().at(index) );
    }
    else
    {
        return ( QString() );
    }
}

WorkflowStep *
ForwardAndBackwardSteps::forwardStep (QString branchId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    int index = this->forwardBranchIds().indexOf(branchId);

    if( index != -1 )
    {
        return ( forwardSteps().at(index) );
    }
    else
    {
        return ( Q_NULLPTR );
    }
}

QString
ForwardAndBackwardSteps::firstForwardBranchId ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    if( this->forwardBranchIds().isEmpty() )
    {
        return ( QString() );
    }
    else
    {
        return ( this->forwardBranchIds().first() );
    }
}

void
ForwardAndBackwardSteps::appendBackwardStep (WorkflowStep * step, QString id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    this->backwardSteps().append(step);
    this->backwardBranchIds().append(id);
}

void
ForwardAndBackwardSteps::appendForwardStep (WorkflowStep * step, QString id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    this->forwardSteps().append(step);
    this->forwardBranchIds().append(id);
}
