
#include <QDebug>
#include <QStateMachine>
#include <QState>
#include <QQueue>

#include <iostream>

#include <levitics/arkhe/gcs/osgi/core/workflow/private/WorkflowStepPrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/private/WorkflowPrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/Workflow.hpp>

log4cxx::LoggerPtr Workflow::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.Workflow"));

Workflow::Workflow(QObject * parent)
    : Superclass(parent)
      ,d_ptr(new WorkflowPrivate(*this))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(Workflow);

    // d->StateMachine = new QStateMachine(this);
}

Workflow::~Workflow()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(Workflow);

//    if (d->StateMachine->isRunning())
//      {
//      d->StateMachine->stop();
//      }

//    // Clean registered step
//    while (!d->RegisteredSteps.isEmpty())
//      {
//      delete d->RegisteredSteps.takeFirst();
    //      }
}

void Workflow::start ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool Workflow::isRunning () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void Workflow::stop ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool Workflow::addTransition (WorkflowStep *                           origin,
                              WorkflowStep *                           destination,
                              const QString &                          branchId,
                              const Workflow::TransitionDirectionality directionality)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool Workflow::hasTransition (WorkflowStep *                           origin,
                              WorkflowStep *                           destination,
                              const QString &                          branchId,
                              const Workflow::TransitionDirectionality directionality)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStep * Workflow::initialStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void Workflow::setInitialStep (WorkflowStep * step)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStep *
Workflow::currentStep () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool
Workflow::hasStep (const QString & id) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStep *
Workflow::step (const QString & id) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool
Workflow::canGoForward (WorkflowStep * step) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool
Workflow::canGoBackward (WorkflowStep * step) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool
Workflow::canGoToStep (const QString & targetId, WorkflowStep * step) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QList<WorkflowStep *>
Workflow::forwardSteps (WorkflowStep * step) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QList<WorkflowStep *>
Workflow::backwardSteps (WorkflowStep * step) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QList<WorkflowStep *>
Workflow::finishSteps () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QList<WorkflowStep *>
Workflow::steps () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int
Workflow::backwardDistanceToStep (WorkflowStep * fromStep, WorkflowStep * origin) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool
Workflow::goBackToOriginStepUponSuccess () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::setGoBackToOriginStepUponSuccess (bool flag)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool
Workflow::verbose () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::setVerbose (bool value)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::goForward (const QString & desiredBranchId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::goBackward (const QString & desiredBranchId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void Workflow::goToStep (const QString & targetId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::evaluateValidationResults (bool validationSucceeded, const QString & branchId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::goToNextStepAfterSuccessfulValidation (const QString & branchId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::goToProcessingStateAfterValidationFailed ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::goToStepSucceeded ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::goToStepFailed ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::goFromGoToStepToStartingStep ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::attemptToGoToNextStep ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void
Workflow::performTransitionBetweenSteps ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
