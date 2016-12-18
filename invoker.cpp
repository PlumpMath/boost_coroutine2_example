
#include "invoker.h"

#include <QtDebug>

Invoker::Invoker(coro_t::pull_type&& coro) : coro_(std::move(coro)) {
    timer_.setSingleShot(true);
    connect(&timer_, &QTimer::timeout, this, &Invoker::cont);
}

void Invoker::run() {
    if(coro_) {
        auto sec = coro_.get();
        qDebug() << "Sleep:" << sec;
        timer_.start(sec * 1000);
    } else {
        qDebug() << "Command finished";
    }
}

void Invoker::cont() {
    coro_();
    run();
}
