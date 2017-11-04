#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PIMPLPTR_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PIMPLPTR_HPP

#include  <memory>
#include <QtGlobal>
/*!
 * @brief Smart pointer implementing the pimpl idiom
 */
namespace levitics::arkhe::gcs::osgi::core
{
    template <typename T>
    class PimplPtr
    {
        public:

            PimplPtr();
            explicit PimplPtr(T * data);
            PimplPtr(const PimplPtr<T> & copy);
            template <typename A1>
            PimplPtr(A1 argument1);
            template <typename A1, typename A2>
            PimplPtr(A1 argument1, A2 argument2);
            template <typename A1, typename A2, typename A3>
            PimplPtr(A1 argument1, A2 argument2, A3 argument3);
            T * operator-> ();
            const T * operator-> () const;
            T & operator* ();
            const T & operator* () const;
            void swap (PimplPtr<T> & other);

        private:

            PimplPtr<T> & operator= (const PimplPtr<T> &);

            std::shared_ptr<T> m_data;
    };
}

#endif
