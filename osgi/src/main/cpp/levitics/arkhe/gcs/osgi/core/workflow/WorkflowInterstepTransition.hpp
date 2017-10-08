#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTERSTEPTRANSITION_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTERSTEPTRANSITION_HPP

#include <QEvent>
#include <QAbstractTransition>
#include <QString>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

class WorkflowInterstepTransition : public QAbstractTransition
{
    Q_OBJECT
    Q_ENUMS(InterstepTransitionType)
public:
    enum InterstepTransitionType
    {
      TransitionToNextStep = 0,
      TransitionToPreviousStep,
      StartingWorkflow,
      StoppingWorkflow,
      TransitionToPreviousStartingStepAfterSuccessfulGoToFinishStep
    };

    WorkflowInterstepTransition();
    WorkflowInterstepTransition(InterstepTransitionType newTransitionType);
    WorkflowInterstepTransition(InterstepTransitionType newTransitionType, const QString& newId);
    WorkflowInterstepTransition(const WorkflowInterstepTransition&) Q_DECL_EQ_DEFAULT;
    WorkflowInterstepTransition(WorkflowInterstepTransition&&) Q_DECL_EQ_DEFAULT;
    WorkflowInterstepTransition& operator=(const WorkflowInterstepTransition&) & = default;
    WorkflowInterstepTransition& operator=(WorkflowInterstepTransition&&) & = default;
    virtual ~WorkflowInterstepTransition();

    InterstepTransitionType transitionType() const;
    void transitionType(InterstepTransitionType type);
    QString id() const;
    void id(QString id);
     void onTransition(QEvent*);
protected:
    virtual bool eventTest(QEvent* e);
private:
    static log4cxx::LoggerPtr logger;
    InterstepTransitionType m_transitionType;
    QString m_id;
};
#endif
