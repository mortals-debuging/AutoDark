#include "themeswitcher.h"

ThemeSwitcher::ThemeSwitcher()
{
}
int ThemeSwitcher::dbusConnect(){

    QDBusConnection dbus = QDBusConnection::sessionBus();
    if (!dbus.isConnected()) {
        qWarning() << "D-Bus connection error:" << dbus.lastError().message();
        return 1;
    }

    // 构造 D-Bus 消息
    QDBusMessage msg = QDBusMessage::createMethodCall(
        "org.gnome.desktop.background",         // 接收方名称
        "/org/gnome/desktop/background/",      // 接收方路径
        "org.gnome.desktop.background",         // 接口名称
        "SetWallpaper");                        // 方法名称

    // 添加参数
    QString wallpaperPath = "/home/mortals/AutoDark/images/macos-big-sur-3840x2160-evening-apple-october-2020-event-5k-23100.jpg";
    msg << QVariant::fromValue(wallpaperPath);

    // 发送 D-Bus 消息并等待响应
    QDBusMessage reply = dbus.call(msg);
    if (reply.type() == QDBusMessage::ErrorMessage) {
        qWarning() << "D-Bus call error:" << reply.errorMessage();
        return 1;
    }
    return 1;
}
