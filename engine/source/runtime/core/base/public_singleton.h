#pragma once

#include <type_traits>

namespace Pilot
{

    template<typename T>
    class PublicSingleton
    {
    protected:
        PublicSingleton() = default;

    public:
        static T& getInstance() noexcept(std::is_nothrow_constructible<T>::value)
        {
            static T instance;   // Type T is Pilot::PilotEngine， 是这个PublicSingleton的子类
            return instance;
        }
        virtual ~PublicSingleton() noexcept = default;
        PublicSingleton(const PublicSingleton&) = delete;
        PublicSingleton& operator=(const PublicSingleton&) = delete;
    };
} // namespace Pilot
