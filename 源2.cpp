#include "campus_nav.h"

// 2. 记历史功能实现：栈实现访问记录与回退
void CampusNav::addVisitHistory(const Point& p) {
    if (p.id == -1) return;
    historyStack.push(p);
    // 同步更新访问流水与热度
    visitFlowQueue.push(p);
    pointMap[p.id].hot++;
    // 滑动窗口控制流水长度
    if (visitFlowQueue.size() > maxFlowSize) {
        visitFlowQueue.pop();
    }
    cout << "[记录] 已访问：" << p.name << endl;
}

Point CampusNav::goBackHistory() {
    if (historyStack.empty()) {
        cout << "[提示] 无历史记录可回退" << endl;
        return Point(-1, "", "", 0, 0);
    }
    Point lastPoint = historyStack.top();
    historyStack.pop();
    cout << "[回退] 已返回：" << lastPoint.name << endl;
    return lastPoint;
}

void CampusNav::showHistory() {
    if (historyStack.empty()) {
        cout << "[提示] 暂无访问历史" << endl;
        return;
    }
    stack<Point> tempStack = historyStack;
    cout << "===== 访问历史（从新到旧）=====" << endl;
    int rank = 1;
    while (!tempStack.empty()) {
        cout << rank << ". " << tempStack.top().name << endl;
        tempStack.pop();
        rank++;
    }
}