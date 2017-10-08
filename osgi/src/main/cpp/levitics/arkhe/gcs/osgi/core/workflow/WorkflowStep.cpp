
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStep.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/private/WorkflowStepPrivate.hpp>

log4cxx::LoggerPtr WorkflowStep::logger =
    log4cxx::Logger::getLogger(std::string("core.workflow.WorkflowStep"));

WorkflowStep::WorkflowStep()
    : d_ptr(new WorkflowStepPrivate(*this))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WorkflowStep::WorkflowStep(const QString & newId)
    : d_ptr(new WorkflowStepPrivate(*this))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

////    Q_D(WorkflowStep);
////    d->Id = newId;
}

// WorkflowStep::WorkflowStep(WorkflowStepPrivate * pimpl,
//                           const QString &       newId)
//    : d_ptr(pimpl)
// {
//    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

////    Q_D(WorkflowStep);
////    d->Id = newId;
// }

WorkflowStep::~WorkflowStep()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QString WorkflowStep::id () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);

    return d->id();
}

void WorkflowStep::id (const QString & newStepId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);

    if( d->workflow()
        && d->workflow()->hasStep(newStepId)
        && !this->id().isEmpty() )
    {
        LOG4CXX_WARN(logger, QString("Failed to change id from '%1' to '%2' - "
                                     "Step already added to a workflow !"
                                     ).arg(this->id()).arg(newStepId).toStdString()
                     );

        return;
    }

    d->id(newStepId);
}

QString WorkflowStep::name () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);

    return d->name();
}

void WorkflowStep::name (const QString & newName)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);
    d->setName(newName);
}

QString WorkflowStep::description () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);

    return d->description();
}

void WorkflowStep::description (const QString & newDescription)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);
    d->setDescription(newDescription);
}

QString WorkflowStep::statusText () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);

    return d->statusText();
}

void WorkflowStep::statusText (const QString & txt)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);
    d->setStatusText(txt);
}

bool WorkflowStep::hasValidateCommand () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D (const WorkflowStep);

    return ( d->hasValidateCmd() );
}

void WorkflowStep::hasValidateCommand (bool newHasValidateCommand)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);
    d->hasValidateCmd(newHasValidateCommand);
}

bool WorkflowStep::hasOnEntryCommand () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
}

void WorkflowStep::hasOnEntryCommand (bool newHasOnEntryCommand)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);
}

bool WorkflowStep::isWidgetType () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
}

QObject *
WorkflowStep::workflowStepQObject ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);

    return ( d );
}

void WorkflowStep::validationComplete (bool validationResults, const QString & branchId) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
    d->validationCompleteInternal(validationResults, branchId);
}

// *
void WorkflowStep::onEntryComplete () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
    d->onEntryCompleteInternal();
}

void WorkflowStep::onExitComplete () const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
    d->onExitCompleteInternal();
}

void WorkflowStep::invokeValidateCommand (const QString & desiredBranchId) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
    d->invokeValidateCommandInternal(desiredBranchId);
}

void WorkflowStep::invokeOnEntryCommand (const WorkflowStep *                                       comingFrom,
                                         const WorkflowInterstepTransition::InterstepTransitionType transitionType)
const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
    d->invokeOnEntryCommandInternal(comingFrom, transitionType);
}

void WorkflowStep::invokeOnExitCommand (const WorkflowStep *                                       goingTo,
                                        const WorkflowInterstepTransition::InterstepTransitionType transitionType)
const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(const WorkflowStep);
    d->invokeOnExitCommandInternal(goingTo, transitionType);
}

void WorkflowStep::validate (const QString & desiredBranchId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(WorkflowStep);

    LOG4CXX_DEBUG(logger, QString("validate - validating the input from %1").arg(d->name()).toStdString());

    //    this->validationComplete(true, desiredBranchId);
}

void WorkflowStep::onEntry (const WorkflowStep *                                       comingFrom,
                            const WorkflowInterstepTransition::InterstepTransitionType transitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_UNUSED(comingFrom);
    Q_UNUSED(transitionType);

    // Signals that we are finished
    this->onEntryComplete();
}

void WorkflowStep::onExit (const WorkflowStep *                                       goingTo,
                           const WorkflowInterstepTransition::InterstepTransitionType transitionType)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_UNUSED(goingTo);
    Q_UNUSED(transitionType);

    //  this->onExitComplete();
}

// */
