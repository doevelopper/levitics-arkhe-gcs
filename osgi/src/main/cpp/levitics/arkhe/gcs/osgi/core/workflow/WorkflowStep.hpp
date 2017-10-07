
#ifndef LEVITICS_OSGI_CORE_WORKFLOW_WORKFLOWSTEP_HPP
#define LEVITICS_OSGI_CORE_WORKFLOW_WORKFLOWSTEP_HPP

#include <QEvent>
#include <QAbstractTransition>
#include <QString>
#include <QScopedPointer>

#include <levitics/osgi/core/logger/Logger.hpp>
#include <core/workflow/WorkflowIntrastepTransition.hpp>
#include <core/workflow/WorkflowInterstepTransition.hpp>

class QObject;
class QState;
class WorkflowStepPrivate;

class WorkflowStep
{
    public:

        explicit WorkflowStep();
        explicit WorkflowStep(const QString & newId);

//        WorkflowStep(const WorkflowStep &) Q_DECL_EQ_DEFAULT;
//        WorkflowStep(WorkflowStep &&) Q_DECL_EQ_DEFAULT;
//        WorkflowStep & operator=(const WorkflowStep &) & = default;
//        WorkflowStep & operator=(WorkflowStep &&) & = default;
        virtual ~WorkflowStep();

        QString id() const;
        void id(const QString & newStepId);

        QString name() const;
        void name(const QString & newName);

        QString description() const;
        void description(const QString & newDescription);

        QString statusText() const;
        void statusText(const QString & txt);

        bool hasValidateCommand() const;
        void hasValidateCommand(bool newHasValidateCommand);

        bool hasOnEntryCommand() const;
        void hasOnEntryCommand(bool newHasOnEntryCommand);

        bool isWidgetType() const;

//        /// Get QObject associated with this step, to connect signals/slots
        QObject * workflowStepQObject();

    protected:

//        explicit WorkflowStep(WorkflowStepPrivate * pimpl, const QString & newId);

////        void setWorkflow(Workflow * newWorkflow);
//        void setStatusText(const QString & newText);
//        QState * processingState() const;
//        QState * validationState() const;
//        WorkflowIntrastepTransition * validationTransition() const;
//        WorkflowIntrastepTransition * validationFailedTransition() const;

        virtual void onEntry(const WorkflowStep *                                       comingFrom,
                             const WorkflowInterstepTransition::InterstepTransitionType transitionType);
        virtual void onExit(const WorkflowStep *                                       goingTo,
                            const WorkflowInterstepTransition::InterstepTransitionType transitionType);
        virtual void validate(const QString & desiredBranchId = QString());
        void invokeValidateCommand(const QString & desiredBranchId = QString()) const;
        void validationComplete(bool validationSuceeded, const QString & branchId = QString()) const;

        void invokeOnEntryCommand(const WorkflowStep *                                       comingFrom,
                                  const WorkflowInterstepTransition::InterstepTransitionType transitionType) const;
        void onEntryComplete() const;

        void invokeOnExitCommand(const WorkflowStep *                                       goingTo,
                                 const WorkflowInterstepTransition::InterstepTransitionType transitionType) const;
        void onExitComplete() const;
        QScopedPointer<WorkflowStepPrivate> d_ptr;

    private:

        Q_DECLARE_PRIVATE(WorkflowStep);
        Q_DISABLE_COPY(WorkflowStep);

//        friend class ctkWorkflow;        // For access to processingState, validationState, setWorkflow, validate
//        friend class ctkWorkflowPrivate; // For access to invokeOn{Entry,Exit}Command, on{Entry,Exit}
        static log4cxx::LoggerPtr logger;
};

#endif
