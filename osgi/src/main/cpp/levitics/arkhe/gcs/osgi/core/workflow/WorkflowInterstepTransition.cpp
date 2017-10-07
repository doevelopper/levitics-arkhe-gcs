
#include <core/workflow/WorkflowInterstepTransition.hpp>
#include <core/workflow/WorkflowInterstepTransitionEvent.hpp>
log4cxx::LoggerPtr WorkflowInterstepTransition::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.WorkflowInterstepTransition"));

WorkflowInterstepTransition::WorkflowInterstepTransition()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowInterstepTransition::WorkflowInterstepTransition(InterstepTransitionType newTransitionType)
    : m_transitionType(newTransitionType)
{
}

WorkflowInterstepTransition::WorkflowInterstepTransition(InterstepTransitionType newTransitionType,
                                                         const QString &         newId
                                                         )
    : m_transitionType(newTransitionType)
      ,m_id(newId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowInterstepTransition::~WorkflowInterstepTransition()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowInterstepTransition::InterstepTransitionType
WorkflowInterstepTransition::transitionType () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_transitionType );
}

void
WorkflowInterstepTransition::transitionType (InterstepTransitionType type)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QString WorkflowInterstepTransition::id () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_id );
}

void WorkflowInterstepTransition::id (QString id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool WorkflowInterstepTransition::eventTest (QEvent * e)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    if( e->type() != QEvent::registerEventType(QEvent::User + 1) )
    {
        LOG4CXX_DEBUG(logger, "check the event type is QEvent::User + 1");

        return ( false );
    }

    WorkflowInterstepTransitionEvent * workflowEvent = static_cast<WorkflowInterstepTransitionEvent *>( e );

    return ( this->m_transitionType == workflowEvent->eventTransitionType()
             && this->m_id == workflowEvent->eventId() );
}

void WorkflowInterstepTransition::onTransition (QEvent *)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
