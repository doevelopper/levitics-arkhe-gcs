
#include <core/workflow/WorkflowInterstepTransitionEvent.hpp>

log4cxx::LoggerPtr WorkflowInterstepTransitionEvent::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.WorkflowInterstepTransitionEvent"));

WorkflowInterstepTransitionEvent::WorkflowInterstepTransitionEvent()
    : QEvent(QEvent::Type( QEvent::registerEventType(QEvent::None)))
      ,m_eventTransitionType(0)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowInterstepTransitionEvent::WorkflowInterstepTransitionEvent(int newTransitionType)
    : QEvent(QEvent::Type( QEvent::registerEventType(QEvent::User + 1)))
      ,m_eventTransitionType(newTransitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowInterstepTransitionEvent::~WorkflowInterstepTransitionEvent()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int
WorkflowInterstepTransitionEvent::eventTransitionType () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_eventTransitionType );
}

void
WorkflowInterstepTransitionEvent::eventTransitionType (int evtTransitiontype)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_eventTransitionType = evtTransitiontype;
}

QString
WorkflowInterstepTransitionEvent::eventId () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_eventId );
}

void
WorkflowInterstepTransitionEvent::eventId (QString evtID)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_eventId = evtID;
}
