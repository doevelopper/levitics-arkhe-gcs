
#include <levitics/osgi/core/workflow/private/WorkflowStepMockPrivate.hpp>
#include <levitics/osgi/core/workflow/WorkflowStepMock.hpp>

log4cxx::LoggerPtr WorkflowStepMock::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.WorkflowStepMock.Test"));

WorkflowStepMock::WorkflowStepMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStepMock::WorkflowStepMock(const QString & newId)
    : WorkflowStep(newId)
      ,d_ptr(new WorkflowStepMockPrivate)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStepMock::~WorkflowStepMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void WorkflowStepMock::onEntry (
    const WorkflowStep *                                       comingFrom,
    const WorkflowInterstepTransition::InterstepTransitionType transitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_UNUSED(comingFrom);
    Q_UNUSED(transitionType);

    Q_D(WorkflowStepMock);
    d->numberOfTimesRanOnEntry(d->numberOfTimesRanOnEntry() + 1);
    this->onEntryComplete();
}

void WorkflowStepMock::onExit (
    const WorkflowStep *                                       goingTo,
    const WorkflowInterstepTransition::InterstepTransitionType transitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_UNUSED(goingTo);
    Q_UNUSED(transitionType);

    Q_D(WorkflowStepMock);
    d->numberOfTimesRanOnExit(d->numberOfTimesRanOnExit() + 1 );
    this->onExitComplete();
}

void WorkflowStepMock::validate (const QString & desiredBranchId)
{
    // Always returns true in this simple example
    this->validationComplete(true,desiredBranchId);
}

int WorkflowStepMock::numberOfTimesRanOnEntry () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStepMock);

    return ( d->numberOfTimesRanOnEntry() );
}

int WorkflowStepMock::numberOfTimesRanOnExit () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStepMock);

    return ( d->numberOfTimesRanOnExit() );
}
