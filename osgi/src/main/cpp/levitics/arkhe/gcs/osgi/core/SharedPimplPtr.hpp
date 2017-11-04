#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_SHAREDPIMPLPTR_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_SHAREDPIMPLPTR_HPP

#include  <memory>
#include <QtGlobal>
/*!
 * @brief Smart pointer implementing the pimpl idiom with a sharing stategy
 */
namespace levitics::arkhe::gcs::osgi::core
{
    template <typename T>
    class SharedPimplPtr
    {
        public:

            SharedPimplPtr();
            explicit SharedPimplPtr(T * data);
            template <typename T1>
            SharedPimplPtr(T1 arg1);
            template <typename T1, typename T2>
            SharedPimplPtr(T1 arg1, T2 arg2);
            template <typename T1, typename T2, typename T3>
            SharedPimplPtr(T1 arg1, T2 arg2, T3 arg3);
            T * operator-> ();
            const T * operator-> () const;
            T & operator* ();
            const T & operator* () const;
            void swap (SharedPimplPtr<T> & other);
            void unique ();

        private:

            SharedPimplPtr<T> & operator= (const SharedPimplPtr<T> &);
            std::shared_ptr<T> m_data;
    };
}
#endif


