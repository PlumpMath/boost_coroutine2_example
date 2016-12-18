#pragma once

#include <QTimer>

#include <boost/coroutine2/all.hpp>
#include <boost/range.hpp>

using coro_t = boost::coroutines2::coroutine<int>;

class Invoker : public QObject {
    QTimer timer_;
    coro_t::pull_type coro_;
public:
    Invoker(coro_t::pull_type&& coro);

public slots:
    void run();
    void cont();
};
