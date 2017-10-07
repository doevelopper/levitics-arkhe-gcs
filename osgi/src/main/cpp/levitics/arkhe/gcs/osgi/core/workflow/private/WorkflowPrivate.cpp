
#include <core/workflow/private/WorkflowPrivate.hpp>
log4cxx::LoggerPtr WorkflowPrivate::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.private.WorkflowPrivate"));

// WorkflowPrivate::WorkflowPrivate()
//    : q_ptr(&object)
// {
//    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

WorkflowPrivate::WorkflowPrivate(Workflow & object)
    : q_ptr(&object)
      ,verbose(false)
      ,m_goBackToOriginStepUponSuccess(true)
      ,m_initialStep(Q_NULLPTR)
      ,m_currentStep(Q_NULLPTR)
      ,m_originStep(Q_NULLPTR)
      ,m_destinationStep(Q_NULLPTR)
      ,m_goToStep(Q_NULLPTR)
      ,m_startingStep(Q_NULLPTR)
      ,m_transitionToPreviousStartingStep(Q_NULLPTR)

//      ,m_stateToStepMap()
//      ,m_registeredSteps()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowPrivate::~WorkflowPrivate()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool
WorkflowPrivate::addStep (WorkflowStep * step)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_Q(Workflow);

    LOG4CXX_ASSERT(logger, step, "Given WorkflowStep is nul");

//    LOG4CXX_ASSERT(logger,!q->hasStep(step->id()));
//    LOG4CXX_ASSERT(logger,!this->StateMachine->isRunning());
}

void WorkflowPrivate::processingAfterOnEntry ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void WorkflowPrivate::processingAfterOnExit ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowPrivate::StepListType
WorkflowPrivate::getRegisteredSteps () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_registeredSteps );
}

void WorkflowPrivate::setRegisteredSteps (const StepListType & registeredSteps)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_registeredSteps = registeredSteps;
}

WorkflowPrivate::StateToStepMapType
WorkflowPrivate::getStateToStepMap () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_stateToStepMap;
}

void
WorkflowPrivate::setStateToStepMap (const StateToStepMapType & stateToStepMap)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_stateToStepMap = stateToStepMap;
}

QMap<WorkflowStep *, WorkflowStep *>
WorkflowPrivate::getStepToPreviousStepMap () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_stepToPreviousStepMap;
}

void WorkflowPrivate::setStepToPreviousStepMap (const QMap<WorkflowStep *, WorkflowStep *> & stepToPreviousStepMap)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_stepToPreviousStepMap = stepToPreviousStepMap;
}

WorkflowInterstepTransition::InterstepTransitionType WorkflowPrivate::getTransitionType () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_transitionType;
}

void WorkflowPrivate::setTransitionType (const WorkflowInterstepTransition::InterstepTransitionType & transitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_transitionType = transitionType;
}

bool WorkflowPrivate::getGoBackToOriginStepUponSuccess () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_goBackToOriginStepUponSuccess;
}

void WorkflowPrivate::setGoBackToOriginStepUponSuccess (bool goBackToOriginStepUponSuccess)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_goBackToOriginStepUponSuccess = goBackToOriginStepUponSuccess;
}

bool WorkflowPrivate::getVerbose () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return verbose;
}

void WorkflowPrivate::setVerbose (bool value)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    verbose = value;
}

WorkflowStep * WorkflowPrivate::startingStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_startingStep );
}

void WorkflowPrivate::setStartingStep (WorkflowStep * startingStep)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_startingStep = startingStep;
}

WorkflowStep * WorkflowPrivate::goToStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_goToStep );
}

void WorkflowPrivate::setGoToStep (WorkflowStep * goToStep)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_goToStep = goToStep;
}

WorkflowStep * WorkflowPrivate::destinationStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_destinationStep );
}

void WorkflowPrivate::setDestinationStep (WorkflowStep * destinationStep)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_destinationStep = destinationStep;
}

WorkflowStep * WorkflowPrivate::originStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_originStep );
}

void WorkflowPrivate::setOriginStep (WorkflowStep * originStep)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_originStep = originStep;
}

WorkflowStep * WorkflowPrivate::currentStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_currentStep );
}

void WorkflowPrivate::setCurrentStep (WorkflowStep * currentStep)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_currentStep = currentStep;
}

WorkflowStep * WorkflowPrivate::initialStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_initialStep );
}

void WorkflowPrivate::setInitialStep (WorkflowStep * initialStep)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_initialStep = initialStep;
}

QStateMachine *
WorkflowPrivate::stateMachine () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_stateMachine );
}

void
WorkflowPrivate::setStateMachine (QStateMachine * stateMachine)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_stateMachine = stateMachine;
}

QMap<WorkflowStep *, ForwardAndBackwardSteps *>
WorkflowPrivate::stepToForwardAndBackwardStepMap () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return ( m_stepToForwardAndBackwardStepMap );
}

void
WorkflowPrivate::setStepToForwardAndBackwardStepMap (const QMap<WorkflowStep *,
                                                                ForwardAndBackwardSteps *> & stepToForwardAndBackwardStepMap)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_stepToForwardAndBackwardStepMap = stepToForwardAndBackwardStepMap;
}
