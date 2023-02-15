#pragma once

#include "EECSGE/core/include/Event.hpp"
#include "EECSGE/core/include/Types.hpp"

class CollisionEvent : public Event
{
public:
    CollisionEvent() = delete;

    explicit CollisionEvent(EntityId first, EntityId second)
        : Event(EventId::Collision)
    {
        SetParam(EventId::First, first);
        SetParam(EventId::Second, second);
    }

    EntityId GetFirst() const
    {
        return GetParam<EntityId>(EventId::First);
    }

    EntityId GetSecond() const
    {
        return GetParam<EntityId>(EventId::Second);
    }
};