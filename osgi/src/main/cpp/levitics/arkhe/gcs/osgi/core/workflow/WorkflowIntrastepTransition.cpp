
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowIntrastepTransition.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowIntrastepTransitionEvent.hpp>

log4cxx::LoggerPtr WorkflowIntrastepTransition::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.WorkflowIntrastepTransition"));

WorkflowIntrastepTransition::WorkflowIntrastepTransition()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowIntrastepTransition::WorkflowIntrastepTransition(
    WorkflowIntrastepTransition::IntrastepTransitionType newTransitionType)
    : m_transitionType(newTransitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowIntrastepTransition::~WorkflowIntrastepTransition()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool WorkflowIntrastepTransition::eventTest (QEvent * e)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    if( e->type() != WorkflowIntrastepTransitionEvent::getWorkflowIntrastepTransitionEventType() )
    {
        return false;
    }

    WorkflowIntrastepTransitionEvent * workflowEvent = static_cast<WorkflowIntrastepTransitionEvent *>( e );

    return ( this->getTransitionType() == workflowEvent->eventTransitionType() );
}

void WorkflowIntrastepTransition::onTransition (QEvent *)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowIntrastepTransition::IntrastepTransitionType WorkflowIntrastepTransition::getTransitionType () const
{
    return ( m_transitionType );
}

void WorkflowIntrastepTransition::setTransitionType (const IntrastepTransitionType & value)
{
    m_transitionType = value;
}
