
#include <levitics/osgi/core/workflow/WorkflowStepSignals.hpp>
#include <levitics/osgi/core/workflow/private/WorkflowStepSignalsPrivate.hpp>

log4cxx::LoggerPtr WorkflowStepSignals::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.WorkflowStepSignals.Test"));

WorkflowStepSignals::WorkflowStepSignals()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStepSignals::WorkflowStepSignals(WorkflowStep * newStep, QObject * parent)
    : QObject(parent)
      ,d_ptr(new WorkflowStepSignalsPrivate)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStepSignals);
    d->setStep(newStep);
}

WorkflowStepSignals::~WorkflowStepSignals()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int WorkflowStepSignals::numberOfTimesRanOnEntry () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStepSignals);

    return ( d->numberOfTimesRanOnEntry() );
}

int WorkflowStepSignals::numberOfTimesRanOnExit () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    Q_D(const WorkflowStepSignals);

    return ( d->numberOfTimesRanOnExit() );
}

void WorkflowStepSignals::validate (const QString & desiredBranchId) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStepSignals);
    QObject::staticMetaObject.invokeMethod( d->step()->workflowStepQObject(), "validationComplete",
                                            Q_ARG(bool, true), Q_ARG(QString, desiredBranchId)
                                            );
}

void WorkflowStepSignals::validateFails () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStepSignals);
    QObject::staticMetaObject.invokeMethod( d->step()->workflowStepQObject(), "validationComplete",
                                            Q_ARG(bool, false), Q_ARG(QString, "")
                                            );
}

void WorkflowStepSignals::onEntry (const WorkflowStep *                                       comingFrom,
                                   const WorkflowInterstepTransition::InterstepTransitionType transitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_UNUSED(comingFrom);
    Q_UNUSED(transitionType);

    Q_D(WorkflowStepSignals);
    d->setNumberOfTimesRanOnEntry(d->numberOfTimesRanOnEntry() + 1);
    QObject::staticMetaObject.invokeMethod( d->step()->workflowStepQObject(), "onEntryComplete");
}

void WorkflowStepSignals::onExit (const WorkflowStep *                                       goingTo,
                                  const WorkflowInterstepTransition::InterstepTransitionType transitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_UNUSED(goingTo);
    Q_UNUSED(transitionType);

    Q_D(WorkflowStepSignals);
    d->setNumberOfTimesRanOnExit(d->numberOfTimesRanOnExit() + 1);

    QObject::staticMetaObject.invokeMethod( d->step()->workflowStepQObject(), "onExitComplete");
}
