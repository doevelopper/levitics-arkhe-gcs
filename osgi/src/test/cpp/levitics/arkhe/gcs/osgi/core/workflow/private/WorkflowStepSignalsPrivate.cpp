
#include <levitics/osgi/core/workflow/private/WorkflowStepSignalsPrivate.hpp>

log4cxx::LoggerPtr WorkflowStepSignalsPrivate::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.private.WorkflowStepSignalsPrivate.Test"));

WorkflowStepSignalsPrivate::WorkflowStepSignalsPrivate()
    : m_numberOfTimesRanOnEntry(0)
      ,m_numberOfTimesRanOnExit(0)
      ,m_Step(Q_NULLPTR)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStepSignalsPrivate::~WorkflowStepSignalsPrivate()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int WorkflowStepSignalsPrivate::numberOfTimesRanOnEntry () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_numberOfTimesRanOnEntry );
}

void WorkflowStepSignalsPrivate::setNumberOfTimesRanOnEntry (int numberOfTimesRanOnEntry)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_numberOfTimesRanOnEntry = numberOfTimesRanOnEntry;
}

int WorkflowStepSignalsPrivate::numberOfTimesRanOnExit () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_numberOfTimesRanOnExit );
}

void WorkflowStepSignalsPrivate::setNumberOfTimesRanOnExit (int numberOfTimesRanOnExit)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_numberOfTimesRanOnExit = numberOfTimesRanOnExit;
}

WorkflowStep *
WorkflowStepSignalsPrivate::step () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_Step );
}

void
WorkflowStepSignalsPrivate::setStep (WorkflowStep * Step)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_Step = Step;
}
