# DBLSQD Qt SDK

The DBLSQD Qt SDK gives you platform-independent auto-updates for any Qt 5
application with just two lines of code.

## Installation
Before you use DBLSQD in your Qt application, you need to add the
DBLSQD Qt SDK files to your project. Download the files from this repository
and put them in your project folder. Then add the following section to your
`.pro` file:

```makefile
#DBLSQD
include(dblsqd-sdk-qt/dblsqd-sdk-qt.pri)
#/DBLSQD
```

## Usage
The easiest way to integrate the DBLSQD auto-updater into your application is
by initializing it in your `main.cpp`.

First, add the necessary includes:
```cpp
#include "dblsqd/feed.h"
#include "dblsqd/update_dialog.h"
```

Then, initialize the update `Feed` and create an `updateDialog` object in
your `main()`:
```cpp
dblsqd::Feed* feed = new dblsqd::Feed("https://feeds.dblsqd.com/:app_token");
dblsqd::UpdateDialog* updateDialog = new dblsqd::UpdateDialog(feed);
```

In a real-world Qt application, your `main.cpp` might then look something like
this:
```cpp
#include "mainwindow.h"
#include <QApplication>
#include "dblsqd/feed.h"
#include "dblsqd/update_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QCoreApplication::setApplicationVersion("1.0.0");
    QCoreApplication::setApplicationName("MyApp");

    dblsqd::Feed* feed = new dblsqd::Feed();
    feed->setUrl("https://feeds.dblsqd.com/:app_token", "release", "win", "x86");
    dblsqd::UpdateDialog* updateDialog = new dblsqd::UpdateDialog(feed, dblsqd::UpdateDialog::Type::OnUpdateAvailable, &w);
    updateDialog->setIcon(":/myapp-icon.png");

    w.show();
    updateDialog->exec();

    return a.exec();
}
```

Full Doxygen documentation for the `Feed` and `UpdateDialog` classes is also
available so you can easily build a customized update experience for your
application.


## License
All parts of the DBLSQD Qt SDK are licensed under the conditions of the
Apache 2.0 license. Please consult the `LICENSE` file for further
details.

## Support
Do you need help integrating DBLSQD into your Qt application?
Please send us a message at https://www.dblsqd.com/contact and we’ll be happy
to assist you.
