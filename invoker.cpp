
#include "invoker.h"

#include <QtDebug>

Invoker::Invoker(coro_t::pull_type&& coro) : coro_(std::move(coro)) {
    timer_.setSingleShot(true);
    connect(&timer_, &QTimer::timeout, this, &Invoker::run);
    iter_ = begin(coro_);
}

void Invoker::run() {
    if (iter_ != end(coro_)) {
        int sec = *iter_;
        qDebug() << "Sleep:" << sec;
        timer_.start(sec * 1000);
        ++iter_;
    }
}
