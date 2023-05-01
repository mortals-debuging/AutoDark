#ifndef THEMESWITCHER_H
#define THEMESWITCHER_H
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>

class ThemeSwitcher
{

public:
    ThemeSwitcher();
    int dbusConnect();
};

#endif // THEMESWITCHER_H
