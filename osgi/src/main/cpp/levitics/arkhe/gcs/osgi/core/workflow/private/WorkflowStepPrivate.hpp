
#ifndef LEVITICS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPPRIVATE_HPP
#define LEVITICS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPPRIVATE_HPP

#include <QObject>
#include <QPointer>
#include <core/workflow/WorkflowStep.hpp>
#include <core/workflow/Workflow.hpp>
#include <levitics/osgi/core/logger/Logger.hpp>

class QString;
class QState;

class WorkflowStepPrivate
    : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(WorkflowStep);

    public:

        WorkflowStepPrivate();
        WorkflowStepPrivate(WorkflowStep & object);
        WorkflowStepPrivate(const WorkflowStepPrivate &) = default;               // Copy constructor
        WorkflowStepPrivate(WorkflowStepPrivate &&) = default;                    // Move constructor
        WorkflowStepPrivate & operator=(const WorkflowStepPrivate &) & = default;  // Copy assignment operator
        WorkflowStepPrivate & operator=(WorkflowStepPrivate &&) & = default;       // Move assignment operator
        virtual ~WorkflowStepPrivate();

        WorkflowStep * q_ptr;

    protected:

        void invokeValidateCommandInternal(const QString & desiredBranchId) const;
        void validationCompleteInternal(bool validationSuceeded, const QString & branchId) const;
        void invokeOnEntryCommandInternal(const WorkflowStep *                                       comingFrom,
                                          const WorkflowInterstepTransition::InterstepTransitionType transitionType)
        const;
        void onEntryCompleteInternal() const;
        void invokeOnExitCommandInternal(const WorkflowStep *                                       goingTo,
                                         const WorkflowInterstepTransition::InterstepTransitionType transitionType)
        const;
        void onExitCompleteInternal() const;

        Workflow * workflow() const;
        void setWorkflow(Workflow * workflow);

        bool widgetType() const;
        void setWidgetType(bool widgetType);

        QString id() const;
        void id(const QString & id);

        QString name() const;
        void setName(const QString & mame);

        QString description() const;
        void setDescription(const QString & description);

        QString statusText() const;
        void setStatusText(const QString & statusText);

        QPointer<QState> processingState() const;
        void setProcessingState(const QPointer<QState> & processingState);

        QPointer<QState> validationState() const;
        void setValidationState(const QPointer<QState> & validationState);

        WorkflowIntrastepTransition * validationTransition() const;
        void setValidationTransition(WorkflowIntrastepTransition * validationTransition);

        WorkflowIntrastepTransition * validationFailedTransition() const;
        void setValidationFailedTransition(WorkflowIntrastepTransition * validationFailedTransition);

        bool hasValidateCmd() const;
        void hasValidateCmd(bool hasValidateCmd);

        bool hasOnEntryCmd() const;
        void hasOnEntryCmd(bool hasOnEntryCmd);

        bool hasOnExitCmd() const;
        void hasOnExitCmd(bool hasOnExitCmd);

Q_SIGNALS:

        void invokeValidateCommand(const QString & desiredBranchId) const;
        void validationComplete(bool validationSuceeded, const QString & branchId) const;
        void invokeOnEntryCommand(const WorkflowStep *                                       comingFrom,
                                  const WorkflowInterstepTransition::InterstepTransitionType transitionType) const;
        void onEntryComplete() const;
        void invokeOnExitCommand(const WorkflowStep *                                       goingTo,
                                 const WorkflowInterstepTransition::InterstepTransitionType transitionType) const;
        void onExitComplete() const;

    private:

        Workflow * m_workflow;
        bool m_widgetType;
        QString m_id;
        QString m_name;
        QString m_description;
        QString m_statusText;
        QPointer<QState> m_processingState;
        QPointer<QState> m_validationState;
        WorkflowIntrastepTransition * m_validationTransition;
        WorkflowIntrastepTransition * m_validationFailedTransition;
        bool m_hasValidateCommand;
        bool m_hasOnEntryCommand;
        bool m_hasOnExitCommand;

//        friend class ctkWorkflowPrivate; // for access to invoke...Internal() methods
        static log4cxx::LoggerPtr logger;
};

#endif
