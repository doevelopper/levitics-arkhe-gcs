
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTERSTEPTRANSITIONEVENT_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTERSTEPTRANSITIONEVENT_HPP

#include <QEvent>
#include <QAbstractTransition>
#include <QString>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

class WorkflowInterstepTransitionEvent
    : public QEvent
{


    public:

        WorkflowInterstepTransitionEvent();
        WorkflowInterstepTransitionEvent(int newTransitionType);
        WorkflowInterstepTransitionEvent(const WorkflowInterstepTransitionEvent &) Q_DECL_EQ_DEFAULT;
        WorkflowInterstepTransitionEvent(WorkflowInterstepTransitionEvent &&) Q_DECL_EQ_DEFAULT;
        WorkflowInterstepTransitionEvent & operator=(const WorkflowInterstepTransitionEvent &) & = default;
        WorkflowInterstepTransitionEvent & operator=(WorkflowInterstepTransitionEvent &&) & = default;
        virtual ~WorkflowInterstepTransitionEvent();
        int eventTransitionType() const;
        void eventTransitionType(int evtTransitiontype);
        QString eventId()const;
        void eventId(QString evtID);

    private:
        int     m_eventTransitionType;
        QString m_eventId;
        static log4cxx::LoggerPtr logger;
};

#endif
