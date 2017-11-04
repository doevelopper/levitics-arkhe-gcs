
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WIDGETS_STYLE_STYLE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WIDGETS_STYLE_STYLE_HPP
#include <QObject>
template <typename T>
class Style  //: public QAbstractListModel
{
    T * ptr;

    public:

        // Constructors
        constexpr Style() noexcept 
		: ptr(Q_NULLPTR) 
		{
        }

        constexpr Style(T * p) noexcept 
		: ptr(p) 
		{
        }

        ~Style() 
		{
            ::delete ptr;
        }

        Style(Style const & rhs)
            : ptr(rhs.ptr ? ::new T(*rhs.ptr) : Q_NULLPTR)
        {
        }

        Style(Style && rhs) noexcept
            : ptr(rhs.ptr)
        {
            rhs.ptr = Q_NULLPTR;
        }

        Style & operator=(Style rhs)
        {
            this->swap(rhs); return *this;
        }

        void swap(Style & rhs) noexcept
        {
            std::swap(rhs.ptr, this->ptr);
        }

        // Pointer stuff
        T & operator*() const noexcept
        {
            return *this->ptr;
        }

        T * operator->() const noexcept
        {
            return this->ptr;
        }

        // ~Style() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;
        // QHash< int, QByteArray > roles() const Q_DECL_OVERRIDE Q_DECL_FINAL
};

template <typename T, typename ... Args>
Style<T> make_value(Args && ... args)
{
    return Style<T>(::new T(std::forward<Args>(args) ...));
}

#endif