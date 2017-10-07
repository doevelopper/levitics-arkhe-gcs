
#include <levitics/osgi/core/workflow/private/WorkflowStepMockPrivate.hpp>

log4cxx::LoggerPtr WorkflowStepMockPrivate::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.private.WorkflowStepMockPrivate"));

WorkflowStepMockPrivate::WorkflowStepMockPrivate()
    :  m_numberOfTimesRanOnEntry (0)
       ,m_numberOfTimesRanOnExit( 0)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStepMockPrivate::~WorkflowStepMockPrivate()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int WorkflowStepMockPrivate::numberOfTimesRanOnEntry () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_numberOfTimesRanOnEntry );
}

void WorkflowStepMockPrivate::numberOfTimesRanOnEntry (int numberOfTimesRanOnEntry)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_numberOfTimesRanOnEntry = numberOfTimesRanOnEntry;
}

int WorkflowStepMockPrivate::numberOfTimesRanOnExit () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_numberOfTimesRanOnExit );
}

void WorkflowStepMockPrivate::numberOfTimesRanOnExit (int numberOfTimesRanOnExit)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_numberOfTimesRanOnExit = numberOfTimesRanOnExit;
}
