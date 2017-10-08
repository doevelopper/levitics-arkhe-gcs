
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowIntrastepTransitionEvent.hpp>

log4cxx::LoggerPtr WorkflowIntrastepTransitionEvent::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.WorkflowIntrastepTransitionEvent"));

WorkflowIntrastepTransitionEvent::WorkflowIntrastepTransitionEvent()
    : QEvent(QEvent::Type(QEvent::registerEventType(QEvent::None)))
      ,m_eventTransitionType(0)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowIntrastepTransitionEvent::WorkflowIntrastepTransitionEvent (int newTransitionType)
    : QEvent(QEvent::Type(getWorkflowIntrastepTransitionEventType ()))
      ,m_eventTransitionType(newTransitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowIntrastepTransitionEvent::~WorkflowIntrastepTransitionEvent()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int WorkflowIntrastepTransitionEvent::getWorkflowIntrastepTransitionEventType ()
{
    static int workflowIntrastepTransitionEventType = QEvent::registerEventType(QEvent::User + 1);

    return workflowIntrastepTransitionEventType;
}

int
WorkflowIntrastepTransitionEvent::eventTransitionType () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_eventTransitionType;
}

void WorkflowIntrastepTransitionEvent::eventTransitionType (int evtTransitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_eventTransitionType = evtTransitionType;
}
