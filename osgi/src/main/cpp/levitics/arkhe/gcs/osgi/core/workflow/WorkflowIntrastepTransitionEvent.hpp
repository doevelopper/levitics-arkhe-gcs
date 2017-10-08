
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTRASTEPTRANSITIONEVENT_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTRASTEPTRANSITIONEVENT_HPP

#include <QEvent>
#include <QAbstractTransition>
#include <QString>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

class WorkflowIntrastepTransitionEvent
    : public  QEvent
{

    public:

        WorkflowIntrastepTransitionEvent();
        WorkflowIntrastepTransitionEvent(int newTransitionType);
        WorkflowIntrastepTransitionEvent(const WorkflowIntrastepTransitionEvent &) Q_DECL_EQ_DEFAULT;
        WorkflowIntrastepTransitionEvent(WorkflowIntrastepTransitionEvent &&) Q_DECL_EQ_DEFAULT;
        WorkflowIntrastepTransitionEvent & operator=(const WorkflowIntrastepTransitionEvent &) & = default;
        WorkflowIntrastepTransitionEvent & operator=(WorkflowIntrastepTransitionEvent &&) & = default;
        virtual ~WorkflowIntrastepTransitionEvent();

       static inline int getWorkflowIntrastepTransitionEventType();
       int eventTransitionType() const;
       void eventTransitionType(int evtTransitionType);
    private:
         int m_eventTransitionType;
        static log4cxx::LoggerPtr logger;
};

#endif
