
#include <QState>
#include <core/workflow/private/WorkflowStepPrivate.hpp>

log4cxx::LoggerPtr WorkflowStepPrivate::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.private.WorkflowStepPrivate"));

WorkflowStepPrivate::WorkflowStepPrivate()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStepPrivate::WorkflowStepPrivate(WorkflowStep & object)
    : q_ptr(&object)
      ,m_workflow(Q_NULLPTR)
      ,m_widgetType(false)
      ,m_processingState( new QState())
      ,m_validationState( new QState())
      ,m_validationTransition(new WorkflowIntrastepTransition(WorkflowIntrastepTransition::ValidationTransition))
      ,m_validationFailedTransition(new WorkflowIntrastepTransition(WorkflowIntrastepTransition::
                                                                    ValidationFailedTransition))
      ,m_hasValidateCommand(false)
      ,m_hasOnEntryCommand(false)
      ,m_hasOnExitCommand(false)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    qRegisterMetaType<WorkflowStep *>("WorkflowStep*");

//    this->validationTransition()->setTargetState(this->validationState());
//    this->processingState()->addTransition(this->validationTransition());

//    this->validationFailedTransition()->setTargetState(this->processingState());
//    this->validationState()->addTransition(this->validationFailedTransition());
}

WorkflowStepPrivate::~WorkflowStepPrivate()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

//    if( !this->validationState().isNull() )
//    {
//        delete this->m_validationState;
//    }

//    if( !this->processingState().isNull() )
//    {
//        delete this->m_processingState;
//    }
}

// *
void WorkflowStepPrivate::invokeValidateCommandInternal (const QString & desiredBranchId) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    emit invokeValidateCommand(desiredBranchId);
}

void WorkflowStepPrivate::validationCompleteInternal (bool validationSuceeded, const QString & branchId) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    emit validationComplete(validationSuceeded, branchId);
}

void
WorkflowStepPrivate::invokeOnEntryCommandInternal (
    const WorkflowStep *                                       comingFrom,
    const WorkflowInterstepTransition::InterstepTransitionType transitionType) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    emit invokeOnEntryCommand(comingFrom, transitionType);
}

void
WorkflowStepPrivate::onEntryCompleteInternal () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    emit onEntryComplete();
}

void
WorkflowStepPrivate::invokeOnExitCommandInternal (
    const WorkflowStep *                                       goingTo,
    const WorkflowInterstepTransition::InterstepTransitionType transitionType)
const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    emit invokeOnExitCommand(goingTo, transitionType);
}

void WorkflowStepPrivate::onExitCompleteInternal () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    emit onExitComplete();
}

bool WorkflowStepPrivate::hasOnExitCmd () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_hasOnExitCommand );
}

void WorkflowStepPrivate::hasOnExitCmd (bool hasOnExitCommand)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_hasOnExitCommand = hasOnExitCommand;
}

bool WorkflowStepPrivate::hasOnEntryCmd () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_hasOnEntryCommand );
}

void WorkflowStepPrivate::hasOnEntryCmd (bool hasOnEntryCommand)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_hasOnEntryCommand = hasOnEntryCommand;
}

bool WorkflowStepPrivate::hasValidateCmd () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_hasValidateCommand );
}

void WorkflowStepPrivate::hasValidateCmd (bool hasValidateCommand)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_hasValidateCommand = hasValidateCommand;
}

WorkflowIntrastepTransition *
WorkflowStepPrivate::validationFailedTransition () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_validationFailedTransition );
}

void WorkflowStepPrivate::setValidationFailedTransition (WorkflowIntrastepTransition * validationFailedTransition)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_validationFailedTransition = validationFailedTransition;
}

WorkflowIntrastepTransition
* WorkflowStepPrivate::validationTransition () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_validationTransition );
}

void WorkflowStepPrivate::setValidationTransition (WorkflowIntrastepTransition * validationTransition)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_validationTransition = validationTransition;
}

QPointer<QState>
WorkflowStepPrivate::validationState () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_validationState );
}

void WorkflowStepPrivate::setValidationState (const QPointer<QState> & validationState)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_validationState = validationState;
}

QPointer<QState>
WorkflowStepPrivate::processingState () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_processingState );
}

void
WorkflowStepPrivate::setProcessingState (const QPointer<QState> & processingState)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_processingState = processingState;
}

QString
WorkflowStepPrivate::statusText () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_statusText );
}

void
WorkflowStepPrivate::setStatusText (const QString & statusText)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_statusText = statusText;
}

QString
WorkflowStepPrivate::description () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_description );
}

void
WorkflowStepPrivate::setDescription (const QString & description)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_description = description;
}

QString
WorkflowStepPrivate::name () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_name );
}

void
WorkflowStepPrivate::setName (const QString & name)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_name = name;
}

QString
WorkflowStepPrivate::id () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_id );
}

void
WorkflowStepPrivate::id (const QString & id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_id = id;
}

bool
WorkflowStepPrivate::widgetType () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_widgetType );
}

void
WorkflowStepPrivate::setWidgetType (bool widgetType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_widgetType = widgetType;
}

Workflow *
WorkflowStepPrivate::workflow () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_workflow );
}

void
WorkflowStepPrivate::setWorkflow (Workflow * workflow)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_workflow = workflow;
}
